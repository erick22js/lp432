#ifndef EMU_BUS_H
#define EMU_BUS_H

#include "common.h"


static uint8 mem_ram[1024*1024*8];
static uint8 mem_rom[1024*64];

/*
	Functions for Access to BUS
*/

extern void busReset();
extern uint8 busRead(uint32 adr);
extern void busWrite(uint32 adr, uint8 data);


#endif