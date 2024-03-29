#include "procedures.h"


#define procMod(v1, v2, res, sign, type) {\
	if (((type)v2)==0){\
		cpu_s->iregs[0] = cpu_s->reg_lpc;\
		cpu_s->iregs[1] = v1;\
		cpuThrowInterruption(INTR_DIVISION_BY_ZERO);\
	}\
	res = v1 % v2;\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_ZF, ((type)res)==0);/* Zero Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_NF, res&sign);/* Negative Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_OF, res&1);/* Odd Flag Affecting */\
}
#define procMod8(v1, v2, res) procMod(v1, v2, res, 0x80, uint8)
#define procMod16(v1, v2, res) procMod(v1, v2, res, 0x8000, uint16)
#define procMod32(v1, v2, res) procMod(v1, v2, res, 0x80000000, uint32)

#define procSMod(v1, v2, res, sign, type) {\
	if (((type)v2)==0){\
		cpu_s->iregs[0] = cpu_s->reg_lpc;\
		cpu_s->iregs[1] = v1;\
		cpuThrowInterruption(INTR_DIVISION_BY_ZERO);\
	}\
	res = (type)((type)v1 % (type)v2);\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_ZF, res==0);/* Zero Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_NF, res&sign);/* Negative Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_OF, res&1);/* Odd Flag Affecting */\
}
#define procSMod8(v1, v2, res) procSMod(v1, v2, res, 0x80, sint8)
#define procSMod16(v1, v2, res) procSMod(v1, v2, res, 0x8000, sint16)
#define procSMod32(v1, v2, res) procSMod(v1, v2, res, 0x80000000, sint32)

#define procSub(v1, v2, res, sign, type) {\
	res = v1 - v2;\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_BF, ((type)res)>((type)v1));/* Borrow Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_VF, ((v1&sign)!=(v2&sign) && (v2&sign)==(res&sign)));/* Overflow Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_ZF, ((type)res)==0);/* Zero Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_NF, res&sign);/* Negative Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_OF, res&1);/* Odd Flag Affecting */\
}
#define procSub8(v1, v2, res) procSub(v1, v2, res, 0x80, uint8)
#define procSub16(v1, v2, res) procSub(v1, v2, res, 0x8000, uint16)
#define procSub32(v1, v2, res) procSub(v1, v2, res, 0x80000000, uint32)

cpuInterr procA0(Cpu *cpu_s){
	// Instruction: mod r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s->os_regm);
	uint32 v2 = cpuReadReg8(cpu_s->os_rego);
	uint32 res = 0;
	procMod8(v1, v2, res);
	cpuWriteReg8(cpu_s->os_regm, res);
	return 0;
}

cpuInterr procA1(Cpu *cpu_s){
	// Instruction: mod r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s->os_regm);
	uint32 v2 = cpuReadReg16(cpu_s->os_rego);
	uint32 res = 0;
	procMod16(v1, v2, res);
	cpuWriteReg16(cpu_s->os_regm, res);
	return 0;
}

cpuInterr procA2(Cpu *cpu_s){
	// Instruction: mod r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s->os_regm);
	uint32 v2 = cpuReadReg32(cpu_s->os_rego);
	uint32 res = 0;
	procMod32(v1, v2, res);
	cpuWriteReg32(cpu_s->os_regm, res);
	return 0;
}

