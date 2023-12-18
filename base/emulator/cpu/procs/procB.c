#include "procedures.h"


#define procAnd(v1, v2, res, sign, type) {\
	res = v1 & v2;\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_ZF, ((type)res)==0);/* Zero Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_NF, res&sign);/* Negative Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_OF, res&1);/* Odd Flag Affecting */\
}
#define procAnd8(v1, v2, res) procAnd(v1, v2, res, 0x80, uint8)
#define procAnd16(v1, v2, res) procAnd(v1, v2, res, 0x8000, uint16)
#define procAnd32(v1, v2, res) procAnd(v1, v2, res, 0x80000000, uint32)

#define procOr(v1, v2, res, sign, type) {\
	res = v1 | v2;\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_ZF, ((type)res)==0);/* Zero Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_NF, res&sign);/* Negative Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_OF, res&1);/* Odd Flag Affecting */\
}
#define procOr8(v1, v2, res) procOr(v1, v2, res, 0x80, uint8)
#define procOr16(v1, v2, res) procOr(v1, v2, res, 0x8000, uint16)
#define procOr32(v1, v2, res) procOr(v1, v2, res, 0x80000000, uint32)

#define procXor(v1, v2, res, sign, type) {\
	res = v1 ^ v2;\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_ZF, ((type)res)==0);/* Zero Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_NF, res&sign);/* Negative Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_OF, res&1);/* Odd Flag Affecting */\
}
#define procXor8(v1, v2, res) procXor(v1, v2, res, 0x80, uint8)
#define procXor16(v1, v2, res) procXor(v1, v2, res, 0x8000, uint16)
#define procXor32(v1, v2, res) procXor(v1, v2, res, 0x80000000, uint32)

#define procBitTest(v, sign, type) {\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_ZF, ((type)v)==0);/* Zero Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_NF, v&sign);/* Negative Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_OF, v&1);/* Odd Flag Affecting */\
}
#define procBitTest8(v) procBitTest(v, 0x80, uint8)
#define procBitTest16(v) procBitTest(v, 0x8000, uint16)
#define procBitTest32(v) procBitTest(v, 0x80000000, uint32)

#define procBitScanFoward(v, res, size) {\
	res = 0;\
	for (int i=size-1; i>=0; i--){\
		if ((v>>i)&1){\
			break;\
		}\
		else{\
			res++;\
		}\
	}\
}
#define procBitScanFoward8(v, res) procBitScanFoward(v, res, 8)
#define procBitScanFoward16(v, res) procBitScanFoward(v, res, 16)
#define procBitScanFoward32(v, res) procBitScanFoward(v, res, 32)

#define procBitScanBackward(v, res, size) {\
	res = 0;\
	for (int i=0; i<size; i++){\
		if ((v>>i)&1){\
			break;\
		}\
		else{\
			res++;\
		}\
	}\
}
#define procBitScanBackward8(v, res) procBitScanBackward(v, res, 8)
#define procBitScanBackward16(v, res) procBitScanBackward(v, res, 16)
#define procBitScanBackward32(v, res) procBitScanBackward(v, res, 32)

cpuInterr procB0(Cpu *cpu_s){
	// Instruction: and r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s->os_regm);
	uint32 v2 = cpuReadReg8(cpu_s->os_rego);
	uint32 res = 0;
	procAnd8(v1, v2, res);
	cpuWriteReg8(cpu_s->os_regm, res);
	return 0;
}

cpuInterr procB1(Cpu *cpu_s){
	// Instruction: and r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s->os_regm);
	uint32 v2 = cpuReadReg16(cpu_s->os_rego);
	uint32 res = 0;
	procAnd16(v1, v2, res);
	cpuWriteReg16(cpu_s->os_regm, res);
	return 0;
}

cpuInterr procB2(Cpu *cpu_s){
	// Instruction: and r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s->os_regm);
	uint32 v2 = cpuReadReg32(cpu_s->os_rego);
	uint32 res = 0;
	procAnd32(v1, v2, res);
	cpuWriteReg32(cpu_s->os_regm, res);
	return 0;
}

