#ifndef EMU_DEVICE_H
#define EMU_DEVICE_H

#include "common.h"


struct Device{
	//
	//	Device Internal Properties
	//
	bool active;
	uint16 port;

	//
	//	IO Ports Registers Access
	//
	uint8 (*read)(uint8 reg);
	void (*write)(uint8 reg, uint8 data);

	//
	//	Controllers
	//
	void (*step)(Device* self, uint32 cycles);

	//
	//	State Properties
	//
	uint32 api_data[4];
	void* api_refs[4];
};


#endif