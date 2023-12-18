#include "procedures.h"


cpuInterr proc00(Cpu *cpu_s){
	// Instruction: nop
	return 0;
}

cpuInterr proc01(Cpu *cpu_s){
	// Instruction: pnop
	procEnsureNotInProtectedMode();
	return 0;
}

cpuInterr proc02(Cpu *cpu_s){
	// Instruction: debug
	cpu_s->iregs[0] = cpu_s->reg_pc;
	cpu_s->iregs[1] = cpu_s->reg_st;
	cpuThrowInterruption(INTR_DEBUGGER_INTERRUPTION);
	return 0;
}

cpuInterr proc04(Cpu *cpu_s){
	// Instruction: jaes imm32
	procEnsureNotInProtectedMode();
	cpuFetchMV32();
	cpu_s->reg_pc |= FLAG_SE;
	cpuJumpTo(cpu_s->mv);
	return 0;
}

cpuInterr proc05(Cpu *cpu_s){
	// Instruction: jaes r32
	procEnsureNotInProtectedMode();
	cpuFetchOS();
	cpu_s->reg_pc |= FLAG_SE;
	cpuJumpTo(cpuReadReg32(cpu_s->os_regm));
	return 0;
}

cpuInterr proc06(Cpu *cpu_s){
	// Instruction: jads imm32
	procEnsureNotInProtectedMode();
	cpuFetchMV32();
	cpu_s->reg_pc &= ~FLAG_SE;
	cpuJumpTo(cpu_s->mv);
	return 0;
}

cpuInterr proc07(Cpu *cpu_s){
	// Instruction: jads r32
	procEnsureNotInProtectedMode();
	cpuFetchOS();
	cpu_s->reg_pc &= ~FLAG_SE;
	cpuJumpTo(cpuReadReg32(cpu_s->os_regm));
	return 0;
}

cpuInterr proc08(Cpu *cpu_s){
	// Instruction: jaep imm32
	procEnsureNotInProtectedMode();
	cpuFetchMV32();
	cpu_s->reg_pc |= FLAG_PE;
	cpuJumpTo(cpu_s->mv);
	return 0;
}

cpuInterr proc09(Cpu *cpu_s){
	// Instruction: jaep r32
	procEnsureNotInProtectedMode();
	cpuFetchOS();
	cpu_s->reg_pc |= FLAG_PE;
	cpuJumpTo(cpuReadReg32(cpu_s->os_regm));
	return 0;
}

cpuInterr proc0A(Cpu *cpu_s){
	// Instruction: jadp imm32
	procEnsureNotInProtectedMode();
	cpuFetchMV32();
	cpu_s->reg_pc &= ~FLAG_PE;
	cpuJumpTo(cpu_s->mv);
	return 0;
}

cpuInterr proc0B(Cpu *cpu_s){
	// Instruction: jadp r32
	procEnsureNotInProtectedMode();
	cpuFetchOS();
	cpu_s->reg_pc &= ~FLAG_PE;
	cpuJumpTo(cpuReadReg32(cpu_s->os_regm));
	return 0;
}

cpuInterr proc0C(Cpu *cpu_s){
	// Instruction: jasp imm32
	procEnsureNotInProtectedMode();
	cpuFetchMV32();
	cpu_s->reg_pc |= FLAG_PM;
	cpuJumpTo(cpu_s->mv);
	return 0;
}

cpuInterr proc0D(Cpu *cpu_s){
	// Instruction: jasp r32
	procEnsureNotInProtectedMode();
	cpuFetchOS();
	cpu_s->reg_pc |= FLAG_PM;
	cpuJumpTo(cpuReadReg32(cpu_s->os_regm));
	return 0;
}

cpuInterr proc0E(Cpu *cpu_s){
	// Instruction: seti
	procEnsureNotInProtectedMode();
	cpu_s->reg_st |= FLAG_IE;
	return 0;
}

cpuInterr proc0F(Cpu *cpu_s){
	// Instruction: clri
	procEnsureNotInProtectedMode();
	cpu_s->reg_st &= ~FLAG_IE;
	return 0;
}

