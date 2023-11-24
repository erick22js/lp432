#include "common.h"


Emu g_emu;
Bus g_bus;
Cpu g_cpu;
Pci g_pci;

/*
	Functions for Access to BUS
*/

uint8 mem_ram[1024*1024*8];

void busReset() {
	memset(mem_ram, 0, sizeof(mem_ram));
}

uint8 busRead(uint32 adr) {
	if (adr < sizeof(mem_ram)){
		return mem_ram[adr];
	}
	return 0;
}

void busWrite(uint32 adr, uint8 data) {
	if (adr < sizeof(mem_ram)){
		mem_ram[adr] = data;
	}
}

/*
	Setup Function
*/

void vmSetup() {
	busSetup(&g_bus, busReset, busRead, busWrite);
	emuSetup(&g_emu, &g_cpu, &g_pci, &g_bus);
}

void vmReset() {
	emuReset(&g_emu);
}

void vmRun() {
	emuRun(&g_emu);
}

void vmStep() {
	emuStep(&g_emu);
}

