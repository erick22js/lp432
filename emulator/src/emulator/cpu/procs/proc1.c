#include "procedures.h"


cpuInterr proc10(Cpu *cpu_s){
	// Instruction: setc
	cpu_s->reg_st |= FLAG_CF;
	return 0;
}

cpuInterr proc11(Cpu *cpu_s){
	// Instruction: clrc
	cpu_s->reg_st &= ~FLAG_CF;
	return 0;
}

cpuInterr proc12(Cpu *cpu_s){
	// Instruction: setb
	cpu_s->reg_st |= FLAG_BF;
	return 0;
}

cpuInterr proc13(Cpu *cpu_s){
	// Instruction: clrb
	cpu_s->reg_st &= ~FLAG_BF;
	return 0;
}

cpuInterr proc14(Cpu *cpu_s){
	// Instruction: setv
	cpu_s->reg_st |= FLAG_VF;
	return 0;
}

cpuInterr proc15(Cpu *cpu_s){
	// Instruction: clrv
	cpu_s->reg_st &= ~FLAG_VF;
	return 0;
}

cpuInterr proc16(Cpu *cpu_s){
	// Instruction: setn
	cpu_s->reg_st |= FLAG_NF;
	return 0;
}

cpuInterr proc17(Cpu *cpu_s){
	// Instruction: clrn
	cpu_s->reg_st &= ~FLAG_NF;
	return 0;
}

cpuInterr proc18(Cpu *cpu_s){
	// Instruction: setz
	cpu_s->reg_st |= FLAG_ZF;
	return 0;
}

cpuInterr proc19(Cpu *cpu_s){
	// Instruction: clrz
	cpu_s->reg_st &= ~FLAG_ZF;
	return 0;
}

cpuInterr proc1A(Cpu *cpu_s){
	// Instruction: seto
	cpu_s->reg_st |= FLAG_OF;
	return 0;
}

cpuInterr proc1B(Cpu *cpu_s){
	// Instruction: clro
	cpu_s->reg_st &= ~FLAG_OF;
	return 0;
}

cpuInterr proc1C(Cpu *cpu_s){
	// Instruction: togc
	cpu_s->reg_st ^= FLAG_CF;
	return 0;
}

cpuInterr proc1D(Cpu *cpu_s){
	// Instruction: togn
	cpu_s->reg_st ^= FLAG_NF;
	return 0;
}

cpuInterr proc1E(Cpu *cpu_s){
	// Instruction: togz
	cpu_s->reg_st ^= FLAG_ZF;
	return 0;
}

cpuInterr proc1F(Cpu *cpu_s){
	// Instruction: togo
	cpu_s->reg_st ^= FLAG_OF;
	return 0;
}

