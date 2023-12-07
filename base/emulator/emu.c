#include "cpu/cpu.h"
#include "pci.h"
#include "emu.h"


/*
	Emulation Properties State
*/

//extern Emu emu_s;


/*
	Internal Functions for Emulation
*/

void emuCycles(Emu *emu, uint32 cycles){
	emu->acu_cycles += cycles;
}


/*
	Control Functions for Emulation
*/

void emuSetup(Emu *emu, Cpu *cpu_s, Pci *pci, Bus *bus) {
	// BUS must be initialized before be used
	assert(bus->state=='SET1');

	// Connect emu to components
	emu->bus = bus;
	emu->cpu_s = cpu_s;
	emu->pci = pci;

	// Connect cpu to components
	cpu_s->busRead = bus->read;
	cpu_s->busWrite = bus->write;
	cpu_s->pci = pci;
	cpu_s->emu = emu;

	// Connect pci to main cpu
	pci->cpu_s = cpu_s;

	// Reset control properties
	emu->acu_cycles = 0;
}

void emuReset(Emu *emu){
	emu->bus->reset();
	pciReset(emu->pci);
	cpuReset(emu->cpu_s);
}

void emuStep(Emu *emu){
	cpuStep(emu->cpu_s);
	pciStep(emu->pci, emu->acu_cycles);
	emu->acu_cycles = 0;
}

void emuRun(Emu *emu){
	for (int i=0; i<4; i++){
		cpuStep(emu->cpu_s);
		pciStep(emu->pci, 0);
	}
}

