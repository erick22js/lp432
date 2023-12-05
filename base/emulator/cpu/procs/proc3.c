#include "procedures.h"


// Segment Control

void procLoadSegment(Cpu *cpu_s, CpuSegment *seg){
	// Base must not be zero to be loaded
	if (seg->base){
		// Retrieve the segments count in base pointer
		uint32 count = cpuReadBus8(cpu_s->reg_std);

		// Disable segment in case not available
		if (seg->selector >= count){
			seg->flags &= ~SEG_ENABLED;
			return;
		}

		// Load segment structure from memory
		uint32 adr = cpu_s->reg_std + (seg->selector * 8);
		seg->flags = cpuReadBus8(adr);
		seg->base = cpuReadBus8(adr+2) | (cpuReadBus16(adr+4) << 8);
		seg->limit = cpuReadBus8(adr+3) | (cpuReadBus16(adr+6) << 8);

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

cpuInterr proc30(Cpu *cpu_s){
	// Instruction: ret
	cpuPop32();
	uint32 return_adr = cpu_s->data;
	cpuJumpTo(return_adr);
	return 0;
}

cpuInterr proc31(Cpu *cpu_s){
	// Instruction: iret
	procEnsureNotInProtectedMode();
	cpuReturnInterrupt(cpu_s);
	return 0;
}

cpuInterr proc32(Cpu *cpu_s){
	// Instruction: int
	cpuThrowInterruption(INTR_SOFTWARE_INTERRUPTION);
}

cpuInterr proc34(Cpu *cpu_s){
	// Instruction: enter
	cpuPush32(cpuReadReg32(GREG_EFP));
	uint32 last_stack = cpuReadReg32(GREG_ESP);
	cpuWriteReg32(GREG_ESP, last_stack);
	cpuPush32(last_stack);
	return 0;
}

cpuInterr proc35(Cpu *cpu_s){
	// Instruction: enter imm16
	cpuFetchMV16();
	cpuPush32(cpuReadReg32(GREG_EFP));
	uint32 last_stack = cpuReadReg32(GREG_ESP);
	uint32 scope_size = cpu_s->mv;
	cpuWriteReg32(GREG_ESP, last_stack+scope_size);
	cpuPush32(last_stack);
	return 0;
}

cpuInterr proc36(Cpu *cpu_s){
	// Instruction: enter r16:regm
	cpuFetchOS();
	cpuPush32(cpuReadReg32(GREG_EFP));
	uint32 last_stack = cpuReadReg32(GREG_ESP);
	uint32 scope_size = cpuReadReg16(cpu_s->os_regm);
	cpuWriteReg32(GREG_ESP, last_stack+scope_size);
	cpuPush32(last_stack);
	return 0;
}

cpuInterr proc37(Cpu *cpu_s){
	// Instruction: leave
	cpuPop32();
	cpuWriteReg32(GREG_ESP, cpu_s->data);
	cpuPop32();
	cpuWriteReg32(GREG_EFP, cpu_s->data);
	return 0;
}

cpuInterr proc38(Cpu *cpu_s){
	cpuFetchOS();

	if (cpu_s->os_desc < 8){
		// Instruction: mvtsr sr:desc r8:regm
		uint8 data = cpuReadReg8(cpu_s->os_regm);
		cpu_s->sregs[cpu_s->os_desc].selector = data;
		procLoadSegment(cpu_s, &cpu_s->sregs[cpu_s->os_desc]);
	}
	else {
		cpuThrowInterruption(INTR_INVALID_OPCODE);
	}

	return 0;
}

cpuInterr proc39(Cpu *cpu_s){
	cpuFetchOS();
	procEnsureNotInProtectedMode();

	switch (cpu_s->os_desc){
		case 0x0:{
			// Instruction: mvtstd r32:regm
			uint32 data = cpuReadReg32(cpu_s->os_regm);
			cpu_s->reg_std = data;
			for (int i = 0; i<SREG_TOTAL; i++){
				procLoadSegment(cpu_s, &cpu_s->sregs[i]);
			}
		}
		break;
		case 0x1:{
			// Instruction: mvtptd r32:regm
			uint32 data = cpuReadReg32(cpu_s->os_regm);
			cpu_s->reg_ptd = data;
		}
		case 0x2:{
			// Instruction: mvtitd r32:regm
			uint32 data = cpuReadReg32(cpu_s->os_regm);
			cpu_s->reg_itd = data;
		}
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr proc3A(Cpu *cpu_s){
	// Instruction: mvfir r32:regm, ir32:rego
	cpuFetchOS();
	procEnsureNotInProtectedMode();
	cpuWriteReg32(cpu_s->os_regm, cpu_s->iregs[cpu_s->os_rego&0x7]);
	return 0;
}

cpuInterr proc3B(Cpu *cpu_s){
	// Instruction: mvtpit sr:desc r8:regm
	cpuFetchOS();
	procEnsureNotInProtectedMode();

	uint32 data = cpuReadReg32(cpu_s->os_regm);
	cpu_s->reg_pit = data;

	// Resets timer
	cpu_s->reg_ctv = 0;
	cpu_s->reg_utv = 0;
	return 0;
}

cpuInterr proc3C(Cpu *cpu_s){
	// Instruction: mvfisp r32:regm
	cpuFetchOS();
	procEnsureNotInProtectedMode();
	cpuWriteReg32(cpu_s->os_regm, cpu_s->reg_isp);
	return 0;
}

cpuInterr proc3D(Cpu *cpu_s){
	// Instruction: mvtisp r32:regm
	cpuFetchOS();
	procEnsureNotInProtectedMode();
	cpu_s->reg_isp = cpuReadReg32(cpu_s->os_regm);
	return 0;
}

cpuInterr proc3E(Cpu *cpu_s){
	// Instruction: sett
	procEnsureNotInProtectedMode();
	cpu_s->reg_st |= FLAG_TI;
	return 0;
}

cpuInterr proc3F(Cpu *cpu_s){
	// Instruction: clrt
	procEnsureNotInProtectedMode();
	cpu_s->reg_st &= ~FLAG_TI;
	return 0;
}

