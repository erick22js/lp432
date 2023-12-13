#ifndef DEVICES_KEYBOARD_H
#define DEVICES_KEYBOARD_H

#include "emulator/device.h"
#include "../window/monitor.h"
#include "sli.h"


/*
	Display Device Functions
*/

extern void keySetup(Device *dev, Monitor *mntr);
extern void keyDestroy(Device *dev);


#endif