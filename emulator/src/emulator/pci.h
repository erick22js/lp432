#ifndef EMU_PCI_H
#define EMU_PCI_H

#include "device.h"


/*
	State Properties of PCI
*/

#define PCI_MAX_DEVICES 16

typedef struct{
	//
	//	Set of Devices
	//
	Device *(devices[PCI_MAX_DEVICES]);
	uint32 count_connected;
	uint32 port_i;
}Pci;
extern Pci pci_s;


/*
	Internal Control Functions for PCI
*/

extern bool pciReadDevice8(uint16 reg, uint8 *data);
extern bool pciReadDevice16(uint16 reg, uint16 *data);
extern bool pciReadDevice32(uint16 reg, uint32 *data);
extern bool pciWriteDevice8(uint16 reg, uint8 data);
extern bool pciWriteDevice16(uint16 reg, uint16 data);
extern bool pciWriteDevice32(uint16 reg, uint32 data);

extern bool pciRequestCpuInterruption(Device *device);


/*
	Control Functions
*/
extern bool pciPlugDevice(Device *device);

extern void pciReset();
extern void pciStep(uint32 cycles);


#endif