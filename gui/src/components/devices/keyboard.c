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

#define TICKS_DELAY 16

#define CTRL_STATE self->api_data[0]
#define CTRL_CYCLES self->api_data[1]
#define CTRL_KEYS(i) self->api_data[2 + i]
#define CTRL_MONITOR_BIND self->api_data[15]

#define STATUS_TYPE self->regs[0]
#define STATUS_TYPEH self->regs[1]
#define STATUS_VERSION self->regs[2]
#define STATUS_VERSIONH self->regs[3]
#define STATUS_VARYATION self->regs[4]
#define STATUS_VENDOR self->regs[5]
#define STATUS_FLAGS self->regs[6]
#define STATUS_READY_STATE self->regs[7]
#define REG_SCANCODE ((uint32*)self->regs)[2]


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
	if (CTRL_CYCLES < TICKS_DELAY){
		return;
	}
	CTRL_CYCLES -= TICKS_DELAY;

	// INIT STATE
	if (CTRL_STATE==-1){
		if (devRequestCpuInterruption(self)){
			printf("Keyboard interruption solved!\n");
			CTRL_STATE = 1;
		}
		return;
	}
	// STOP STATE
	else if (CTRL_STATE==0){
		return;
	}
	// BUSY STATE
	else if (CTRL_STATE==1){
		for (int i = 0; i < 4; i++){
			if (!CTRL_KEYS(i)){
				break;
			}
			if (CTRL_KEYS(i)&0x40000){
				if (devCanRequestCpuInterruption(self)){
					REG_SCANCODE = (CTRL_KEYS(i)&0xFFFF) | 0x400;
					devRequestCpuInterruption(self);
					CTRL_KEYS(i) &= ~0x40000;
				}
				break;
			}
			else if (CTRL_KEYS(i)&0x80000){
				if (devCanRequestCpuInterruption(self)){
					REG_SCANCODE = (CTRL_KEYS(i)&0xFFFF);
					devRequestCpuInterruption(self);
					for (; i < 3; i++){
						CTRL_KEYS(i) = CTRL_KEYS(i+1);
					}
					CTRL_KEYS(3) = 0;
				}
				break;
			}
		}
	}
}

void keyEventListener(SDL_Event *ev, void* *data){
	Device *self = data[1];
	bool down = ev->type == SDL_KEYDOWN;
	SDL_Keycode scancode = ev->key.keysym.sym;
	if (scancode&SDLK_SCANCODE_MASK){
		scancode &= ~SDLK_SCANCODE_MASK;
		scancode |= 0x200;
	}
	if (down){
		//printf("\ndown");
		for (int i = 0; i < 4; i++){
			if (!CTRL_KEYS(i)){
				CTRL_KEYS(i) = scancode | 0x40000;
				break;
			}
			else if ((CTRL_KEYS(i)&0xFFFF)==scancode){
				break;
			}
		}
	}
	else {
		//printf("\nup");
		for (int i = 0; i < 4; i++){
			if ((CTRL_KEYS(i)&0xFFFF)==scancode){
				CTRL_KEYS(i) |= 0x80000;
				break;
			}
		}
	}
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

	// Configure Control Properties
	CTRL_STATE = -1; // State
	CTRL_CYCLES = 0; // Cycles Counter
	CTRL_KEYS(0) = 0; // Key 1 Status Controller
	CTRL_KEYS(1) = 0; // Key 2 Status Controller
	CTRL_KEYS(2) = 0; // Key 3 Status Controller
	CTRL_KEYS(3) = 0; // Key 4 Status Controller

	// Configure Registers
	STATUS_TYPE = DEVICE_TYPE; // Device Type
	STATUS_TYPEH = DEVICE_TYPE>>8;
	STATUS_VERSION = DEVICE_VERSION; // Device Version
	STATUS_VERSIONH = DEVICE_VERSION>>8;
	STATUS_VARYATION = DEVICE_VARYATION; // Device Varyation
	STATUS_VENDOR = DEVICE_VENDOR; // Device Vendor
	STATUS_FLAGS = 0; // Device Control Flags
	STATUS_READY_STATE = 0; // Ready State
	REG_SCANCODE = 0; // Scancode Register

	// Add Keyboard Events Listener to monitor
	mntr->bind_data[1] = (void*)self;
	mntr->onKeyboardEvent = keyEventListener;
}

void keyDestroy(Device *dev) {

}

