#include "procedures.h"
#include "../../pci.h"


#define procIn8(adr, dest) {if (!pciReadDevice8(cpu_s->pci, adr, &dest)) cpuThrowInterruption(INTR_DEVICE_UNAVAILABLE);}
#define procIn16(adr, dest) {if (!pciReadDevice16(cpu_s->pci, adr, &dest)) cpuThrowInterruption(INTR_DEVICE_UNAVAILABLE);}
#define procIn32(adr, dest) {if (!pciReadDevice32(cpu_s->pci, adr, &dest)) cpuThrowInterruption(INTR_DEVICE_UNAVAILABLE);}

#define procOut8(adr, src) {if (!pciWriteDevice8(cpu_s->pci, adr, src)) cpuThrowInterruption(INTR_DEVICE_UNAVAILABLE);}
#define procOut16(adr, src) {if (!pciWriteDevice16(cpu_s->pci, adr, src)) cpuThrowInterruption(INTR_DEVICE_UNAVAILABLE);}
#define procOut32(adr, src) {if (!pciWriteDevice32(cpu_s->pci, adr, src)) cpuThrowInterruption(INTR_DEVICE_UNAVAILABLE);}

#define portWideAdr8To16(adr) ((adr&0x7)|((adr&0xF8)<<5))

cpuInterr procF0(Cpu *cpu_s){
	// Instruction: in r8:regm, r16:rego
	cpuFetchOS();
	uint16 adr = cpuReadReg16(cpu_s->os_rego);
	uint8 data = 0;
	procIn8(adr, data);
	cpuWriteReg8(cpu_s->os_regm, data);
	return 0;
}

cpuInterr procF1(Cpu *cpu_s){
	// Instruction: in r16:regm, r16:rego
	cpuFetchOS();
	uint16 adr = cpuReadReg16(cpu_s->os_rego);
	uint16 data = 0;
	procIn16(adr, data);
	cpuWriteReg16(cpu_s->os_regm, data);
	return 0;
}

cpuInterr procF2(Cpu *cpu_s){
	// Instruction: in r32:regm, r16:rego
	cpuFetchOS();
	uint16 adr = cpuReadReg16(cpu_s->os_rego);
	uint32 data = 0;
	procIn32(adr, data);
	cpuWriteReg32(cpu_s->os_regm, data);
	return 0;
}

cpuInterr procF3(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0: {
			// Instruction: in r8:regm, imm8:MV
			cpuFetchMV8();
			uint16 adr = portWideAdr8To16(cpu_s->mv);
			uint8 data = 0;
			procIn8(adr, data);
			cpuWriteReg8(cpu_s->os_regm, data);
		}
		break;
		case 0x1: {
			// Instruction: in r16:regm, imm8:MV
			cpuFetchMV8();
			uint16 adr = portWideAdr8To16(cpu_s->mv);
			uint16 data = 0;
			procIn16(adr, data);
			cpuWriteReg16(cpu_s->os_regm, data);
		}
		break;
		case 0x2: {
			// Instruction: in r32:regm, imm8:MV
			cpuFetchMV8();
			uint16 adr = portWideAdr8To16(cpu_s->mv);
			uint32 data = 0;
			procIn32(adr, data);
			cpuWriteReg32(cpu_s->os_regm, data);
		}
		break;
		case 0x3: {
			// Instruction: in r8:regm, imm16:MV
			cpuFetchMV16();
			uint16 adr = cpu_s->mv;
			uint8 data = 0;
			procIn8(adr, data);
			cpuWriteReg8(cpu_s->os_regm, data);
		}
		break;
		case 0x4: {
			// Instruction: in r16:regm, imm16:MV
			cpuFetchMV16();
			uint16 adr = cpu_s->mv;
			uint16 data = 0;
			procIn16(adr, data);
			cpuWriteReg16(cpu_s->os_regm, data);
		}
		break;
		case 0x5: {
			// Instruction: in r32:regm, imm16:MV
			cpuFetchMV16();
			uint16 adr = cpu_s->mv;
			uint32 data = 0;
			procIn32(adr, data);
			cpuWriteReg32(cpu_s->os_regm, data);
		}
		break;
	}
	return 0;
}

