.onmark SERIAL_ASM
.mark SERIAL_ASM

//
//	print_serial
//	desc: Prints a text string to serial output
//args:
// - ebx => address of string
//
.scope print_serial
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
