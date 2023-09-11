#include "procedures.h"


#define procIn(adr, size, dest) {}
#define procOut(adr, size, src) {}

cpuInterr procF0(){
	// Instruction: in r8:regm, r16:rego
	cpuFetchOS();
	uint16 adr = cpuReadReg16(cpu_s.os_rego);
	uint8 data = 0;
	procIn(adr, 1, data);
	cpuWriteReg8(cpu_s.os_regm, data);
	return 0;
}

cpuInterr procF1(){
	// Instruction: in r16:regm, r16:rego
	cpuFetchOS();
	uint16 adr = cpuReadReg16(cpu_s.os_rego);
	uint16 data = 0;
	procIn(adr, 2, data);
	cpuWriteReg16(cpu_s.os_regm, data);
	return 0;
}

cpuInterr procF2(){
	// Instruction: in r32:regm, r16:rego
	cpuFetchOS();
	uint16 adr = cpuReadReg16(cpu_s.os_rego);
	uint32 data = 0;
	procIn(adr, 4, data);
	cpuWriteReg32(cpu_s.os_regm, data);
	return 0;
}

cpuInterr procF3(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0: {
			// Instruction: in r8:regm, imm8:MV
			cpuFetchMV8();
			uint16 adr = cpu_s.mv;
			uint8 data = 0;
			procIn(adr, 1, data);
			cpuWriteReg8(cpu_s.os_regm, data);
		}
		break;
		case 0x1: {
			// Instruction: in r16:regm, imm8:MV
			cpuFetchMV8();
			uint16 adr = cpu_s.mv;
			uint16 data = 0;
			procIn(adr, 2, data);
			cpuWriteReg16(cpu_s.os_regm, data);
		}
		break;
		case 0x2: {
			// Instruction: in r32:regm, imm8:MV
			cpuFetchMV8();
			uint16 adr = cpu_s.mv;
			uint32 data = 0;
			procIn(adr, 4, data);
			cpuWriteReg32(cpu_s.os_regm, data);
		}
		break;
		case 0x3: {
			// Instruction: in r8:regm, imm16:MV
			cpuFetchMV16();
			uint16 adr = cpu_s.mv;
			uint8 data = 0;
			procIn(adr, 1, data);
			cpuWriteReg8(cpu_s.os_regm, data);
		}
		break;
		case 0x4: {
			// Instruction: in r16:regm, imm16:MV
			cpuFetchMV16();
			uint16 adr = cpu_s.mv;
			uint16 data = 0;
			procIn(adr, 2, data);
			cpuWriteReg16(cpu_s.os_regm, data);
		}
		break;
		case 0x5: {
			// Instruction: in r32:regm, imm16:MV
			cpuFetchMV16();
			uint16 adr = cpu_s.mv;
			uint32 data = 0;
			procIn(adr, 4, data);
			cpuWriteReg32(cpu_s.os_regm, data);
		}
		break;
	}
	return 0;
}

cpuInterr procF4(){
	// Instruction: out r16:regm, r8:rego
	cpuFetchOS();
	uint16 adr = cpuReadReg16(cpu_s.os_regm);
	uint8 data = cpuReadReg8(cpu_s.os_rego);
	procOut(adr, 1, data);
	return 0;
}

cpuInterr procF5(){
	// Instruction: out r16:regm, r16:rego
	cpuFetchOS();
	uint16 adr = cpuReadReg16(cpu_s.os_regm);
	uint16 data = cpuReadReg16(cpu_s.os_rego);
	procOut(adr, 2, data);
	return 0;
}

cpuInterr procF6(){
	// Instruction: out r16:regm, r32:rego
	cpuFetchOS();
	uint16 adr = cpuReadReg16(cpu_s.os_regm);
	uint32 data = cpuReadReg32(cpu_s.os_rego);
	procOut(adr, 4, data);
	return 0;
}

cpuInterr procF7(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0: {
			// Instruction: out imm8:MV, r8:rego
			cpuFetchMV8();
			uint16 adr = cpu_s.mv;
			uint8 data = cpuReadReg8(cpu_s.os_rego);
			procOut(adr, 1, data);
		}
		break;
		case 0x1: {
			// Instruction: out imm8:MV, r16:rego
			cpuFetchMV8();
			uint16 adr = cpu_s.mv;
			uint16 data = cpuReadReg16(cpu_s.os_rego);
			procOut(adr, 2, data);
		}
		break;
		case 0x2: {
			// Instruction: out imm8:MV, r16:rego
			cpuFetchMV8();
			uint16 adr = cpu_s.mv;
			uint32 data = cpuReadReg32(cpu_s.os_rego);
			procOut(adr, 4, data);
		}
		break;
		case 0x3: {
			// Instruction: out imm16:MV, r8:rego
			cpuFetchMV16();
			uint16 adr = cpu_s.mv;
			uint8 data = cpuReadReg8(cpu_s.os_rego);
			procOut(adr, 1, data);
		}
		break;
		case 0x4: {
			// Instruction: out imm16:MV, r16:rego
			cpuFetchMV16();
			uint16 adr = cpu_s.mv;
			uint16 data = cpuReadReg16(cpu_s.os_rego);
			procOut(adr, 2, data);
		}
		break;
		case 0x5: {
			// Instruction: out imm16:MV, r32:rego
			cpuFetchMV16();
			uint16 adr = cpu_s.mv;
			uint32 data = cpuReadReg32(cpu_s.os_rego);
			procOut(adr, 4, data);
		}
		break;
	}
	return 0;
}

cpuInterr procF8(){
	// Instruction: halt
	procEnsureNotInProtectedMode();
	cpu_s.halted = true;
	return 0;
}

cpuInterr procF9(){
	// Instruction: wait
	procEnsureNotInProtectedMode();
	cpu_s.waiting = true;
	return 0;
}

cpuInterr procFA(){
	// Instruction: stop
	procEnsureNotInProtectedMode();
	// TODO
	return 0;
}

cpuInterr procFB(){
	cpu_s.prefix = true;
	cpu_s.seg_data = &cpu_s.sregs[SREG_AS];
	return 0;
}

cpuInterr procFC(){
	cpu_s.prefix = true;
	cpu_s.seg_data = &cpu_s.sregs[SREG_BS];
	return 0;
}

cpuInterr procFD(){
	cpu_s.prefix = true;
	cpu_s.seg_data = &cpu_s.sregs[SREG_ES];
	return 0;
}

cpuInterr procFE(){
	cpu_s.prefix = true;
	cpu_s.seg_data = &cpu_s.sregs[SREG_FS];
	return 0;
}

cpuInterr procFF(){
	cpu_s.prefix = true;
	cpu_s.seg_data = &cpu_s.sregs[SREG_GS];
	return 0;
}

