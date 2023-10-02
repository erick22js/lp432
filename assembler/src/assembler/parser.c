#include "parser.h"
#include "base.h"


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
	bool has_ns = false;
	bool has_mv = false;
	uint8 os1 = 0x0;
	uint8 os2 = 0x0;
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
	if (has_os1){
		// Descriptor will be the conditional code
		if (encode->desc == DESC_COND){
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
		// TODO
		throwError(ERROR_UNKNOWN);
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
			// TODO: Error => Expected closing paren
			throwError(ERROR_UNKNOWN);
		}
	}
	// Unexpected token, expected expression
	else {
		throwError(ERROR_UNKNOWN);
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
			}
			out->type = data_type->type_imm;
		}
		else {
			// TODO: Error => Expected Data type name
			throwError(ERROR_UNKNOWN);
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
			if (opr2.value.integer == 0){
				// TODO: Error => Second operand is zero
				throwError(ERROR_UNKNOWN);
			}
			opr1.value.integer /= opr2.value.integer;
		}
		else {
			if (opr2.value.integer == 0){
				// TODO: Error => Second operand is zero
				throwError(ERROR_UNKNOWN);
			}
			opr1.value.integer %= opr2.value.integer;
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
	if (base == TYPE_IMM8 || base == TYPE_IMM16 || base == TYPE_IMM32){
		return given == base || given == TYPE_IMM;
	}
	if (base == TYPE_IMM){
		return given == TYPE_IMM8 || given == TYPE_IMM16 || given == TYPE_IMM32 || given == TYPE_IMM;
	}
	return base == given;
}

int parserFetchArgs(Arg* args, int* count){
	createSeek();
	Token tk = {0};
	tryCatchAndThrow(
		tkrFetchToken(&tk)
	);

	while (tk.kind != TOKEN_NEW_LINE && tk.kind != TOKEN_END_OF_FILE && (*count < 4)){
		// The argument is a register
		Reg *reg = null;
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
						args[*count].value.mem.reg1 = regi->code;

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
							// TODO: Error
							throwError(ERROR_UNKNOWN);
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
					// TODO: Error
					throwError(ERROR_UNKNOWN);
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
				// TODO: Error
				throwError(ERROR_UNKNOWN);
			}
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
			if ((instruction = findInstructionByName(tk.value.string))){
				// Fetch all the arguments given in instruction
				Enc *matched_encode = null;
				log("Instruction:\n");
				tkrPrint(&tk);
				Arg args[4];
				int args_count = 0;
				tryCatchAndThrow(
					parserFetchArgs(args, &args_count)
				);
				log("arguments: %d\n", args_count);

				// Compares with any varyant from instruction encoding
				bool matched_some_varyation = false;
				for (int ei = 0; ei<instruction->encodes_length; ei++){
					Enc *encode = &instruction->encodes[ei];

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
						// TODO: Error
						throwError(ERROR_UNKNOWN);
						log("ERROR: Has something more left in line!\n");
					}
					else {
						tryCatchAndThrow(
							encodeInstruction(matched_encode, args, 0)
						);
					}
				}
				else {
					throwError(ERROR_UNKNOWN);
					log("NOT MATCHED!\n");
				}
			}

			// Otherwise, is not a expected token
			else {
				tkrPrint(&tk);
				// TODO: Unexpected token
				throwError(ERROR_UNKNOWN);
				continue;
			}
		}
		else {
			tkrPrint(&tk);
		}
	}

	//
	//	End parse phase
	//
	if (first){
		parser.bin = malloc(parser.bin_size);
	}
	else{
		*bin = parser.bin;
		*bin_size = parser.bin_size;
		log("\n######## PARSER DONE\n\n");
	}
	return 0;
};
