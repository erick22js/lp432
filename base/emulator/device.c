#include "device.h"
#include "pci.h"



//
//	Device Pci and Cpu Communication
//

bool devRequestCpuInterruption(Device *device){
	return pciRequestCpuInterruption(device->pci, device);
}

