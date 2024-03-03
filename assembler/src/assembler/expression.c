#include "expression.h"


//
//	EXPRESSION SOLVING
//

Error expCast(Value *out, Type type) {
	// Convert Immediate to Float
	if (typeIsImm(out->type) && typeIsFloat(type)){
		// Unsigned Imm cast from
		if (typeIsUnsigned(out->type)){
			out->val.fp = (f64)out->val.lit;
		}
		// Signed Imm cast from
		else {
			out->val.fp = (f64)((i64)out->val.lit);
		}
		out->type = type;
		return ERROR_NONE;
	}
	
	// Convert Float to Immediate
	else if (typeIsFloat(out->type) && typeIsImm(type)){
		// Unsigned Imm cast to
		if (typeIsUnsigned(type)){
			out->val.lit = (u64)out->val.fp;
		}
		// Signed Imm cast to
		else {
			out->val.lit = (i64)out->val.fp;
		}
		out->type = type;
		return ERROR_NONE;
	}
	
	// Any in same group cast
	else if ((typeIsGreg(out->type) && typeIsGreg(type)) || (typeIsImm(out->type) && typeIsImm(type)) || (typeIsFloat(out->type) && typeIsFloat(type)) || (typeIsMem(out->type) && typeIsMem(type))){
		out->type = type;
		return ERROR_NONE;
	}
	
	// TODO: Error => Invalid casting
	errThrow(ERROR_INVALID_CASTING);
}

Error expNeg(Value *out) {
	if (typeIsImm(out->type)){
		out->val.lit = -((signed)out->val.lit);
	}
	else if (typeIsFloat(out->type)){
		out->val.fp = -out->val.fp;
	}
	else {
		// TODO: Error => Invalid operand type
		errThrow(ERROR_INVALID_OPERANDS);
	}
	
	return ERROR_NONE;
}

Error expNot(Value *out) {
	if (typeIsImm(out->type)){
		out->val.lit = ~((signed)out->val.lit);
	}
	else {
		// TODO: Error => Invalid operand type
		errThrow(ERROR_INVALID_OPERANDS);
	}
	
	return ERROR_NONE;
}

Error expBNot(Value *out) {
	if (typeIsImm(out->type)){
		out->type = TYPE_IMM;
		out->val.lit = !((signed)out->val.lit);
	}
	else if (typeIsFloat(out->type)){
		out->type = TYPE_IMM;
		out->val.lit = !out->val.fp;
	}
	else {
		// TODO: Error => Invalid operand type
		errThrow(ERROR_INVALID_OPERANDS);
	}
	
	return ERROR_NONE;
}

#define _expBinArith(evalf, evali, check) {\
	if (!typeIsLiteral(out->type) || !typeIsLiteral(opr.type)){\
		/* TODO: Error => Invalid operand type*/\
		errThrow(ERROR_INVALID_OPERANDS);\
	}\
	\
	Type tp = out->type>opr.type? out->type: opr.type;\
	expCast(out, tp);\
	expCast(&opr, tp);\
	\
	if (typeIsFloat(tp)){\
		check;\
		evalf;\
	}\
	else {\
		check;\
		evali;\
	}\
}

#define expBinArith(op) \
	_expBinArith(out->val.fp = out->val.fp op opr.val.fp, out->val.lit = out->val.lit op opr.val.lit, ;)

#define expBinArithZeroCheck(evalf, evali) \
	_expBinArith(evalf, evali, \
		if (opr.val.fp==0 || opr.val.lit==0) {\
			/* TODO: Error => Divisor cannot be zero */\
			errThrow(ERROR_DIVISOR_ZERO);\
		}\
	)

#define expBinBitwise(op) {\
	if (!typeIsImm(out->type) || !typeIsImm(opr.type)){\
		/* TODO: Error => Invalid operand type*/\
		errThrow(ERROR_INVALID_OPERANDS);\
	}\
	\
	Type tp = out->type>opr.type? out->type: opr.type;\
	expCast(out, tp);\
	expCast(&opr, tp);\
	\
	out->val.lit = out->val.lit op opr.val.lit;\
}

