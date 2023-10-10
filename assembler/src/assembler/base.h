#ifndef ASM_ISA_H
#define ASM_ISA_H

#include "common.h"


/*
	Structures and Data Namings
*/

// Type of Data
typedef enum{
	TYPE_VOID,
	TYPE_R8, TYPE_R16, TYPE_R32, TYPE_R,
	TYPE_FPR, TYPE_IR,
	TYPE_IMM8, TYPE_IMM16, TYPE_IMM32, TYPE_IMM,
	TYPE_IMMS8, TYPE_IMMS16, TYPE_IMMS32, TYPE_IMMS,
	TYPE_MEM8, TYPE_MEM16, TYPE_MEM32, TYPE_MEM64, TYPE_MEM,
	TYPE_MEMS8, TYPE_MEMS16, TYPE_MEMS32, TYPE_MEMS64, TYPE_MEMS,
}DataType;

// Encoding mode of Data
typedef enum{
	ENCODE_VOID,
	ENCODE_REGM, ENCODE_REGO, ENCODE_DESC,
	ENCODE_REGM1, ENCODE_REGO1, ENCODE_DESC1,
	ENCODE_REGM2, ENCODE_REGO2, ENCODE_DESC2,
	ENCODE_REGM3, ENCODE_REGO3, ENCODE_DESC3,
	ENCODE_MEM,
	ENCODE_MV8, ENCODE_MV16, ENCODE_MV32,
}DataEncode;

// Addressing Modes
typedef enum{
	ADRM_ABS8 = 0, ADRM_ABS16, ADRM_ABS32,
	ADRM_PTR,
	ADRM_IDX8, ADRM_IDX16, ADRM_IDX32,
	ADRM_IDXI, ADRM_IDXI8, ADRM_IDXI16, ADRM_IDXI32,
	ADRM_DYN, ADRM_DYNI,
	ADRM_STC8, ADRM_STC16, ADRM_STC32,
}AddressingMode;

// Nickname for Data Types
typedef struct{
	const char* name; // The name of type
	DataType type_reg; // The type in register format
	DataType type_imm; // The type in immediate format
	DataType type_mem; // The type in memory format
}DataName;
extern DataName data_names[];
extern const int data_names_length;

extern DataName *findDataByName(const char* name);


// Nickname for Registers
typedef struct{
	const char* name; // The name of register
	DataType type; // The type of register
	uint8 code;
}Reg;
extern Reg regs[];
extern const int regs_length;

extern Reg *findRegByName(const char* name);


// Instruction jump conditions
extern const char* jpconds[];

extern uint8 findJpCondByName(const char* name);


// Constant Expression values Struct
typedef struct{
	DataType type;
	union {
		uint8 code; // For Registers
		uint32 integer; // For Immediate Values
		float32 real; // For Immediate Values
	}value;
}Value;

// Instruction Argument Struct
typedef struct{
	AddressingMode adrm;
	uint8 regi, reg1, reg2;
	uint32 nv; // Immediate of memory addressing
}MemAccess;
typedef struct{
	DataType type;
	union {
		uint8 code; // For Registers
		uint32 integer; // For Immediate Values
		float32 real; // For Immediate Values
		MemAccess mem; // For Memory Access
	}value;
}Arg;

// Instruction Parameter Struct
typedef struct{
	DataType type;
	DataEncode encode;
}Param;

// Instruction Encoding Struct
typedef struct{
	uint8 opcode;
	uint8 desc;
	int params_length;
	Param params[4];
}Enc;

// Instruction Struct
#define NO_DESC 0xFF
#define COND_DESC 0xF0
#define CONDO_DESC 0xF1
typedef struct{
	const char* mne; // The instruction mnemonic
	const int encodes_length;
	Enc encodes[24];
}Ist;
extern Ist isa[];
extern const int isa_length;

Ist *findInstructionByName(const char* name);

// Prefix Struct
typedef struct{
	const char* name; // The prefix name
	uint8 code; // Code of prefix
}Prefix;
extern Prefix prefix[];
extern const int prefix_length;

Prefix *findPrefixByName(const char* name);


// Operand Struct


#endif