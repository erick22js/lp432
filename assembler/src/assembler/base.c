#include "base.h"


//
//	DATA CLASSIFICATION
//

Typename types[] = {
	{"Void", TYPE_VOID},
	{"Greg8", TYPE_GR8},
	{"Greg16", TYPE_GR16},
	{"Greg32", TYPE_GR32},
	{"Greg", TYPE_GR},
	{"Fpreg", TYPE_FPR},
	{"Sreg", TYPE_SR},
	{"Ireg", TYPE_IR},
	{"Imm8", TYPE_IMM8},
	{"Imm16", TYPE_IMM16},
	{"Imm32", TYPE_IMM32},
	{"Imm64", TYPE_IMM64},
	{"Imm", TYPE_IMM},
	{"Imms8", TYPE_IMMS8},
	{"Imms16", TYPE_IMMS16},
	{"Imms32", TYPE_IMMS32},
	{"Imms64", TYPE_IMMS64},
	{"Imms", TYPE_IMMS},
	{"Float32", TYPE_FLOAT32},
	{"Float64", TYPE_FLOAT64},
	{"Float", TYPE_FLOAT},
	{"Mem8", TYPE_MEM8},
	{"Mem16", TYPE_MEM16},
	{"Mem32", TYPE_MEM32},
	{"Mem64", TYPE_MEM64},
	{"Mem", TYPE_MEM},
	{"Mems8", TYPE_MEMS8},
	{"Mems16", TYPE_MEMS16},
	{"Mems32", TYPE_MEMS32},
	{"Mems64", TYPE_MEMS64},
	{"Mems", TYPE_MEMS},
};

Typename *baseFindTypename(char* name) {
	for (int i=0; i<(sizeof(types)/sizeof(Typename)); i++){
		if (strcmp(types[i].name, name) == 0){
			return &types[i];
		}
	}
	return null;
}

Castname casts[] = {
	{"Byte", { [GTYPE_IMM] = TYPE_IMM8, [GTYPE_REG] = TYPE_GR8, [GTYPE_MEM] = TYPE_MEM8 }, 1},
	{"Half", { [GTYPE_IMM] = TYPE_IMM16, [GTYPE_REG] = TYPE_GR16, [GTYPE_MEM] = TYPE_MEM16 }, 2},
	{"Word", { [GTYPE_IMM] = TYPE_IMM32, [GTYPE_REG] = TYPE_GR32, [GTYPE_MEM] = TYPE_MEM32 }, 4},
	{"Dword", { [GTYPE_IMM] = TYPE_IMM64, [GTYPE_REG] = TYPE_NO, [GTYPE_MEM] = TYPE_MEM64 }, 8},
	{"SByte", { [GTYPE_IMM] = TYPE_IMMS8, [GTYPE_REG] = TYPE_NO, [GTYPE_MEM] = TYPE_MEMS8 }, 1},
	{"SHalf", { [GTYPE_IMM] = TYPE_IMMS16, [GTYPE_REG] = TYPE_NO, [GTYPE_MEM] = TYPE_MEMS16 }, 2},
	{"SWord", { [GTYPE_IMM] = TYPE_IMMS32, [GTYPE_REG] = TYPE_NO, [GTYPE_MEM] = TYPE_MEMS32 }, 4},
	{"SDword", { [GTYPE_IMM] = TYPE_IMMS64, [GTYPE_REG] = TYPE_NO, [GTYPE_MEM] = TYPE_MEMS64 }, 8},
	{"Float", { [GTYPE_IMM] = TYPE_FLOAT32, [GTYPE_REG] = TYPE_NO, [GTYPE_MEM] = TYPE_NO }, 4},
	{"Double", { [GTYPE_IMM] = TYPE_FLOAT64, [GTYPE_REG] = TYPE_NO, [GTYPE_MEM] = TYPE_NO }, 8},
};

Castname *baseFindCastname(char* name) {
	for (int i=0; i<(sizeof(casts)/sizeof(Castname)); i++){
		if (strcmp(casts[i].name, name) == 0){
			return &casts[i];
		}
	}
	return null;
}


//
//	REGISTERS
//