cpuInterr procF4(Cpu *cpu_s){
	// Instruction: out r16:regm, r8:rego
	cpuFetchOS();
	uint16 adr = cpuReadReg16(cpu_s->os_regm);
	uint8 data = cpuReadReg8(cpu_s->os_rego);
	procOut8(adr, data);
	return 0;
}

cpuInterr procF5(Cpu *cpu_s){
	// Instruction: out r16:regm, r16:rego
	cpuFetchOS();
	uint16 adr = cpuReadReg16(cpu_s->os_regm);
	uint16 data = cpuReadReg16(cpu_s->os_rego);
	procOut16(adr, data);
	return 0;
}

cpuInterr procF6(Cpu *cpu_s){
	// Instruction: out r16:regm, r32:rego
	cpuFetchOS();
	uint16 adr = cpuReadReg16(cpu_s->os_regm);
	uint32 data = cpuReadReg32(cpu_s->os_rego);
	procOut32(adr, data);
	return 0;
}

cpuInterr procF7(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0: {
			// Instruction: out imm8:MV, r8:regm
			cpuFetchMV8();
			uint16 adr = portWideAdr8To16(cpu_s->mv);
			uint8 data = cpuReadReg8(cpu_s->os_regm);
			procOut8(adr, data);
		}
		break;
		case 0x1: {
			// Instruction: out imm8:MV, r16:regm
			cpuFetchMV8();
			uint16 adr = portWideAdr8To16(cpu_s->mv);
			uint16 data = cpuReadReg16(cpu_s->os_regm);
			procOut16(adr, data);
		}
		break;
		case 0x2: {
			// Instruction: out imm8:MV, r32:regm
			cpuFetchMV8();
			uint16 adr = portWideAdr8To16(cpu_s->mv);
			uint32 data = cpuReadReg32(cpu_s->os_regm);
			procOut32(adr, data);
		}
		break;
		case 0x3: {
			// Instruction: out imm16:MV, r8:regm
			cpuFetchMV16();
			uint16 adr = cpu_s->mv;
			uint8 data = cpuReadReg8(cpu_s->os_regm);
			procOut8(adr, data);
		}
		break;
		case 0x4: {
			// Instruction: out imm16:MV, r16:regm
			cpuFetchMV16();
			uint16 adr = cpu_s->mv;
			uint16 data = cpuReadReg16(cpu_s->os_regm);
			procOut16(adr, data);
		}
		break;
		case 0x5: {
			// Instruction: out imm16:MV, r32:regm
			cpuFetchMV16();
			uint16 adr = cpu_s->mv;
			uint32 data = cpuReadReg32(cpu_s->os_regm);
			procOut32(adr, data);
		}
		break;
	}
	return 0;
}

cpuInterr procF8(Cpu *cpu_s){
	// Instruction: halt
	procEnsureNotInProtectedMode();
	cpu_s->halted = true;
	return 0;
}

cpuInterr procF9(Cpu *cpu_s){
	// Instruction: wait
	procEnsureNotInProtectedMode();
	if (cpu_s->pci->count_connected){
		cpu_s->waiting = true;
	}
	else{
		cpuThrowInterruption(INTR_DEVICE_UNAVAILABLE);
	}
	return 0;
}

cpuInterr procFA(Cpu *cpu_s){
	// Instruction: stop
	procEnsureNotInProtectedMode();
	// TODO
	return 0;
}
/*
cpuInterr procFB(Cpu *cpu_s){
	// Prefix: AS
	cpu_s->prefix = true;
	cpu_s->seg_data = &cpu_s->sregs[SREG_AS];
	return 0;
}

cpuInterr procFC(Cpu *cpu_s){
	// Prefix: BS
	cpu_s->prefix = true;
	cpu_s->seg_data = &cpu_s->sregs[SREG_BS];
	return 0;
}

cpuInterr procFD(Cpu *cpu_s){
	// Prefix: ES
	cpu_s->prefix = true;
	cpu_s->seg_data = &cpu_s->sregs[SREG_ES];
	return 0;
}

cpuInterr procFE(Cpu *cpu_s){
	// Prefix: FS
	cpu_s->prefix = true;
	cpu_s->seg_data = &cpu_s->sregs[SREG_FS];
	return 0;
}

cpuInterr procFF(Cpu *cpu_s){
	// Prefix: GS
	cpu_s->prefix = true;
	cpu_s->seg_data = &cpu_s->sregs[SREG_GS];
	return 0;
}
*/
