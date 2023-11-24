#include "procedures.h"


cpuInterr proc50(Cpu *cpu_s){
	// Instruction: pop r8:regm
	cpuFetchOS();
	cpuPop8();
	cpuWriteReg8(cpu_s->os_regm, cpu_s->data);
	return 0;
}

cpuInterr proc51(Cpu *cpu_s){
	// Instruction: pop r16:regm
	cpuFetchOS();
	cpuPop16();
	cpuWriteReg16(cpu_s->os_regm, cpu_s->data);
	return 0;
}

cpuInterr proc52(Cpu *cpu_s){
	// Instruction: pop r32:regm
	cpuFetchOS();
	cpuPop32();
	cpuWriteReg32(cpu_s->os_regm, cpu_s->data);
	return 0;
}

cpuInterr proc53(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0: {
			// Instruction: pop mem8
			cpuFetchMemIndex();
			cpuPop8();
			cpuWriteMem8(cpu_s->mem_adr, cpu_s->data);
		}
		break;
		case 0x1: {
			// Instruction: pop mem16
			cpuFetchMemIndex();
			cpuPop16();
			cpuWriteMem16(cpu_s->mem_adr, cpu_s->data);
		}
		break;
		case 0x2: {
			// Instruction: pop mem32
			cpuFetchMemIndex();
			cpuPop32();
			cpuWriteMem32(cpu_s->mem_adr, cpu_s->data);
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr proc54(Cpu *cpu_s){
	// Instruction: psh r8:regm
	cpuFetchOS();
	cpuPush8(cpuReadReg8(cpu_s->os_regm));
	return 0;
}

cpuInterr proc55(Cpu *cpu_s){
	// Instruction: psh r16:regm
	cpuFetchOS();
	cpuPush16(cpuReadReg16(cpu_s->os_regm));
	return 0;
}

cpuInterr proc56(Cpu *cpu_s){
	// Instruction: psh r32:regm
	cpuFetchOS();
	cpuPush32(cpuReadReg32(cpu_s->os_regm));
	return 0;
}

cpuInterr proc57(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0:{
			// Instruction: psh mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s->mem_adr);
			cpuPush8(cpu_s->data);
		}
		break;
		case 0x1:{
			// Instruction: psh mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s->mem_adr);
			cpuPush16(cpu_s->data);
		}
		break;
		case 0x2:{
			// Instruction: psh mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s->mem_adr);
			cpuPush32(cpu_s->data);
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr proc58(Cpu *cpu_s){
	// Instruction: psh imm8:MV
	cpuFetchMV8();
	cpuPush8(cpu_s->data);
	return 0;
}

cpuInterr proc59(Cpu *cpu_s){
	// Instruction: psh imm16:MV
	cpuFetchMV16();
	cpuPush16(cpu_s->data);
	return 0;
}

cpuInterr proc5A(Cpu *cpu_s){
	// Instruction: psh imm32:MV
	cpuFetchMV32();
	cpuPush32(cpu_s->data);
	return 0;
}

cpuInterr proc5B(Cpu *cpu_s){
	// Instruction: poplst
	cpuPop16();
	cpu_s->reg_st = (cpu_s->reg_st&0xFFFF0000)|cpu_s->data;
	return 0;
}

cpuInterr proc5C(Cpu *cpu_s){
	// Instruction: popst
	procEnsureNotInProtectedMode();
	cpuPop32();
	cpu_s->reg_st = cpu_s->data;
	return 0;
}

cpuInterr proc5D(Cpu *cpu_s){
	// Instruction: pshlst
	cpuPush16(cpu_s->reg_st);
	return 0;
}

cpuInterr proc5E(Cpu *cpu_s){
	// Instruction: pshst
	procEnsureNotInProtectedMode();
	cpuPush32(cpu_s->reg_st);
	return 0;
}

cpuInterr proc5F(Cpu *cpu_s){
	// Instruction: updfp
	cpuWriteReg32(GREG_EFP, cpuReadReg32(GREG_ESP));
	return 0;
}

