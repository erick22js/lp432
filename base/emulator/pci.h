#ifndef EMU_PCI_H
#define EMU_PCI_H

#include "device.h"


/*
	State Properties of PCI
*/

#define PCI_MAX_DEVICES 16

struct Pci{
	//
	//	Set of Devices
	//
	Cpu *cpu_s; // The main connected CPU
	Bus *bus; // The main connected BUS
	Device *(devices[PCI_MAX_DEVICES]);
	uint32 count_connected;
	uint32 port_i;
};
//extern Pci pci_s;


/*
	Internal Control Functions for PCI
*/

extern bool pciReadDevice8(Pci *pci, uint16 reg, uint8 *data);
extern bool pciReadDevice16(Pci *pci, uint16 reg, uint16 *data);
extern bool pciReadDevice32(Pci *pci, uint16 reg, uint32 *data);
extern bool pciWriteDevice8(Pci *pci, uint16 reg, uint8 data);
extern bool pciWriteDevice16(Pci *pci, uint16 reg, uint16 data);
extern bool pciWriteDevice32(Pci *pci, uint16 reg, uint32 data);

extern bool pciRequestCpuInterruption(Pci *pci, Device *device);


/*
	Control Functions
*/
extern bool pciPlugDevice(Pci *pci, Device *device);

extern void pciSetup(Pci *pci, Bus *bus);
extern void pciReset(Pci *pci);
extern void pciStep(Pci *pci, uint32 cycles);


#endif