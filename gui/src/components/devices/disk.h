#ifndef DEVICES_DISK_H
#define DEVICES_DISK_H

#include "emulator/device.h"
#include "../window/monitor.h"
#include "sli.h"


/*
	Display Device Functions
*/

extern void dskSetup(Device *dev, char* image, uint32 size);
extern void dskDestroy(Device *dev);


#endif