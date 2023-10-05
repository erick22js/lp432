#ifndef EMU_BUS_H
#define EMU_BUS_H

#include "common.h"


/*
	BUS Properties State Struct
*/

struct Bus{
	uint32 state;
	void (*reset)();
	uint8 (*read)(uint32 adr);
	void (*write)(uint32 adr, uint8 data);
};


/*
	Functions for Handling BUS
*/

extern void busSetup(Bus *bus, void (*funcReset)(), uint8(*funcRead)(uint32 adr), void(*funcWrite)(uint32 adr, uint8 data));


#endif