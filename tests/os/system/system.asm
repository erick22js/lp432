.onmark
.mark

.include "interruption.asm"
.include "console.asm"
.include "filesystem.asm"


//
//	MEMORY SYMBOLS
//

.const char_vector 0x2000 // Length: 0xD20


//
//	CODE TEXT
//

//
//	allDevicesOk
//	return:
//	- eax => 1 = yes or 0 = no
//
.scope allDevicesOk
	// Saving old procedure values
	psh ebx
	mov eax, 0
	
	// Gathering the external devices
	// Serial
	mov ebx, 0
	mov bl, [device_serial]
	jr.eqz ebx, @end
	// Display
	mov ebx, 0
	mov bl, [device_display]
	jr.eqz ebx, @end
	// Keyboard
	mov ebx, 0
	mov bl, [device_keyboard]
	jr.eqz ebx, @end
	// Disk
	mov ebx, 0
	mov bl, [device_disk]
	jr.eqz ebx, @end
	
	// End of function
	mov eax, 1
	end:
	pop ebx
	ret
.endscope
