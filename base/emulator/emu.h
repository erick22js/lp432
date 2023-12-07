#ifndef EMU_H
#define EMU_H

#include "common.h"
#include "bus.h"


/*
	Emulation Properties State
*/

struct Emu{
	bool running;

	/* Conected Devices */
	Cpu *cpu_s; // Main CPU of emulator
	Pci *pci; // Main PCI
	Bus *bus; // Main BUS connected

	/* Timing Control */
	uint32 acu_cycles;
};
//static Emu emu_s;


/*
	Internal Functions for Emulation
*/

extern void emuCycles(Emu *emu, uint32 cycles);


/*
	Control Functions for Emulation
*/

extern void emuSetup(Emu *emu, Cpu *cpu_s, Pci *pci, Bus *bus);
extern void emuReset(Emu *emu);
extern void emuStep(Emu *emu);
extern void emuRun(Emu *emu);


#endif