cpuInterr procB3(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0:{
			// Instruction: and r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAnd8(v1, v2, res);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: and r16:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAnd16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: and r32:regm, imm32:MV
			cpuFetchMV32();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAnd32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: and r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAnd8(v1, v2, res);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: and r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAnd16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: and r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAnd32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x6:{
			// Instruction: and r16:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAnd16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x7:{
			// Instruction: and r32:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAnd32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x8:{
			// Instruction: and r32:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAnd32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x9:{
			// Instruction: and r16:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAnd16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0xA:{
			// Instruction: and r32:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAnd32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xB:{
			// Instruction: and r32:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAnd32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xC:{
			// Instruction: and r32:regm, imms8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->code);
			uint32 res = 0;
			procAnd32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xD:{
			// Instruction: and r32:regm, imms16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->code);
			uint32 res = 0;
			procAnd32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xE:{
			// Instruction: and r32:regm, mems8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->data);
			uint32 res = 0;
			procAnd32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xF:{
			// Instruction: and r32:regm, mems16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->data);
			uint32 res = 0;
			procAnd32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		default: {
			cpu_s->iregs[0] = cpu_s->reg_lpc;
			cpu_s->iregs[1] = cpu_s->opcode;
			cpu_s->iregs[2] = cpu_s->os_desc;
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr procB4(Cpu *cpu_s){
	// Instruction: or r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s->os_regm);
	uint32 v2 = cpuReadReg8(cpu_s->os_rego);
	uint32 res = 0;
	procOr8(v1, v2, res);
	cpuWriteReg8(cpu_s->os_regm, res);
	return 0;
}

cpuInterr procB5(Cpu *cpu_s){
	// Instruction: or r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s->os_regm);
	uint32 v2 = cpuReadReg16(cpu_s->os_rego);
	uint32 res = 0;
	procOr16(v1, v2, res);
	cpuWriteReg16(cpu_s->os_regm, res);
	return 0;
}

cpuInterr procB6(Cpu *cpu_s){
	// Instruction: or r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s->os_regm);
	uint32 v2 = cpuReadReg32(cpu_s->os_rego);
	uint32 res = 0;
	procOr32(v1, v2, res);
	cpuWriteReg32(cpu_s->os_regm, res);
	return 0;
}

cpuInterr procB7(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0:{
			// Instruction: or r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procOr8(v1, v2, res);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: or r16:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procOr16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: or r32:regm, imm32:MV
			cpuFetchMV32();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procOr32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: or r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procOr8(v1, v2, res);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: or r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procOr16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: or r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procOr32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x6:{
			// Instruction: or r16:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procOr16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x7:{
			// Instruction: or r32:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procOr32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x8:{
			// Instruction: or r32:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procOr32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x9:{
			// Instruction: or r16:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procOr16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0xA:{
			// Instruction: or r32:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procOr32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xB:{
			// Instruction: or r32:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procOr32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xC:{
			// Instruction: or r32:regm, imms8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->code);
			uint32 res = 0;
			procOr32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xD:{
			// Instruction: or r32:regm, imms16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->code);
			uint32 res = 0;
			procOr32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xE:{
			// Instruction: or r32:regm, mems8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->data);
			uint32 res = 0;
			procOr32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xF:{
			// Instruction: or r32:regm, mems16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->data);
			uint32 res = 0;
			procOr32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		default: {
			cpu_s->iregs[0] = cpu_s->reg_lpc;
			cpu_s->iregs[1] = cpu_s->opcode;
			cpu_s->iregs[2] = cpu_s->os_desc;
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr procB8(Cpu *cpu_s){
	// Instruction: xor r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s->os_regm);
	uint32 v2 = cpuReadReg8(cpu_s->os_rego);
	uint32 res = 0;
	procXor8(v1, v2, res);
	cpuWriteReg8(cpu_s->os_regm, res);
	return 0;
}

cpuInterr procB9(Cpu *cpu_s){
	// Instruction: xor r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s->os_regm);
	uint32 v2 = cpuReadReg16(cpu_s->os_rego);
	uint32 res = 0;
	procXor16(v1, v2, res);
	cpuWriteReg16(cpu_s->os_regm, res);
	return 0;
}

cpuInterr procBA(Cpu *cpu_s){
	// Instruction: xor r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s->os_regm);
	uint32 v2 = cpuReadReg32(cpu_s->os_rego);
	uint32 res = 0;
	procXor32(v1, v2, res);
	cpuWriteReg32(cpu_s->os_regm, res);
	return 0;
}

cpuInterr procBB(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0:{
			// Instruction: xor r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procXor8(v1, v2, res);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: xor r16:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procXor16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: xor r32:regm, imm32:MV
			cpuFetchMV32();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procXor32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: xor r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procXor8(v1, v2, res);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: xor r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procXor16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: xor r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procXor32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x6:{
			// Instruction: xor r16:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procXor16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x7:{
			// Instruction: xor r32:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procXor32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x8:{
			// Instruction: xor r32:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procXor32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x9:{
			// Instruction: xor r16:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procXor16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0xA:{
			// Instruction: xor r32:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procXor32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xB:{
			// Instruction: xor r32:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procXor32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xC:{
			// Instruction: xor r32:regm, imms8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->code);
			uint32 res = 0;
			procXor32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xD:{
			// Instruction: xor r32:regm, imms16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->code);
			uint32 res = 0;
			procXor32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xE:{
			// Instruction: xor r32:regm, mems8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->data);
			uint32 res = 0;
			procXor32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xF:{
			// Instruction: xor r32:regm, mems16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->data);
			uint32 res = 0;
			procXor32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		default: {
			cpu_s->iregs[0] = cpu_s->reg_lpc;
			cpu_s->iregs[1] = cpu_s->opcode;
			cpu_s->iregs[2] = cpu_s->os_desc;
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr procBE(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0:{
			// Instruction: bt r8:regm
			uint32 v = cpuReadReg8(cpu_s->os_regm);
			procBitTest8(v);
		}
		break;
		case 0x1:{
			// Instruction: bt r16:regm
			uint32 v = cpuReadReg16(cpu_s->os_regm);
			procBitTest16(v);
		}
		break;
		case 0x2:{
			// Instruction: bt r32:regm
			uint32 v = cpuReadReg32(cpu_s->os_regm);
			procBitTest32(v);
		}
		break;
		case 0x3:{
			// Instruction: bt mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v = cpu_s->data;
			procBitTest8(v);
		}
		break;
		case 0x4:{
			// Instruction: bt mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v = cpu_s->data;
			procBitTest16(v);
		}
		break;
		case 0x5:{
			// Instruction: bt mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s->mem_adr);
			uint32 v = cpu_s->data;
			procBitTest32(v);
		}
		break;
		case 0x6:{
			// Instruction: bts r32:regm, imm8
			cpuFetch8();
			uint8 bit = cpu_s->mv;
			cpuWriteReg32(cpu_s->os_regm, cpuReadReg32(cpu_s->os_regm) | (1<<(bit)));
		}
		break;
		case 0x7:{
			// Instruction: btc r32:regm, imm8
			cpuFetch8();
			uint8 bit = cpu_s->mv;
			cpuWriteReg32(cpu_s->os_regm, cpuReadReg32(cpu_s->os_regm) & (~(1<<(bit))));
		}
		break;
		case 0x8:{
			// Instruction: btt r32:regm, imm8
			cpuFetch8();
			uint8 bit = cpu_s->mv;
			cpuWriteReg32(cpu_s->os_regm, cpuReadReg32(cpu_s->os_regm) ^ (1<<(bit)));
		}
		break;
		case 0x9:{
			// Instruction: bts r32:regm, r32:rego
			uint32 bit = cpu_s->os_rego;
			cpuWriteReg32(cpu_s->os_regm, cpuReadReg32(cpu_s->os_regm) | (1<<(bit)));
		}
		break;
		case 0xA:{
			// Instruction: btc r32:regm, r32:rego
			uint32 bit = cpu_s->os_rego;
			cpuWriteReg32(cpu_s->os_regm, cpuReadReg32(cpu_s->os_regm) & (~(1<<(bit))));
		}
		break;
		case 0xB:{
			// Instruction: btt r32:regm, r32:rego
			uint32 bit = cpu_s->os_rego;
			cpuWriteReg32(cpu_s->os_regm, cpuReadReg32(cpu_s->os_regm) ^ (1<<(bit)));
		}
		break;
		default: {
			cpu_s->iregs[0] = cpu_s->reg_lpc;
			cpu_s->iregs[1] = cpu_s->opcode;
			cpu_s->iregs[2] = cpu_s->os_desc;
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr procBF(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0:{
			// Instruction: bsf r32:regm1, r8:rego2
			uint32 dest = cpu_s->os_regm;
			cpuFetchOS();
			uint32 v = cpuReadReg8(cpu_s->os_rego);
			uint32 res = 0;
			procBitScanFoward8(v, res);
			cpuWriteReg32(dest, res);
		}
		break;
		case 0x1:{
			// Instruction: bsf r32:regm1, r16:rego2
			uint32 dest = cpu_s->os_regm;
			cpuFetchOS();
			uint32 v = cpuReadReg16(cpu_s->os_rego);
			uint32 res = 0;
			procBitScanFoward16(v, res);
			cpuWriteReg32(dest, res);
		}
		break;
		case 0x2:{
			// Instruction: bsf r32:regm1, r32:rego2
			uint32 dest = cpu_s->os_regm;
			cpuFetchOS();
			uint32 v = cpuReadReg32(cpu_s->os_rego);
			uint32 res = 0;
			procBitScanFoward32(v, res);
			cpuWriteReg32(dest, res);
		}
		break;
		case 0x3:{
			// Instruction: bsf r32:regm1, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v = cpu_s->data;
			uint32 res = 0;
			procBitScanFoward8(v, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: bsf r32:regm1, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v = cpu_s->data;
			uint32 res = 0;
			procBitScanFoward16(v, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: bsf r32:regm1, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s->mem_adr);
			uint32 v = cpu_s->data;
			uint32 res = 0;
			procBitScanFoward32(v, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x6:{
			// Instruction: bsb r32:regm1, r8:rego2
			uint32 dest = cpu_s->os_regm;
			cpuFetchOS();
			uint32 v = cpuReadReg8(cpu_s->os_rego);
			uint32 res = 0;
			procBitScanBackward8(v, res);
			cpuWriteReg32(dest, res);
		}
		break;
		case 0x7:{
			// Instruction: bsb r32:regm1, r16:rego2
			uint32 dest = cpu_s->os_regm;
			cpuFetchOS();
			uint32 v = cpuReadReg16(cpu_s->os_rego);
			uint32 res = 0;
			procBitScanBackward16(v, res);
			cpuWriteReg32(dest, res);
		}
		break;
		case 0x8:{
			// Instruction: bsb r32:regm1, r32:rego2
			uint32 dest = cpu_s->os_regm;
			cpuFetchOS();
			uint32 v = cpuReadReg32(cpu_s->os_rego);
			uint32 res = 0;
			procBitScanBackward32(v, res);
			cpuWriteReg32(dest, res);
		}
		break;
		case 0x9:{
			// Instruction: bsb r32:regm1, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v = cpu_s->data;
			uint32 res = 0;
			procBitScanBackward8(v, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xA:{
			// Instruction: bsb r32:regm1, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v = cpu_s->data;
			uint32 res = 0;
			procBitScanBackward16(v, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xB:{
			// Instruction: bsb r32:regm1, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s->mem_adr);
			uint32 v = cpu_s->data;
			uint32 res = 0;
			procBitScanBackward32(v, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		default: {
			cpu_s->iregs[0] = cpu_s->reg_lpc;
			cpu_s->iregs[1] = cpu_s->opcode;
			cpu_s->iregs[2] = cpu_s->os_desc;
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

