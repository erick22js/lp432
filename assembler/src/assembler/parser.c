//#include <windows.h>
//#include <Shlwapi.h>

#include "parser.h"
#include "base.h"
#include "symbols.h"
#include "path.h"


/*
	Global Parser Properties
*/

Parser parser;


/*
	Parser Outputting Functions
*/

void out8(uint8 data) {
	if (!parser.phase_one){
		(parser.bin)[parser.bc] = data;
	}
	parser.pc += 1; parser.bc += 1;
	if (parser.phase_one && parser.bc > parser.bin_size){
		parser.bin_size = parser.bc;
	}
}

void out16(uint16 data) {
	if (!parser.phase_one){
		(parser.bin)[parser.bc] = (data)&0xFF;
		(parser.bin)[parser.bc+1] = (data>>8)&0xFF;
	}
	parser.pc += 2; parser.bc += 2;
	if (parser.phase_one && parser.bc > parser.bin_size){
		parser.bin_size = parser.bc;
	}
}

void out32(uint32 data) {
	if (!parser.phase_one){
		(parser.bin)[parser.bc] = (data)&0xFF;
		(parser.bin)[parser.bc+1] = (data>>8)&0xFF;
		(parser.bin)[parser.bc+2] = (data>>16)&0xFF;
		(parser.bin)[parser.bc+3] = (data>>24)&0xFF;
	}
	parser.pc += 4; parser.bc += 4;
	if (parser.phase_one && parser.bc > parser.bin_size){
		parser.bin_size = parser.bc;
	}
}

int encodeInstruction(Enc *encode, Arg* args, uint8 cond_desc) {
	// Detects for auxiliary bytes and
	// Resulting encoding
	bool has_os1 = false;
	bool has_os2 = false;
	bool has_os3 = false;
	bool has_ns = false;
	bool has_mv = false;
	uint8 os1 = 0x0;
	uint8 os2 = 0x0;
	uint8 os3 = 0x0;
	MemAccess mem;
	uint32 mv = 0x0;
	uint8 mv_size = 32;

	// Encode the given arguments
	for (int i = 0; i<encode->params_length; i++){
		Param *param = &encode->params[i];
		Arg *arg = &args[i];

		switch (param->encode){
			case ENCODE_REGM1: 
			case ENCODE_REGM: {
				has_os1 = true;
				os1 = (os1&0xF0) | (arg->value.code&0x0F);
			}
			break;
			case ENCODE_REGO1: 
			case ENCODE_REGO: {
				has_os1 = true;
				os1 = (os1&0x0F) | ((arg->value.code&0xF) << 4);
			}
			break;
			case ENCODE_REGM2: {
				has_os2 = true;
				os2 = (os2&0xF0) | (arg->value.code&0x0F);
			}
			break;
			case ENCODE_REGO2: {
				has_os2 = true;
				os2 = (os2&0x0F) | ((arg->value.code&0xF) << 4);
			}
			break;
			case ENCODE_REGM3: {
				has_os3 = true;
				os3 = (os3&0xF0) | (arg->value.code&0x0F);
			}
			break;
			case ENCODE_REGO3: {
				has_os3 = true;
				os3 = (os3&0x0F) | ((arg->value.code&0xF) << 4);
			}
			break;
			case ENCODE_MEM: {
				has_ns = true;
				mem = arg->value.mem;
			}
			break;
			case ENCODE_MV8: {
				has_mv = true;
				mv_size = 8;
				mv = arg->value.integer;
			}
			break;
			case ENCODE_MV16: {
				has_mv = true;
				mv_size = 16;
				mv = arg->value.integer;
			}
			break;
			case ENCODE_MV32: {
				has_mv = true;
				mv_size = 32;
				mv = arg->value.integer;
			}
			break;
		}
	}

	// Outputs the given result
	out8(encode->opcode);
	if (has_os1 || encode->desc == COND_DESC || encode->desc == CONDO_DESC){
		// Descriptor will be the conditional code
		if (encode->desc == COND_DESC || encode->desc == CONDO_DESC){
			out8((os1&0x0F) | ((cond_desc&0xF)<<4));
		}
		// Descriptor will be the specified by encode instruction
		else if (encode->desc != NO_DESC){
			out8((os1&0x0F) | ((encode->desc&0xF)<<4));
		}
		// Descriptor will be replaced by second operand
		else {
			out8(os1);
		}
		if (has_os2){
			out8(os2);
			if (has_os3){
				out8(os3);
			}
		}
	}
	if (has_ns){
		out8((mem.regi&0x0F) | ((mem.adrm&0x0F) << 4));
		switch (mem.adrm){
			case ADRM_IDX8:
			case ADRM_ABS8: {
				out8(mem.nv);
			}
			break;
			case ADRM_IDX16:
			case ADRM_ABS16: {
				out16(mem.nv);
			}
			break;
			case ADRM_IDX32:
			case ADRM_ABS32: {
				out32(mem.nv);
			}
			break;
			case ADRM_PTR: {}
			break;
			case ADRM_IDXI: {
				out8(mem.reg1&0x0F);
			}
			break;
			case ADRM_STC8:
			case ADRM_IDXI8: {
				out8(mem.reg1&0x0F);
				out8(mem.nv);
			}
			break;
			case ADRM_STC16:
			case ADRM_IDXI16: {
				out8(mem.reg1&0x0F);
				out16(mem.nv);
			}
			break;
			case ADRM_STC32:
			case ADRM_IDXI32: {
				out8(mem.reg1&0x0F);
				out32(mem.nv);
			}
			break;
			case ADRM_DYN: {
				out8((mem.reg1&0x0F) | ((mem.reg2&0x0F)<<4));
			}
			break;
			case ADRM_DYNI: {
				out8((mem.reg1&0x0F) | ((mem.reg2&0x0F)<<4));
				out16(mem.nv);
			}
			break;
		}
	}
	if (has_mv){
		switch (mv_size){
			case 8: { out8(mv); }; break;
			case 16: { out16(mv); }; break;
			case 32: { out32(mv); }; break;
		}
	}

	return 0;
}


