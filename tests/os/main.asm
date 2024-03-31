.address 0x8000
mov esp, 0x7F00
ja sysStart

.include "system/system.asm"


//
//	MEMORY SYMBOLS
//

hello_text: .text "HELLO LUIS OS!\0"


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
	mov eax, char_vector
	ba displayChangeBuffer
	
	// Enabling display
	mov al, 1
	ba displayEnable
	
	// Starting console
	ba cslInit
	
	// Setup File System
	ba fsSetup
	// Format Disk partition
	loop_disk:
		ba fsBusy
		jr.nez eax, @loop_disk
	ba fsFormat
	// Allocate clusters
	loop_disk2:
		ba fsBusy
		jr.nez eax, @loop_disk2
	mov ebx, 0x4000
	mov ecx, 3
	ba _fsClusterAllocate
	mov ebx, 0x4010
	mov ecx, 20
	ba _fsClusterAllocate
	mov ebx, 0x4010
	mov ecx, 7
	ba _fsClusterFree
	
	// Putting character to console
	mov ess, hello_text
	mov eax, 0
	mov al, [ess]
	loop_text:
		ba cslPut
		mov al, 1
		ba cslSeekCur
		inc ess
		mov al, [ess]
		jr.nez eax, @loop_text
	
	ja sysLoop
.endscope

.scope sysLoop
	ja sysLoop
.endscope
