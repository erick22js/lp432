#include "device.h"
#include "pci.h"



//
//	Device Pci and Cpu Communication
//

bool devRequestCpuInterruption(Device *device){
	return pciRequestCpuInterruption(device->pci, device);
}

bool devCanRequestCpuInterruption(Device *device){
	return pciCanRequestCpuInterruption(device->pci, device);
}