#define expBoolArith(op) {\
	if (!typeIsLiteral(out->type) || !typeIsLiteral(opr.type)){\
		/* TODO: Error => Invalid operand type*/\
		errThrow(ERROR_INVALID_OPERANDS);\
	}\
	\
	Type tp = out->type>opr.type? out->type: opr.type;\
	expCast(out, tp);\
	expCast(&opr, tp);\
	\
	if (typeIsFloat(tp)){\
		out->val.lit = out->val.fp op opr.val.fp;\
	}\
	else {\
		out->val.lit = out->val.lit op opr.val.lit;\
	}\
	out->type = TYPE_IMM;\
}


//
//	CORE OPERATIONS
//

Error expExpression(Value *out);

Error expOperand(Value *out) {
	Token tk;
	errTryCatch(
		tkrFetch(&tk)
	);
	
	if (tk.type == TOKEN_LITERAL){
		if (tk.fp_lit){
			out->type = TYPE_FLOAT;
			out->val.fp = tk.value.fp;
		}
		else {
			out->type = TYPE_IMM;
			out->val.lit = tk.value.lit;
		}
	}
	else if (tk.type == TOKEN_NAME){
		// Find for register
		Reg *reg = null;
		if ((reg = baseFindReg(tk.value.str))){
			out->type = reg->type;
			out->val.code = reg->index;
			return ERROR_NONE;
		}
		
		// Find for defined symbol
		if (symvHas(tk.value.str)){
			symvLoad(tk.value.str, out);
		}
		else if (asm_info.phase_two || asm_info.static_exp){
			// TODO: Error => Symbol not defined
			err_offset = tk.position;
			errThrow(ERROR_SYMBOL_NOT_DEFINED);
		}
		// In phase one, find out or just ignore it
		else {
			out->type = TYPE_IMM;
			out->val.lit = 1;
			return ERROR_NONE;
		}
	}
	else if (tkIsSymbol(tk, '[')){
		seekCreate();
		errTryCatch(
			tkrFetch(&tk)
		);
		out->type = TYPE_MEM;
		Reg *regi = null;
		// Indexed base
		if (tk.type==TOKEN_NAME && (regi = baseFindReg(tk.value.str)) && regi->type == TYPE_GR32){
			out->mem.regi = regi->index;
			seekSave();
			errTryCatch(
				tkrFetch(&tk)
			);
			
			// 2nd operand
			if (tkIsSymbol(tk, ',')){
				seekSave();
				errTryCatch(
					tkrFetch(&tk)
				);
				
				Reg *reg1 = null;
				// Index operand
				if (tk.type==TOKEN_NAME && (reg1 = baseFindReg(tk.value.str)) && reg1->type == TYPE_GR32){
					out->mem.reg1 = reg1->index;
					seekSave();
					errTryCatch(
						tkrFetch(&tk)
					);
					
					// 3rd operand
					if (tkIsSymbol(tk, ',')){
						seekSave();
						Value nv = {0};
						expExpression(&nv);
						if (!typeIsImm(nv.type)){
							// TODO: Error => Expected immediate expression
							errThrow(ERROR_EXPECTED_IMMEDIATE);
						}
						out->mem.mode = nv.type==TYPE_IMM8||nv.type==TYPE_IMMS8? ADRM_IDXI8: nv.type==TYPE_IMM16||nv.type==TYPE_IMMS16? ADRM_IDXI16: ADRM_IDXI32;
						out->mem.nv = (u32)nv.val.lit;
					}
					else if (tkIsSymbol(tk, '.')){
						seekSave();
						errTryCatch(
							tkrFetch(&tk)
						);
						
						Reg *reg2 = null;
						// Sub-index operand
						if (tk.type==TOKEN_NAME && (reg2 = baseFindReg(tk.value.str)) && reg2->type == TYPE_GR32){
							out->mem.reg2 = reg2->index;
							seekSave();
							errTryCatch(
								tkrFetch(&tk)
							);
							
							// ADRM: Dynamic Indexed
							if (tkIsSymbol(tk, ',')){
								Value nv = {0};
								expExpression(&nv);
								if (!typeIsImm(nv.type)){
									// TODO: Error => Expected immediate expression
									errThrow(ERROR_EXPECTED_IMMEDIATE);
								}
								out->mem.mode = ADRM_DYNI;
								out->mem.nv = (u32)nv.val.lit;
							}
							// ADRM: Dynamic
							else {
								seekRestore();
								out->mem.mode = ADRM_DYN;
							}
						}
						// ADRM: Struct
						else {
							seekRestore();
							Value nv = {0};
							expExpression(&nv);
							if (!typeIsImm(nv.type)){
								// TODO: Error => Expected immediate expression
								errThrow(ERROR_EXPECTED_IMMEDIATE);
							}
							out->mem.mode = nv.type==TYPE_IMM8||nv.type==TYPE_IMMS8? ADRM_STC8: nv.type==TYPE_IMM16||nv.type==TYPE_IMMS16? ADRM_STC16: ADRM_STC32;
							out->mem.nv = (u32)nv.val.lit;
						}
					}
					// ADRM: Indexed Implicit
					else {
						seekRestore();
						out->mem.mode = ADRM_IDXI;
					}
				}
				// ADRM: Indexed
				else {
					seekRestore();
					Value nv = {0};
					expExpression(&nv);
					if (!typeIsImm(nv.type)){
						// TODO: Error => Expected immediate expression
						errThrow(ERROR_EXPECTED_IMMEDIATE);
					}
					out->mem.mode = nv.type==TYPE_IMM8||nv.type==TYPE_IMMS8? ADRM_IDX8: nv.type==TYPE_IMM16||nv.type==TYPE_IMMS16? ADRM_IDX16: ADRM_IDX32;
					out->mem.nv = (u32)nv.val.lit;
				}
			}
			// ADRM: Pointer
			else {
				seekRestore();
				out->mem.mode = ADRM_PTR;
			}
		}
		// ADRM: Absolute Address
		else {
			seekRestore();
			Value nv = {0};
			expExpression(&nv);
			if (!typeIsImm(nv.type)){
				// TODO: Error => Expected immediate expression
				errThrow(ERROR_EXPECTED_IMMEDIATE);
			}
			out->mem.mode = nv.type==TYPE_IMM8||nv.type==TYPE_IMMS8? ADRM_ABS8: nv.type==TYPE_IMM16||nv.type==TYPE_IMMS16? ADRM_ABS16: ADRM_ABS32;
			out->mem.nv = (u32)nv.val.lit;
		}
		
		errTryCatch(
			tkrFetch(&tk)
		);
		if (!tkIsSymbol(tk, ']')){
			// TODO: Error => Expected closing backet
			err_offset = tk.position;
			errThrow(ERROR_EXPECTED_CLOSIN_BRACKET);
		}
	}
	else {
		// TODO: Error => Unexpected token
		err_offset = tk.position;
		errThrow(ERROR_UNEXPECTED_TOKEN);
	}
	
	return ERROR_NONE;
}

