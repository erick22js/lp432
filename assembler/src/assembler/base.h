#ifndef ASM_BASE_H
#define ASM_BASE_H

#include "common.h"


//
//	DATA CLASSIFICATION
//

typedef enum {
	TYPE_NO,
	
	TYPE_VOID,
	TYPE_VARIABLE,
	TYPE_GR8,
	TYPE_GR16,
	TYPE_GR32,
	TYPE_GR,
	TYPE_FPR,
	TYPE_SR,
	TYPE_IR,
	TYPE_IMM8,
	TYPE_IMM16,
	TYPE_IMM32,
	TYPE_IMM64,
	TYPE_IMM,
	TYPE_IMMS8,
	TYPE_IMMS16,
	TYPE_IMMS32,
	TYPE_IMMS64,
	TYPE_IMMS,
	TYPE_FLOAT32,
	TYPE_FLOAT64,
	TYPE_FLOAT,
	TYPE_MEM8,
	TYPE_MEM16,
	TYPE_MEM32,
	TYPE_MEM64,
	TYPE_MEM,
	TYPE_MEMS8,
	TYPE_MEMS16,
	TYPE_MEMS32,
	TYPE_MEMS64,
	TYPE_MEMS,
	
	TYPE_TOTAL
} Type;

typedef enum {
	GTYPE_IMM,
	GTYPE_REG,
	GTYPE_MEM,
	GTYPE_OTHER
} GType;

typedef struct {
	const char* name;
	Type type;
} Typename;

Typename *baseFindTypename(char* name);
typedef struct {
	const char* name;
	Type gtypes[4];
	int size;
} Castname;

Castname *baseFindCastname(char* name);

int __types_comb[TYPE_TOTAL][TYPE_TOTAL];

#define typeMatches(from, to) __types_comb[from][to]

#define typeIsGreg(type) (type>=TYPE_GR8 && type<=TYPE_GR)
#define typeIsReg(type) (type>=TYPE_GR8 && type<=TYPE_IR)
#define typeIsImm(type) (type>=TYPE_IMM8 && type<=TYPE_IMMS)
#define typeIsFloat(type) (type>=TYPE_FLOAT32 && type<=TYPE_FLOAT)
#define typeIsLiteral(type) (type>=TYPE_IMM8 && type<=TYPE_FLOAT)
#define typeIsMem(type) (type>=TYPE_MEM8 && type<=TYPE_MEMS)
#define typeIsUnsigned(type) ((type>=TYPE_IMM8 && type<=TYPE_IMM) || (type>=TYPE_MEM8 && type<=TYPE_MEM))
#define typeIsSigned(type) ((type>=TYPE_IMMS8 && type<=TYPE_IMMS) || (type>=TYPE_MEMS8 && type<=TYPE_MEMS))
#define typeGroup(type) (typeIsImm(type)||typeIsFloat(type)? GTYPE_IMM: typeIsMem(type)? GTYPE_MEM: typeIsReg(type)? GTYPE_REG: GTYPE_OTHER)


//
//	REGISTERS
//

typedef struct {
	const char* name;
	Type type;
	int index;
} Reg;

Reg *baseFindReg(char* name);


//
//	EXPRESSION VALUES
//

typedef enum {
	ADRM_ABS8, ADRM_ABS16, ADRM_ABS32,
	ADRM_PTR,
	ADRM_IDX8, ADRM_IDX16, ADRM_IDX32,
	ADRM_IDXI, ADRM_IDXI8, ADRM_IDXI16, ADRM_IDXI32,
	ADRM_DYN, ADRM_DYNI,
	ADRM_STC8, ADRM_STC16, ADRM_STC32,
} AdrMode;

typedef struct {
	AdrMode mode;
	u32 regi, reg1, reg2;
	u32 nv;
} MemAccess;

typedef struct {
	Type type;
	union {
		u64 lit, code;
		f64 fp;
		u32 lit32; // Used for output casting
		f32 fp32; // Used for output casting
	} val;
	MemAccess mem;
} Value;


//
//	INSTRUCTION DESCRIPTION
//

#define NO_DESC 0xFF
#define COND_DESC 0xF0
#define CONDO_DESC 0xF1

typedef enum Encode {
	ENCODE_VOID,
	ENCODE_REGM, ENCODE_REGO, ENCODE_DESC,
	ENCODE_REGM1, ENCODE_REGO1, ENCODE_DESC1,
	ENCODE_REGM2, ENCODE_REGO2, ENCODE_DESC2,
	ENCODE_REGM3, ENCODE_REGO3, ENCODE_DESC3,
	ENCODE_MEM,
	ENCODE_MV8, ENCODE_MV16, ENCODE_MV32, ENCODE_MV64,
} Encode;

typedef struct Param {
	const char* name; // For macros only
	Type type; // Must in value for any parameter
	Encode encode; // For instructions only
} Param;

typedef struct InstrEncode {
	u8 opcode;
	u8 desc;
	Param params[MAX_CMD_PARAMS];
	int params_len;
} InstrEncode;

typedef struct Instruction {
	const char* mne;
	int encodes_len;
	InstrEncode encodes[32];
} Instruction;

extern Instruction const isa[];
extern int const isa_len;

Instruction *instrFindByName(const char* name);
int instrFindSufix(const char* name, bool *condo);
bool paramMatches(Param* base, Value* cmp, int params_len);


#endif