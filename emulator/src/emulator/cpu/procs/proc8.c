#include "procedures.h"


#define procAdd(v1, v2, res, wcarry) {\
	res = v1 + v2 + (cpu_s.reg_st&FLAG_CF && wcarry? 1: 0);\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_CF, res<v1);/* Carry Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_VF, ((v1&0x80000000)==(v2&0x80000000) && (v1&0x80000000)!=(res&0x80000000)));/* Overflow Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_ZF, res==0);/* Zero Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_NF, res&0x80000000);/* Negative Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_OF, res&1);/* Odd Flag Affecting */\
}

#define procSub(v1, v2, res, wborrow) {\
	res = v1 - v2 - (cpu_s.reg_st&FLAG_BF && wborrow? 1: 0);\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_BF, res>v1);/* Borrow Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_VF, ((v1&0x80000000)!=(v2&0x80000000) && (v2&0x80000000)==(res&0x80000000)));/* Overflow Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_ZF, res==0);/* Zero Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_NF, res&0x80000000);/* Negative Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_OF, res&1);/* Odd Flag Affecting */\
}

cpuInterr proc80(){
	// Instruction: adc r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s.os_regm);
	uint32 v2 = cpuReadReg8(cpu_s.os_rego);
	uint32 res = 0;
	procAdd(v1, v2, res, true);
	cpuWriteReg8(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc81(){
	// Instruction: adc r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s.os_regm);
	uint32 v2 = cpuReadReg16(cpu_s.os_rego);
	uint32 res = 0;
	procAdd(v1, v2, res, true);
	cpuWriteReg16(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc82(){
	// Instruction: adc r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s.os_regm);
	uint32 v2 = cpuReadReg32(cpu_s.os_rego);
	uint32 res = 0;
	procAdd(v1, v2, res, true);
	cpuWriteReg32(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc83(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0:{
			// Instruction: adc r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procAdd(v1, v2, res, true);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: adc r16:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procAdd(v1, v2, res, true);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: adc r32:regm, imm32:MV
			cpuFetchMV32();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procAdd(v1, v2, res, true);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: adc r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procAdd(v1, v2, res, true);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: adc r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procAdd(v1, v2, res, true);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: adc r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procAdd(v1, v2, res, true);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr proc84(){
	// Instruction: add r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s.os_regm);
	uint32 v2 = cpuReadReg8(cpu_s.os_rego);
	uint32 res = 0;
	procAdd(v1, v2, res, false);
	cpuWriteReg8(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc85(){
	// Instruction: add r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s.os_regm);
	uint32 v2 = cpuReadReg16(cpu_s.os_rego);
	uint32 res = 0;
	procAdd(v1, v2, res, false);
	cpuWriteReg16(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc86(){
	// Instruction: add r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s.os_regm);
	uint32 v2 = cpuReadReg32(cpu_s.os_rego);
	uint32 res = 0;
	procAdd(v1, v2, res, false);
	cpuWriteReg32(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc87(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0:{
			// Instruction: add r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procAdd(v1, v2, res, false);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: add r16:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procAdd(v1, v2, res, false);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: add r32:regm, imm32:MV
			cpuFetchMV32();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procAdd(v1, v2, res, false);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: add r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procAdd(v1, v2, res, false);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: add r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procAdd(v1, v2, res, false);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: add r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procAdd(v1, v2, res, false);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr proc88(){
	// Instruction: sbb r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s.os_regm);
	uint32 v2 = cpuReadReg8(cpu_s.os_rego);
	uint32 res = 0;
	procSub(v1, v2, res, true);
	cpuWriteReg8(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc89(){
	// Instruction: sbb r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s.os_regm);
	uint32 v2 = cpuReadReg16(cpu_s.os_rego);
	uint32 res = 0;
	procSub(v1, v2, res, true);
	cpuWriteReg16(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc8A(){
	// Instruction: sbb r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s.os_regm);
	uint32 v2 = cpuReadReg32(cpu_s.os_rego);
	uint32 res = 0;
	procSub(v1, v2, res, true);
	cpuWriteReg32(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc8B(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0:{
			// Instruction: sbb r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procSub(v1, v2, res, true);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: sbb r16:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procSub(v1, v2, res, true);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: sbb r32:regm, imm32:MV
			cpuFetchMV32();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procSub(v1, v2, res, true);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: sbb r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procSub(v1, v2, res, true);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: sbb r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procSub(v1, v2, res, true);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: sbb r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procSub(v1, v2, res, true);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr proc8C(){
	// Instruction: sub r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s.os_regm);
	uint32 v2 = cpuReadReg8(cpu_s.os_rego);
	uint32 res = 0;
	procSub(v1, v2, res, false);
	cpuWriteReg8(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc8D(){
	// Instruction: sub r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s.os_regm);
	uint32 v2 = cpuReadReg16(cpu_s.os_rego);
	uint32 res = 0;
	procSub(v1, v2, res, false);
	cpuWriteReg16(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc8E(){
	// Instruction: sub r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s.os_regm);
	uint32 v2 = cpuReadReg32(cpu_s.os_rego);
	uint32 res = 0;
	procSub(v1, v2, res, false);
	cpuWriteReg32(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc8F(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0:{
			// Instruction: sub r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procSub(v1, v2, res, false);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: sub r16:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procSub(v1, v2, res, false);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: sub r32:regm, imm32:MV
			cpuFetchMV32();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procSub(v1, v2, res, false);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: sub r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procSub(v1, v2, res, false);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: sub r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procSub(v1, v2, res, false);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: sub r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procSub(v1, v2, res, false);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

