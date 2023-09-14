#include "procedures.h"


cpuInterr proc00(){
	// Instruction: nop
	return 0;
}

cpuInterr proc01(){
	// Instruction: pnop
	procEnsureNotInProtectedMode();
	return 0;
}

cpuInterr proc02(){
	// Instruction: debug
	cpuThrowInterruption(INTR_DEBUGGER_INTERRUPTION);
	return 0;
}

cpuInterr proc04(){
	// Instruction: jaes imm32
	procEnsureNotInProtectedMode();
	cpuFetchMV32();
	cpu_s.reg_pc |= FLAG_SE;
	cpuJumpTo(cpu_s.mv);
	return 0;
}

cpuInterr proc05(){
	// Instruction: jaes r32
	procEnsureNotInProtectedMode();
	cpuFetchOS();
	cpu_s.reg_pc |= FLAG_SE;
	cpuJumpTo(cpuReadReg32(cpu_s.os_regm));
	return 0;
}

cpuInterr proc06(){
	// Instruction: jads imm32
	procEnsureNotInProtectedMode();
	cpuFetchMV32();
	cpu_s.reg_pc &= ~FLAG_SE;
	cpuJumpTo(cpu_s.mv);
	return 0;
}

cpuInterr proc07(){
	// Instruction: jads r32
	procEnsureNotInProtectedMode();
	cpuFetchOS();
	cpu_s.reg_pc &= ~FLAG_SE;
	cpuJumpTo(cpuReadReg32(cpu_s.os_regm));
	return 0;
}

cpuInterr proc08(){
	// Instruction: jaep imm32
	procEnsureNotInProtectedMode();
	cpuFetchMV32();
	cpu_s.reg_pc |= FLAG_PE;
	cpuJumpTo(cpu_s.mv);
	return 0;
}

cpuInterr proc09(){
	// Instruction: jaep r32
	procEnsureNotInProtectedMode();
	cpuFetchOS();
	cpu_s.reg_pc |= FLAG_PE;
	cpuJumpTo(cpuReadReg32(cpu_s.os_regm));
	return 0;
}

cpuInterr proc0A(){
	// Instruction: jadp imm32
	procEnsureNotInProtectedMode();
	cpuFetchMV32();
	cpu_s.reg_pc &= ~FLAG_PE;
	cpuJumpTo(cpu_s.mv);
	return 0;
}

cpuInterr proc0B(){
	// Instruction: jadp r32
	procEnsureNotInProtectedMode();
	cpuFetchOS();
	cpu_s.reg_pc &= ~FLAG_PE;
	cpuJumpTo(cpuReadReg32(cpu_s.os_regm));
	return 0;
}

cpuInterr proc0C(){
	// Instruction: jasp imm32
	procEnsureNotInProtectedMode();
	cpuFetchMV32();
	cpu_s.reg_pc |= FLAG_PM;
	cpuJumpTo(cpu_s.mv);
	return 0;
}

cpuInterr proc0D(){
	// Instruction: jasp r32
	procEnsureNotInProtectedMode();
	cpuFetchOS();
	cpu_s.reg_pc |= FLAG_PM;
	cpuJumpTo(cpuReadReg32(cpu_s.os_regm));
	return 0;
}

cpuInterr proc0E(){
	// Instruction: seti
	procEnsureNotInProtectedMode();
	cpu_s.reg_st |= FLAG_IE;
	return 0;
}

cpuInterr proc0F(){
	// Instruction: clri
	procEnsureNotInProtectedMode();
	cpu_s.reg_st &= ~FLAG_IE;
	return 0;
}

