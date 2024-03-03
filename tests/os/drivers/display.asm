.onmark
.mark


//
//	MEMORY SYMBOLS
//

//
//	CODE TEXT
//

//
//	Display Interruption Handler
//
.scope intrDisplayDevice
	// Saving old procedure values
	psh edx
	
	// End of function
	end:
	pop edx
	ret
.endscope

//
//	displayEnable
//	desc: Changes the display view status
// - al => enable status (0=False, 1=True)
//
.scope displayEnable
	// Saving old procedure values
	psh ebx
	psh eax
	
	// Gathering the extenal device
	mov ebx, 0
	mov bl, [device_display]
	jr.eqz ebx, @end
	
	// Outputing value to device
	lsh ebx, 8
	add ebx, 0x18
	out bx, al
	
	// End of function
	end:
	pop eax
	pop ebx
	ret
.endscope

//
//	displayChangeBuffer
//	desc: Change the display for buffer loading in display rendering
// - eax => Address buffer
//
.scope displayChangeBuffer
	// Saving old procedure values
	psh ebx
	psh eax
	
	// Gathering the extenal device
	mov ebx, 0
	mov bl, [device_display]
	jr.eqz ebx, @end
	
	// Outputing value to device
	lsh ebx, 8
	add bx, 0x10
	out bx, eax
	
	// End of function
	end:
	pop eax
	pop ebx
	ret
.endscope

//
//	displayGetWidth
//	return:
//	- eax => Width of display
//
.scope displayGetWidth
	// Saving old procedure values
	psh ebx
	mov eax, 0
	
	// Gathering the extenal device
	mov ebx, 0
	mov bl, [device_display]
	jr.eqz ebx, @end
	
	// Inputing the data
	lsh ebx, 8
	add bx, 8
	in eax, bx
	
	// End of function
	end:
	pop ebx
	ret
.endscope

//
//	displayGetHeight
//	return:
//	- eax => Heigth of display
//
.scope displayGetHeight
	// Saving old procedure values
	psh ebx
	mov eax, 0
	
	// Gathering the extenal device
	mov ebx, 0
	mov bl, [device_display]
	jr.eqz ebx, @end
	
	// Inputing the data
	lsh ebx, 8
	add bx, 12
	in eax, bx
	
	// End of function
	end:
	pop ebx
	ret
.endscope

//
//	displayGetCharWidth
//	return:
//	- eax => Width of display characters
//
.scope displayGetCharWidth
	// Saving old procedure values
	psh ebx
	mov eax, 0
	
	// Gathering the extenal device
	mov ebx, 0
	mov bl, [device_display]
	jr.eqz ebx, @end
	
	// Inputing the data
	mov eax, 8
	
	// End of function
	end:
	pop ebx
	ret
.endscope

//
//	displayGetCharHeight
//	return:
//	- eax => Height of display characters
//
.scope displayGetCharHeight
	// Saving old procedure values
	psh ebx
	mov eax, 0
	
	// Gathering the extenal device
	mov ebx, 0
	mov bl, [device_display]
	jr.eqz ebx, @end
	
	// Inputing the data
	mov eax, 12
	
	// End of function
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
	psh edx
	psh ecx
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
	pop ecx
	pop edx
	pop eax
	ret
.endscope
