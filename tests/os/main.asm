.address 0x8000
ja sys_start

//	MEMORY MAP
//	0x1000..0x103F => Interruption Vector
//	0x1040..0x10FF => System Properties
//	0x1100..0x14FF => Mapped Devices
//		0x0 -> Device Port
//		0x1 -> Device Type
//		0x2 -> Device Version
//		0x3 -> Device Vendor

//
//	MEMORY SYMBOLS
//

// Main devices
.const device_serial 0x1040 ;u32
.const device_keyboard 0x1044 ;u32
.const device_display 0x1048 ;u32


//
//	CODE TEXT
//

sys_start:
	ja sys_loop

sys_loop:
	ja sys_loop