/*
	Expression parsing Functions
*/

int parserExpUnary(Value *out){
	createSeek();
	Token tk = {0};
	tryCatchAndThrow(
		tkrFetchToken(&tk)
	);

	// Only constant values are currently supported
	if (tk.kind == TOKEN_INTEGER){
		out->type = TYPE_IMM;
		out->value.integer = tk.value.integer;
	}
	else if (tk.kind == TOKEN_IDENTIFIER){
		Value *val = findSymbol(tk.value.string);
		if (val){
			*out = *val;
		}
		else if(!parser.phase_one){
			asm_error_v1 = tk.value.string;
			throwError(ERROR_SYMBOL_NOT_DEFINED);
		}
		else {
			out->type = TYPE_IMM;
			out->value.integer = 0;
		}
	}
	else if (tkIsSymbol(tk, '@') || tkIsSymbol(tk, '$')){
		saveSeek();
		uint32 address = tkIsSymbol(tk, '@')? parser.pc: parser.bc;
		tryCatchAndThrow(
			tkrFetchToken(&tk)
		);

		if (tk.kind == TOKEN_INTEGER){
			out->type = TYPE_IMM;
			out->value.integer = tk.value.integer - address;
		}
		else if (tk.kind == TOKEN_IDENTIFIER){
			Value *val = findSymbol(tk.value.string);
			if (val){
				*out = *val;
				out->value.integer -= address;
			}
			else{
				asm_error_v1 = tk.value.string;
				throwError(ERROR_SYMBOL_NOT_DEFINED);
			}
		}
		else {
			restoreSeek();
			out->type = TYPE_IMM;
			out->value.integer = address;
		}
	}
	else if (tkIsSymbol(tk, '+')){
		Value in;
		tryCatchAndThrow(
			parserExpUnary(&in)
		);
		out->type = in.type;
		out->value = in.value;
	}
	else if (tkIsSymbol(tk, '-')){
		Value in;
		tryCatchAndThrow(
			parserExpUnary(&in)
		);
		out->type = in.type;
		out->value.integer = -((sint32)in.value.integer);
	}
	else if (tkIsSymbol(tk, '~')){
		Value in;
		tryCatchAndThrow(
			parserExpUnary(&in)
		);
		out->type = in.type;
		out->value.integer = ~in.value.integer;
	}
	else if (tkIsSymbol(tk, '!')){
		Value in;
		tryCatchAndThrow(
			parserExpUnary(&in)
		);
		out->type = in.type;
		out->value.integer = !in.value.integer;
	}
	else if (tkIsSymbol(tk, '(')){
		tryCatchAndThrow(
			parserExpression(out)
		);
		tryCatchAndThrow(
			tkrFetchToken(&tk)
		);
		if (!tkIsSymbol(tk, ')')){
			asm_error_v1 = ')';
			throwError(ERROR_EXPECTED_CHAR);
		}
	}
	// Unexpected token, expected expression
	else {
		asm_error_v1 = tk.kind;
		throwError(ERROR_UNEXPECTED);
	}

	saveSeek();
	tryCatchAndThrow(
		tkrFetchToken(&tk)
	);
	if (tkIsSymbol(tk, ':')){
		tryCatchAndThrow(
			tkrFetchToken(&tk)
		);
		DataName *data_type;
		if ((tk.kind == TOKEN_IDENTIFIER) && (data_type = findDataByName(tk.value.string))){
			switch (data_type->type_imm){
				case TYPE_IMM8: { out->value.integer = (uint8)out->value.integer; } break;
				case TYPE_IMM16: { out->value.integer = (uint16)out->value.integer; } break;
				case TYPE_IMM32: { out->value.integer = (uint32)out->value.integer; } break;
				case TYPE_IMMS8: { out->value.integer = (sint32)((sint8)out->value.integer); } break;
				case TYPE_IMMS16: { out->value.integer = (sint32)((sint16)out->value.integer); } break;
				case TYPE_IMMS32: { out->value.integer = (sint32)((sint32)out->value.integer); } break;
				default: {
					asm_error_v1 = tk.value.string;
					throwError(ERROR_INVALID_CAST_TYPE);
				}
			}
			out->type = data_type->type_imm;
		}
		else {
			throwError(ERROR_EXPECTED_DATA_TYPE);
		}
	}
	else {
		restoreSeek();
	}

	return 0;
}

