.address 0x8000
mov esp, 0x7F00
ja sysStart

.include "system.asm"


//
//	MEMORY SYMBOLS
//

hello_text: .text "Hello World!\0"


//
//	CODE TEXT
//

// System Code
.scope sysStart
	// Initializing output devices
	ba intrVecSetup
	
	// Waiting for all devices to be loaded
	.scope devs_wait
		ba allDevicesOk
		jr.eqz eax, @devs_wait
	.endscope
	
	// Changing display buffer address
	mov bx, 0x210
	mov eax, char_vector
	out bx, eax
	
	// Enabling display
	mov bx, 0x218
	mov al, 1
	out bx, al
	
	// Reading Data from Disk
	mov ess, 0x100
	mov esd, 0x10000
	mov ecx, 0x110
	ba readFromDisk
	
	// Drawing text on screen
	mov eax, hello_text
	ba drawText
	
	ja sysLoop
.endscope

.scope sysLoop
	ja sysLoop
.endscope
