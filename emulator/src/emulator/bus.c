#include "bus.h"



/*
	Functions for Access to BUS
*/

void busReset(){
	memset(mem_ram, 0, sizeof(mem_ram));
}

uint8 busRead(uint32 adr){
	if (adr < sizeof(mem_ram)){
		return mem_ram[adr];
	}
	return 0;
}

void busWrite(uint32 adr, uint8 data){
	if (adr < sizeof(mem_ram)){
		mem_ram[adr] = data;
	}
}
