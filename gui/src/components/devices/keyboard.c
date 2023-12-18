#include "keyboard.h"



/*
	Device Info
*/

#define DEVICE_TYPE SLI_TYPE_KEYBOARD
#define DEVICE_VARYATION 1 // Main
#define DEVICE_VERSION 1 // First
#define DEVICE_VENDOR SLI_VENDOR_STANDARD


/*
	Symbols Definition
*/

#define PIXELS_PER_TICK 32

#define CTRL_STATE self->api_data[0]
#define CTRL_CYCLES self->api_data[1]

#define STATUS_TYPE self->regs[0]
#define STATUS_TYPEH self->regs[1]
#define STATUS_VERSION self->regs[2]
#define STATUS_VERSIONH self->regs[3]
#define STATUS_VARYATION self->regs[4]
#define STATUS_VENDOR self->regs[5]
#define STATUS_FLAGS self->regs[6]
#define STATUS_READY_STATE self->regs[7]


/*
	Handling Callback Functions
*/

uint8 keyRead(Device* self, uint8 reg){
	return self->regs[reg];
}

void keyWrite(Device* self, uint8 reg, uint8 data){
	if (reg >= 16){
		self->regs[reg] = data;
	}
}

void keyStep(Device* self, uint32 cycles){
	// CYCLE SYNC
	CTRL_CYCLES += cycles;
	if (CTRL_CYCLES < PIXELS_PER_TICK){
		return;
	}
	CTRL_CYCLES -= PIXELS_PER_TICK;

	// INIT STATE
	if (CTRL_STATE==-1){
		if (devRequestCpuInterruption(self)){
			printf("Keyboard interruption solved!\n");
			CTRL_STATE = 0;
		}
		return;
	}
	// STOP STATE
	else if (CTRL_STATE==0){
		return;
	}
}

void keyEventListener(SDL_Event *ev){
	//printf("Event on runner\n");
}


/*
	Display Device Functions
*/

void keySetup(Device *self, Monitor *mntr) {
	// Configure Device Object
	memset(self, 0, sizeof(self));
	self->read = keyRead;
	self->write = keyWrite;
	self->step = keyStep;
	self->active = true;

	// Add Keyboard Events Listener to monitor
	mntr->onKeyboardEvent = keyEventListener;

	// Configure Control Properties
	CTRL_STATE = -1; // State
	CTRL_CYCLES = 0; // Cycles Counter

	// Configure Registers
	STATUS_TYPE = DEVICE_TYPE; // Device Type
	STATUS_TYPEH = DEVICE_TYPE>>8;
	STATUS_VERSION = DEVICE_VERSION; // Device Version
	STATUS_VERSIONH = DEVICE_VERSION>>8;
	STATUS_VARYATION = DEVICE_VARYATION; // Device Varyation
	STATUS_VENDOR = DEVICE_VENDOR; // Device Vendor
	STATUS_FLAGS = 0; // Device Control Flags
	STATUS_READY_STATE = 0; // Ready State
}

void keyDestroy(Device *dev) {

}

