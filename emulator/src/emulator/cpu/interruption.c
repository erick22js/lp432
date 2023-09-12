#include "memory.h"


/*
	CPU Interruption Dealing
*/

void cpuIntrPush(uint32 data){
	cpu_s.reg_isp -= 4;
	busWrite8(cpu_s.reg_isp, (data)&0xFF);
	busWrite8(cpu_s.reg_isp+1, (data>>8)&0xFF);
	busWrite8(cpu_s.reg_isp+2, (data>>16)&0xFF);
	busWrite8(cpu_s.reg_isp+3, (data>>24)&0xFF);
}

uint32 cpuIntrPop(){
	uint32 data = 0;
	data |= busRead8(cpu_s.reg_isp);
	data |= busRead8(cpu_s.reg_isp+1)<<8;
	data |= busRead8(cpu_s.reg_isp+2)<<16;
	data |= busRead8(cpu_s.reg_isp+3)<<24;
	cpu_s.reg_isp += 4;
	return data;
}

uint32 cpuBusRead(uint32 adr){
	uint32 data = 0;
	data |= busRead8(adr);
	data |= busRead8(adr+1)<<8;
	data |= busRead8(adr+2)<<16;
	data |= busRead8(adr+3)<<24;
	return data;
}

void cpuInterrupt(){
	// Fault Interruption
	if (cpu_s.interrupt>=0x2 && cpu_s.interrupt<=0x5){
		cpuIntrPush(cpu_s.reg_st);
		cpuIntrPush(cpu_s.reg_lpc);
	}
	// Branch Interruption
	else{
		cpuIntrPush(cpu_s.reg_st);
		cpuIntrPush(cpu_s.reg_pc);
	}
	// Set some flags
	cpu_s.reg_st &= ~FLAG_PM; // Disable protected mode
	cpu_s.reg_st = (cpu_s.reg_st&0xF0FFFFFF) | ((cpu_s.interrupt&0xF) << 24); // Signalize in Flags the current interruption

	// Retrieve IR Address and jump to it
	uint32 intrr_adr = cpuBusRead(cpu_s.reg_itd + (cpu_s.interrupt*4));
	cpuJumpTo(intrr_adr);
}

void cpuReturnInterrupt(){
	// Only return if is in a interruption
	if (cpu_s.reg_st&0x0F000000){
		cpu_s.reg_pc = cpuIntrPop();
		cpu_s.reg_st = cpuIntrPop();
	}
}