Reg regs[] = {
	{"eax", TYPE_GR32, 0}, {"edx", TYPE_GR32, 1}, {"ecx", TYPE_GR32, 2}, {"ebx", TYPE_GR32, 3},
	{"eex", TYPE_GR32, 4}, {"ehx", TYPE_GR32, 5}, {"egx", TYPE_GR32, 6}, {"efx", TYPE_GR32, 7},
	{"ex0", TYPE_GR32, 8}, {"ex1", TYPE_GR32, 9}, {"ex2", TYPE_GR32, 10}, {"ex3", TYPE_GR32, 11},
	{"ess", TYPE_GR32, 12}, {"esd", TYPE_GR32, 13}, {"esp", TYPE_GR32, 14}, {"efp", TYPE_GR32, 15},
	{"ax", TYPE_GR16, 0}, {"dx", TYPE_GR16, 1}, {"cx", TYPE_GR16, 2}, {"bx", TYPE_GR16, 3},
	{"ex", TYPE_GR16, 4}, {"hx", TYPE_GR16, 5}, {"gx", TYPE_GR16, 6}, {"fx", TYPE_GR16, 7},
	{"x0", TYPE_GR16, 8}, {"x1", TYPE_GR16, 9}, {"x2", TYPE_GR16, 10}, {"x3", TYPE_GR16, 11},
	{"ss", TYPE_GR16, 12}, {"sd", TYPE_GR16, 13}, {"sp", TYPE_GR16, 14}, {"fp", TYPE_GR16, 15},
	{"al", TYPE_GR8, 0}, {"dl", TYPE_GR8, 1}, {"cl", TYPE_GR8, 2}, {"bl", TYPE_GR8, 3},
	{"el", TYPE_GR8, 4}, {"hl", TYPE_GR8, 5}, {"gl", TYPE_GR8, 6}, {"fl", TYPE_GR8, 7},
	{"l0", TYPE_GR8, 8}, {"l1", TYPE_GR8, 9}, {"l2", TYPE_GR8, 10}, {"l3", TYPE_GR8, 11},
	{"f0", TYPE_FPR, 0}, {"f1", TYPE_FPR, 1}, {"f2", TYPE_FPR, 2}, {"f3", TYPE_FPR, 4},
	{"f4", TYPE_FPR, 4}, {"f5", TYPE_FPR, 5}, {"f6", TYPE_FPR, 6}, {"f7", TYPE_FPR, 7},
	{"f8", TYPE_FPR, 8}, {"f9", TYPE_FPR, 9}, {"f10", TYPE_FPR, 10}, {"f11", TYPE_FPR, 11},
	{"f12", TYPE_FPR, 12}, {"f13", TYPE_FPR, 13}, {"f14", TYPE_FPR, 14}, {"f15", TYPE_FPR, 15},
	{"sr0", TYPE_SR, 0}, {"sr1", TYPE_SR, 1}, {"sr2", TYPE_SR, 2}, {"sr3", TYPE_SR, 4},
	{"sr4", TYPE_SR, 4}, {"sr5", TYPE_SR, 5}, {"sr6", TYPE_SR, 6}, {"sr7", TYPE_SR, 7},
	{"ir0", TYPE_IR, 0}, {"ir1", TYPE_IR, 1}, {"ir2", TYPE_IR, 2}, {"ir3", TYPE_IR, 4},
	{"ir4", TYPE_IR, 4}, {"ir5", TYPE_IR, 5}, {"ir6", TYPE_IR, 6}, {"ir7", TYPE_IR, 7},
};

Reg *baseFindReg(char* name) {
	for (int i=0; i<(sizeof(regs)/sizeof(Reg)); i++){
		if (strcmp(regs[i].name, name) == 0){
			return &regs[i];
		}
	}
	return null;
}


//
//	Instructions and Parameters
//

Instruction *instrFindByName(const char* name) {
	for (int i=0; i<isa_len; i++){
		if (strcmp(isa[i].mne, name) == 0){
			return (Instruction*) &isa[i];
		}
	}
	return null;
}

bool paramMatches(Param* base, Value* cmp, int params_len) {
	for (int i=0; i<params_len && i<MAX_CMD_PARAMS; i++){
		if (!typeMatches(base[i].type, cmp[i].type)){
			return false;
		}
	}
	return true;
}

const char* (sufixes[]) = {
	"eq", "ne", "gt", "lt", "ge", "le", "ab", "bl", "ae", "be", "cs", "cc", "ns", "os", "vs", "vc",
	"eqz", "nez", "gtz", "ltz", "gez", "lez", "abz", "blz", "aez", "bez", "lc", "nlc", "ln", "lo", "lv", "nlv"
};

int instrFindSufix(const char* name, bool *condo) {
	for (int i=0; i<32; i++){
		if (strcmp(sufixes[i], name)==0) {
			*condo = i>=16;
			return i>=16? i-16: i;
		}
	}
	return -1;
}


//
//	DATA CASTING
//

