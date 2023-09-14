#include "procedures.h"


#define procMul(v1, v2, res, sign) {\
	res = v1 * v2;\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_ZF, res==0);/* Zero Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_NF, res&sign);/* Negative Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_OF, res&1);/* Odd Flag Affecting */\
}
#define procMul8(v1, v2, res) procMul(v1, v2, res, 0x80)
#define procMul16(v1, v2, res) procMul(v1, v2, res, 0x8000)
#define procMul32(v1, v2, res) procMul(v1, v2, res, 0x80000000)

#define procMul64(v1, v2, res) {\
	res = v1 * v2;\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_ZF, res==0);/* Zero Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_NF, res&0x8000000000000000);/* Negative Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_OF, res&1);/* Odd Flag Affecting */\
}

#define procDiv(v1, v2, res, sign) {\
	if (v2==0){\
		cpuThrowInterruption(INTR_DIVISION_BY_ZERO);\
	}\
	res = v1 / v2;\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_ZF, res==0);/* Zero Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_NF, res&sign);/* Negative Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_OF, res&1);/* Odd Flag Affecting */\
}
#define procDiv8(v1, v2, res) procDiv(v1, v2, res, 0x80)
#define procDiv16(v1, v2, res) procDiv(v1, v2, res, 0x8000)
#define procDiv32(v1, v2, res) procDiv(v1, v2, res, 0x80000000)

