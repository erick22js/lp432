#ifndef EMU_H
#define EMU_H

#include "common.h"
#include "bus.h"


/*
	Emulation Properties State
*/

typedef struct{
	bool running;
}Emu;
static Emu emu_s;


/*
	Internal Functions for Emulation
*/

extern void emuCycles(uint32 cycles);


/*
	Control Functions for Emulation
*/

extern void emuReset();
extern void emuStep();
extern void emuRun();


#endif