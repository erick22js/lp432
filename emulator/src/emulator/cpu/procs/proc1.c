#include "procedures.h"


cpuInterr proc10(){
	// Instruction: setc
	cpu_s.reg_st |= FLAG_CF;
	return 0;
}

cpuInterr proc11(){
	// Instruction: clrc
	cpu_s.reg_st &= ~FLAG_CF;
	return 0;
}

cpuInterr proc12(){
	// Instruction: setb
	cpu_s.reg_st |= FLAG_BF;
	return 0;
}

cpuInterr proc13(){
	// Instruction: clrb
	cpu_s.reg_st &= ~FLAG_BF;
	return 0;
}

cpuInterr proc14(){
	// Instruction: setv
	cpu_s.reg_st |= FLAG_VF;
	return 0;
}

cpuInterr proc15(){
	// Instruction: clrv
	cpu_s.reg_st &= ~FLAG_VF;
	return 0;
}

cpuInterr proc16(){
	// Instruction: setn
	cpu_s.reg_st |= FLAG_NF;
	return 0;
}

cpuInterr proc17(){
	// Instruction: clrn
	cpu_s.reg_st &= ~FLAG_NF;
	return 0;
}

cpuInterr proc18(){
	// Instruction: setz
	cpu_s.reg_st |= FLAG_ZF;
	return 0;
}

cpuInterr proc19(){
	// Instruction: clrz
	cpu_s.reg_st &= ~FLAG_ZF;
	return 0;
}

cpuInterr proc1A(){
	// Instruction: seto
	cpu_s.reg_st |= FLAG_OF;
	return 0;
}

cpuInterr proc1B(){
	// Instruction: clro
	cpu_s.reg_st &= ~FLAG_OF;
	return 0;
}

cpuInterr proc1C(){
	// Instruction: togc
	cpu_s.reg_st ^= FLAG_CF;
	return 0;
}

cpuInterr proc1D(){
	// Instruction: togn
	cpu_s.reg_st ^= FLAG_NF;
	return 0;
}

cpuInterr proc1E(){
	// Instruction: togz
	cpu_s.reg_st ^= FLAG_ZF;
	return 0;
}

cpuInterr proc1F(){
	// Instruction: togo
	cpu_s.reg_st ^= FLAG_OF;
	return 0;
}

