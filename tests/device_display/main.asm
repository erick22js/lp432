.address 0x8000
ja sys_start

//
//	MEMORY SYMBOLS
//

.const intr_address 0x1000


//
//	CODE TEXT
//

// Interruption Code
.scope intr_generic
	iret
.endscope

.scope intr_hardware
	iret
.endscope

// System Code
.scope sys_start
	// Setup interruption vector
	mov ex0, intr_generic
	mov ex3, intr_hardware
	mov [intr_address + 0x0*4], ex0
	mov [intr_address + 0x1*4], ex0
	mov [intr_address + 0x2*4], ex0
	mov [intr_address + 0x3*4], ex0
	mov [intr_address + 0x4*4], ex0
	mov [intr_address + 0x5*4], ex0
	mov [intr_address + 0x6*4], ex0
	mov [intr_address + 0x7*4], ex0
	mov [intr_address + 0x8*4], ex0
	mov [intr_address + 0x9*4], ex0
	mov [intr_address + 0xA*4], ex0
	mov [intr_address + 0xB*4], ex0
	mov [intr_address + 0xC*4], ex0
	mov [intr_address + 0xD*4], ex0
	mov [intr_address + 0xE*4], ex0
	mov [intr_address + 0xF*4], ex3
	
	ja sys_loop
.endscope

.scope sys_loop
	ja sys_loop
.endscope






