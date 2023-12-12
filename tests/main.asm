// Map the address of program ROM in memory
.program_adr 0x8000
ja sys_start


//
//	CONSTANTS
//


//
//	PROGRAM CODE
//

.include "tests.asm"


//
//	sys_start
//	desc: The first entry procedure in ROM
//
.scope sys_start
	// Setting up the stack
	mov esp, 0x7FFF
	
	ba do_tests
	
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
