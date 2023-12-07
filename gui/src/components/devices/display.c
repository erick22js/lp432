#include "display.h"



/*
	Handling Callback Functions
*/

uint8 dsRead(Device* self, uint8 reg){
	return self->regs[reg];
}

void dsWrite(Device* self, uint8 reg, uint8 data){
	//self->regs[reg] = data;
}

void dsStep(Device* self, uint32 cycles){
	*(uint32*)(self->api_refs[0]) = devBusRead32(self, 0x00000000);
}


/*
	Display Device Functions
*/

void dsSetup(Device *dev, Monitor *mntr) {
	memset(dev, 0, sizeof(dev));
	dev->read = dsRead;
	dev->write = dsWrite;
	dev->step = dsStep;
	dev->active = true;
	((uint32*)dev->regs)[2] = mntr->buff_wid;
	((uint32*)dev->regs)[3] = mntr->buff_hei;
	dev->api_refs[0] = mntr->buffer;
}

void dsDestroy(Device *dev) {

}

