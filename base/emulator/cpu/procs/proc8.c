#include "procedures.h"


#define procAdd(v1, v2, res, wcarry, sign, type) {\
	res = v1 + v2 + (cpu_s->reg_st&FLAG_CF && wcarry? 1: 0);\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_CF, ((type)res)<((type)v1));/* Carry Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_VF, ((v1&sign)==(v2&sign) && (v1&sign)!=(res&sign)));/* Overflow Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_ZF, ((type)res)==0);/* Zero Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_NF, res&sign);/* Negative Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_OF, res&1);/* Odd Flag Affecting */\
}
#define procAdd8(v1, v2, res, wcarry) procAdd(v1, v2, res, wcarry, 0x80, uint8)
#define procAdd16(v1, v2, res, wcarry) procAdd(v1, v2, res, wcarry, 0x8000, uint16)
#define procAdd32(v1, v2, res, wcarry) procAdd(v1, v2, res, wcarry, 0x80000000, uint32)

#define procSub(v1, v2, res, wborrow, sign, type) {\
	res = v1 - v2 - (cpu_s->reg_st&FLAG_BF && wborrow? 1: 0);\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_BF, ((type)res)>((type)v1));/* Borrow Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_VF, ((v1&sign)!=(v2&sign) && (v2&sign)==(res&sign)));/* Overflow Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_ZF, ((type)res)==0);/* Zero Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_NF, res&sign);/* Negative Flag Affecting */\
	cpu_s->reg_st = setBit(cpu_s->reg_st, FLAG_OF, res&1);/* Odd Flag Affecting */\
}
#define procSub8(v1, v2, res, wborrow) procSub(v1, v2, res, wborrow, 0x80, uint8)
#define procSub16(v1, v2, res, wborrow) procSub(v1, v2, res, wborrow, 0x8000, uint16)
#define procSub32(v1, v2, res, wborrow) procSub(v1, v2, res, wborrow, 0x80000000, uint32)

cpuInterr proc80(Cpu *cpu_s){
	// Instruction: adc r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s->os_regm);
	uint32 v2 = cpuReadReg8(cpu_s->os_rego);
	uint32 res = 0;
	procAdd8(v1, v2, res, true);
	cpuWriteReg8(cpu_s->os_regm, res);
	return 0;
}

cpuInterr proc81(Cpu *cpu_s){
	// Instruction: adc r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s->os_regm);
	uint32 v2 = cpuReadReg16(cpu_s->os_rego);
	uint32 res = 0;
	procAdd16(v1, v2, res, true);
	cpuWriteReg16(cpu_s->os_regm, res);
	return 0;
}

cpuInterr proc82(Cpu *cpu_s){
	// Instruction: adc r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s->os_regm);
	uint32 v2 = cpuReadReg32(cpu_s->os_rego);
	uint32 res = 0;
	procAdd32(v1, v2, res, true);
	cpuWriteReg32(cpu_s->os_regm, res);
	return 0;
}

