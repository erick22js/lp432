#include "common.h"


Monitor monitor;

// Main components
Emu g_emu;
Bus g_bus;
Cpu g_cpu;
Pci g_pci;

// Peripherals
Device g_serial;
Device g_display;
Device g_keyboard;
Device g_disk;


/*
	Functions for configuration
*/

void cfgFlush() {
	iniObjectSave("config.ini", config);
}


/*
	Functions for Access to BUS
*/

uint8* mem_ram = NULL;
uint32 mem_ram_length = 0;

void busReset() {
	memset(mem_ram, 0, sizeof(mem_ram));
}

uint8 busRead(uint32 adr) {
	if (adr < mem_ram_length){
		return mem_ram[adr];
	}
	return 0;
}

void busWrite(uint32 adr, uint8 data) {
	if (adr < mem_ram_length){
		mem_ram[adr] = data;
	}
}


/*
	Setup Function
*/

void vmSetup() {
	busSetup(&g_bus, busReset, busRead, busWrite);
	emuSetup(&g_emu, &g_cpu, &g_pci, &g_bus);
	pciSetup(&g_pci, &g_bus);

	// Setup ram
	mem_ram_length = iniObjectHasKey(setup, "ramsize")? (uint32)iniObjectGetKeyAsNumber(setup, "ramsize"): 1024*256;
	mem_ram = (uint8*)malloc(mem_ram_length);
	memset(mem_ram, 0, mem_ram_length);

	// Preload rom
	if (iniObjectHasKey(setup, "rompath")){
		const char* path = iniObjectGetKeyAsText(setup, "rompath");

		FILE *file;
		errno_t err;
		if ((err = fopen_s(&file, path, "rb"))){
			//printf("Error on loading rom file at path \"%s\", cause => %i\n", path, err);
		}
		if (!file){
			printf("Rom in path \"%s\" does not exists!\n", path);
		}
		else {
			printf("Loading rom at path \"%s\"...\n", path);
			fseek(file, 0, SEEK_END);
			long size = ftell(file);
			fseek(file, 0, SEEK_SET);

			uint32 offset = iniObjectGetKeyAsHex(setup, "romoffset");
			while (size){
				busWrite(offset, fgetc(file)&0xFF);
				offset++;
				size--;
			}
			fclose(file);
		}
	}

	// Setup cpu jump address
	g_cpu.reg_pc = iniObjectGetKeyAsHex(setup, "startadr");

	// Setup main monitor
	mntrOpen(&monitor, "monitor", 640, 512, 320, 256, false, false, true);

	// Setup peripheral devices
	srlSetup(&g_serial, &monitor);
	pciPlugDevice(&g_pci, &g_serial);
	dsSetup(&g_display, &monitor);
	pciPlugDevice(&g_pci, &g_display);
	keySetup(&g_keyboard, &monitor);
	pciPlugDevice(&g_pci, &g_keyboard);
	dskSetup(&g_disk, "storage.img", 128);
	pciPlugDevice(&g_pci, &g_disk);
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

