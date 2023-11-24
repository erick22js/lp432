#include "procedures.h"


bool procTestFlags(Cpu *cpu_s, uint8 cond){
	switch (cond){
		case 0x0: { // Equal
			return eval(cpu_s->reg_st&FLAG_ZF);
		};
		break;
		case 0x1: { // Not Equal
			return !eval(cpu_s->reg_st&FLAG_ZF);
		};
		break;
		case 0x2: { // Greater
			return (eval(cpu_s->reg_st&FLAG_VF)==eval(cpu_s->reg_st&FLAG_NF)) && !eval(cpu_s->reg_st&FLAG_ZF);
		};
		break;
		case 0x3: { // Lesser
			return (eval(cpu_s->reg_st&FLAG_VF)!=eval(cpu_s->reg_st&FLAG_NF)) && !eval(cpu_s->reg_st&FLAG_ZF);
		};
		break;
		case 0x4: { // Greater or Equal
			return (eval(cpu_s->reg_st&FLAG_VF)==eval(cpu_s->reg_st&FLAG_NF)) || eval(cpu_s->reg_st&FLAG_ZF);
		};
		break;
		case 0x5: { // Lesser or Equal
			return (eval(cpu_s->reg_st&FLAG_VF)!=eval(cpu_s->reg_st&FLAG_NF)) || eval(cpu_s->reg_st&FLAG_ZF);
		};
		break;
		case 0x6: { // Above
			return !eval(cpu_s->reg_st&FLAG_BF) && !eval(cpu_s->reg_st&FLAG_ZF);
		};
		break;
		case 0x7: { // Below
			return eval(cpu_s->reg_st&FLAG_BF) && !eval(cpu_s->reg_st&FLAG_ZF);
		};
		break;
		case 0x8: { // Above or Equal
			return !eval(cpu_s->reg_st&FLAG_BF) || eval(cpu_s->reg_st&FLAG_ZF);
		};
		break;
		case 0x9: { // Below or Equal
			return eval(cpu_s->reg_st&FLAG_BF) || eval(cpu_s->reg_st&FLAG_ZF);
		};
		break;
		case 0xA: { // Carry
			return eval(cpu_s->reg_st&FLAG_CF);
		};
		break;
		case 0xB: { // Not Carry
			return !eval(cpu_s->reg_st&FLAG_CF);
		};
		break;
		case 0xC: { // Negative
			return eval(cpu_s->reg_st&FLAG_NF);
		};
		break;
		case 0xD: { // Odd
			return eval(cpu_s->reg_st&FLAG_OF);
		};
		break;
		case 0xE: { // Overflow
			return eval(cpu_s->reg_st&FLAG_VF);
		};
		break;
		case 0xF: { // Not Overflow
			return !eval(cpu_s->reg_st&FLAG_VF);
		};
		break;
	}
	return true;
}

bool procTestOperand(Cpu *cpu_s, uint8 cond, uint32 opr){
	switch (cond){
		case 0x0: { // Equal Zero
			return opr==0;
		};
		break;
		case 0x1: { // Not Equal Zero
			return opr!=0;
		};
		break;
		case 0x2: { // Greater than Zero
			return u32ToInt(opr)>0;
		};
		break;
		case 0x3: { // Lesser than Zero
			return u32ToInt(opr)<0;
		};
		break;
		case 0x4: { // Greater or Equal to Zero
			return u32ToInt(opr)>=0;
		};
		break;
		case 0x5: { // Lesser or Equal to Zero
			return u32ToInt(opr)<=0;
		};
		break;
		case 0x6: { // Above than Zero
			return opr>0;
		};
		break;
		case 0x7: { // Below than Zero
			return opr<0;
		};
		break;
		case 0x8: { // Above or Equal to Zero
			return opr>=0;
		};
		break;
		case 0x9: { // Below or Equal to Zero
			return opr<=0;
		};
		break;
		case 0xA: { // Likely Carry
			return eval(opr)==eval(cpu_s->reg_st&FLAG_CF);
		};
		break;
		case 0xB: { // Not Likely Carry
			return eval(opr)!=eval(cpu_s->reg_st&FLAG_CF);
		};
		break;
		case 0xC: { // Likely Negative
			return eval(opr)==eval(cpu_s->reg_st&FLAG_NF);
		};
		break;
		case 0xD: { // Likely Odd
			return eval(opr)==eval(cpu_s->reg_st&FLAG_OF);
		};
		break;
		case 0xE: { // Likely Overflow
			return eval(opr)==eval(cpu_s->reg_st&FLAG_VF);
		};
		break;
		case 0xF: { // Not Likely Carry
			return eval(opr)!=eval(cpu_s->reg_st&FLAG_VF);
		};
		break;
	}
	return true;
}

cpuInterr proc20(Cpu *cpu_s){
	// Instruction: jr imm16:MV
	cpuFetch16();
	cpuJumpBy(u16ToInt(cpu_s->code));
	return 0;
}

