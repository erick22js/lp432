.address 0x8000
ja sysStart

//
//	MEMORY SYMBOLS
//

.const intr_address 0x1000
.const char_vector 0x2000

hello_text: .text "Hello World!\0"

//
//	CODE TEXT
//

.scope intrSetup
	iret
.endscope

.scope intrVecSetup
	psh eax
	
	// Sets all interruption vector to default interrupt function dealer and attrib the pointer
	mov eax, intrSetup
	mov [intr_address + 0x00], eax
	mov [intr_address + 0x04], eax
	mov [intr_address + 0x08], eax
	mov [intr_address + 0x0C], eax
	mov [intr_address + 0x10], eax
	mov [intr_address + 0x14], eax
	mov [intr_address + 0x18], eax
	mov [intr_address + 0x1C], eax
	mov [intr_address + 0x20], eax
	mov [intr_address + 0x24], eax
	mov [intr_address + 0x28], eax
	mov [intr_address + 0x2C], eax
	mov [intr_address + 0x30], eax
	mov [intr_address + 0x34], eax
	mov [intr_address + 0x38], eax
	mov [intr_address + 0x3C], eax
	mov eax, intr_address
	mvtitd eax
	
	// Sets the interruption stack to before vector and enables interruption
	mov eax, 0x7FFC
	mvtisp eax
	seti
	
	pop eax
	ret
.endscope

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

// System Code
.scope sysStart
	mov esp, 0x7F00
	
	// Initializing output devices
	ba intrVecSetup
	
	// Changing display buffer address
	mov bx, 0x210
	mov eax, char_vector
	out bx, eax
	
	// Enabling display
	mov bx, 0x218
	mov al, 1
	out bx, al
	
	// Drawing text on screen
	mov eax, hello_text
	ba drawText
	
	ja sysLoop
.endscope

.scope sysLoop
	ja sysLoop
.endscope