Error expUnary(Value *out) {
	// Fetch prefix signal/operator
	seekCreate();
	Token tk;
	errTryCatch(
		tkrFetch(&tk)
	);
	
	if (tkIsSymbol(tk, '-')){
		errTryCatch(
			expUnary(out)
		);
		errTryCatch(
			expNeg(out)
		);
	}
	else if (tkIsSymbol(tk, '+')){
		errTryCatch(
			expUnary(out)
		);
	}
	else if (tkIsSymbol(tk, '~')){
		errTryCatch(
			expUnary(out)
		);
		errTryCatch(
			expNot(out)
		);
	}
	else if (tkIsSymbol(tk, '!')){
		errTryCatch(
			expUnary(out)
		);
		errTryCatch(
			expBNot(out)
		);
	}
	else if (tkIsSymbol(tk, '@') || tkIsSymbol(tk, '$')){
		u32 offset = tkIsSymbol(tk, '@')? asm_info.ps: asm_info.bs;
		seekSave();
		errTryCatch(
			tkrFetch(&tk)
		);
		seekRestore();
		if (tk.type == TOKEN_LITERAL || tk.type == TOKEN_NAME){
			errTryCatch(
				expUnary(out)
			);
			out->val.lit -= offset;
		}
		else {
			out->val.lit = offset;
		}
		out->type = TYPE_IMM;
	}
	else if (tkIsSymbol(tk, '(')){
		errTryCatch(
			expExpression(out)
		);
		errTryCatch(
			tkrFetch(&tk)
		);
		if (!tkIsSymbol(tk, ')')){
			// TODO: Error => Expected closing paren
			err_offset = tk.position;
			errThrow(ERROR_EXPECTED_CLOSIN_PAREN);
		}
	}
	else {
		seekRestore();
		errTryCatch(
			expOperand(out)
		);
	}
	
	// Fetch casting expression
	seekSave();
	errTryCatch(
		tkrFetch(&tk)
	);
	if (tkIsSymbol(tk, ':')){
		errTryCatch(
			tkrFetch(&tk)
		);
		Castname *cn;
		if (tk.type!=TOKEN_NAME || !(cn = baseFindCastname(tk.value.str))){
			// TODO: Error => Expected data type name
			err_offset = tk.position;
			errThrow(ERROR_EXPECTED_DATANAME);
		}
		
		errTryCatch(
			expCast(out, cn->gtypes[typeGroup(out->type)])
		);
	}
	else {
		seekRestore();
	}
	
	return ERROR_NONE;
}

