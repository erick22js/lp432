#include "keyboard.h"



/*
	Symbols Definition
*/

#define PIXELS_PER_TICK 32

#define CTRL_STATE self->api_data[0]
#define CTRL_CYCLES self->api_data[1]


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
	self->regs[0] = 1; // Device Type
	self->regs[1] = 0;
	self->regs[2] = 0; // Device Version
	self->regs[3] = 0;
	self->regs[4] = 0; // Device Varyation
	self->regs[5] = 0; // Device Vendor
	self->regs[6] = 0; // Device Control Flags
	self->regs[7] = 0; // Ready State
}

void keyDestroy(Device *dev) {

}
