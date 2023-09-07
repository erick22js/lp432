#include "cpu/cpu.h"
#include "emu.h"


/*
	Emulation Properties State
*/

extern Emu emu_s;


/*
	Control Functions for Emulation
*/

void emuReset(){
	busReset();
	cpuReset();
}

void emuStep(){
	cpuStep();
}

void emuRun(){
	for (int i=0; i<4; i++){
		cpuStep();
	}
}