Error expBinMul(Value *out) {
	errTryCatch(
		expUnary(out)
	);
	seekCreate();
	Token tk;
	errTryCatch(
		tkrFetch(&tk)
	);
	
	while (tkIsSymbol(tk, '*') || tkIsSymbol(tk, '/') || tkIsSymbol(tk, '%')){
		Value opr;
		errTryCatch(
			expUnary(&opr)
		);
		
		if (tkIsSymbol(tk, '*')){
			expBinArith(*);
		}
		else if (tkIsSymbol(tk, '/')){
			expBinArithZeroCheck(out->val.fp = out->val.fp / opr.val.fp, out->val.lit = out->val.lit / opr.val.lit);
		}
		else if (tkIsSymbol(tk, '%')){
			expBinArithZeroCheck(out->val.fp = (f64)((u64)out->val.fp % (u64)opr.val.fp), out->val.lit = out->val.lit % opr.val.lit);
		}
		
		seekSave();
		errTryCatch(
			tkrFetch(&tk)
		);
	}
	seekRestore();
	
	return ERROR_NONE;
}

Error expBinSum(Value *out) {
	errTryCatch(
		expBinMul(out)
	);
	seekCreate();
	Token tk;
	errTryCatch(
		tkrFetch(&tk)
	);
	
	while (tkIsSymbol(tk, '+') || tkIsSymbol(tk, '-')){
		Value opr;
		errTryCatch(
			expBinMul(&opr)
		);
		
		if (tkIsSymbol(tk, '+')){
			expBinArith(+);
		}
		else if (tkIsSymbol(tk, '-')){
			expBinArith(-);
		}
		
		seekSave();
		errTryCatch(
			tkrFetch(&tk)
		);
	}
	seekRestore();
	
	return ERROR_NONE;
}

Error expBinShift(Value *out) {
	errTryCatch(
		expBinSum(out)
	);
	seekCreate();
	Token tk;
	errTryCatch(
		tkrFetch(&tk)
	);
	
	if (tkIsSymbol(tk, *(u16*)">>") || tkIsSymbol(tk, *(u16*)"<<")){
		Value opr;
		errTryCatch(
			expBinSum(&opr)
		);
		
		if (tkIsSymbol(tk, *(u16*)">>")){
			expBinBitwise(>>);
		}
		else {
			expBinBitwise(<<);
		}
		
		seekSave();
		errTryCatch(
			tkrFetch(&tk)
		);
	}
	seekRestore();
	
	return ERROR_NONE;
}

