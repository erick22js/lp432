#ifndef EMU_CPU_INTERRUPTION_H
#define EMU_CPU_INTERRUPTION_H

#include "cpu.h"


/*
	Interruptions Identification
*/

#define INTR_NONE 0x0
#define INTR_PROTECTED_MODE_VIOLATION 0x1
#define INTR_PAGE_FAULT 0x3
#define INTR_SEGMENT_NOT_PRESENT 0x4
#define INTR_DIRECTORY_FAULT 0x5
#define INTR_DENIED_DATA_ACCESS 0x6
#define INTR_DENIED_CODE_ACCESS 0x7
#define INTR_INVALID_OPCODE 0x9
#define INTR_DIVISION_BY_ZERO 0xA
#define INTR_DEBUGGER_INTERRUPTION 0xC
#define INTR_DEVICE_UNAVAILABLE 0xD
#define INTR_SOFTWARE_INTERRUPTION 0xE
#define INTR_HARDWARE_INTERRUPTION 0xF


/*
	Util Functions
*/
// Throw a interruption to cpu deal with
#define cpuThrowInterruption(intrr) {cpu_s.interrupt = intrr; return intrr;}
// Try to execute a cpu function dealing with interruptions requests
#define cpuTryExecute(function) {if(function) return cpu_s.interrupt;}

/*
	CPU Interruption Dealing
*/
void cpuInterrupt();
void cpuReturnInterrupt();


#endif