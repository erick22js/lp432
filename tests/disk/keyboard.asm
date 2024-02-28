.onmark
.mark


//
//	CODE TEXT
//

.scope intrKeyboardDevice
	// Saving old procedure values
	psh edx
	
	// Gathering the extenal device
	mov ebx, 0
	mov bl, [device_keyboard]
	jr.eqz ebx, @end
	
	// Processing event
	lsh ebx, 8
	add ebx, 8
	in edx, bx
	ba printHexadecimal
	rsh edx, 8
	ba printHexadecimal
	
	// End of function
	end:
	pop edx
	ret
.endscope