int parserExpMul(Value *out) {
	Value opr1;
	tryCatchAndThrow(
		parserExpUnary(&opr1)
	);
	createSeek();

	Token tk = {0};
	tryCatchAndThrow(
		tkrFetchToken(&tk)
	);
	while (tkIsSymbol(tk, '*') || tkIsSymbol(tk, '/') || tkIsSymbol(tk, '%')){
		Value opr2;
		tryCatchAndThrow(
			parserExpUnary(&opr2)
		);
		saveSeek();
		if (tkIsSymbol(tk, '*')){
			opr1.value.integer *= opr2.value.integer;
		}
		else if (tkIsSymbol(tk, '/')){
			if (opr2.value.integer == 0 && !parser.phase_one){
				throwError(ERROR_DIVISION_BY_ZERO);
			}
			opr1.value.integer /= opr2.value.integer? opr2.value.integer: 1;
		}
		else {
			if (opr2.value.integer == 0 && !parser.phase_one){
				throwError(ERROR_DIVISION_BY_ZERO);
			}
			opr1.value.integer %= opr2.value.integer? opr2.value.integer: 1;
		}

		tryCatchAndThrow(
			tkrFetchToken(&tk)
		);
	}
	restoreSeek();

	out->type = opr1.type;
	out->value = opr1.value;
	return 0;
}

int parserExpAdd(Value *out) {
	Value opr1;
	tryCatchAndThrow(
		parserExpMul(&opr1)
	);
	createSeek();

	Token tk = {0};
	tryCatchAndThrow(
		tkrFetchToken(&tk)
	);
	while (tkIsSymbol(tk, '+') || tkIsSymbol(tk, '-')){
		Value opr2;
		tryCatchAndThrow(
			parserExpMul(&opr2)
		);
		saveSeek();
		if (tkIsSymbol(tk, '+')){
			opr1.value.integer += opr2.value.integer;
		}
		else {
			opr1.value.integer -= opr2.value.integer;
		}

		tryCatchAndThrow(
			tkrFetchToken(&tk)
		);
	}
	restoreSeek();

	out->type = opr1.type;
	out->value = opr1.value;
	return 0;
}

int parserExpShift(Value *out) {
	Value opr1;
	tryCatchAndThrow(
		parserExpAdd(&opr1)
	);
	createSeek();

	Token tk = {0};
	tryCatchAndThrow(
		tkrFetchToken(&tk)
	);
	while (tkIsSymbol(tk, '>') || tkIsSymbol(tk, '<')){
		Value opr2;
		tryCatchAndThrow(
			parserExpAdd(&opr2)
		);
		saveSeek();
		if (tkIsSymbol(tk, '>')){
			opr1.value.integer >>= opr2.value.integer;
		}
		else {
			opr1.value.integer <<= opr2.value.integer;
		}

		tryCatchAndThrow(
			tkrFetchToken(&tk)
		);
	}
	restoreSeek();

	out->type = opr1.type;
	out->value = opr1.value;
	return 0;
}

int parserExpEqual(Value *out) {
	Value opr1;
	tryCatchAndThrow(
		parserExpShift(&opr1)
	);
	createSeek();

	Token tk = {0};
	tryCatchAndThrow(
		tkrFetchToken(&tk)
	);
	while (tkIsSymbol(tk, '=')||tkIsSymbol(tk, '!')){
		Value opr2;
		tryCatchAndThrow(
			parserExpShift(&opr2)
		);
		saveSeek();
		if (tkIsSymbol(tk, '=')){
			opr1.value.integer = opr1.value.integer==opr2.value.integer;
		}
		else {
			opr1.value.integer = opr1.value.integer!=opr2.value.integer;
		}

		tryCatchAndThrow(
			tkrFetchToken(&tk)
		);
	}
	restoreSeek();

	out->type = opr1.type;
	out->value = opr1.value;
	return 0;
}

int parserExpAnd(Value *out) {
	Value opr1;
	tryCatchAndThrow(
		parserExpEqual(&opr1)
	);
	createSeek();

	Token tk = {0};
	tryCatchAndThrow(
		tkrFetchToken(&tk)
	);
	while (tkIsSymbol(tk, '&')){
		Value opr2;
		tryCatchAndThrow(
			parserExpEqual(&opr2)
		);
		saveSeek();
		opr1.value.integer &= opr2.value.integer;

		tryCatchAndThrow(
			tkrFetchToken(&tk)
		);
	}
	restoreSeek();

	out->type = opr1.type;
	out->value = opr1.value;
	return 0;
}

int parserExpOr(Value *out) {
	Value opr1;
	tryCatchAndThrow(
		parserExpAnd(&opr1)
	);
	createSeek();

	Token tk = {0};
	tryCatchAndThrow(
		tkrFetchToken(&tk)
	);
	while (tkIsSymbol(tk, '|')){
		Value opr2;
		tryCatchAndThrow(
			parserExpAnd(&opr2)
		);
		saveSeek();
		opr1.value.integer |= opr2.value.integer;

		tryCatchAndThrow(
			tkrFetchToken(&tk)
		);
	}
	restoreSeek();

	out->type = opr1.type;
	out->value = opr1.value;
	return 0;
}