cpuInterr proc83(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0:{
			// Instruction: adc r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAdd8(v1, v2, res, true);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: adc r16:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAdd16(v1, v2, res, true);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: adc r32:regm, imm32:MV
			cpuFetchMV32();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAdd32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: adc r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAdd8(v1, v2, res, true);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: adc r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAdd16(v1, v2, res, true);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: adc r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAdd32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x6:{
			// Instruction: adc r16:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAdd16(v1, v2, res, true);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x7:{
			// Instruction: adc r32:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAdd32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x8:{
			// Instruction: adc r32:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAdd32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x9:{
			// Instruction: adc r16:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAdd16(v1, v2, res, true);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0xA:{
			// Instruction: adc r32:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAdd32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xB:{
			// Instruction: adc r32:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAdd32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xC:{
			// Instruction: adc r32:regm, imms8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->code);
			uint32 res = 0;
			procAdd32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xD:{
			// Instruction: adc r32:regm, imms16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->code);
			uint32 res = 0;
			procAdd32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xE:{
			// Instruction: adc r32:regm, mems8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->data);
			uint32 res = 0;
			procAdd32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xF:{
			// Instruction: adc r32:regm, mems16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->data);
			uint32 res = 0;
			procAdd32(v1, v2, res, true);
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

cpuInterr proc84(Cpu *cpu_s){
	// Instruction: add r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s->os_regm);
	uint32 v2 = cpuReadReg8(cpu_s->os_rego);
	uint32 res = 0;
	procAdd8(v1, v2, res, false);
	cpuWriteReg8(cpu_s->os_regm, res);
	return 0;
}

cpuInterr proc85(Cpu *cpu_s){
	// Instruction: add r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s->os_regm);
	uint32 v2 = cpuReadReg16(cpu_s->os_rego);
	uint32 res = 0;
	procAdd16(v1, v2, res, false);
	cpuWriteReg16(cpu_s->os_regm, res);
	return 0;
}

cpuInterr proc86(Cpu *cpu_s){
	// Instruction: add r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s->os_regm);
	uint32 v2 = cpuReadReg32(cpu_s->os_rego);
	uint32 res = 0;
	procAdd32(v1, v2, res, false);
	cpuWriteReg32(cpu_s->os_regm, res);
	return 0;
}

cpuInterr proc87(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0:{
			// Instruction: add r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAdd8(v1, v2, res, false);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: add r16:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAdd16(v1, v2, res, false);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: add r32:regm, imm32:MV
			cpuFetchMV32();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAdd32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: add r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAdd8(v1, v2, res, false);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: add r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAdd16(v1, v2, res, false);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: add r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAdd32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x6:{
			// Instruction: add r16:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAdd16(v1, v2, res, false);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x7:{
			// Instruction: add r32:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAdd32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x8:{
			// Instruction: add r32:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procAdd32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x9:{
			// Instruction: add r16:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAdd16(v1, v2, res, false);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0xA:{
			// Instruction: add r32:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAdd32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xB:{
			// Instruction: add r32:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procAdd32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xC:{
			// Instruction: add r32:regm, imms8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->code);
			uint32 res = 0;
			procAdd32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xD:{
			// Instruction: add r32:regm, imms16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->code);
			uint32 res = 0;
			procAdd32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xE:{
			// Instruction: add r32:regm, mems8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->data);
			uint32 res = 0;
			procAdd32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xF:{
			// Instruction: add r32:regm, mems16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->data);
			uint32 res = 0;
			procAdd32(v1, v2, res, false);
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

cpuInterr proc88(Cpu *cpu_s){
	// Instruction: sbb r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s->os_regm);
	uint32 v2 = cpuReadReg8(cpu_s->os_rego);
	uint32 res = 0;
	procSub8(v1, v2, res, true);
	cpuWriteReg8(cpu_s->os_regm, res);
	return 0;
}

cpuInterr proc89(Cpu *cpu_s){
	// Instruction: sbb r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s->os_regm);
	uint32 v2 = cpuReadReg16(cpu_s->os_rego);
	uint32 res = 0;
	procSub16(v1, v2, res, true);
	cpuWriteReg16(cpu_s->os_regm, res);
	return 0;
}

cpuInterr proc8A(Cpu *cpu_s){
	// Instruction: sbb r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s->os_regm);
	uint32 v2 = cpuReadReg32(cpu_s->os_rego);
	uint32 res = 0;
	procSub32(v1, v2, res, true);
	cpuWriteReg32(cpu_s->os_regm, res);
	return 0;
}

cpuInterr proc8B(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0:{
			// Instruction: sbb r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub8(v1, v2, res, true);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: sbb r16:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub16(v1, v2, res, true);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: sbb r32:regm, imm32:MV
			cpuFetchMV32();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: sbb r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub8(v1, v2, res, true);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: sbb r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub16(v1, v2, res, true);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: sbb r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x6:{
			// Instruction: sbb r16:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub16(v1, v2, res, true);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x7:{
			// Instruction: sbb r32:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x8:{
			// Instruction: sbb r32:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x9:{
			// Instruction: sbb r16:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub16(v1, v2, res, true);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0xA:{
			// Instruction: sbb r32:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xB:{
			// Instruction: sbb r32:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xC:{
			// Instruction: sbb r32:regm, imms8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->code);
			uint32 res = 0;
			procSub32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xD:{
			// Instruction: sbb r32:regm, imms16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->code);
			uint32 res = 0;
			procSub32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xE:{
			// Instruction: sbb r32:regm, mems8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->data);
			uint32 res = 0;
			procSub32(v1, v2, res, true);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xF:{
			// Instruction: sbb r32:regm, mems16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->data);
			uint32 res = 0;
			procSub32(v1, v2, res, true);
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

cpuInterr proc8C(Cpu *cpu_s){
	// Instruction: sub r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s->os_regm);
	uint32 v2 = cpuReadReg8(cpu_s->os_rego);
	uint32 res = 0;
	procSub8(v1, v2, res, false);
	cpuWriteReg8(cpu_s->os_regm, res);
	return 0;
}

cpuInterr proc8D(Cpu *cpu_s){
	// Instruction: sub r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s->os_regm);
	uint32 v2 = cpuReadReg16(cpu_s->os_rego);
	uint32 res = 0;
	procSub16(v1, v2, res, false);
	cpuWriteReg16(cpu_s->os_regm, res);
	return 0;
}

cpuInterr proc8E(Cpu *cpu_s){
	// Instruction: sub r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s->os_regm);
	uint32 v2 = cpuReadReg32(cpu_s->os_rego);
	uint32 res = 0;
	procSub32(v1, v2, res, false);
	cpuWriteReg32(cpu_s->os_regm, res);
	return 0;
}

cpuInterr proc8F(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0:{
			// Instruction: sub r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub8(v1, v2, res, false);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: sub r16:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub16(v1, v2, res, false);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: sub r32:regm, imm32:MV
			cpuFetchMV32();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: sub r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub8(v1, v2, res, false);
			cpuWriteReg8(cpu_s->os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: sub r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub16(v1, v2, res, false);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: sub r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x6:{
			// Instruction: sub r16:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub16(v1, v2, res, false);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0x7:{
			// Instruction: sub r32:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x8:{
			// Instruction: sub r32:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->code;
			uint32 res = 0;
			procSub32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0x9:{
			// Instruction: sub r16:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub16(v1, v2, res, false);
			cpuWriteReg16(cpu_s->os_regm, res);
		}
		break;
		case 0xA:{
			// Instruction: sub r32:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xB:{
			// Instruction: sub r32:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = cpu_s->data;
			uint32 res = 0;
			procSub32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xC:{
			// Instruction: sub r32:regm, imms8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->code);
			uint32 res = 0;
			procSub32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xD:{
			// Instruction: sub r32:regm, imms16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->code);
			uint32 res = 0;
			procSub32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xE:{
			// Instruction: sub r32:regm, mems8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s->data);
			uint32 res = 0;
			procSub32(v1, v2, res, false);
			cpuWriteReg32(cpu_s->os_regm, res);
		}
		break;
		case 0xF:{
			// Instruction: sub r32:regm, mems16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s->os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s->data);
			uint32 res = 0;
			procSub32(v1, v2, res, false);
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

