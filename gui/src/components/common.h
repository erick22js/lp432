#ifndef GUI_COMMON_H
#define GUI_COMMON_H

#include "emulator/emulator.h"


extern Emu g_emu;
extern Bus g_bus;
extern Cpu g_cpu;
extern Pci g_pci;

/*
	Functions for Access to BUS
*/

extern uint8 mem_ram[];

extern void busReset();

extern uint8 busRead(uint32 adr);

extern void busWrite(uint32 adr, uint8 data);

/*
	Setup Function
*/

extern void vmSetup();

extern void vmReset();

extern void vmRun();

extern void vmStep();



#endif