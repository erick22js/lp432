.onmark
.mark

.include "interruption.asm"


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

//
//	drawText
//	args:
//	- eax => null-terminated-String Source
//
.scope drawText
	psh eax
	mov ecx, char_vector
	loop:
		mov dl, [eax]
		and edx, 0xFF
		jr.eqz edx, @end
		or edx, 0xFF0000
		mov [ecx], edx
		add ecx, 4
		inc eax
		jr @loop
	end:
	pop eax
	ret
.endscope
