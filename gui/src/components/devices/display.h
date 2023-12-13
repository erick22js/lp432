#ifndef DEVICES_DISPLAY_H
#define DEVICES_DISPLAY_H

#include "emulator/device.h"
#include "../window/monitor.h"
#include "sli.h"


/*
	Display Device Functions
*/

extern void dsSetup(Device *dev, Monitor *mntr);
extern void dsDestroy(Device *dev);


#endif