;ja 10, 10; teste
/*
	ABOUT
	
	This program is a indeed to test most parts of
	assembler and emulator, all information about
	the current execution of program is printed
	through the device port mapped at address 0xB
	character by character, is recommended to
	attach any listener to this port.
	All the required instructions needed to at least
	start this program and execute test are:
	- mov r32, im32
	- ja im32
	- jr im16
	- jr.eqz r32, im16
	- ba im32
	- psh r32
	- pop r32
	- ret
	- out im8, r8
	- inc r32
	
	With some luck and skill, every test should show
	"passed" status and show "All tests done!" as
	the last message.
	
*/

// Map the address of program ROM in memory
.address 0x8000
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
