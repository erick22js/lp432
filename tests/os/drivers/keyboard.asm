.onmark
.mark


//
//	MEMORY SYMBOLS
//
/*
.const key_buffer 0x1080 ; size = 7 * (1=code, 1=state)
.const key_seek 0x108E ; size = 1
.const key_bottom 0x108F ; size = 1
*/

//
//	CODE TEXT
//

//
//	Keyboard Interruption Handler
//
.scope intrKeyboardDevice
	// Saving old procedure values
	psh ebx
	psh edx
	psh ecx
	psh eax
	
	// Gathering the extenal device
	mov ebx, 0
	mov bl, [device_keyboard]
	jr.eqz ebx, @end
	
	// Processing event
	mov ecx, 0
	// Inputing Key data
	lsh ebx, 8
	add ebx, 8
	in edx, bx
	mov eax, edx
	and edx, 0x1FF ; Key Code
	rsh eax, 11 ; Key State
	
	// End of function
	end:
	pop eax
	pop ecx
	pop edx
	pop ebx
	ret
.endscope
