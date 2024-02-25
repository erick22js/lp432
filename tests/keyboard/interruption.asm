.onmark
.mark


//
//	MEMORY SYMBOLS
//

.const intr_address 0x1000 // Length: 0x40
.const device_serial 0x1040 // The main serial device port
.const device_display 0x1041 // The main display device port
.const device_keyboard 0x1042 // The main keyboard device port
.const list_devices 0x1100 // Length: 0x800

//
//	CODE TEXT
//

.include "serial.asm"
.include "keyboard.asm"

.scope intrActNoAction
	psh eax
	mov eax, 0x80000000
	halt
	loop: jr @loop
	pop eax
	iret
.endscope

.scope intrActProtectionViolation
	psh eax
	mov eax, 0x80000001
	halt
	loop: jr @loop
	pop eax
	iret
.endscope

.scope intrActPageFault
	psh eax
	mov eax, 0x80000003
	halt
	loop: jr @loop
	pop eax
	iret
.endscope

.scope intrActSegmentNotPresent
	psh eax
	mov eax, 0x80000004
	halt
	loop: jr @loop
	pop eax
	iret
.endscope

.scope intrActDirectoryFault
	psh eax
	mov eax, 0x80000005
	halt
	loop: jr @loop
	pop eax
	iret
.endscope

.scope intrActDeniedMemoryAccess
	psh eax
	mov eax, 0x80000006
	halt
	loop: jr @loop
	pop eax
	iret
.endscope

.scope intrActDeniedCodeAccess
	psh eax
	mov eax, 0x80000007
	halt
	loop: jr @loop
	pop eax
	iret
.endscope

.scope intrActInvalidOpcode
	psh eax
	mov eax, 0x80000009
	halt
	loop: jr @loop
	pop eax
	iret
.endscope

.scope intrActDivisionByZero
	psh eax
	mov eax, 0x8000000A
	halt
	loop: jr @loop
	pop eax
	iret
.endscope

.scope intrActTimerInterruption
	psh eax
	mov eax, 0x8000000B
	halt
	loop: jr @loop
	pop eax
	iret
.endscope

.scope intrActDebuggerInterruption
	psh eax
	mov eax, 0x8000000C
	halt
	loop: jr @loop
	pop eax
	iret
.endscope

.scope intrActDeviceUnavailable
	psh eax
	mov eax, 0x8000000D
	halt
	loop: jr @loop
	pop eax
	iret
.endscope

.scope intrActSoftwareInterruption
	psh eax
	mov eax, 0x8000000E
	halt
	loop: jr @loop
	pop eax
	iret
.endscope

.scope intrActHardwareInterruption
	psh eax
	psh edx
	psh ecx
	psh eex
	psh efx
	psh egx
	
	// Load the hardware port
	mvfir edx, ir0
	
	// Check if the device is already registered by program, if no, only do his registration, if yes, execute dedicated interruption routine (no for now)
	and edx, 0xFF
	mov ecx, edx
	mul ecx, 8
	add ecx, list_devices
	mov eax, [ecx]
	jr.nez eax, @driver_routine
	
	// Loading device type
	mov ecx, edx
	lsh ecx, 8
	in ex, cx
	// Loading device version
	add ecx, 2
	in fx, cx
	// Loading device vendor
	add ecx, 3
	in gx, cx
	// Saving device type
	mov ecx, edx
	mul ecx, 8
	add ecx, list_devices
	mov [ecx], el
	// Saving device vendor
	add ecx, 1
	mov [ecx], gl
	// Saving device version
	add ecx, 1
	mov [ecx], fx
	
	add ecx, 2
	mov ex0, 0
	// Serial Driver routine
	cmp eex, 1
	jr.ne @not_serial
		mov [device_serial], dl
		mov ex0, 0
	not_serial:
	// Keyboard Driver routine
	cmp eex, 4
	jr.ne @not_keyboard
		mov [device_keyboard], dl
		mov ex0, intrKeyboardDevice
	not_keyboard:
	// Display Driver routine
	cmp eex, 7
	jr.ne @not_display
		mov [device_display], dl
		mov ex0, 0
	not_display:
	mov [ecx], ex0
	
	pop egx
	pop efx
	pop eex
	pop ecx
	pop edx
	pop eax
	iret
	
	driver_routine:
		mov ecx, edx
		mul ecx, 8
		add ecx, list_devices+4
		mov ebx, [ecx]
		jr.eqz ebx, @no_operation
		// edx: Port index
		ba ebx
		
		no_operation:
		pop egx
		pop efx
		pop eex
		pop ecx
		pop edx
		pop eax
		iret
.endscope

.scope intrVecSetup
	psh eax
	
	// Sets all interruption vector to default interrupt function dealer and attrib the pointer
	mov eax, intrActNoAction
	mov [intr_address + 0x00], eax
	mov eax, intrActProtectionViolation
	mov [intr_address + 0x04], eax
	mov eax, intrActNoAction
	mov [intr_address + 0x08], eax
	mov eax, intrActPageFault
	mov [intr_address + 0x0C], eax
	mov eax, intrActSegmentNotPresent
	mov [intr_address + 0x10], eax
	mov eax, intrActDirectoryFault
	mov [intr_address + 0x14], eax
	mov eax, intrActDeniedMemoryAccess
	mov [intr_address + 0x18], eax
	mov eax, intrActDeniedCodeAccess
	mov [intr_address + 0x1C], eax
	mov eax, intrActNoAction
	mov [intr_address + 0x20], eax
	mov eax, intrActInvalidOpcode
	mov [intr_address + 0x24], eax
	mov eax, intrActDivisionByZero
	mov [intr_address + 0x28], eax
	mov eax, intrActTimerInterruption
	mov [intr_address + 0x2C], eax
	mov eax, intrActDebuggerInterruption
	mov [intr_address + 0x30], eax
	mov eax, intrActDeviceUnavailable
	mov [intr_address + 0x34], eax
	mov eax, intrActSoftwareInterruption
	mov [intr_address + 0x38], eax
	mov eax, intrActHardwareInterruption
	mov [intr_address + 0x3C], eax
	mov eax, intr_address
	mvtitd eax
	
	// Sets the interruption stack to before vector and enables interruption
	mov eax, 0x7FFC
	mvtisp eax
	seti
	
	pop eax
	ret
.endscope
