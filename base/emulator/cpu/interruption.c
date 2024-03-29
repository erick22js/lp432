#include "memory.h"


/*
	CPU Interruption Dealing
*/

void cpuIntrPush(Cpu *cpu_s, uint32 data){
	cpu_s->reg_isp -= 4;
	cpuWriteBus32(cpu_s->reg_isp, data);
}

uint32 cpuIntrPop(Cpu *cpu_s){
	uint32 data = cpuReadBus32(cpu_s->reg_isp);
	cpu_s->reg_isp += 4;
	return data;
}

void cpuInterrupt(Cpu *cpu_s){
	// Fault Interruption
	cpuIntrPush(cpu_s, cpu_s->reg_st);
	if (cpu_s->interrupt>=0x2 && cpu_s->interrupt<=0x5){
		cpuIntrPush(cpu_s, cpu_s->reg_lpc);
	}
	// Branch Interruption
	else{
		cpuIntrPush(cpu_s, cpu_s->reg_pc);
	}
	// Set some flags
	cpu_s->reg_st &= ~FLAG_PM; // Disable protected mode
	cpu_s->reg_st &= ~FLAG_IE; // Disable external interruption
	cpu_s->reg_st = (cpu_s->reg_st&0xF0FF00FF) | ((cpu_s->interrupt&0xF) << 24); // Signalize in Flags the current interruption

	// Retrieve IR Address and jump to it
	uint32 intr_ptr = cpu_s->reg_itd + (cpu_s->interrupt*4);
	uint32 intr_adr = cpuReadBus32(intr_ptr);
	cpuJumpTo(intr_adr);
}

void cpuReturnInterrupt(Cpu *cpu_s){
	// Only return if is in a interruption
	if (cpu_s->reg_st&0x0F000000){
		cpu_s->reg_pc = cpuIntrPop(cpu_s);
		cpu_s->reg_st = cpuIntrPop(cpu_s);
	}
}
