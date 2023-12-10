#include "cpu/cpu.h"
#include "pci.h"


/*
	State Properties of PCI
*/

//Pci pci_s;


/*
	Internal Control Functions for PCI
*/

#define IOA_TO_PORT_SHIFT 8
#define IOA_TO_REG_MASK 0xFF

bool pciReadDevice8(Pci *pci, uint16 reg, uint8 *data){
	uint16 port = reg>>IOA_TO_PORT_SHIFT;
	reg &= IOA_TO_REG_MASK;

	if (port>=PCI_MAX_DEVICES || pci->devices[port]==null){
		return false;
	}

	Device *dev = pci->devices[port];
	if (dev->read){
		data[0] = dev->read(dev, (uint8)reg);
	}
	else {
		data[0] = 0;
	}

	return true;
}

bool pciReadDevice16(Pci *pci, uint16 reg, uint16 *data){
	uint16 port = reg>>IOA_TO_PORT_SHIFT;
	reg &= IOA_TO_REG_MASK;

	if (port>=PCI_MAX_DEVICES || pci->devices[port]==null){
		return false;
	}

	Device *dev = pci->devices[port];
	if (dev->read){
		((uint8*)data)[0] = dev->read(dev, (uint8)reg);
		((uint8*)data)[1] = dev->read(dev, (uint8)reg+1);
	}
	else {
		((uint8*)data)[0] = 0;
		((uint8*)data)[1] = 0;
	}

	return true;
}

bool pciReadDevice32(Pci *pci, uint16 reg, uint32 *data){
	uint16 port = reg>>IOA_TO_PORT_SHIFT;
	reg &= IOA_TO_REG_MASK;

	if (port>=PCI_MAX_DEVICES || pci->devices[port]==null){
		return false;
	}

	Device *dev = pci->devices[port];
	if (dev->read){
		((uint8*)data)[0] = dev->read(dev, (uint8)reg);
		((uint8*)data)[1] = dev->read(dev, (uint8)reg+1);
		((uint8*)data)[2] = dev->read(dev, (uint8)reg+2);
		((uint8*)data)[3] = dev->read(dev, (uint8)reg+3);
	}
	else {
		((uint8*)data)[0] = 0;
		((uint8*)data)[1] = 0;
		((uint8*)data)[2] = 0;
		((uint8*)data)[3] = 0;
	}

	return true;
}

bool pciWriteDevice8(Pci *pci, uint16 reg, uint8 data){
	uint16 port = reg>>IOA_TO_PORT_SHIFT;
	reg &= IOA_TO_REG_MASK;

	if (port>=PCI_MAX_DEVICES || pci->devices[port]==null){
		return false;
	}

	Device *dev = pci->devices[port];
	if (dev->write){
		dev->write(dev, (uint8)reg, data);
	}

	return true;
}

bool pciWriteDevice16(Pci *pci, uint16 reg, uint16 data){
	uint16 port = reg>>IOA_TO_PORT_SHIFT;
	reg &= IOA_TO_REG_MASK;

	if (port>=PCI_MAX_DEVICES || pci->devices[port]==null){
		return false;
	}

	Device *dev = pci->devices[port];
	if (dev->write){
		dev->write(dev, (uint8)reg, (data)&0xFF);
		dev->write(dev, (uint8)reg+1, (data>>8)&0xFF);
	}

	return true;
}

bool pciWriteDevice32(Pci *pci, uint16 reg, uint32 data){
	uint16 port = reg>>IOA_TO_PORT_SHIFT;
	reg &= IOA_TO_REG_MASK;

	if (port>=PCI_MAX_DEVICES || pci->devices[port]==null){
		return false;
	}

	Device *dev = pci->devices[port];
	if (dev->write){
		dev->write(dev, (uint8)reg, (data)&0xFF);
		dev->write(dev, (uint8)reg+1, (data>>8)&0xFF);
		dev->write(dev, (uint8)reg+2, (data>>16)&0xFF);
		dev->write(dev, (uint8)reg+3, (data>>24)&0xFF);
	}

	return true;
}

bool pciRequestCpuInterruption(Pci *pci, Device *device){
	return cpuRequestInterrupt(pci->cpu_s, device->port);
}



/*
	Control Functions
*/
bool pciPlugDevice(Pci *pci, Device *device){
	while (pci->port_i < PCI_MAX_DEVICES){
		if (pci->devices[pci->port_i] == null){
			pci->count_connected++;
			pci->devices[pci->port_i] = device;
			device->pci = pci;
			device->port = pci->port_i;
			device->bus = pci->bus;
			pci->port_i++;
			return true;
		}
		pci->port_i++;
	}
	return false;
}

extern void pciSetup(Pci *pci, Bus *bus) {
	pci->count_connected = 0;
	pci->port_i = 1;
	for (int i = 0; i<PCI_MAX_DEVICES; i++){
		pci->devices[i] = null;
	}
	pci->bus = bus;
}

extern void pciReset(Pci *pci){
	pci->count_connected = 0;
	pci->port_i = 1;
	for (int i = 0; i<PCI_MAX_DEVICES; i++){
		pci->devices[i] = null;
	}
}

extern void pciStep(Pci *pci, uint32 cycles){
	for (int i = 0; i<PCI_MAX_DEVICES; i++){
		if (pci->devices[i] && pci->devices[i]->active && pci->devices[i]->step){
			pci->devices[i]->step(pci->devices[i], cycles);
		}
	}
}
