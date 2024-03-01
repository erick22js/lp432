.address 0x8000
mov esp, 0x7F00
ja sysStart

.include "system.asm"


//
//	MEMORY SYMBOLS
//

hello_text: .text "Hello World!\0"


//
//	CODE TEXT
//

// System Code
.scope sysStart
	// Initializing output devices
	ba intrVecSetup
	
	// Waiting for all devices to be loaded
	.scope devs_wait
		ba allDevicesOk
		jr.eqz eax, @devs_wait
	.endscope
	
	// Changing display buffer address
	mov eax, char_vector
	ba changeDisplayBuffer
	
	// Enabling display
	mov al, 1
	ba enableDisplay
	
	// Drawing text on screen
	mov eax, hello_text
	ba drawText
	
	ja sysLoop
.endscope

.scope sysLoop
	// Rendering Text on Screen
	ba getDisplayWidth
	mov eex, eax
	ba getDisplayCharWidth
	div eex, eax
	mov ecx, 0
	mov ex0, 16
	lines:
		dec ex0
		mov ex1, 16
		char:
			// Calculating buffer address
			// Base buffer address
			mov ebx, char_vector
			// Line Offset
			mov eax, eex
			mul eax, 4
			mov edx, ecx
			rsh edx, 4
			mul eax, edx
			add ebx, eax
			// Character Offset
			mov eax, ecx
			and eax, 0xF
			mul eax, 4
			add ebx, eax
			
			// Ploting Character
			mov [ebx], cl
			mov al, 0xFF
			mov [ebx, 2], al
			inc ecx
			dec ex1
			jr.nez ex1, @char
		jr.nez ex0, @lines
	endlines:
	pull_key:
		ba consumeKey
		jr.eqz edx, @end_pull_key
		
		ba printHexadecimal
		// Calculating buffer address
		// Base buffer address
		mov ebx, char_vector
		// Line Offset
		mov ex0, eex
		mul ex0, 4
		mov ex1, edx
		rsh ex1, 4
		mul ex0, ex1
		add ebx, ex0
		// Character Offset
		mov ex0, edx
		and ex0, 0xF
		mul ex0, 4
		add ebx, ex0
		
		// Ploting Background
		mov el, 0xF0
		jr.eqz eax, @not_press
			mov el, 0x0F
		not_press:
		mov [ebx, 3], el
		
		jr @pull_key
	end_pull_key:
	ja sysLoop
.endscope
