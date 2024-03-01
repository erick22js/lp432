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
	// Loading seek and addresses
	mov ebx, edx
	mov cl, [key_seek]
	mov eax, ecx
	lsh eax, 2
	add eax, key_buffer
	// Outputing Scancode
	and edx, 0x1FF
	mov [eax], dl
	// Outputing Key State
	rsh ebx, 11
	inc eax
	mov [eax], bl
	// Advancing and bounding seek
	inc ecx
	mod ecx, 0xE
	mov [key_seek], cl
	
	// Wrapping bottom
	mov eax, [key_bottom]
	cmp eax, ecx
	jr.ne @end
	inc eax
	mod eax, 0xE
	mov [key_bottom], eax
	
	// End of function
	end:
	pop eax
	pop ecx
	pop edx
	pop ebx
	ret
.endscope

//
//	consumeKey
//	return:
// - eax => Status (1 = Pressed, 0 = Released)
// - edx => Scancode (0 = No Key Press)
//
.scope consumeKey
	// Saving old procedure values
	psh ebx
	psh ecx
	
	mov eax, 0
	mov edx, 0
	
	// Analyzing bottom
	mov ecx, 0
	mov cl, [key_seek]
	mov ebx, 0
	mov bl, [key_bottom]
	cmp ecx, ebx
	jr.eq @end
	
	// Retrieving Key
	mov ecx, ebx
	lsh ecx, 2
	mov dl, [ecx, key_buffer]
	mov al, [ecx, key_buffer+1]
	
	// Updating Bottom
	inc ebx
	mod ebx, 0xE
	mov [key_bottom], ebx
	
	// End of function
	end:
	pop ecx
	pop ebx
	ret
.endscope
