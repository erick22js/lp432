#include "cpu/cpu.h"
#include "pci.h"
#include "emu.h"


/*
	Emulation Properties State
*/

extern Emu emu_s;


/*
	Internal Functions for Emulation
*/

void emuCycles(uint32 cycles){
	// TODO
}


/*
	Control Functions for Emulation
*/

void emuReset(){
	busReset();
	pciReset();
	cpuReset();
}

void emuStep(){
	cpuStep();
	pciStep(0);
}

void emuRun(){
	for (int i=0; i<4; i++){
		cpuStep();
		pciStep(0);
	}
}

