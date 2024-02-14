// Map the address of program ROM in memory
.address 0x8000
ja sys_start


//
//	PROGRAM CONSTANTS
//

hello_world: .text "Hello World!"
hello_world_end: .byte 0


//
//	PROGRAM CODE
//

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


//
//	sys_start
//	desc: The first entry procedure in ROM
//
.scope sys_start
	// Setting up the stack
	mov esp, 0x7FFF
	// Call for function to print the "Hello World!"
	mov ebx, hello_world
	ba print_serial
	// Jump to system main loop
	ja sys_loop
.endscope


//
//	sys_loop
//	desc: Keeps running to avoid program leaks
//
.scope sys_loop
	ja sys_loop
.endscope
