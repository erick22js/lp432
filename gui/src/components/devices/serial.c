#include "serial.h"



/*
	Device Info
*/

#define DEVICE_TYPE SLI_TYPE_SERIAL
#define DEVICE_VARYATION 1 // Main
#define DEVICE_VERSION 1 // First
#define DEVICE_VENDOR SLI_VENDOR_STANDARD


/*
	Symbols Definition
*/

#define PIXELS_PER_TICK 32

#define CTRL_STATE self->api_data[0]
#define CTRL_CYCLES self->api_data[1]


/*
	Handling Callback Functions
*/

uint8 srlRead(Device* self, uint8 reg){
	return self->regs[reg];
}

void srlWrite(Device* self, uint8 reg, uint8 data){
	switch (reg){
		case 1: {
			printf(" %d", data);
		}
		break;
		case 2: {
			printf(" 0x%X", data);
		}
		break;
		case 3: {
			printf("%c", data);
		}
		break;
	}
}

void srlStep(Device* self, uint32 cycles){
	// CYCLE SYNC
	CTRL_CYCLES += cycles;
	if (CTRL_CYCLES < PIXELS_PER_TICK){
		return;
	}
	CTRL_CYCLES -= PIXELS_PER_TICK;

	// INIT STATE
	if (CTRL_STATE==-1){
		if (devRequestCpuInterruption(self)){
			printf("Serial interruption solved!\n");
			CTRL_STATE = 0;
		}
		return;
	}
	// STOP STATE
	else if (CTRL_STATE==0){
		return;
	}
}


/*
	Display Device Functions
*/

void srlSetup(Device *self, Monitor *mntr) {
	// Configure Device Object
	memset(self, 0, sizeof(self));
	self->read = srlRead;
	self->write = srlWrite;
	self->step = srlStep;
	self->active = true;

	// Configure Control Properties
	CTRL_STATE = -1; // State
	CTRL_CYCLES = 0; // Cycles Counter

	// Configure Registers
	self->regs[0] = DEVICE_TYPE; // Device Type #Input data
	self->regs[1] = DEVICE_TYPE>>8; // #Input data (also show in host console as decimal value)
	self->regs[2] = DEVICE_VERSION; // Device Version #Input data (also show in host console as hexadecimal value)
	self->regs[3] = DEVICE_VERSION>>8; // #Input data (also show in host console as character value)
	self->regs[4] = DEVICE_VARYATION; // Device Varyation
	self->regs[5] = DEVICE_VENDOR; // Device Vendor
	self->regs[6] = 0; // Device Control Flags
	self->regs[7] = 0; // #Output data from Serial Device
}

void srlDestroy(Device *dev) {

}

