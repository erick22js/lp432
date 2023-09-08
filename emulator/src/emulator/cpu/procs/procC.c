#include "procedures.h"


#define procLsh(v1, v2, res, sign) {\
	res = v1 << v2;\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_ZF, res==0);/* Zero Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_NF, res&sign);/* Negative Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_OF, res&1);/* Odd Flag Affecting */\
}
#define procLsh8(v1, v2, res) procLsh(v1, v2, res, 0x80)
#define procLsh16(v1, v2, res) procLsh(v1, v2, res, 0x8000)
#define procLsh32(v1, v2, res) procLsh(v1, v2, res, 0x80000000)

#define procRsh(v1, v2, res, sign) {\
	res = v1 >> v2;\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_ZF, res==0);/* Zero Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_NF, res&sign);/* Negative Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_OF, res&1);/* Odd Flag Affecting */\
}
#define procRsh8(v1, v2, res) procRsh(v1, v2, res, 0x80)
#define procRsh16(v1, v2, res) procRsh(v1, v2, res, 0x8000)
#define procRsh32(v1, v2, res) procRsh(v1, v2, res, 0x80000000)

#define procLrot(v1, v2, res, sign, size, mask) {\
	v2 &= mask;\
	res = (v1 << v2) | (v1 >> (size-v2));\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_ZF, res==0);/* Zero Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_NF, res&sign);/* Negative Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_OF, res&1);/* Odd Flag Affecting */\
}
#define procLrot8(v1, v2, res) procLrot(v1, v2, res, 0x80, 8, 0x07)
#define procLrot16(v1, v2, res) procLrot(v1, v2, res, 0x8000, 16, 0x0F)
#define procLrot32(v1, v2, res) procLrot(v1, v2, res, 0x80000000, 32, 0x1F)

#define procRrot(v1, v2, res, sign, size, mask) {\
	v2 &= mask;\
	res = (v1 >> v2) | (v1 << (size-v2));\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_ZF, res==0);/* Zero Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_NF, res&sign);/* Negative Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_OF, res&1);/* Odd Flag Affecting */\
}
#define procRrot8(v1, v2, res) procRrot(v1, v2, res, 0x80, 8, 0x07)
#define procRrot16(v1, v2, res) procRrot(v1, v2, res, 0x8000, 16, 0x0F)
#define procRrot32(v1, v2, res) procRrot(v1, v2, res, 0x80000000, 32, 0x1F)

cpuInterr procC0(){
	// Instruction: lsh r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s.os_regm);
	uint32 v2 = cpuReadReg8(cpu_s.os_rego);
	uint32 res = 0;
	procLsh8(v1, v2, res);
	cpuWriteReg8(cpu_s.os_regm, res);
	return 0;
}

cpuInterr procC1(){
	// Instruction: lsh r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s.os_regm);
	uint32 v2 = cpuReadReg16(cpu_s.os_rego);
	uint32 res = 0;
	procLsh16(v1, v2, res);
	cpuWriteReg16(cpu_s.os_regm, res);
	return 0;
}

cpuInterr procC2(){
	// Instruction: lsh r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s.os_regm);
	uint32 v2 = cpuReadReg32(cpu_s.os_rego);
	uint32 res = 0;
	procLsh32(v1, v2, res);
	cpuWriteReg32(cpu_s.os_regm, res);
	return 0;
}

cpuInterr procC3(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0:{
			// Instruction: lsh r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procLsh8(v1, v2, res);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: lsh r16:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procLsh16(v1, v2, res);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: lsh r32:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procLsh32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: lsh r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procLsh8(v1, v2, res);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: lsh r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procLsh16(v1, v2, res);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: lsh r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procLsh32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr procC4(){
	// Instruction: rsh r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s.os_regm);
	uint32 v2 = cpuReadReg8(cpu_s.os_rego);
	uint32 res = 0;
	procRsh8(v1, v2, res);
	cpuWriteReg8(cpu_s.os_regm, res);
	return 0;
}

cpuInterr procC5(){
	// Instruction: rsh r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s.os_regm);
	uint32 v2 = cpuReadReg16(cpu_s.os_rego);
	uint32 res = 0;
	procRsh16(v1, v2, res);
	cpuWriteReg16(cpu_s.os_regm, res);
	return 0;
}

cpuInterr procC6(){
	// Instruction: rsh r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s.os_regm);
	uint32 v2 = cpuReadReg32(cpu_s.os_rego);
	uint32 res = 0;
	procRsh32(v1, v2, res);
	cpuWriteReg32(cpu_s.os_regm, res);
	return 0;
}

cpuInterr procC7(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0:{
			// Instruction: rsh r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procRsh8(v1, v2, res);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: rsh r16:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procRsh16(v1, v2, res);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: rsh r32:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procRsh32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: rsh r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procRsh8(v1, v2, res);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: rsh r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procRsh16(v1, v2, res);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: rsh r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procRsh32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr procC8(){
	// Instruction: rrot r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s.os_regm);
	uint32 v2 = cpuReadReg8(cpu_s.os_rego);
	uint32 res = 0;
	procRrot8(v1, v2, res);
	cpuWriteReg8(cpu_s.os_regm, res);
	return 0;
}

cpuInterr procC9(){
	// Instruction: rrot r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s.os_regm);
	uint32 v2 = cpuReadReg16(cpu_s.os_rego);
	uint32 res = 0;
	procRrot16(v1, v2, res);
	cpuWriteReg16(cpu_s.os_regm, res);
	return 0;
}

cpuInterr procCA(){
	// Instruction: rrot r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s.os_regm);
	uint32 v2 = cpuReadReg32(cpu_s.os_rego);
	uint32 res = 0;
	procRrot32(v1, v2, res);
	cpuWriteReg32(cpu_s.os_regm, res);
	return 0;
}

cpuInterr procCB(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0:{
			// Instruction: rrot r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procRrot8(v1, v2, res);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: rrot r16:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procRrot16(v1, v2, res);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: rrot r32:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procRrot32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: rrot r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procRrot8(v1, v2, res);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: rrot r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procRrot16(v1, v2, res);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: rrot r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procRrot32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr procCC(){
	// Instruction: lrot r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s.os_regm);
	uint32 v2 = cpuReadReg8(cpu_s.os_rego);
	uint32 res = 0;
	procLrot8(v1, v2, res);
	cpuWriteReg8(cpu_s.os_regm, res);
	return 0;
}

cpuInterr procCD(){
	// Instruction: lrot r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s.os_regm);
	uint32 v2 = cpuReadReg16(cpu_s.os_rego);
	uint32 res = 0;
	procLrot16(v1, v2, res);
	cpuWriteReg16(cpu_s.os_regm, res);
	return 0;
}

cpuInterr procCE(){
	// Instruction: lrot r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s.os_regm);
	uint32 v2 = cpuReadReg32(cpu_s.os_rego);
	uint32 res = 0;
	procLrot32(v1, v2, res);
	cpuWriteReg32(cpu_s.os_regm, res);
	return 0;
}

cpuInterr procCF(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0:{
			// Instruction: lrot r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procLrot8(v1, v2, res);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: lrot r16:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procLrot16(v1, v2, res);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: lrot r32:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procLrot32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: lrot r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procLrot8(v1, v2, res);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: lrot r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procLrot16(v1, v2, res);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: lrot r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procLrot32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}


