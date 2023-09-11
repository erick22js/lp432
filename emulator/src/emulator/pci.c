#include "cpu/cpu.h"
#include "pci.h"


/*
	State Properties of PCI
*/

Pci pci_s;


/*
	Internal Control Functions for PCI
*/

#define IOA_TO_PORT_SHIFT 5
#define IOA_TO_REG_MASK 0x1F

bool pciReadDevice8(uint16 reg, uint8 *data){
	uint16 port = reg>>IOA_TO_PORT_SHIFT;
	reg &= IOA_TO_REG_MASK;

	if (port>=PCI_MAX_DEVICES || pci_s.devices[port]==null){
		return false;
	}

	Device *dev = pci_s.devices[port];
	if (dev->read){
		data[0] = dev->read((uint8)reg);
	}

	return true;
}

bool pciReadDevice16(uint16 reg, uint16 *data){
	uint16 port = reg>>IOA_TO_PORT_SHIFT;
	reg &= IOA_TO_REG_MASK;

	if (port>=PCI_MAX_DEVICES || pci_s.devices[port]==null){
		return false;
	}

	Device *dev = pci_s.devices[port];
	if (dev->read){
		((uint8*)data)[0] = dev->read((uint8)reg);
		((uint8*)data)[1] = dev->read((uint8)reg+1);
	}

	return true;
}

bool pciReadDevice32(uint16 reg, uint32 *data){
	uint16 port = reg>>IOA_TO_PORT_SHIFT;
	reg &= IOA_TO_REG_MASK;

	if (port>=PCI_MAX_DEVICES || pci_s.devices[port]==null){
		return false;
	}

	Device *dev = pci_s.devices[port];
	if (dev->read){
		((uint8*)data)[0] = dev->read((uint8)reg);
		((uint8*)data)[1] = dev->read((uint8)reg+1);
		((uint8*)data)[2] = dev->read((uint8)reg+2);
		((uint8*)data)[3] = dev->read((uint8)reg+3);
	}

	return true;
}

bool pciWriteDevice8(uint16 reg, uint8 data){
	uint16 port = reg>>IOA_TO_PORT_SHIFT;
	reg &= IOA_TO_REG_MASK;

	if (port>=PCI_MAX_DEVICES || pci_s.devices[port]==null){
		return false;
	}

	Device *dev = pci_s.devices[port];
	if (dev->read){
		dev->write((uint8)reg, data);
	}

	return true;
}

bool pciWriteDevice16(uint16 reg, uint16 data){
	uint16 port = reg>>IOA_TO_PORT_SHIFT;
	reg &= IOA_TO_REG_MASK;

	if (port>=PCI_MAX_DEVICES || pci_s.devices[port]==null){
		return false;
	}

	Device *dev = pci_s.devices[port];
	if (dev->read){
		dev->write((uint8)reg, (data)&0xFF);
		dev->write((uint8)reg+1, (data>>8)&0xFF);
	}

	return true;
}

bool pciWriteDevice32(uint16 reg, uint32 data){
	uint16 port = reg>>IOA_TO_PORT_SHIFT;
	reg &= IOA_TO_REG_MASK;

	if (port>=PCI_MAX_DEVICES || pci_s.devices[port]==null){
		return false;
	}

	Device *dev = pci_s.devices[port];
	if (dev->read){
		dev->write((uint8)reg, (data)&0xFF);
		dev->write((uint8)reg+1, (data>>8)&0xFF);
		dev->write((uint8)reg+2, (data>>16)&0xFF);
		dev->write((uint8)reg+3, (data>>24)&0xFF);
	}

	return true;
}

bool pciRequestCpuInterruption(Device *device){
	return cpuRequestInterrupt(device->port);
}



/*
	Control Functions
*/
bool pciPlugDevice(Device *device){
	while (pci_s.port_i < PCI_MAX_DEVICES){
		if (pci_s.devices[pci_s.port_i] == null){
			pci_s.devices[pci_s.port_i] = device;
			device->port = pci_s.port_i;
			pci_s.port_i++;
			return true;
		}
		pci_s.port_i++;
	}
	return false;
}

extern void pciReset(){
	pci_s.port_i = 1;
	for (int i = 0; i<PCI_MAX_DEVICES; i++){
		pci_s.devices[i] = null;
	}
}

extern void pciStep(uint32 cycles){
	for (int i = 0; i<PCI_MAX_DEVICES; i++){
		if (pci_s.devices[i] && pci_s.devices[i]->active && pci_s.devices[i]->step){
			pci_s.devices[i]->step(pci_s.devices[i], cycles);
		}
	}
}