int parserExpXor(Value *out) {
	Value opr1;
	tryCatchAndThrow(
		parserExpOr(&opr1)
	);
	createSeek();

	Token tk = {0};
	tryCatchAndThrow(
		tkrFetchToken(&tk)
	);
	while (tkIsSymbol(tk, '^')){
		Value opr2;
		tryCatchAndThrow(
			parserExpOr(&opr2)
		);
		saveSeek();
		opr1.value.integer ^= opr2.value.integer;

		tryCatchAndThrow(
			tkrFetchToken(&tk)
		);
	}
	restoreSeek();

	out->type = opr1.type;
	out->value = opr1.value;
	return 0;
}

int parserExpression(Value* out){
	tryCatchAndThrow(
		parserExpXor(out)
	);
	return 0;
}


/*
	Parser Hidden Layer Functions
*/

bool matchTypes(DataType base, DataType given){
	if (base == TYPE_MEM8 || base == TYPE_MEM16 || base == TYPE_MEM32 || base == TYPE_MEM64){
		return given == base || given == TYPE_MEM;
	}
	if (base == TYPE_MEM){
		return given == TYPE_MEM8 || given == TYPE_MEM16 || given == TYPE_MEM32 || given == TYPE_MEM64;
	}
	if (base == TYPE_IMM8 || base == TYPE_IMM16 || base == TYPE_IMM32){
		return given == base || given == TYPE_IMM;
	}
	if (base == TYPE_IMM){
		return given == TYPE_IMM8 || given == TYPE_IMM16 || given == TYPE_IMM32 || given == TYPE_IMM;
	}
	return base == given;
}

int parserFetchArgs(Arg* args, int* count, int limit){
	createSeek();
	Token tk = {0};
	tryCatchAndThrow(
		tkrFetchToken(&tk)
	);

	while (tk.kind != TOKEN_NEW_LINE && tk.kind != TOKEN_END_OF_FILE && (*count < limit)){
		// The argument is a register
		Reg *reg = null;
		SymArg *arg = null;

		if (tk.kind == TOKEN_IDENTIFIER && (reg = findRegByName(tk.value.string))){
			args[*count].type = reg->type;
			args[*count].value.code = reg->code;
		}
		// The arcument is a memory access reference
		else if (tkIsSymbol(tk, '[')){
			saveSeek();
			tryCatchAndThrow(
				tkrFetchToken(&tk)
			);
			args[*count].type = TYPE_MEM;

			// Addressing with register index
			Reg *regi = null;
			if (tk.kind == TOKEN_IDENTIFIER && (regi = findRegByName(tk.value.string))){
				saveSeek();
				tryCatchAndThrow(
					tkrFetchToken(&tk)
				);
				args[*count].value.mem.regi = regi->code;

				// Addressing Mode => POINTER
				if (tkIsSymbol(tk, ']')){
					restoreSeek();
					args[*count].value.mem.adrm = ADRM_PTR;
				}
				else if (tkIsSymbol(tk, '-')){
					Value in;
					tryCatchAndThrow(
						parserExpression(&in)
					);
					args[*count].value.mem.adrm =
						in.value.integer<0x100 || in.type==TYPE_IMM8 || in.type==TYPE_IMMS8? ADRM_IDX8:
						in.value.integer<0x10000 || in.type==TYPE_IMM16 || in.type==TYPE_IMMS16? ADRM_IDX16:
						ADRM_IDX32;
					args[*count].value.mem.nv = -(sint32)in.value.integer;
				}
				else if (tkIsSymbol(tk, '+')){
					saveSeek();
					tryCatchAndThrow(
						tkrFetchToken(&tk)
					);

					// Indexed by Registers
					Reg *reg1 = null;
					if (tk.kind == TOKEN_IDENTIFIER && (reg1 = findRegByName(tk.value.string))){
						saveSeek();
						tryCatchAndThrow(
							tkrFetchToken(&tk)
						);
						args[*count].value.mem.reg1 = reg1->code;

						// Adressing Mode => INDEXED IMPLICIT
						if (tkIsSymbol(tk, ']')){
							restoreSeek();
							args[*count].value.mem.adrm = ADRM_IDXI;
						}
						// Adressing Mode => INDEXED IMPLICIT (WITH IMMEDIATE)
						else if (tkIsSymbol(tk, '+')){
							Value in;
							tryCatchAndThrow(
								parserExpression(&in)
							);
							args[*count].value.mem.adrm =
								in.value.integer<0x100 || in.type==TYPE_IMM8 || in.type==TYPE_IMMS8? ADRM_IDXI8:
								in.value.integer<0x10000 || in.type==TYPE_IMM16 || in.type==TYPE_IMMS16? ADRM_IDXI16:
								ADRM_IDXI32;
							args[*count].value.mem.nv = in.value.integer;
						}
						else if (tkIsSymbol(tk, '*')){
							saveSeek();
							tryCatchAndThrow(
								tkrFetchToken(&tk)
							);
							
							// Addressing by Register
							Reg *reg2 = null;
							if (tk.kind == TOKEN_IDENTIFIER && (reg2 = findRegByName(tk.value.string))){
								saveSeek();
								tryCatchAndThrow(
									tkrFetchToken(&tk)
								);
								args[*count].value.mem.reg2 = reg2->code;

								// Adressing Mode => DYNAMIC
								if (tkIsSymbol(tk, ']')){
									restoreSeek();
									args[*count].value.mem.adrm = ADRM_DYN;
								}
								// Adressing Mode => DYNAMIC INDEXED
								else {
									restoreSeek();
									Value in;
									tryCatchAndThrow(
										parserExpression(&in)
									);
									args[*count].value.mem.adrm = ADRM_DYNI;
									args[*count].value.mem.nv = in.value.integer;
								}
							}
							// Adressing Mode => STRUCT
							else {
								Value in;
								tryCatchAndThrow(
									parserExpression(&in)
								);
								args[*count].value.mem.adrm =
									in.value.integer<0x100 || in.type==TYPE_IMM8 || in.type==TYPE_IMMS8? ADRM_STC8:
									in.value.integer<0x10000 || in.type==TYPE_IMM16 || in.type==TYPE_IMMS16? ADRM_STC16:
									ADRM_STC32;
								args[*count].value.mem.nv = in.value.integer;
							}
						}
						// Unexpected Error
						else {
							asm_error_v1 = tk.kind;
							throwError(ERROR_UNEXPECTED);
						}
					}
					// Adressing Mode => INDEXED
					else {
						restoreSeek();
						Value in;
						tryCatchAndThrow(
							parserExpression(&in)
						);
						args[*count].value.mem.adrm =
							in.value.integer<0x100 || in.type==TYPE_IMM8 || in.type==TYPE_IMMS8? ADRM_IDX8:
							in.value.integer<0x10000 || in.type==TYPE_IMM16 || in.type==TYPE_IMMS16? ADRM_IDX16:
							ADRM_IDX32;
						args[*count].value.mem.nv = in.value.integer;
					}
				}
				// Unexpected Error
				else {
					asm_error_v1 = tk.kind;
					throwError(ERROR_UNEXPECTED);
				}
			}
			// Addressing Mode => ABSOLUTE
			else {
				restoreSeek();
				Value in;
				tryCatchAndThrow(
					parserExpression(&in)
				);
				args[*count].value.mem.adrm =
					in.value.integer<0x100 || in.type==TYPE_IMM8 || in.type==TYPE_IMMS8? ADRM_ABS8:
					in.value.integer<0x10000 || in.type==TYPE_IMM16 || in.type==TYPE_IMMS16? ADRM_ABS16:
					ADRM_ABS32;
				args[*count].value.mem.nv = in.value.integer;
			}

			// The last token must be a closin bracket
			tryCatchAndThrow(
				tkrFetchToken(&tk)
			);
			if (!tkIsSymbol(tk, ']')){
				asm_error_v1 = ']';
				throwError(ERROR_EXPECTED_CHAR);
			}
		}
		// The argument is a parameter reference
		else if (tk.kind == TOKEN_IDENTIFIER && (arg = findSymArg(tk.value.string))) {
			args[*count].type = arg->type;
			args[*count].value = arg->value.value;
		}
		// The argument is a immediate literal
		else {
			restoreSeek();
			Value in;
			tryCatchAndThrow(
				parserExpression(&in)
			);
			args[*count].type = in.type;
			args[*count].value.integer = in.value.integer;
		}
		saveSeek();
		(*count)++;

		// Check if next provided argument is a comma
		// only if is, will keep fetching for arguments
		tryCatchAndThrow(
			tkrFetchToken(&tk)
		);
		if (tkIsSymbol(tk, ',')){
			saveSeek();
			tryCatchAndThrow(
				tkrFetchToken(&tk)
			);
			continue;
		}
		else {
			break;
		}
	}
	restoreSeek();

	return 0;
}


