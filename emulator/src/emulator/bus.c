#include "bus.h"


/*
	Functions for Handling BUS
*/

void busSetup(Bus *bus, void (*funcReset)(), uint8(*funcRead)(uint32 adr), void(*funcWrite)(uint32 adr, uint8 data)) {
	bus->state = 'SET1';
	bus->reset = funcReset;
	bus->read = funcRead;
	bus->write = funcWrite;
}

