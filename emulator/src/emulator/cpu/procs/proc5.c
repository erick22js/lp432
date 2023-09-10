#include "procedures.h"


cpuInterr proc50(){
	// Instruction: pop r8:regm
	cpuFetchOS();
	cpuPop8();
	cpuWriteReg8(cpu_s.os_regm, cpu_s.data);
	return 0;
}

cpuInterr proc51(){
	// Instruction: pop r16:regm
	cpuFetchOS();
	cpuPop16();
	cpuWriteReg16(cpu_s.os_regm, cpu_s.data);
	return 0;
}

cpuInterr proc52(){
	// Instruction: pop r32:regm
	cpuFetchOS();
	cpuPop32();
	cpuWriteReg32(cpu_s.os_regm, cpu_s.data);
	return 0;
}

cpuInterr proc53(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0: {
			// Instruction: pop mem8
			cpuFetchMemIndex();
			cpuPop8();
			cpuWriteMem8(cpu_s.mem_adr, cpu_s.data);
		}
		break;
		case 0x1: {
			// Instruction: pop mem16
			cpuFetchMemIndex();
			cpuPop16();
			cpuWriteMem16(cpu_s.mem_adr, cpu_s.data);
		}
		break;
		case 0x2: {
			// Instruction: pop mem32
			cpuFetchMemIndex();
			cpuPop32();
			cpuWriteMem32(cpu_s.mem_adr, cpu_s.data);
		}
		break;
	}
	return 0;
}

cpuInterr proc54(){
	// Instruction: psh r8:regm
	cpuFetchOS();
	cpuPush8(cpuReadReg8(cpu_s.os_regm));
	return 0;
}

cpuInterr proc55(){
	// Instruction: psh r16:regm
	cpuFetchOS();
	cpuPush16(cpuReadReg16(cpu_s.os_regm));
	return 0;
}

cpuInterr proc56(){
	// Instruction: psh r32:regm
	cpuFetchOS();
	cpuPush32(cpuReadReg32(cpu_s.os_regm));
	return 0;
}

cpuInterr proc57(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0:{
			// Instruction: psh mem8
			cpuFetchMemIndex();
			cpuReadMem8(cpu_s.mem_adr);
			cpuPush8(cpu_s.data);
		}
		break;
		case 0x1:{
			// Instruction: psh mem16
			cpuFetchMemIndex();
			cpuReadMem16(cpu_s.mem_adr);
			cpuPush16(cpu_s.data);
		}
		break;
		case 0x2:{
			// Instruction: psh mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s.mem_adr);
			cpuPush32(cpu_s.data);
		}
		break;
	}
	return 0;
}

cpuInterr proc58(){
	// Instruction: psh imm8:MV
	cpuFetchMV8();
	cpuPush8(cpu_s.data);
	return 0;
}

cpuInterr proc59(){
	// Instruction: psh imm16:MV
	cpuFetchMV16();
	cpuPush16(cpu_s.data);
	return 0;
}

cpuInterr proc5A(){
	// Instruction: psh imm32:MV
	cpuFetchMV32();
	cpuPush32(cpu_s.data);
	return 0;
}

cpuInterr proc5B(){
	// Instruction: poplst
	cpuPop16();
	cpu_s.reg_st = (cpu_s.reg_st&0xFFFF0000)|cpu_s.data;
	return 0;
}

cpuInterr proc5C(){
	// Instruction: popst
	procEnsureNotInProtectedMode();
	cpuPop32();
	cpu_s.reg_st = cpu_s.data;
	return 0;
}

cpuInterr proc5D(){
	// Instruction: pshlst
	cpuPush16(cpu_s.reg_st);
	return 0;
}

cpuInterr proc5E(){
	// Instruction: pshst
	procEnsureNotInProtectedMode();
	cpuPush32(cpu_s.reg_st);
	return 0;
}

cpuInterr proc5F(){
	// Instruction: updfp
	cpuWriteReg32(GREG_EFP, cpuReadReg32(GREG_ESP));
	return 0;
}