/*
	Parser High Layer Functions
*/
int parserParse(bool first, uint8** bin, uint32* bin_size){
	//
	// Start parse phase
	//
	parser.phase_one = first;
	parser.pc = parser.bc = 0;
	resetMarks();
	if (first){
		log("\n######## PARSER PHASE 1\n\n");
	}
	else{
		log("\n######## PARSER PHASE 2\n\n");
	}

	//
	//	Do the parse of file
	//
	Token tk = {0};
	lexerEnded();
	while (tk.kind != TOKEN_END_OF_FILE || hasRemainLexers()){
		tryCatchAndThrow(
			tkrFetchToken(&tk)
		);
		
		// Lexer has ended
		if (tk.kind == TOKEN_END_OF_FILE){
			if (lexerCurrent()->status){
				scopeLeave();
			}
			if (!lexerClose()){
				break;
			}
			continue;
		}
		// Break of line
		else if (tk.kind == TOKEN_NEW_LINE){
			continue;
		}
		// Identifier
		else if (tk.kind == TOKEN_IDENTIFIER){
			// Identify if is a instruction mnemonic
			Ist *instruction = null;
			Prefix *prefix = null;
			SymMacro *macro = null;
			if ((instruction = findInstructionByName(tk.value.string))){
				// Fetch all the arguments given in instruction
				Enc *matched_encode = null;
				log("Instruction:\n");
				tkrPrint(&tk);
				uint8 cond_desc = 0xFF;

				createSeek();
				tryCatchAndThrow(
					tkrFetchToken(&tk)
				);
				if (tkIsSymbol(tk, '.')){
					tryCatchAndThrow(
						tkrFetchToken(&tk)
					);
					if (tk.kind != TOKEN_IDENTIFIER || (cond_desc = findJpCondByName(tk.value.string))==0xFF){
						throwError(ERROR_UNSUPPLIED_CONDITION_SPECIFIER);
					}
				}
				else {
					restoreSeek();
				}

				Arg args[4];
				int args_count = 0;
				tryCatchAndThrow(
					parserFetchArgs(args, &args_count, 4)
				);
				log("arguments: %d\n", args_count);

				// Compares with any varyant from instruction encoding
				bool matched_some_varyation = false;
				for (int ei = 0; ei<instruction->encodes_length; ei++){
					Enc *encode = &instruction->encodes[ei];

					// If the instruction requires a jump condition specifier, check if was given any one
					if (encode->desc==COND_DESC){
						if (cond_desc==0xFF || (cond_desc&0x10)){
							continue;
						}
					}
					else if (encode->desc == CONDO_DESC){
						if (cond_desc==0xFF || !(cond_desc&0x10)){
							continue;
						}
					}
					// Otherwise, must not give
					else if (cond_desc!=0xFF){
						continue;
					}

					// The number of parameters and the arguments must match
					if (encode->params_length != args_count){
						continue;
					}

					// Compares with each parameter to verify wich the variant is acceptable
					bool matched_all_arguments = true;
					for (int ai = 0; ai<encode->params_length; ai++){
						Param *param = &encode->params[ai];
						Arg *arg = &args[ai];

						if (!matchTypes(param->type, arg->type)){
							matched_all_arguments = false;
							break;
						}
					}

					// If all arguments matched in final, pick this varyation
					if (matched_all_arguments){
						log("MATCHED!!!\n");
						matched_encode = encode;
						matched_some_varyation = true;
						break;
					}
				}

				if (matched_some_varyation){
					// The parser must detect no any character left in line
					int offset = tkrConsumeLine();
					if (offset != (-1)){
						throwError(ERROR_EXPECTED_END_OF_LINE);
					}
					else {
						tryCatchAndThrow(
							encodeInstruction(matched_encode, args, cond_desc)
						);
					}
				}
				else {
					asm_error_v1 = instruction->mne;
					throwError(ERROR_NO_INSTRUCTION_PATTERN);
				}
			}
			// May be a prefix declaration
			else if ((prefix = findPrefixByName(tk.value.string))){
				tryCatchAndThrow(
					tkrFetchToken(&tk)
				);
				if (!tkIsSymbol(tk, '.')){
					// TODO: Error => Prefix may be followed by a dot marker
					throwError(ERROR_PREFIX_POSTDOT_MISSING);
				}
				out8(prefix->code);
				continue;
			}
			// Otherwise, may be a macro invokation
			else if ((macro = findMacro(tk.value.string))){
				Arg args[4];
				int args_count = 0;
				tryCatchAndThrow(
					parserFetchArgs(args, &args_count, 4)
				);
				log("arguments: %d\n", args_count);
				scopeEnter();

				// The number of parameters and the arguments must match
				if (macro->params_len != args_count){
					asm_error_v1 = macro->name;
					throwError(ERROR_MACRO_WRONG_ARGUMENTS);
				}

				// The parser must detect no any character left in line
				int offset = tkrConsumeLine();
				if (offset != (-1)){
					throwError(ERROR_EXPECTED_END_OF_LINE);
				}

				// Compares with each parameter to verify wich the variant is acceptable
				for (int ai = 0; ai<macro->params_len; ai++){
					Arg *arg = &args[ai];

					if (!matchTypes(macro->params[ai].type, arg->type)){
						asm_error_v1 = macro->name;
						throwError(ERROR_MACRO_WRONG_ARGUMENTS);
					}
					else {
						Value value;
						value.type = macro->params[ai].type;
						value.value = arg->value;

						if (matchTypes(TYPE_IMM, arg->type)){
							storeSymConst(macro->params[ai].name, value);
						}
						else {
							storeSymArg(macro->params[ai].name, value);
						}
					}
				}

				lexerOpenFile(macro->src);
				lexerSeekSet(macro->start);
				lexerCurrent()->limit = macro->end;
				lexerCurrent()->status = 1;
				continue;
			}
			// Otherwise, must be a label declaration
			else {
				const char* name = tk.value.string;
				tryCatchAndThrow(
					tkrFetchToken(&tk)
				);
				if (!tkIsSymbol(tk, ':')){
					asm_error_v1 = ':';
					throwError(ERROR_EXPECTED_CHAR);
				}

				if (parser.phase_one){
					if (findSymbol(name)){
						asm_error_v1 = name;
						throwError(ERROR_ALREADY_DECLARATED_SYMBOL);
					}
					Value v = {.type = TYPE_IMM, .value = {.integer = parser.pc}};
					storeSymLabel(name, v);
				}
				log("Label with name \"%s\" with address 0x%X declarated!\n", name, parser.pc);
				continue;
			}
		}
		else if (tkIsSymbol(tk, '.')){
			tryCatchAndThrow(
				tkrFetchToken(&tk)
			);
			if (tk.kind != TOKEN_IDENTIFIER){
				throwError(ERROR_EXPECTED_PROCESSOR_COMMAND);
			}
			const char* cmd = tk.value.string;

			if (strcmp(cmd, "adr")==0){
				Value val;
				tryCatchAndThrow(
					parserExpression(&val)
				);
				parser.pc = parser.bc = val.value.integer;
			}
			else if (strcmp(cmd, "program_adr")==0){
				Value val;
				tryCatchAndThrow(
					parserExpression(&val)
				);
				parser.pc = val.value.integer;
			}
			else if (strcmp(cmd, "binary_adr")==0){
				Value val;
				tryCatchAndThrow(
					parserExpression(&val)
				);
				parser.bc = val.value.integer;
			}
			else if (strcmp(cmd, "scope")==0){
				createSeek();
				tryCatchAndThrow(
					tkrFetchToken(&tk)
				);

				if (tk.kind == TOKEN_IDENTIFIER){
					const char *name = tk.value.string;

					if (parser.phase_one){
						if (findSymbol(name)){
							asm_error_v1 = name;
							throwError(ERROR_ALREADY_DECLARATED_SYMBOL);
						}
						Value v = {.type = TYPE_IMM, .value = {.integer = parser.pc}};
						storeSymLabel(name, v);
					}
				}
				else {
					restoreSeek();
				}

				scopeEnter();
			}
			else if (strcmp(cmd, "endscope")==0){
				scopeLeave();
			}
			else if (strcmp(cmd, "macro") == 0){
				tryCatchAndThrow(
					tkrFetchToken(&tk)
				);

				if (tk.kind != TOKEN_IDENTIFIER){
					throwError(ERROR_EXPECTED_MACRO_NAME);
				}
				const char *name = tk.value.string;
				log("Declaring macro with name %s\n", name);

				SymMacro macro;
				macro.name = name;
				macro.params_len = 0;
				createSeek();

				tryCatchAndThrow(
					tkrFetchToken(&tk)
				);
				while (tk.kind != TOKEN_NEW_LINE && macro.params_len<4){
					restoreSeek();
					//Value in;
					Token tk;
					tryCatchAndThrow(
						tkrFetchToken(&tk)
					);
					if (tk.kind != TOKEN_IDENTIFIER){
						throwError(ERROR_EXPECTED_MACRO_PARAM_NAME);
					}
					macro.params[macro.params_len].name = textReuse(tk.value.string);
					const char* param_name = tk.value.string;

					saveSeek();
					tryCatchAndThrow(
						tkrFetchToken(&tk)
					);
					if (tkIsSymbol(tk, ':')){
						tryCatchAndThrow(
							tkrFetchToken(&tk)
						);
						DataName *data_type;
						if ((tk.kind == TOKEN_IDENTIFIER) && (data_type = findDataByName(tk.value.string))){
							macro.params[macro.params_len].type = data_type->type;
							saveSeek();
						}
						else {
							throwError(ERROR_EXPECTED_DATA_TYPE);
						}
					}
					else {
						macro.params[macro.params_len].type = TYPE_IMM;
						restoreSeek();
					}

					macro.params_len++;

					// Check if next provided argument is a comma
					// only if is, will keep fetching for arguments
					tryCatchAndThrow(
						tkrFetchToken(&tk)
					);
					if (tkIsSymbol(tk, ',')){
						saveSeek();
						tryCatchAndThrow(
							tkrFetchToken(&tk)
						);
						continue;
					}
					else {
						break;
					}
				}
				restoreSeek();

				uint32 start = lexerTell();
				uint32 end = start;
				while (!tkrEnded()){
					tkrConsumeLine();
					end = lexerTell();
					tryCatchAndThrow(
						tkrFetchToken(&tk)
					);
					if (tkIsSymbol(tk, '.')){
						tryCatchAndThrow(
							tkrFetchToken(&tk)
						);
						if (tk.kind == TOKEN_IDENTIFIER && strcmp(tk.value.string, "endmacro") == 0){
							break;
						}
					}
				}
				log("Macro bounds between %d and %d\n", start, end);

				if (parser.phase_one){
					if (findMacro(name)){
						asm_error_v1 = name;
						throwError(ERROR_ALREADY_DECLARATED_MACRO);
					}
					macro.start = start;
					macro.end = end;
					macro.src = textReuse(lexerCurrent()->path);
					storeSymMacro(macro);
				}
			}
			else if (strcmp(cmd, "const")==0){
				tryCatchAndThrow(
					tkrFetchToken(&tk)
				);

				if (tk.kind != TOKEN_IDENTIFIER){
					throwError(ERROR_EXPECTED_CONSTANT_NAME);
				}
				const char *name = tk.value.string;

				Value in;
				tryCatchAndThrow(
					parserExpression(&in)
				);
				if (!parser.phase_one){
					storeSymConst(name, in);
				}
			}
			else if ((strcmp(cmd, "byte")==0) || (strcmp(cmd, "half")==0) || (strcmp(cmd, "word")==0)){
				int type = (strcmp(cmd, "byte")==0)? 8: (strcmp(cmd, "half")==0)? 16: 32;
				createSeek();
				
				tryCatchAndThrow(
					tkrFetchToken(&tk)
				);
				while (tk.kind != TOKEN_NEW_LINE){
					restoreSeek();
					Value in;
					tryCatchAndThrow(
						parserExpression(&in)
					);
					if (type==8){
						out8(in.value.integer);
					}
					else if (type==16){
						out16(in.value.integer);
					}
					else {
						out32(in.value.integer);
					}
					saveSeek();

					// Check if next provided argument is a comma
					// only if is, will keep fetching for arguments
					tryCatchAndThrow(
						tkrFetchToken(&tk)
					);
					if (tkIsSymbol(tk, ',')){
						saveSeek();
						tryCatchAndThrow(
							tkrFetchToken(&tk)
						);
						continue;
					}
					else {
						break;
					}
				}
				restoreSeek();
			}
			else if (strcmp(cmd, "text")==0){
				tryCatchAndThrow(
					tkrFetchToken(&tk)
				);

				if (tk.kind != TOKEN_STRING){
					throwError(ERROR_EXPECTED_STRING);
				}

				char *chr = tk.value.string;
				while (*chr){
					out8(*chr);
					chr++;
				}
			}
			else if (strcmp(cmd, "include")==0){
				tryCatchAndThrow(
					tkrFetchToken(&tk)
				);

				if (tk.kind != TOKEN_STRING){
					throwError(ERROR_EXPECTED_PATH_STRING);
				}

				char path[512];
				combinePath(path, lexerCurrent()->path, "..");
				combinePath(path, path, (char*)tk.value.string);
				
				// The parser must detect no any character left in line
				int offset = tkrConsumeLine();
				if (offset != (-1)){
					throwError(ERROR_EXPECTED_END_OF_LINE);
				}
				
				if (!lexerOpenFile(path)) {
					asm_error_v1 = path;
					throwError(ERROR_FILE_DO_NOT_EXISTS);
				}
				continue;
			}
			else if (strcmp(cmd, "mark")==0){
				createSeek();
				tryCatchAndThrow(
					tkrFetchToken(&tk)
				);

				if (tk.kind != TOKEN_IDENTIFIER && tk.kind != TOKEN_STRING && tk.kind != TOKEN_NEW_LINE && tk.kind != TOKEN_END_OF_FILE){
					throwError(ERROR_EXPECTED_CONSTANT_NAME);
				}

				if (tk.kind == TOKEN_NEW_LINE || tk.kind == TOKEN_END_OF_FILE){
					restoreSeek();
					setMark(textReuse(lexerCurrent()->path));
				}
				else {
					const char *mark_name = tk.value.string;
					setMark(textReuse(tk.value.string));
				}
			}
			else if (strcmp(cmd, "unmark")==0){
				createSeek();
				tryCatchAndThrow(
					tkrFetchToken(&tk)
				);

				if (tk.kind != TOKEN_IDENTIFIER && tk.kind != TOKEN_STRING && tk.kind != TOKEN_NEW_LINE && tk.kind != TOKEN_END_OF_FILE){
					throwError(ERROR_EXPECTED_CONSTANT_NAME);
				}

				if (tk.kind == TOKEN_NEW_LINE || tk.kind == TOKEN_END_OF_FILE){
					restoreSeek();
					unsetMark(textReuse(lexerCurrent()->path));
				}
				else {
					const char *mark_name = tk.value.string;
					unsetMark(textReuse(tk.value.string));
				}
			}
			else if (strcmp(cmd, "onmark")==0 || strcmp(cmd, "nonmark")==0){
				createSeek();
				tryCatchAndThrow(
					tkrFetchToken(&tk)
				);

				bool non = strcmp(cmd, "nonmark")==0;

				if (tk.kind != TOKEN_IDENTIFIER && tk.kind != TOKEN_STRING && tk.kind != TOKEN_NEW_LINE && tk.kind != TOKEN_END_OF_FILE){
					throwError(ERROR_EXPECTED_CONSTANT_NAME);
				}

				if (tk.kind == TOKEN_NEW_LINE || tk.kind == TOKEN_END_OF_FILE){
					restoreSeek();
					if (non ^ hasMark(textReuse(lexerCurrent()->path))){
						lexerClose();
						continue;
					}
				}
				else {
					const char *mark_name = tk.value.string;
					if (non ^ hasMark(textReuse(mark_name))){
						lexerClose();
						continue;
					}
				}
			}
			else if (strcmp(cmd, "print")==0){
				tryCatchAndThrow(
					tkrFetchToken(&tk)
				);

				if (tk.kind != TOKEN_STRING){
					throwError(ERROR_EXPECTED_STRING);
				}

				if (first){
					printf("@@@ MESSAGE => %s\n", tk.value.string);
				}
			}
			else {
				asm_error_v1 = cmd;
				throwError(ERROR_ERROR_INVALID_PROCESSOR_NAME);
			}

			// The parser must detect no any character left in line
			int offset = tkrConsumeLine();
			if (offset != (-1)){
				throwError(ERROR_EXPECTED_END_OF_LINE);
			}
		}
		else {
			asm_error_v1 = tk.kind;
			throwError(ERROR_UNEXPECTED);
		}
	}

	//
	//	End parse phase
	//
	if (first){
		parser.bin = calloc(parser.bin_size, 1);
	}
	else{
		*bin = parser.bin;
		*bin_size = parser.bin_size;
		log("\n######## PARSER DONE\n\n");
	}
	return 0;
};