Error expBinCmp(Value *out) {
	errTryCatch(
		expBinShift(out)
	);
	seekCreate();
	Token tk;
	errTryCatch(
		tkrFetch(&tk)
	);
	
	if (tkIsSymbol(tk, *(u16*)"==") || tkIsSymbol(tk, *(u16*)"!=") || tkIsSymbol(tk, *(u16*)">") || tkIsSymbol(tk, *(u16*)">=") || tkIsSymbol(tk, *(u16*)"<") || tkIsSymbol(tk, *(u16*)"<=")){
		Value opr;
		errTryCatch(
			expBinShift(&opr)
		);
		
		if (tkIsSymbol(tk, *(u16*)"==")){
			expBoolArith(==);
		}
		else if (tkIsSymbol(tk, *(u16*)"!=")){
			expBoolArith(==);
		}
		else if (tkIsSymbol(tk, *(u16*)">")){
			expBoolArith(>);
		}
		else if (tkIsSymbol(tk, *(u16*)">=")){
			expBoolArith(>=);
		}
		else if (tkIsSymbol(tk, *(u16*)"<")){
			expBoolArith(<);
		}
		else {
			expBoolArith(<=);
		}
		
		seekSave();
		errTryCatch(
			tkrFetch(&tk)
		);
	}
	seekRestore();
	
	return ERROR_NONE;
}

Error expBinAnd(Value *out) {
	errTryCatch(
		expBinCmp(out)
	);
	seekCreate();
	Token tk;
	errTryCatch(
		tkrFetch(&tk)
	);
	
	while (tkIsSymbol(tk, '&')){
		Value opr;
		errTryCatch(
			expBinCmp(&opr)
		);
		
		expBinBitwise(&);
		
		seekSave();
		errTryCatch(
			tkrFetch(&tk)
		);
	}
	seekRestore();
	
	return ERROR_NONE;
}

Error expBinXor(Value *out) {
	errTryCatch(
		expBinAnd(out)
	);
	seekCreate();
	Token tk;
	errTryCatch(
		tkrFetch(&tk)
	);
	
	while (tkIsSymbol(tk, '^')){
		Value opr;
		errTryCatch(
			expBinAnd(&opr)
		);
		
		expBinBitwise(^);
		
		seekSave();
		errTryCatch(
			tkrFetch(&tk)
		);
	}
	seekRestore();
	
	return ERROR_NONE;
}

Error expBinOr(Value *out) {
	errTryCatch(
		expBinXor(out)
	);
	seekCreate();
	Token tk;
	errTryCatch(
		tkrFetch(&tk)
	);
	
	while (tkIsSymbol(tk, '|')){
		Value opr;
		errTryCatch(
			expBinXor(&opr)
		);
		
		expBinBitwise(|);
		
		seekSave();
		errTryCatch(
			tkrFetch(&tk)
		);
	}
	seekRestore();
	
	return ERROR_NONE;
}

Error expBinBAnd(Value *out) {
	errTryCatch(
		expBinOr(out)
	);
	seekCreate();
	Token tk;
	errTryCatch(
		tkrFetch(&tk)
	);
	
	while (tkIsSymbol(tk, *(u16*)"&&")){
		Value opr;
		errTryCatch(
			expBinOr(&opr)
		);
		
		expBoolArith(&&);
		
		seekSave();
		errTryCatch(
			tkrFetch(&tk)
		);
	}
	seekRestore();
	
	return ERROR_NONE;
}

Error expBinBOr(Value *out) {
	errTryCatch(
		expBinBAnd(out)
	);
	seekCreate();
	Token tk;
	errTryCatch(
		tkrFetch(&tk)
	);
	
	while (tkIsSymbol(tk, *(u16*)"||")){
		Value opr;
		errTryCatch(
			expBinBAnd(&opr)
		);
		
		expBoolArith(||);
		
		seekSave();
		errTryCatch(
			tkrFetch(&tk)
		);
	}
	seekRestore();
	
	return ERROR_NONE;
}

Error expExpression(Value *out) {
	errTryCatch(
		expBinBOr(out)
	);
	
	return ERROR_NONE;
}


//
//	EXPRESSION SCANNING
//

Error expFetch(Value *out) {
	//err_offset = lexTell();
	errTryCatch(
		expExpression(out)
	);
	
	if (out->type==TYPE_FLOAT32 || out->type==TYPE_FLOAT){
		out->val.fp32 = (f32)out->val.fp;
	}
	
	expPrint(out);
	return ERROR_NONE;
}

