.onmark
.mark


//
//	CODE TEXT
//

//
//	printHexa
//	desc: Prints a hexadecimal value to serial output
//args:
// - dl => numerical value
//
.scope printHexadecimal
	// Saving old procedure values
	psh ebx
	
	// Gathering the extenal device
	mov ebx, 0
	mov bl, [device_serial]
	jr.eqz ebx, @end
	
	// Outputing value to serial device
	lsh ebx, 8
	add ebx, 2
	out bx, dl
	
	// End of function
	end:
	pop ebx
	ret
.endscope

//
//	print_serial
//	desc: Prints a text string to serial output
//args:
// - ebx => address of string
//
.scope printString
	// Saving old procedure values
	psh ebx
	psh eax
	
	// Printing characters till find a zero
	mov eax, 0
	print_letter:
		mov al, [ebx]
		jr.eqz eax, @print_letter_end
		out 0xB, al
		inc ebx
		jr @print_letter
	print_letter_end:
	
	// Restoring the old values
	pop eax
	pop ebx
	ret
.endscope