cpuInterr proc90(){
	// Instruction: mul r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s.os_regm);
	uint32 v2 = cpuReadReg8(cpu_s.os_rego);
	uint32 res = 0;
	procMul8(v1, v2, res);
	cpuWriteReg8(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc91(){
	// Instruction: mul r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s.os_regm);
	uint32 v2 = cpuReadReg16(cpu_s.os_rego);
	uint32 res = 0;
	procMul16(v1, v2, res);
	cpuWriteReg16(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc92(){
	// Instruction: mul r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s.os_regm);
	uint32 v2 = cpuReadReg32(cpu_s.os_rego);
	uint32 res = 0;
	procMul32(v1, v2, res);
	cpuWriteReg32(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc93(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0:{
			// Instruction: mul r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procMul8(v1, v2, res);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: mul r16:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procMul16(v1, v2, res);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: mul r32:regm, imm32:MV
			cpuFetchMV32();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procMul32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: mul r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procMul8(v1, v2, res);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: mul r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procMul16(v1, v2, res);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: mul r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procMul32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0x6:{
			// Instruction: mul r16:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procMul16(v1, v2, res);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x7:{
			// Instruction: mul r32:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procMul32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0x8:{
			// Instruction: mul r32:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procMul32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0x9:{
			// Instruction: mul r16:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procMul16(v1, v2, res);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0xA:{
			// Instruction: mul r32:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procMul32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0xB:{
			// Instruction: mul r32:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procMul32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0xC:{
			// Instruction: mul r32:regm, imms8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s.code);
			uint32 res = 0;
			procMul32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0xD:{
			// Instruction: mul r32:regm, imms16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s.code);
			uint32 res = 0;
			procMul32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0xE:{
			// Instruction: mul r32:regm, mems8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s.data);
			uint32 res = 0;
			procMul32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0xF:{
			// Instruction: mul r32:regm, mems16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s.data);
			uint32 res = 0;
			procMul32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr proc94(){
	// Instruction: hmul r32:regm1, r32:rego1, r32:regm2
	uint8 destl = cpu_s.os_regm;
	uint8 desth = cpu_s.os_rego;
	cpuFetchOS();
	uint64 v1 = cpuReadReg32(destl);
	uint64 v2 = cpuReadReg32(cpu_s.os_regm);
	uint64 res = 0;
	procMul64(v1, v2, res);
	cpuWriteReg32(destl, res&0xFFFFFFFF);
	cpuWriteReg32(desth, (res>>32)&0xFFFFFFFF);
	return 0;
}

cpuInterr proc95(){
	// Instruction: hmul r32:regm, r32:rego, mem32
	uint8 destl = cpu_s.os_regm;
	uint8 desth = cpu_s.os_rego;
	uint64 v1 = cpuReadReg32(cpu_s.os_regm);
	cpuFetchMemIndex();
	cpuReadMem32(cpu_s.mem_adr);
	uint64 v2 = cpu_s.data;
	uint64 res = 0;
	procMul64(v1, v2, res);
	cpuWriteReg32(cpu_s.os_regm, res&0xFFFFFFFF);
	cpuWriteReg32(cpu_s.os_rego, (res>>32)&0xFFFFFFFF);
	return 0;
}

cpuInterr proc96(){
	// Instruction: hsmul r32:regm1, r32:rego1, r32:regm2
	uint8 destl = cpu_s.os_regm;
	uint8 desth = cpu_s.os_rego;
	cpuFetchOS();
	sint64 v1 = (sint64)u32ToInt(cpuReadReg32(destl));
	sint64 v2 = (sint64)u32ToInt(cpuReadReg32(cpu_s.os_regm));
	sint64 res = 0;
	procMul64(v1, v2, res);
	cpuWriteReg32(destl, res&0xFFFFFFFF);
	cpuWriteReg32(desth, (res>>32)&0xFFFFFFFF);
	return 0;
}

cpuInterr proc97(){
	// Instruction: hsmul r32:regm, r32:rego, mem32
	uint8 destl = cpu_s.os_regm;
	uint8 desth = cpu_s.os_rego;
	sint64 v1 = (sint64)u32ToInt(cpuReadReg32(cpu_s.os_regm));
	cpuFetchMemIndex();
	cpuReadMem32(cpu_s.mem_adr);
	sint64 v2 = (sint64)u32ToInt(cpu_s.data);
	sint64 res = 0;
	procMul64(v1, v2, res);
	cpuWriteReg32(cpu_s.os_regm, res&0xFFFFFFFF);
	cpuWriteReg32(cpu_s.os_rego, (res>>32)&0xFFFFFFFF);
	return 0;
}

cpuInterr proc9C(){
	// Instruction: div r8:regm, r8:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg8(cpu_s.os_regm);
	uint32 v2 = cpuReadReg8(cpu_s.os_rego);
	uint32 res = 0;
	procDiv8(v1, v2, res);
	cpuWriteReg8(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc9D(){
	// Instruction: div r16:regm, r16:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg16(cpu_s.os_regm);
	uint32 v2 = cpuReadReg16(cpu_s.os_rego);
	uint32 res = 0;
	procDiv16(v1, v2, res);
	cpuWriteReg16(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc9E(){
	// Instruction: div r32:regm, r32:rego
	cpuFetchOS();
	uint32 v1 = cpuReadReg32(cpu_s.os_regm);
	uint32 v2 = cpuReadReg32(cpu_s.os_rego);
	uint32 res = 0;
	procDiv32(v1, v2, res);
	cpuWriteReg32(cpu_s.os_regm, res);
	return 0;
}

cpuInterr proc9F(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0:{
			// Instruction: div r8:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procDiv8(v1, v2, res);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x1:{
			// Instruction: div r16:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procDiv16(v1, v2, res);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x2:{
			// Instruction: div r32:regm, imm32:MV
			cpuFetchMV32();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procDiv32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0x3:{
			// Instruction: div r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg8(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procDiv8(v1, v2, res);
			cpuWriteReg8(cpu_s.os_regm, res);
		}
		break;
		case 0x4:{
			// Instruction: div r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procDiv16(v1, v2, res);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x5:{
			// Instruction: div r32:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procDiv32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0x6:{
			// Instruction: div r16:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procDiv16(v1, v2, res);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0x7:{
			// Instruction: div r32:regm, imm8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procDiv32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0x8:{
			// Instruction: div r32:regm, imm16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.code;
			uint32 res = 0;
			procDiv32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0x9:{
			// Instruction: div r16:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg16(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procDiv16(v1, v2, res);
			cpuWriteReg16(cpu_s.os_regm, res);
		}
		break;
		case 0xA:{
			// Instruction: div r32:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procDiv32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0xB:{
			// Instruction: div r32:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = cpu_s.data;
			uint32 res = 0;
			procDiv32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0xC:{
			// Instruction: div r32:regm, imms8:MV
			cpuFetchMV8();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s.code);
			uint32 res = 0;
			procDiv32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0xD:{
			// Instruction: div r32:regm, imms16:MV
			cpuFetchMV16();
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s.code);
			uint32 res = 0;
			procDiv32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0xE:{
			// Instruction: div r32:regm, mems8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = (sint32)u8ToInt(cpu_s.data);
			uint32 res = 0;
			procDiv32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		case 0xF:{
			// Instruction: div r32:regm, mems16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s.mem_adr);
			uint32 v1 = cpuReadReg32(cpu_s.os_regm);
			uint32 v2 = (sint32)u16ToInt(cpu_s.data);
			uint32 res = 0;
			procDiv32(v1, v2, res);
			cpuWriteReg32(cpu_s.os_regm, res);
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