Error expArgumentsFetch(Value *args, int *args_len) {
	logDevInfo("ARG: Arguments list: \n");
	seekCreate();
	Token tk;
	errTryCatch(
		tkrFetch(&tk)
	);
	*args_len = 0;
	
	if (tk.type != TOKEN_EOL){
		while (!lexEnded()){
			seekRestore();
			//err_offset = lexTell();
			Value val = {0};
			errTryCatch(
				expFetch(&val)
			);
			seekSave();
			
			if ((*args_len) < MAX_CMD_PARAMS){
				args[*args_len] = val;
				(*args_len)++;
			}
			
			errTryCatch(
				tkrFetch(&tk)
			);
			if (!tkIsSymbol(tk, ',')){
				seekRestore();
				break;
			}
			seekSave();
		}
		
		if (tk.type != TOKEN_EOL){
			// TODO: Error => Expected end of line
			err_offset = tk.position;
			errThrow(ERROR_EXPECTED_EOL);
		}
	}
	logDevInfo("ARG: Arguments total: %d \n", *args_len);
	return ERROR_NONE;
}

void expPrint(Value *in) {
	if (typeIsImm(in->type)){
		logDevInfo("VAL: Immediate:%d = %lld / 0x%llX\n", in->type, in->val.lit, in->val.lit);
	}
	else if (typeIsFloat(in->type)){
		logDevInfo("VAL: FImmediate:%d = %lf / 0x%llX\n", in->type, in->val.fp, in->val.lit);
	}
	else if (typeIsMem(in->type)){
		switch (in->mem.mode){
			case ADRM_ABS8:
			case ADRM_ABS16:
			case ADRM_ABS32: {
				logDevInfo("VAL: Memory = [0x%X]\n", in->mem.nv);
			}
			break;
			case ADRM_PTR: {
				logDevInfo("VAL: Memory = [%d:regi]\n", in->mem.regi);
			}
			break;
			case ADRM_IDX8:
			case ADRM_IDX16:
			case ADRM_IDX32: {
				logDevInfo("VAL: Memory = [%d:regi, 0x%X]\n", in->mem.regi, in->mem.nv);
			}
			break;
			case ADRM_IDXI: {
				logDevInfo("VAL: Memory = [%d:regi, %d:reg1]\n", in->mem.regi, in->mem.reg1);
			}
			break;
			case ADRM_IDXI8:
			case ADRM_IDXI16:
			case ADRM_IDXI32: {
				logDevInfo("VAL: Memory = [%d:regi, %d:reg1, 0x%X]\n", in->mem.regi, in->mem.reg1, in->mem.nv);
			}
			break;
			case ADRM_STC8:
			case ADRM_STC16:
			case ADRM_STC32: {
				logDevInfo("VAL: Memory = [%d:regi, %d:reg1 . 0x%X]\n", in->mem.regi, in->mem.reg1, in->mem.nv);
			}
			break;
			case ADRM_DYN: {
				logDevInfo("VAL: Memory = [%d:regi, %d:reg1 . %d:reg2]\n", in->mem.regi, in->mem.reg1, in->mem.reg2);
			}
			break;
			case ADRM_DYNI: {
				logDevInfo("VAL: Memory = [%d:regi, %d:reg1 . %d:reg2, 0x%X]\n", in->mem.regi, in->mem.reg1, in->mem.reg2, in->mem.nv);
			}
			break;
			default: {
				logDevInfo("VAL: Memory = invalid adrm: %d:adrm, %d:regi, 0x%X:nv\n", in->mem.mode, in->mem.regi, in->mem.nv);
			}
		}
	}
	else if (typeIsGreg(in->type)){
		logDevInfo("VAL: GReg = %lld%s \n", in->val.lit, (in->type==TYPE_GR8? ": r8": in->type==TYPE_GR16? ": r16": in->type==TYPE_GR32? ": r32": ""));
	}
	else if (in->type == TYPE_FPR){
		logDevInfo("VAL: FPReg = %lld \n", in->val.lit);
	}
	else if (in->type == TYPE_SR){
		logDevInfo("VAL: SReg = %lld \n", in->val.lit);
	}
	else if (in->type == TYPE_IR){
		logDevInfo("VAL: IReg = %lld \n", in->val.lit);
	}
	else {
		logDevInfo("VAL: -unknown- = %lld / 0x%llX\n", in->val.lit, in->val.lit);
	}
}
