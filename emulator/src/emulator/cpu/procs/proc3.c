#include "procedures.h"


// Segment Control
#define SEG_ENABLED 0x01
#define SEG_READABLE 0x02
#define SEG_WRITEABLE 0x04
#define SEG_EXECUTABLE 0x08
#define SEG_SCALE 0x40
#define SEG_APPEND 0x80

void procLoadSegment(CpuSegment *seg){
	// Base must not be zero to be loaded
	if (seg->base){
		// Retrieve the segments count in base pointer
		uint32 count = busRead8(cpu_s.reg_std);

		// Disable segment in case not available
		if (seg->selector >= count){
			seg->flags &= ~SEG_ENABLED;
			return;
		}

		// Load segment structure from memory
		uint32 adr = cpu_s.reg_std + (seg->selector * 8);
		seg->flags = busRead8(adr);
		seg->base = (busRead8(adr+2)) | (busRead8(adr+4) << 8) | (busRead8(adr+5) << 16);
		seg->limit = (busRead8(adr+3)) | (busRead8(adr+6) << 8) | (busRead8(adr+7) << 16);

		// Setup loaded segment base and limit
		seg->base = seg->base << 8;
		if (seg->flags&SEG_APPEND){
			seg->limit = (seg->flags&SEG_SCALE? (seg->limit << 8) | 0xFF: seg->limit) + seg->base;
		}
		else{
			seg->limit = (seg->limit << 8) | 0xFF;
		}
	}
}

cpuInterr proc30(){
	// Instruction: ret
	cpuPop32();
	uint32 return_adr = cpu_s.data;
	cpuJumpTo(return_adr);
	return 0;
}

cpuInterr proc31(){
	// Instruction: iret
	procEnsureNotInProtectedMode();
	cpuReturnInterrupt();
	return 0;
}

cpuInterr proc32(){
	// Instruction: int
	cpuThrowInterruption(INTR_SOFTWARE_INTERRUPTION);
}

cpuInterr proc34(){
	// Instruction: enter
	cpuPush32(cpuReadReg32(GREG_EFP));
	uint32 last_stack = cpuReadReg32(GREG_ESP);
	cpuWriteReg32(GREG_ESP, last_stack);
	cpuPush32(last_stack);
	return 0;
}

cpuInterr proc35(){
	// Instruction: enter imm16
	cpuFetchMV16();
	cpuPush32(cpuReadReg32(GREG_EFP));
	uint32 last_stack = cpuReadReg32(GREG_ESP);
	uint32 scope_size = cpu_s.mv;
	cpuWriteReg32(GREG_ESP, last_stack+scope_size);
	cpuPush32(last_stack);
	return 0;
}

cpuInterr proc36(){
	// Instruction: enter r16:regm
	cpuFetchOS();
	cpuPush32(cpuReadReg32(GREG_EFP));
	uint32 last_stack = cpuReadReg32(GREG_ESP);
	uint32 scope_size = cpuReadReg16(cpu_s.os_regm);
	cpuWriteReg32(GREG_ESP, last_stack+scope_size);
	cpuPush32(last_stack);
	return 0;
}

cpuInterr proc37(){
	// Instruction: leave
	cpuPop32();
	cpuWriteReg32(GREG_ESP, cpu_s.data);
	cpuPop32();
	cpuWriteReg32(GREG_EFP, cpu_s.data);
	return 0;
}

cpuInterr proc38(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0:{
			// Instruction: mvtcs r8:regm
			uint8 data = cpuReadReg8(cpu_s.os_regm);
			cpu_s.sregs[SREG_CS].selector = data;
			procLoadSegment(&cpu_s.sregs[SREG_CS]);
		}
		break;
		case 0x1:{
			// Instruction: mvtss r8:regm
			uint8 data = cpuReadReg8(cpu_s.os_regm);
			cpu_s.sregs[SREG_SS].selector = data;
			procLoadSegment(&cpu_s.sregs[SREG_SS]);
		}
		break;
		case 0x2:{
			// Instruction: mvtds r8:regm
			uint8 data = cpuReadReg8(cpu_s.os_regm);
			cpu_s.sregs[SREG_DS].selector = data;
			procLoadSegment(&cpu_s.sregs[SREG_DS]);
		}
		break;
		case 0x3:{
			// Instruction: mvtas r8:regm
			uint8 data = cpuReadReg8(cpu_s.os_regm);
			cpu_s.sregs[SREG_AS].selector = data;
			procLoadSegment(&cpu_s.sregs[SREG_AS]);
		}
		break;
		case 0x4:{
			// Instruction: mvtbs r8:regm
			uint8 data = cpuReadReg8(cpu_s.os_regm);
			cpu_s.sregs[SREG_BS].selector = data;
			procLoadSegment(&cpu_s.sregs[SREG_BS]);
		}
		break;
		case 0x5:{
			// Instruction: mvtes r8:regm
			uint8 data = cpuReadReg8(cpu_s.os_regm);
			cpu_s.sregs[SREG_ES].selector = data;
			procLoadSegment(&cpu_s.sregs[SREG_ES]);
		}
		break;
		case 0x6:{
			// Instruction: mvtfs r8:regm
			uint8 data = cpuReadReg8(cpu_s.os_regm);
			cpu_s.sregs[SREG_FS].selector = data;
			procLoadSegment(&cpu_s.sregs[SREG_FS]);
		}
		break;
		case 0x7:{
			// Instruction: mvtgs r8:regm
			uint8 data = cpuReadReg8(cpu_s.os_regm);
			cpu_s.sregs[SREG_GS].selector = data;
			procLoadSegment(&cpu_s.sregs[SREG_GS]);
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr proc39(){
	cpuFetchOS();
	procEnsureNotInProtectedMode();

	switch (cpu_s.os_desc){
		case 0x0:{
			// Instruction: mvtstd r32:regm
			uint32 data = cpuReadReg32(cpu_s.os_regm);
			cpu_s.reg_std = data;
			for (int i = 0; i<SREG_TOTAL; i++){
				procLoadSegment(&cpu_s.sregs[i]);
			}
		}
		break;
		case 0x1:{
			// Instruction: mvtptd r32:regm
			uint32 data = cpuReadReg32(cpu_s.os_regm);
			cpu_s.reg_ptd = data;
		}
		case 0x2:{
			// Instruction: mvtitd r32:regm
			uint32 data = cpuReadReg32(cpu_s.os_regm);
			cpu_s.reg_itd = data;
		}
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr proc3A(){
	// Instruction: mvfir r32:regm, ir32:rego
	cpuFetchOS();
	procEnsureNotInProtectedMode();
	cpuWriteReg32(cpu_s.os_regm, cpu_s.iregs[cpu_s.os_rego&0x7]);
	return 0;
}

