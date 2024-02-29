.onmark
.mark


//
//	CODE TEXT
//

//
//	enableDisplay
//	desc: Changes the display view status
// - al => enable status (0=False, 1=True)
//
.scope enableDisplay
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
//	changeDisplayBuffer
//	desc: Change the display for buffer loading in display rendering
// - eax => Address buffer
//
.scope changeDisplayBuffer
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