// Line: convert from
// Collumn: convert to
int __types_comb[TYPE_TOTAL][TYPE_TOTAL] = {
	[TYPE_VOID] = {  [TYPE_VOID] = 1, [TYPE_VARIABLE] = 0, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_VARIABLE] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 1, [TYPE_GR16] = 1, [TYPE_GR32] = 1, [TYPE_GR] = 1, [TYPE_FPR] = 1, [TYPE_SR] = 1, [TYPE_IR] = 1, [TYPE_IMM8] = 1, [TYPE_IMM16] = 1, [TYPE_IMM32] = 1, [TYPE_IMM64] = 1, [TYPE_IMM] = 1, [TYPE_IMMS8] = 1, [TYPE_IMMS16] = 1, [TYPE_IMMS32] = 1, [TYPE_IMMS64] = 1, [TYPE_IMMS] = 1, [TYPE_FLOAT32] = 1, [TYPE_FLOAT64] = 1, [TYPE_FLOAT] = 1, [TYPE_MEM8] = 1, [TYPE_MEM16] = 1, [TYPE_MEM32] = 1, [TYPE_MEM64] = 1, [TYPE_MEM] = 1, [TYPE_MEMS8] = 1, [TYPE_MEMS16] = 1, [TYPE_MEMS32] = 1, [TYPE_MEMS64] = 1, [TYPE_MEMS] = 1 },
	[TYPE_GR8] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 1, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 1, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_GR16] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 1, [TYPE_GR32] = 0, [TYPE_GR] = 1, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_GR32] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 1, [TYPE_GR] = 1, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_GR] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 1, [TYPE_GR16] = 1, [TYPE_GR32] = 1, [TYPE_GR] = 1, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_FPR] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 1, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_SR] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 1, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_IR] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 1, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_IMM8] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 1, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 1, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_IMM16] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 1, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 1, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_IMM32] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 1, [TYPE_IMM64] = 0, [TYPE_IMM] = 1, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_IMM64] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 1, [TYPE_IMM64] = 1, [TYPE_IMM] = 1, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_IMM] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 1, [TYPE_IMM16] = 1, [TYPE_IMM32] = 1, [TYPE_IMM64] = 1, [TYPE_IMM] = 1, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_IMMS8] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 1, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 1, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_IMMS16] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 1, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 1, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_IMMS32] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 1, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 1, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_IMMS64] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 1, [TYPE_IMM64] = 0, [TYPE_IMM] = 1, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 1, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_IMMS] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 1, [TYPE_IMMS8] = 1, [TYPE_IMMS16] = 1, [TYPE_IMMS32] = 1, [TYPE_IMMS64] = 1, [TYPE_IMMS] = 1, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_FLOAT32] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 1, [TYPE_IMM64] = 0, [TYPE_IMM] = 1, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 1, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 1, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_FLOAT64] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 1, [TYPE_FLOAT] = 1, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_FLOAT] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 1, [TYPE_FLOAT64] = 1, [TYPE_FLOAT] = 1, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_MEM8] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 1, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 1, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_MEM16] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 1, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 1, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_MEM32] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 1, [TYPE_MEM64] = 0, [TYPE_MEM] = 1, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_MEM64] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 1, [TYPE_IMM64] = 0, [TYPE_IMM] = 1, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 1, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_MEM] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 1, [TYPE_MEM16] = 1, [TYPE_MEM32] = 1, [TYPE_MEM64] = 1, [TYPE_MEM] = 1, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 0 },
	[TYPE_MEMS8] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 1, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 1 },
	[TYPE_MEMS16] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 1, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 1 },
	[TYPE_MEMS32] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 1, [TYPE_MEMS64] = 0, [TYPE_MEMS] = 1 },
	[TYPE_MEMS64] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 1, [TYPE_IMM64] = 0, [TYPE_IMM] = 1, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 0, [TYPE_MEMS16] = 0, [TYPE_MEMS32] = 0, [TYPE_MEMS64] = 1, [TYPE_MEMS] = 0 },
	[TYPE_MEMS] = {  [TYPE_VOID] = 0, [TYPE_VARIABLE] = 1, [TYPE_GR8] = 0, [TYPE_GR16] = 0, [TYPE_GR32] = 0, [TYPE_GR] = 0, [TYPE_FPR] = 0, [TYPE_SR] = 0, [TYPE_IR] = 0, [TYPE_IMM8] = 0, [TYPE_IMM16] = 0, [TYPE_IMM32] = 0, [TYPE_IMM64] = 0, [TYPE_IMM] = 0, [TYPE_IMMS8] = 0, [TYPE_IMMS16] = 0, [TYPE_IMMS32] = 0, [TYPE_IMMS64] = 0, [TYPE_IMMS] = 0, [TYPE_FLOAT32] = 0, [TYPE_FLOAT64] = 0, [TYPE_FLOAT] = 0, [TYPE_MEM8] = 0, [TYPE_MEM16] = 0, [TYPE_MEM32] = 0, [TYPE_MEM64] = 0, [TYPE_MEM] = 0, [TYPE_MEMS8] = 1, [TYPE_MEMS16] = 1, [TYPE_MEMS32] = 1, [TYPE_MEMS64] = 1, [TYPE_MEMS] = 1 },
};