cpuInterr procA3(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0:{
			// Instruction: mod r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procMod8(v1, v2, res);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: mod r16:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procMod16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: mod r32:regm, imm32:MV
			cpuFetchMV32();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: mod r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procMod8(v1, v2, res);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: mod r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procMod16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: mod r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x6:{
			// Instruction: mod r16:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procMod16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x7:{
			// Instruction: mod r32:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x8:{
			// Instruction: mod r32:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x9:{
			// Instruction: mod r16:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procMod16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0xA:{
			// Instruction: mod r32:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xB:{
			// Instruction: mod r32:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xC:{
			// Instruction: mod r32:regm, imms8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->code);
			uint32 res = 0;
			procMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xD:{
			// Instruction: mod r32:regm, imms16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->code);
			uint32 res = 0;
			procMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xE:{
			// Instruction: mod r32:regm, mems8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->data);
			uint32 res = 0;
			procMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xF:{
			// Instruction: mod r32:regm, mems16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->data);
			uint32 res = 0;
			procMod32(v1, v2, res);
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

cpuInterr procA4(Cpu *cpu_s){
	// Instruction: smod r8:regm, r8:rego
	cpuFetchOS();
	sint32 v1 = cpuReadReg8(cpu_s->os_regm);
	sint32 v2 = cpuReadReg8(cpu_s->os_rego);
	sint32 res = 0;
	procSMod8(v1, v2, res);
	cpuWriteReg8(cpu_s->os_regm, res);
	return 0;
}

cpuInterr procA5(Cpu *cpu_s){
	// Instruction: smod r16:regm, r16:rego
	cpuFetchOS();
	sint32 v1 = cpuReadReg16(cpu_s->os_regm);
	sint32 v2 = cpuReadReg16(cpu_s->os_rego);
	sint32 res = 0;
	procSMod16(v1, v2, res);
	cpuWriteReg16(cpu_s->os_regm, res);
	return 0;
}

cpuInterr procA6(Cpu *cpu_s){
	// Instruction: smod r32:regm, r32:rego
	cpuFetchOS();
	sint32 v1 = cpuReadReg32(cpu_s->os_regm);
	sint32 v2 = cpuReadReg32(cpu_s->os_rego);
	sint32 res = 0;
	procSMod32(v1, v2, res);
	cpuWriteReg32(cpu_s->os_regm, res);
	return 0;
}

cpuInterr procA7(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0:{
			// Instruction: smod r8:regm, imm8:MV
			cpuFetchMV8();
			sint32 v1 = cpuReadReg8(cpu_s->os_regm);
			sint32 v2 = cpu_s->code;
			sint32 res = 0;
			procSMod8(v1, v2, res);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: smod r16:regm, imm16:MV
			cpuFetchMV16();
			sint32 v1 = cpuReadReg16(cpu_s->os_regm);
			sint32 v2 = cpu_s->code;
			sint32 res = 0;
			procSMod16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: smod r32:regm, imm32:MV
			cpuFetchMV32();
			sint32 v1 = cpuReadReg32(cpu_s->os_regm);
			sint32 v2 = cpu_s->code;
			sint32 res = 0;
			procSMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: smod r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			sint32 v1 = cpuReadReg8(cpu_s->os_regm);
			sint32 v2 = cpu_s->data;
			sint32 res = 0;
			procSMod8(v1, v2, res);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: smod r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			sint32 v1 = cpuReadReg16(cpu_s->os_regm);
			sint32 v2 = cpu_s->data;
			sint32 res = 0;
			procSMod16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: smod r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s->mem_adr);
			sint32 v1 = cpuReadReg32(cpu_s->os_regm);
			sint32 v2 = cpu_s->data;
			sint32 res = 0;
			procSMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x6:{
			// Instruction: smod r16:regm, imm8:MV
			cpuFetchMV8();
			sint32 v1 = cpuReadReg16(cpu_s->os_regm);
			sint32 v2 = cpu_s->code;
			sint32 res = 0;
			procSMod16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x7:{
			// Instruction: smod r32:regm, imm8:MV
			cpuFetchMV8();
			sint32 v1 = cpuReadReg32(cpu_s->os_regm);
			sint32 v2 = cpu_s->code;
			sint32 res = 0;
			procSMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x8:{
			// Instruction: smod r32:regm, imm16:MV
			cpuFetchMV16();
			sint32 v1 = cpuReadReg32(cpu_s->os_regm);
			sint32 v2 = cpu_s->code;
			sint32 res = 0;
			procSMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x9:{
			// Instruction: smod r16:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			sint32 v1 = cpuReadReg16(cpu_s->os_regm);
			sint32 v2 = cpu_s->data;
			sint32 res = 0;
			procSMod16(v1, v2, res);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0xA:{
			// Instruction: smod r32:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			sint32 v1 = cpuReadReg32(cpu_s->os_regm);
			sint32 v2 = cpu_s->data;
			sint32 res = 0;
			procSMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xB:{
			// Instruction: smod r32:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			sint32 v1 = cpuReadReg32(cpu_s->os_regm);
			sint32 v2 = cpu_s->data;
			sint32 res = 0;
			procSMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xC:{
			// Instruction: smod r32:regm, imms8:MV
			cpuFetchMV8();
			sint32 v1 = cpuReadReg32(cpu_s->os_regm);
			sint32 v2 = (sint32)u8ToInt(cpu_s->code);
			sint32 res = 0;
			procSMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xD:{
			// Instruction: smod r32:regm, imms16:MV
			cpuFetchMV16();
			sint32 v1 = cpuReadReg32(cpu_s->os_regm);
			sint32 v2 = (sint32)u16ToInt(cpu_s->code);
			sint32 res = 0;
			procSMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xE:{
			// Instruction: smod r32:regm, mems8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			sint32 v1 = cpuReadReg32(cpu_s->os_regm);
			sint32 v2 = (sint32)u8ToInt(cpu_s->data);
			sint32 res = 0;
			procSMod32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xF:{
			// Instruction: smod r32:regm, mems16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			sint32 v1 = cpuReadReg32(cpu_s->os_regm);
			sint32 v2 = (sint32)u16ToInt(cpu_s->data);
			sint32 res = 0;
			procSMod32(v1, v2, res);
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

cpuInterr procA8(Cpu *cpu_s){
	// Instruction: cmp r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s->os_regm);
	uint32 v2 = cpuReadReg8(cpu_s->os_rego);
	uint32 res = 0;
	procSub8(v1, v2, res);
	return 0;
}

cpuInterr procA9(Cpu *cpu_s){
	// Instruction: cmp r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s->os_regm);
	uint32 v2 = cpuReadReg16(cpu_s->os_rego);
	uint32 res = 0;
	procSub16(v1, v2, res);
	return 0;
}

cpuInterr procAA(Cpu *cpu_s){
	// Instruction: cmp r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s->os_regm);
	uint32 v2 = cpuReadReg32(cpu_s->os_rego);
	uint32 res = 0;
	procSub32(v1, v2, res);
	return 0;
}

cpuInterr procAB(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0:{
			// Instruction: cmp r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub8(v1, v2, res);
		}
		break;
		case 0x1:{
			// Instruction: cmp r16:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub16(v1, v2, res);
		}
		break;
		case 0x2:{
			// Instruction: cmp r32:regm, imm32:MV
			cpuFetchMV32();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub32(v1, v2, res);
		}
		break;
		case 0x3:{
			// Instruction: cmp r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub8(v1, v2, res);
		}
		break;
		case 0x4:{
			// Instruction: cmp r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub16(v1, v2, res);
		}
		break;
		case 0x5:{
			// Instruction: cmp r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub32(v1, v2, res);
		}
		break;
		case 0x6:{
			// Instruction: cmp r16:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub16(v1, v2, res);
		}
		break;
		case 0x7:{
			// Instruction: cmp r32:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub32(v1, v2, res);
		}
		break;
		case 0x8:{
			// Instruction: cmp r32:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub32(v1, v2, res);
		}
		break;
		case 0x9:{
			// Instruction: cmp r16:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub16(v1, v2, res);
		}
		break;
		case 0xA:{
			// Instruction: cmp r32:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub32(v1, v2, res);
		}
		break;
		case 0xB:{
			// Instruction: cmp r32:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub32(v1, v2, res);
		}
		break;
		case 0xC:{
			// Instruction: cmp r32:regm, imms8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->code);
			uint32 res = 0;
			procSub32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xD:{
			// Instruction: cmp r32:regm, imms16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->code);
			uint32 res = 0;
			procSub32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xE:{
			// Instruction: cmp r32:regm, mems8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->data);
			uint32 res = 0;
			procSub32(v1, v2, res);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xF:{
			// Instruction: cmp r32:regm, mems16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->data);
			uint32 res = 0;
			procSub32(v1, v2, res);
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

