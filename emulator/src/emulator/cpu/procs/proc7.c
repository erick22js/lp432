#include "procedures.h"


cpuInterr proc70(){
	// Instruction: mov r8:regm, r8:rego
	cpuFetchOS();
	cpuWriteReg8(cpu_s.os_regm, cpuReadReg8(cpu_s.os_rego));
	return 0;
}

cpuInterr proc71(){
	// Instruction: mov r16:regm, r16:rego
	cpuFetchOS();
	cpuWriteReg16(cpu_s.os_regm, cpuReadReg16(cpu_s.os_rego));
	return 0;
}

cpuInterr proc72(){
	// Instruction: mov r32:regm, r32:rego
	cpuFetchOS();
	cpuWriteReg32(cpu_s.os_regm, cpuReadReg32(cpu_s.os_rego));
	return 0;
}

cpuInterr proc73(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0:{
			// Instruction: mov r8:regm, imm8:MV
			cpuFetchMV8();
			cpuWriteReg8(cpu_s.os_regm, cpu_s.code);
		}
		break;
		case 0x1:{
			// Instruction: mov r16:regm, imm16:MV
			cpuFetchMV16();
			cpuWriteReg16(cpu_s.os_regm, cpu_s.code);
		}
		break;
		case 0x2:{
			// Instruction: mov r32:regm, imm32:MV
			cpuFetchMV32();
			cpuWriteReg32(cpu_s.os_regm, cpu_s.code);
		}
		break;
		case 0x3:{
			// Instruction: mov r8:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			cpuWriteReg8(cpu_s.os_regm, cpu_s.data);
		}
		break;
		case 0x4:{
			// Instruction: mov r16:regm, mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s.mem_adr);
			cpuWriteReg16(cpu_s.os_regm, cpu_s.data);
		}
		break;
		case 0x5:{
			// Instruction: mov r32:regm, mem8
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s.mem_adr);
			cpuWriteReg32(cpu_s.os_regm, cpu_s.data);
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr proc74(){
	// Instruction: mov mem8, imm8:MV
	cpuFetchMemIndex();
	cpuFetchMV8();
	cpuWriteMem8(cpu_s.mem_adr, cpu_s.code);
	return 0;
}

cpuInterr proc75(){
	// Instruction: mov mem16, imm16:MV
	cpuFetchMemIndex();
	cpuFetchMV16();
	cpuWriteMem16(cpu_s.mem_adr, cpu_s.code);
	return 0;
}

cpuInterr proc76(){
	// Instruction: mov mem32, imm32:MV
	cpuFetchMemIndex();
	cpuFetchMV32();
	cpuWriteMem32(cpu_s.mem_adr, cpu_s.code);
	return 0;
}

cpuInterr proc77(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0:{
			// Instruction: mov mem8, r8:regm
			cpuFetchMemIndex();
			cpuWriteMem8(cpu_s.mem_adr, cpuReadReg8(cpu_s.os_regm));
		}
		break;
		case 0x1:{
			// Instruction: mov mem16, r16:regm
			cpuFetchMemIndex();
			cpuWriteMem16(cpu_s.mem_adr, cpuReadReg16(cpu_s.os_regm));
		}
		break;
		case 0x2:{
			// Instruction: mov mem32, r32:regm
			cpuFetchMemIndex();
			cpuWriteMem32(cpu_s.mem_adr, cpuReadReg32(cpu_s.os_regm));
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr proc78(){
	// Instruction: xchg r8:regm, r8:rego
	cpuFetchOS();
	uint8 temp = cpuReadReg8(cpu_s.os_regm);
	cpuWriteReg8(cpu_s.os_regm, cpuReadReg8(cpu_s.os_rego));
	cpuWriteReg8(cpu_s.os_rego, temp);
	return 0;
}

cpuInterr proc79(){
	// Instruction: xchg r16:regm, r16:rego
	cpuFetchOS();
	uint16 temp = cpuReadReg16(cpu_s.os_regm);
	cpuWriteReg16(cpu_s.os_regm, cpuReadReg16(cpu_s.os_rego));
	cpuWriteReg16(cpu_s.os_rego, temp);
	return 0;
}

cpuInterr proc7A(){
	// Instruction: xchg r32:regm, r32:rego
	cpuFetchOS();
	uint32 temp = cpuReadReg32(cpu_s.os_regm);
	cpuWriteReg32(cpu_s.os_regm, cpuReadReg32(cpu_s.os_rego));
	cpuWriteReg32(cpu_s.os_rego, temp);
	return 0;
}

cpuInterr proc7B(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0:{
			// Instruction: xchg mem8, r8:regm
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			uint8 data = cpu_s.data;
			cpuWriteMem8(cpu_s.mem_adr, cpuReadReg8(cpu_s.os_regm));
			cpuWriteReg8(cpu_s.os_regm, data);
		}
		break;
		case 0x1:{
			// Instruction: xchg mem16, r16:regm
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s.mem_adr);
			uint16 data = cpu_s.data;
			cpuWriteMem16(cpu_s.mem_adr, cpuReadReg16(cpu_s.os_regm));
			cpuWriteReg16(cpu_s.os_regm, data);
		}
		break;
		case 0x2:{
			// Instruction: xchg mem32, r32:regm
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s.mem_adr);
			uint32 data = cpu_s.data;
			cpuWriteMem32(cpu_s.mem_adr, cpuReadReg32(cpu_s.os_regm));
			cpuWriteReg32(cpu_s.os_regm, data);
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

