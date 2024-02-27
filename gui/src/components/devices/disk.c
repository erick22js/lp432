#include "keyboard.h"



/*
	Device Info
*/

#define DEVICE_TYPE SLI_TYPE_DISK_DRIVE
#define DEVICE_VARYATION 1 // Main
#define DEVICE_VERSION 1 // First
#define DEVICE_VENDOR SLI_VENDOR_STANDARD


/*
	Symbols Definition
*/

#define TICKS_DELAY 128

#define CTRL_STATE self->api_data[0]
#define CTRL_CYCLES self->api_data[1]
#define CTRL_IMAGE self->api_refs[0]

#define STATUS_TYPE self->regs[0]
#define STATUS_TYPEH self->regs[1]
#define STATUS_VERSION self->regs[2]
#define STATUS_VERSIONH self->regs[3]
#define STATUS_VARYATION self->regs[4]
#define STATUS_VENDOR self->regs[5]
#define STATUS_FLAGS self->regs[6]
#define STATUS_READY_STATE self->regs[7]
#define REG_DISK_SIZE ((uint32*)self->regs)[2]
#define REG_DISK_SEEK ((uint32*)self->regs)[3]
#define REG_MEM_SEEK ((uint32*)self->regs)[4]
#define REG_LENGTH ((uint32*)self->regs)[5]
#define REG_CONTROL self->regs[24]


/*
	Handling Callback Functions
*/

uint8 dskRead(Device* self, uint8 reg){
	if (reg==24){
		if (CTRL_STATE==0){
			return 0;
		}
		if (CTRL_STATE==1){
			return 0x02;
		}
		if (CTRL_STATE==2){
			return 0x04;
		}
		return 0x01;
	}
	return self->regs[reg];
}

void dskWrite(Device* self, uint8 reg, uint8 data){
	if (reg==24){
		if (data&0x02 && CTRL_STATE==0){
			CTRL_STATE = 1;
		}
		if (data&0x04 && CTRL_STATE==0){
			CTRL_STATE = 2;
		}
		return;
	}
	else if (reg >= 12){}
	else {
		return;
	}
	self->regs[reg] = data;
}

void dskStep(Device* self, uint32 cycles){
	// CYCLE SYNC
	CTRL_CYCLES += cycles;
	if (CTRL_CYCLES < TICKS_DELAY){
		return;
	}
	CTRL_CYCLES -= TICKS_DELAY;

	// INIT STATE
	if (CTRL_STATE==-1){
		if (devRequestCpuInterruption(self)){
			printf("Disk interruption solved!\n");
			CTRL_STATE = 0;
		}
		return;
	}
	// WAIT STATE
	else if (CTRL_STATE==0){
		return;
	}
	// READ STATE
	else if (CTRL_STATE==1){
		for (int i = 0; i<16 && REG_LENGTH && REG_DISK_SEEK<REG_DISK_SIZE; i++){
			fseek(CTRL_IMAGE, REG_DISK_SEEK, SEEK_SET);
			devBusWrite8(self, REG_MEM_SEEK, fgetc(CTRL_IMAGE));
			REG_DISK_SEEK++; REG_MEM_SEEK++;
			REG_LENGTH--;
		}
		if (REG_DISK_SEEK>=REG_DISK_SIZE || !REG_LENGTH){
			CTRL_STATE = 8;
		}
	}
	// WRITE STATE
	else if (CTRL_STATE==2){
		for (int i = 0; i<16 && REG_LENGTH && REG_DISK_SEEK<REG_DISK_SIZE; i++){
			fseek(CTRL_IMAGE, REG_DISK_SEEK, SEEK_SET);
			fputc(devBusRead8(self, REG_MEM_SEEK), CTRL_IMAGE);
			REG_DISK_SEEK++; REG_MEM_SEEK++;
			REG_LENGTH--;
		}
		if (REG_DISK_SEEK>=REG_DISK_SIZE || !REG_LENGTH){
			CTRL_STATE = 8;
			fflush(CTRL_IMAGE);
		}
	}
	// DONE STATE
	else if (CTRL_STATE==8){
		if (devRequestCpuInterruption(self)){
			CTRL_STATE = 0;
		}
		return;
	}
}


/*
	Display Device Functions
*/

void dskSetup(Device *self, char* image, uint32 isize) {
	// Configure Device Object
	memset(self, 0, sizeof(self));
	self->read = dskRead;
	self->write = dskWrite;
	self->step = dskStep;
	self->active = true;

	// Setup file image
	FILE *file = null;
	while (!file){
		if (fopen_s(&file, image, "r+b")){
			fopen_s(&file, image, "wb");
			fseek(file, 1024*1024*isize, SEEK_SET);
			fputc(0, file);
			fclose(file);
			file = null;
		}
		else {
			break;
		}
	}
	fseek(file, 0, SEEK_END);
	uint32 img_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	// Configure Control Properties
	CTRL_STATE = -1; // State
	CTRL_CYCLES = 0; // Cycles Counter
	CTRL_IMAGE = file; // Image File Reference

	// Configure Registers
	STATUS_TYPE = DEVICE_TYPE; // Device Type
	STATUS_TYPEH = DEVICE_TYPE>>8;
	STATUS_VERSION = DEVICE_VERSION; // Device Version
	STATUS_VERSIONH = DEVICE_VERSION>>8;
	STATUS_VARYATION = DEVICE_VARYATION; // Device Varyation
	STATUS_VENDOR = DEVICE_VENDOR; // Device Vendor
	STATUS_FLAGS = 0; // Device Control Flags
	STATUS_READY_STATE = 0; // Ready State
	REG_DISK_SIZE = img_size; // The Size of Disk Image
}

void dskDestroy(Device *dev) {

}

