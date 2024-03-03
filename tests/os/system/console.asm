.onmark
.mark

.include "../drivers/display.asm"
.include "../util/util.asm"


//
//	MEMORY SYMBOLS
//

.const console_seek 0x1900 // The current position in console buffer
.const console_limit 0x1904 // The limit for console buffer
.const console_stride 0x1908 // The number of character per line
.const console_fore 0x190C // The color of foreground character
.const console_back 0x190D // The color of background character
.const console_buffer 0x1A00 // Length: 0x400


//
//	CODE TEXT
//

//
//	cslInit
//
.scope cslInit
	// Saving old procedure values
	_saveCtx
	
	// Retrieving the stride of screen characters
	ba displayGetWidth
	mov eex, eax ; Width of console grid
	ba displayGetCharWidth
	div eex, eax
	ba displayGetHeight
	mov ehx, eax ; Height of console grid
	ba displayGetCharHeight
	div ehx, eax
	mov efx, eex ; Length of console buffer
	mul efx, ehx
	
	// Setting up the sizes info
	mov [console_stride], eex
	mov [console_limit], efx
	mov eax, 0
	mov [console_seek], eax
	mov hl, 0xFF
	mov [console_fore], hl
	mov hl, 0
	mov [console_back], hl
	
	// Cleaning the console
	mov ecx, 0
	clean:
		
		mov eax, 0
		mov ebx, ecx
		mul ebx, 4
		mov [ebx, char_vector], eax ; Instrução fedida
		
		inc ecx
		cmp ecx, efx
		jr.eq @clean
	
	
	// End of function
	end:
	_restoreCtx
	ret
.endscope

//
//	cslSeekSet
//	return:
//	- eax => The seek offset
//
.scope cslSeekSet
	// Saving old procedure values
	_saveCtx
	
	// Loading seek position and avoiding buffer overflow
	mov efx, [console_limit]
	mov [console_seek], efx
	cmp eax, efx
	jr.ae @end
	
	mov [console_seek], eax
	
	// End of function
	end:
	_restoreCtx
	ret
.endscope

//
//	cslSeekCur
//	return:
//	- eax => The seek offset
//
.scope cslSeekCur
	// Saving old procedure values
	_saveCtx
	
	// Loading seek position and avoiding buffer overflow
	mov ecx, [console_seek]
	add ecx, eax
	mov efx, [console_limit]
	mov [console_seek], efx
	cmp ecx, efx
	jr.ae @end
	
	mov [console_seek], ecx
	
	// End of function
	end:
	_restoreCtx
	ret
.endscope

//
//	cslEnded
//	return:
//	- eax => The status of buffer seek (True=overflow, False=valid)
//
.scope cslEnded
	// Saving old procedure values
	_saveCtx
	
	// Loading seek position and avoiding buffer overflow
	mov eax, 1
	mov ecx, [console_seek]
	mov efx, [console_limit]
	cmp ecx, efx
	jr.ae @end
	mov eax, 0
	
	// End of function
	end:
	_restoreCtx
	ret
.endscope

//
//	cslPut
//	args:
//	- al => Character combination to put
//
.scope cslPut
	// Saving old procedure values
	_saveCtx
	
	// Loading seek position and avoiding buffer overflow
	mov ecx, [console_seek]
	mov efx, [console_limit]
	cmp ecx, efx
	jr.ae @end
	
	// Storing data
	mov el, [console_back]
	mov hl, [console_fore]
	mov ebx, ecx
	mul ebx, 4
	mov [ecx, console_buffer], al
	mov [ebx, char_vector], al
	mov [ebx, char_vector+2], hl
	mov [ebx, char_vector+3], el
	
	// End of function
	end:
	_restoreCtx
	ret
.endscope

//
//	cslUnput
//
.scope cslUnput
	// Saving old procedure values
	_saveCtx
	
	// Loading seek position and avoiding buffer overflow
	mov ecx, [console_seek]
	mov efx, [console_limit]
	cmp ecx, efx
	jr.ae @end
	
	// Storing data
	mov el, [console_back]
	mov hl, [console_fore]
	mov ebx, ecx
	mul ebx, 4
	mov eax, 0
	mov [ecx, console_buffer], al
	mov [ebx, char_vector], eax
	
	// End of function
	end:
	_restoreCtx
	ret
.endscope