cpuInterr proc21(Cpu *cpu_s){
	// Instruction: jr.cc imm16:MV
	cpuFetchOS();
	cpuFetch16();
	if (procTestFlags(cpu_s, cpu_s->os_desc)){
		cpuJumpBy(u16ToInt(cpu_s->code));
	}
	return 0;
}

cpuInterr proc22(Cpu *cpu_s){
	// Instruction: jr.cc r32:regm, imm16:MV
	cpuFetchOS();
	cpuFetch16();
	if (procTestOperand(cpu_s, cpu_s->os_desc, cpuReadReg32(cpu_s->os_regm))){
		cpuJumpBy(u16ToInt(cpu_s->code));
	}
	return 0;
}

cpuInterr proc23(Cpu *cpu_s){
	// Instruction: ja r32:regm
	cpuFetchOS();
	cpuJumpTo(cpuReadReg32(cpu_s->os_regm));
	return 0;
}

cpuInterr proc24(Cpu *cpu_s){
	// Instruction: ja imm32:MV
	cpuFetch32();
	cpuJumpTo(cpu_s->code);
	return 0;
}

cpuInterr proc25(Cpu *cpu_s){
	// Instruction: ja.cc imm32:MV
	cpuFetchOS();
	cpuFetch32();
	if (procTestFlags(cpu_s, cpu_s->os_desc)){
		cpuJumpTo(cpu_s->code);
	}
	return 0;
}

cpuInterr proc26(Cpu *cpu_s){
	// Instruction: ja.cc r32:regm, imm32:MV
	cpuFetchOS();
	cpuFetch32();
	if (procTestOperand(cpu_s, cpu_s->os_desc, cpuReadReg32(cpu_s->os_regm))){
		cpuJumpTo(cpu_s->code);
	}
	return 0;
}

cpuInterr proc27(Cpu *cpu_s){
	// Instruction: xjmp r32:regm
	cpuFetchOS();
	uint32 address = cpu_s->reg_pc;
	cpuJumpTo(cpuReadReg32(cpu_s->os_regm));
	cpuWriteReg32(cpu_s->os_regm, address);
	return 0;
}

cpuInterr proc28(Cpu *cpu_s){
	// Instruction: br imm16:MV
	cpuFetch16();
	cpuPush32(cpu_s->reg_pc);
	cpuJumpBy(u16ToInt(cpu_s->code));
	return 0;
}

cpuInterr proc29(Cpu *cpu_s){
	// Instruction: br.cc imm16:MV
	cpuFetchOS();
	cpuFetch16();
	if (procTestFlags(cpu_s, cpu_s->os_desc)){
		cpuPush32(cpu_s->reg_pc);
		cpuJumpBy(u16ToInt(cpu_s->code));
	}
	return 0;
}

cpuInterr proc2A(Cpu *cpu_s){
	// Instruction: br.cc r32:regm, imm16:MV
	cpuFetchOS();
	cpuFetch16();
	if (procTestOperand(cpu_s, cpu_s->os_desc, cpuReadReg32(cpu_s->os_regm))){
		cpuPush32(cpu_s->reg_pc);
		cpuJumpBy(u16ToInt(cpu_s->code));
	}
	return 0;
}

cpuInterr proc2B(Cpu *cpu_s){
	// Instruction: ba r32:regm
	cpuFetchOS();
	cpuPush32(cpu_s->reg_pc);
	cpuJumpTo(cpuReadReg32(cpu_s->os_regm));
	return 0;
}

cpuInterr proc2C(Cpu *cpu_s){
	// Instruction: ba imm32:MV
	cpuFetch32();
	cpuPush32(cpu_s->reg_pc);
	cpuJumpTo(cpu_s->code);
	return 0;
}

cpuInterr proc2D(Cpu *cpu_s){
	// Instruction: ba.cc imm32:MV
	cpuFetchOS();
	cpuFetch32();
	if (procTestFlags(cpu_s, cpu_s->os_desc)){
		cpuPush32(cpu_s->reg_pc);
		cpuJumpTo(cpu_s->code);
	}
	return 0;
}

cpuInterr proc2E(Cpu *cpu_s){
	// Instruction: ba.cc r32:regm, imm32:MV
	cpuFetchOS();
	cpuFetch32();
	if (procTestOperand(cpu_s, cpu_s->os_desc, cpuReadReg32(cpu_s->os_regm))){
		cpuPush32(cpu_s->reg_pc);
		cpuJumpTo(cpu_s->code);
	}
	return 0;
}

cpuInterr proc2F(Cpu *cpu_s){
	// Instruction: xbch r32:regm
	cpuFetchOS();
	uint32 address = cpu_s->reg_pc;
	cpuPush32(cpu_s->reg_pc);
	cpuJumpTo(cpuReadReg32(cpu_s->os_regm));
	cpuWriteReg32(cpu_s->os_regm, address);
	return 0;
}
