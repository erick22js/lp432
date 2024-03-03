.onmark
.mark


//
//	MEMORY SYMBOLS
//

.const key_buffer 0x1080 ; size = 7 * (1=code, 1=state)
.const key_seek 0x108E ; size = 1
.const key_bottom 0x108F ; size = 1


//
//	CODE TEXT
//

.scope intrKeyboardDevice
	// Saving old procedure values
	psh ebx
	psh edx
	psh ecx
	psh eax
	psh eex
	psh ex0
	psh ex1
	psh ex2
	
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
	mov ebx, edx
	and edx, 0x1FF ; Keycode
	rsh ebx, 11 ; Keystate
	
	ba printHexadecimal
	
	// Retrieving characters size
	ba getDisplayWidth
	mov eex, eax
	ba getDisplayCharWidth
	div eex, eax
	
	// Calculating buffer address
	// Base buffer address
	mov ex2, char_vector
	// Line Offset
	mov ex0, eex
	mul ex0, 4
	mov ex1, edx
	rsh ex1, 4
	mul ex0, ex1
	add ex2, ex0
	// Character Offset
	mov ex0, edx
	and ex0, 0xF
	mul ex0, 4
	add ex2, ex0
	
	// Ploting Background
	mov el, 0xF0
	jr.eqz ebx, @not_press
		mov el, 0x0F
	not_press:
	mov [ex2, 3], el
	
	// End of function
	end:
	pop ex2
	pop ex1
	pop ex0
	pop eex
	pop eax
	pop ecx
	pop edx
	pop ebx
	ret
.endscope
