#ifndef DEVICES_SERIAL_H
#define DEVICES_SERIAL_H

#include "emulator/device.h"
#include "../window/monitor.h"


/*
	Serial Device Functions
*/

extern void srlSetup(Device *dev, Monitor *mntr);
extern void srlDestroy(Device *dev);


#endif