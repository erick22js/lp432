.onmark
.mark


//
//	MEMORY SYMBOLS
//

.const intr_address 0x1000 // Length: 0x40
.const list_devices 0x1100 // Length: 0x100

//
//	CODE TEXT
//

.scope intrActNoAction
	mov eax, 0x80000000
	loop: jr @loop
	iret
.endscope

.scope intrActProtectionViolation
	mov eax, 0x80000001
	loop: jr @loop
	iret
.endscope

.scope intrActPageFault
	mov eax, 0x80000003
	loop: jr @loop
	iret
.endscope

.scope intrActSegmentNotPresent
	mov eax, 0x80000004
	loop: jr @loop
	iret
.endscope

.scope intrActDirectoryFault
	mov eax, 0x80000005
	loop: jr @loop
	iret
.endscope

.scope intrActDeniedMemoryAccess
	mov eax, 0x80000006
	loop: jr @loop
	iret
.endscope

.scope intrActDeniedCodeAccess
	mov eax, 0x80000007
	loop: jr @loop
	iret
.endscope

.scope intrActInvalidOpcode
	mov eax, 0x80000009
	loop: jr @loop
	iret
.endscope

.scope intrActDivisionByZero
	mov eax, 0x8000000A
	loop: jr @loop
	iret
.endscope

.scope intrActTimerInterruption
	mov eax, 0x8000000B
	loop: jr @loop
	iret
.endscope

.scope intrActDebuggerInterruption
	mov eax, 0x8000000C
	loop: jr @loop
	iret
.endscope

.scope intrActDeviceUnavailable
	mov eax, 0x8000000D
	loop: jr @loop
	iret
.endscope

.scope intrActSoftwareInterruption
	mov eax, 0x8000000E
	loop: jr @loop
	iret
.endscope

.scope intrActHardwareInterruption
	// Load the hardware port
	mvfir edx, ir0
	
	// Check if the device is already registered by program, if no, only do his registration, if yes, execute dedicated interruption routine (no for now)
	and edx, 0xFF
	mov ecx, edx
	add ecx, list_devices
	mov eax, [ecx]
	jr.nez eax, @register
	
	mov ecx, edx
	lsh ecx, 8
	in eax, cx
	mov ecx, edx
	add ecx, list_devices
	mov [ecx], al
	iret
	
	register:
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

