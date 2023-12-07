#ifndef EMU_DEVICE_H
#define EMU_DEVICE_H

#include "common.h"
#include "bus.h"


struct Device{
	//
	//	Device Internal Properties
	//
	bool active;
	uint16 port;

	//
	//	Bus Conection
	//
	Bus* bus;

	//
	//	IO Ports and Registers Access
	//
	uint8 regs[32];
	uint8 (*read)(Device* self, uint8 reg);
	void (*write)(Device* self, uint8 reg, uint8 data);

	//
	//	Controllers
	//
	void (*step)(Device* self, uint32 cycles);

	//
	//	State Properties for Custom devices design
	//
	uint32 api_data[8];
	void* api_refs[8];
};


//
//	Device Bus Access
//

#define devBusRead8(dev, adr) (dev->bus->read(adr))
#define devBusWrite8(dev, adr, data) {dev->bus->write(adr, data);}
#define devBusRead16(dev, adr) (dev->bus->read(adr)|(dev->bus->read(adr+1)<<8))
#define devBusWrite16(dev, adr, data) {dev->bus->write(adr, data); dev->bus->write(adr+1, data>>8);}
#define devBusRead32(dev, adr) (dev->bus->read(adr)|(dev->bus->read(adr+1)<<8)|(dev->bus->read(adr+2)<<16)|(dev->bus->read(adr+3)<<24))
#define devBusWrite32(dev, adr, data) {dev->bus->write(adr, data); dev->bus->write(adr+1, data>>8); dev->bus->write(adr+2, data>>16); dev->bus->write(adr+3, data>>24);}


#endif