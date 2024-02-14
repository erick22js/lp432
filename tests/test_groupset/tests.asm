
//
//	TEXTS
//

text_test_regs_movs: .text "Test 1: Data \"mov\" to and between regs...\0"
text_test_movs_adrm: .text "Test 2: Data \"mov\" in memory...\0"
text_test_mem_wides: .text "Test 3: Memory different wides access...\0"
text_test_conv_xchg: .text "Test 4: Differents wides extension and data exchanges...\0"
text_test_stack: .text "Test 5: Stack pushes and pops...\0"
text_test_interruption: .text "Test 6: System interruption...\0"
text_test_software_flags: .text "Test 7: Software flags changes and integrity...\0"
text_test_jumps: .text "Test 8: Program jumps and branches...\0"
text_test_adds_subs: .text "Test 9: Instructions \"adc\", \"add\", \"sbb\" and \"sub\"...\0"
text_passed: .text "Passed!\n\0"
text_failed: .text "Failed!\n\0"
text_tests_done: .text "All tests done!\n\0"


//
//	VARYABLE SYMBOLS
//

//
//	CODE
//

.include "serial.asm"


// Test the moviment of data between and to registers
.scope test_regs_movs
	mov ebx, text_test_regs_movs
	ba print_serial
	
	// 32-bit literal moves
	mov eax, 0x10101010
	mov edx, 0x11111111
	mov ecx, 0x22222222
	mov ebx, 0x33333333
	mov eex, 0x44444444
	mov ehx, 0x55555555
	mov egx, 0x66666666
	mov efx, 0x77777777
	mov ex0, 0x88888888
	mov ex1, 0x99999999
	mov ex2, 0xAAAAAAAA
	mov ex3, 0xBBBBBBBB
	mov ess, 0xCCCCCCCC
	mov esd, 0xDDDDDDDD
	mov efp, (-1):SHalf
	
	// 16-bit literal moves
	mov ax, 0x8888
	mov dx, 0x9999
	mov cx, 0xAAAA
	mov bx, 0xBBBB
	mov ex, 0xCCCC
	mov hx, 0xDDDD
	mov gx, 0xEEEE
	mov fx, 0xFFFF
	mov x0, 0x0101
	mov x1, 0x1111
	mov x2, 0x2222
	mov x3, 0x3333
	mov ss, 0x4444
	mov sd, 0x5555
	mov fp, 0x7777:Byte
	
	// 8-bit literal moves
	mov al, 0xFF
	mov dl, 0x1F
	mov cl, 0x2F
	mov bl, 0x3F
	mov el, 0x4F
	mov hl, 0x5F
	mov gl, 0x6F
	mov fl, 0x7F
	mov l0, 0x8F
	mov l1, 0x9F
	mov l2, 0xAF
	mov l3, 0xBF
	
	// Overriding registers
	mov dx, ax
	mov bx, cx
	mov hx, ex
	mov fx, gx
	mov x1, x0
	mov x3, x2
	mov sd, ss
	
	// Saving registers
	mov [0x4000], eax
	mov [0x4004], edx
	mov [0x4008], ecx
	mov [0x400C], ebx
	mov [0x4010], eex
	mov [0x4014], ehx
	mov [0x4018], egx
	mov [0x401C], efx
	mov [0x4020], ex0
	mov [0x4024], ex1
	mov [0x4028], ex2
	mov [0x402C], ex3
	mov [0x4030], ess
	mov [0x4034], esd
	mov [0x4038], esp
	mov [0x403C], efp
	
	// Testing each saved data
	mov edx, [0x4000]
	cmp edx, 0x101088FF
	jr.ne @failed
	mov edx, [0x4004]
	cmp edx, 0x111188FF
	jr.ne @failed
	mov edx, [0x4008]
	cmp edx, 0x2222AA2F
	jr.ne @failed
	mov edx, [0x400C]
	cmp edx, 0x3333AA2F
	jr.ne @failed
	mov edx, [0x4010]
	cmp edx, 0x4444CC4F
	jr.ne @failed
	mov edx, [0x4014]
	cmp edx, 0x5555CC4F
	jr.ne @failed
	mov edx, [0x4018]
	cmp edx, 0x6666EE6F
	jr.ne @failed
	mov edx, [0x401C]
	cmp edx, 0x7777EE6F
	jr.ne @failed
	mov edx, [0x4020]
	cmp edx, 0x8888018F
	jr.ne @failed
	mov edx, [0x4024]
	cmp edx, 0x9999018F
	jr.ne @failed
	mov edx, [0x4028]
	cmp edx, 0xAAAA22AF
	jr.ne @failed
	mov edx, [0x402C]
	cmp edx, 0xBBBB22AF
	jr.ne @failed
	mov edx, [0x4030]
	cmp edx, 0xCCCC4444
	jr.ne @failed
	mov edx, [0x4034]
	cmp edx, 0xDDDD4444
	jr.ne @failed
	mov edx, [0x4038]
	cmp edx, esp
	jr.ne @failed
	mov edx, [0x403C]
	cmp edx, 0xFFFF0077
	jr.ne @failed
	
	// If the test has passed
	mov ebx, text_passed
	ba print_serial
	ret
	
	// If the test has failed
	failed:
	mov ebx, text_failed
	ba print_serial
	ret
.endscope

// Test data moviment to memory with many memory addressing modes
.scope test_movs_addresses
	mov ebx, text_test_movs_adrm
	ba print_serial
	
	// Resets the registers
	mov eax, 0
	mov edx, 0
	mov ecx, 0
	mov ebx, 0
	mov eex, 0
	mov ehx, 0
	mov egx, 0
	mov efx, 0
	mov ex0, 0
	mov ex1, 0
	mov ex2, 0
	mov ex3, 0
	mov ess, 0
	mov esd, 0
	mov efp, 0
	
	// Testing [NV:u8]
	mov eax, 0xBE1D01D0
	mov [0xFFFFFF10:Byte], eax
	mov edx, [0xFFFFFF10:Byte]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [NV:u16]
	mov eax, 0xBE1D01D0
	mov [0xFFFF0014:Half], eax
	mov edx, [0xFFFF0014:Half]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [NV:u32]
	mov eax, 0xBE1D01D0
	mov [0x00000018:Word], eax
	mov edx, [0x00000018:Word]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32]
	mov eax, 0xBE1D01D0
	mov ebx, 0x001C
	mov [ebx], eax
	mov edx, [ebx]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32 + NV:s8]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov [ebx, 0xFFFFFF00:Byte], eax
	mov edx, [ebx, 0xFFFFFF00:Byte]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32 + NV:s16]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov [ebx, 0xFFFF0004:Half], eax
	mov edx, [ebx, 0xFFFF0004:Half]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32 + NV:s32]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov [ebx, 0x00000008:Word], eax
	mov edx, [ebx, 0x00000008:Word]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32, reg1:s32]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 0x000C
	mov [ebx, ecx], eax
	mov edx, [ebx, ecx]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32, reg1:s32, NV:s8]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 0x0010
	mov [ebx, ecx, 0xFFFFFF00:Byte], eax
	mov edx, [ebx, ecx, 0xFFFFFF00:Byte]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32, reg1:s32, NV:s16]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 0x0010
	mov [ebx, ecx, 0xFFFF0004:Half], eax
	mov edx, [ebx, ecx, 0xFFFF0004:Half]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32, reg1:s32, NV:s32]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 0x0010
	mov [ebx, ecx, 0x00000008:Word], eax
	mov edx, [ebx, ecx, 0x00000008:Word]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32, reg1:s32.reg2:u32]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 0x000E
	mov eex, 2
	mov [ebx, ecx.eex], eax
	mov edx, [ebx, ecx.eex]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32, reg1:s32.reg2:u32, NV:s16]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 0x000E
	mov eex, 2
	mov [ebx, ecx.eex, 0xFFFF0004:Half], eax
	mov edx, [ebx, ecx.eex, 0xFFFF0004:Half]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32, reg1:s32.NV:u8]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 2
	mov [ebx, ecx.0xFFFFFF12:Byte], eax
	mov edx, [ebx, ecx.0xFFFFFF12:Byte]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32, reg1:s32.NV:u16]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 2
	mov [ebx, ecx.0xFFFF0014:Half], eax
	mov edx, [ebx, ecx.0xFFFF0014:Half]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32, reg1:s32.NV:u16]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 2
	mov [ebx, ecx.0x00000016:Word], eax
	mov edx, [ebx, ecx.0x00000016:Word]
	cmp eax, edx
	jr.ne @failed
	
	// If the test has passed
	mov ebx, text_passed
	ba print_serial
	ret
	
	// If the test has failed
	failed:
	mov ebx, text_failed
	ba print_serial
	ret
.endscope

// Test the diferent memory wide accesses
.scope test_movs_mem_wides
	mov ebx, text_test_mem_wides
	ba print_serial
	
	// Unsigned 8-bit
	mov al, 0x72
	mov [0x50]:Byte, al
	mov dl, [0x50]:Byte
	cmp al, dl
	jr.ne @failed
	
	// Unsigned 16-bit
	mov ax, 0x8C72
	mov [0x51]:Half, ax
	mov dx, [0x51]:Half
	cmp ax, dx
	jr.ne @failed
	
	// Unsigned 32-bit
	mov eax, 0x90908C72
	mov [0x53]:Word, eax
	mov edx, [0x53]:Word
	cmp eax, edx
	jr.ne @failed
	
	// Unsigned 8-bit to 16-bit register
	mov ax, 37
	mov [0x57]:Byte, al
	mov dx, [0x57]:Byte
	cmp ax, dx
	jr.ne @failed
	
	// Unsigned 16-bit to 32-bit register
	mov eax, 37
	mov [0x58]:Byte, al
	mov edx, [0x58]:Byte
	cmp eax, edx
	jr.ne @failed
	
	// Unsigned 32-bit to 32-bit register
	mov eax, 9237
	mov [0x59]:Half, ax
	mov edx, [0x59]:Half
	cmp eax, edx
	jr.ne @failed
	
	// If the test has passed
	mov ebx, text_passed
	ba print_serial
	ret
	
	// If the test has failed
	failed:
	mov ebx, text_failed
	ba print_serial
	ret
.endscope

// Test the different data sizes signed conversions and exchanges
.scope test_conv_xchg
	mov ebx, text_test_conv_xchg
	ba print_serial
	
	// Convert signed 8-bit to signed 16-bit
	cvbth dx, (-45):Byte
	cmp dx, (-45):Half
	jr.ne @failed
	mov ax, -45
	cvbth dx, al
	cmp ax, dx
	jr.ne @failed
	mov [0x60]:Byte, al
	cvbth dx, [0x60]:Byte
	cmp ax, dx
	jr.ne @failed
	
	// Convert signed 8-bit to signed 32-bit
	cvbtw edx, (-45):Byte
	cmp edx, (-45):Word
	jr.ne @failed
	mov eax, -45
	cvbtw edx, al
	cmp eax, edx
	jr.ne @failed
	mov [0x61]:Byte, al
	cvbtw edx, [0x61]:Byte
	cmp eax, edx
	jr.ne @failed
	
	// Convert signed 16-bit to signed 32-bit
	cvhtw edx, (-45):Half
	cmp edx, (-45):Word
	jr.ne @failed
	mov eax, -45
	cvhtw edx, ax
	cmp eax, edx
	jr.ne @failed
	mov [0x62]:Half, ax
	cvhtw edx, [0x62]:Half
	cmp eax, edx
	jr.ne @failed
	
	// Exchange data between registers
	mov eax, 0x11111111
	mov edx, 0x22222222
	xchg eax, edx
	cmp eax, 0x22222222
	jr.ne @failed
	cmp edx, 0x11111111
	jr.ne @failed
	
	//halt
	mov ecx, 0x33333333
	mov ebx, 0x44444444
	xchg cx, bx
	cmp ecx, 0x33334444
	jr.ne @failed
	cmp ebx, 0x44443333
	jr.ne @failed
	
	mov eex, 0x55555555
	mov ehx, 0x66666666
	xchg el, hl
	cmp eex, 0x55555566
	jr.ne @failed
	cmp ehx, 0x66666655
	jr.ne @failed
	
	// Exchange data between registers and memory
	mov edx, 0x88888888
	mov [0x68]:Word, edx
	xchg [0x68]:Word, eax
	mov edx, [0x68]:Word
	cmp eax, 0x88888888
	jr.ne @failed
	cmp edx, 0x22222222
	jr.ne @failed
	
	mov ebx, 0x9999
	mov [0x6C]:Half, bx
	xchg [0x6C]:Half, cx
	mov ebx, [0x6C]:Half
	cmp ecx, 0x33339999
	jr.ne @failed
	cmp ebx, 0x00004444
	jr.ne @failed
	
	mov ehx, 0xAA
	mov [0x6E]:Byte, hl
	xchg [0x6E]:Byte, el
	mov ehx, [0x6E]:Byte
	cmp eex, 0x555555AA
	jr.ne @failed
	cmp ehx, 0x00000066
	jr.ne @failed
	
	// If the test has passed
	mov ebx, text_passed
	ba print_serial
	ret
	
	// If the test has failed
	failed:
	mov ebx, text_failed
	ba print_serial
	ret
.endscope

// Test the all the related stack access instructions
.scope test_stack
	mov ebx, text_test_stack
	ba print_serial
	
	// Resets the registers
	mov eax, 0
	mov edx, 0
	mov ecx, 0
	mov ebx, 0
	mov eex, 0
	mov ehx, 0
	mov egx, 0
	mov efx, 0
	mov ex0, 0
	mov ex1, 0
	mov ex2, 0
	mov ex3, 0
	mov ess, 0
	mov esd, 0
	mov efp, 0
	
	// Test every push and pop
	mov al, 0x9E
	psh al
	pop dl
	cmp al, dl
	jr.ne @failed
	
	mov ax, 0x459E
	psh ax
	pop dx
	cmp ax, dx
	jr.ne @failed
	
	mov eax, 0xABAB459E
	psh eax
	pop edx
	cmp eax, edx
	jr.ne @failed
	
	mov al, [0x60]:Byte
	psh [0x60]:Byte
	pop dl
	cmp al, dl
	jr.ne @failed
	
	mov ax, [0x60]:Half
	psh [0x60]:Half
	pop dx
	cmp ax, dx
	jr.ne @failed
	
	mov eax, [0x60]:Word
	psh [0x60]:Word
	pop edx
	cmp eax, edx
	jr.ne @failed
	
	psh 0x95:Byte
	pop [0x70]:Byte
	mov al, [0x70]:Byte
	cmp al, 0x95:Byte
	jr.ne @failed
	
	psh 0x7395:Half
	pop [0x71]:Half
	mov ax, [0x71]:Half
	cmp ax, 0x7395:Half
	jr.ne @failed
	
	psh 0xB3847395:Word
	pop [0x73]:Word
	mov eax, [0x73]:Word
	cmp eax, 0xB3847395:Word
	jr.ne @failed
	
	psh 0x80009000:Word
	popst
	pshlst
	pop ax
	cmp ax, 0x9000:Half
	jr.ne @failed
	pshst
	pop eax
	cmp eax, 0x80009010:Word
	jr.ne @failed
	
	// If the test has passed
	mov ebx, text_passed
	ba print_serial
	ret
	
	// If the test has failed
	failed:
	mov ebx, text_failed
	ba print_serial
	ret
.endscope

// Test the interruption system
.scope test_interruption
	mov ebx, text_test_interruption
	ba print_serial
	
	mov ebx, 0x100
	mov ecx, 16
	fill_table:
		mov eax, callback:Word
		mov [ebx]:Word, eax
		add ebx, 4
		dec ecx
		jr.gtz ecx, @fill_table
	
	mov edx, 0x100:Word
	mvtitd edx
	mov edx, 0x1000:Word
	mvtisp edx
	
	wait_loop:
		int
		mov eax, [0xFF]:Byte
		jr.eqz eax, @wait_loop
	jr @passed
	
	.scope callback
		mov l0, 1
		mov [0xFF]:Byte, l0
		iret
	.endscope
	
	// If the test has passed
	passed:
	mov ebx, text_passed
	ba print_serial
	ret
	
	// If the test has failed
	failed:
	mov ebx, text_failed
	ba print_serial
	ret
.endscope

// Test all software flags change
.scope test_software_flags
	mov ebx, text_test_software_flags
	ba print_serial
	
	psh 0x00000000:Word
	popst
	setc
	setb
	setv
	setn
	setz
	seto
	pshst
	pop edx
	cmp edx, 0x0000003F
	jr.ne @failed
	
	psh 0x0000003F:Word
	popst
	clrc
	clrb
	clrv
	clrn
	clrz
	clro
	pshst
	pop edx
	cmp edx, 0x00000000
	jr.ne @failed
	
	// If the test has passed
	mov ebx, text_passed
	ba print_serial
	ret
	
	// If the test has failed
	failed:
	mov ebx, text_failed
	ba print_serial
	ret
.endscope

// Test all jumps and branches
.scope test_jumps
	mov ebx, text_test_jumps
	ba print_serial
	
	.scope
		mov eax, 37
		mov edx, 19
		cmp eax, edx
		jr.lt @failed
		jr.le @failed
		jr.bl @failed
		jr.be @failed
		jr.eq @failed
		jr.gt @t1
		jr @failed
		t1:
		jr.ge @t2
		jr @failed
		t2:
		jr.ab @t3
		jr @failed
		t3:
		jr.ae @t4
		jr @failed
		t4:
		jr.ne @t5
		jr @failed
		t5:
	.endscope
	
	.scope
		mov eax, 10
		mov edx, 79
		cmp eax, edx
		jr.gt @failed
		jr.ge @failed
		jr.ab @failed
		jr.ae @failed
		jr.eq @failed
		jr.lt @t1
		jr @failed
		t1:
		jr.le @t2
		jr @failed
		t2:
		jr.bl @t3
		jr @failed
		t3:
		jr.be @t4
		jr @failed
		t4:
		jr.ne @t5
		jr @failed
		t5:
	.endscope
	
	.scope
		mov eax, 973
		mov edx, 973
		cmp eax, edx
		jr.lt @failed
		jr.gt @failed
		jr.bl @failed
		jr.ab @failed
		jr.ne @failed
		jr.ge @t1
		jr @failed
		t1:
		jr.le @t2
		jr @failed
		t2:
		jr.ae @t3
		jr @failed
		t3:
		jr.be @t4
		jr @failed
		t4:
		jr.eq @t5
		jr @failed
		t5:
	.endscope
	
	.scope
		mov eax, 95
		mov edx, -39
		cmp eax, edx
		jr.lt @failed
		jr.le @failed
		jr.ab @failed
		jr.ae @failed
		jr.eq @failed
		jr.gt @t1
		jr @failed
		t1:
		jr.ge @t2
		jr @failed
		t2:
		jr.bl @t3
		jr @failed
		t3:
		jr.be @t4
		jr @failed
		t4:
		jr.ne @t5
		jr @failed
		t5:
	.endscope
	
	.scope
		mov eax, -102
		mov edx, 86
		cmp eax, edx
		jr.gt @failed
		jr.ge @failed
		jr.bl @failed
		jr.be @failed
		jr.eq @failed
		jr.lt @t1
		jr @failed
		t1:
		jr.le @t2
		jr @failed
		t2:
		jr.ab @t3
		jr @failed
		t3:
		jr.ae @t4
		jr @failed
		t4:
		jr.ne @t5
		jr @failed
		t5:
	.endscope
	
	.scope
		mov eax, -35
		mov edx, -126
		cmp eax, edx
		jr.lt @failed
		jr.le @failed
		jr.bl @failed
		jr.be @failed
		jr.eq @failed
		jr.gt @t1
		jr @failed
		t1:
		jr.ge @t2
		jr @failed
		t2:
		jr.ab @t3
		jr @failed
		t3:
		jr.ae @t4
		jr @failed
		t4:
		jr.ne @t5
		jr @failed
		t5:
	.endscope
	
	.scope
		mov eax, -195
		mov edx, -150
		cmp eax, edx
		jr.gt @failed
		jr.ge @failed
		jr.ab @failed
		jr.ae @failed
		jr.eq @failed
		jr.lt @t1
		jr @failed
		t1:
		jr.le @t2
		jr @failed
		t2:
		jr.bl @t3
		jr @failed
		t3:
		jr.be @t4
		jr @failed
		t4:
		jr.ne @t5
		jr @failed
		t5:
	.endscope
	
	.scope
		mov eax, -973
		mov edx, -973
		cmp eax, edx
		jr.lt @failed
		jr.gt @failed
		jr.bl @failed
		jr.ab @failed
		jr.ne @failed
		jr.ge @t1
		jr @failed
		t1:
		jr.le @t2
		jr @failed
		t2:
		jr.ae @t3
		jr @failed
		t3:
		jr.be @t4
		jr @failed
		t4:
		jr.eq @t5
		jr @failed
		t5:
	.endscope
	
	mov eax, xflow1:Word
	xjmp eax
	bef1:
	jr @failed
	bef2:
	
	mov eax, xflow2:Word
	xbch eax
	bef3:
	ja eax
	jr @failed
	bef4:
	
	// If the test has passed
	passed:
	mov ebx, text_passed
	ba print_serial
	ret
	
	xflow1:
	add eax, bef2-bef1
	ja eax
	
	xflow2:
	add eax, bef4-bef3
	ret
	
	// If the test has failed
	failed:
	mov ebx, text_failed
	ba print_serial
	ret
.endscope

// Test all adds and subs instructions
.scope test_adds_subs
	mov ebx, text_test_adds_subs
	ba print_serial
	
	mov ex0, 0x274389D1
	mov ex1, 0x75984726
	mov ex2, 0x35218932
	mov ex3, 0x598AB12E
	
	// Testing adds behaviors
	clrc
	mov eax, ex0
	add eax, ex1
	cmp eax, 0x9CDBD0F7
	jr.ne @failed
	
	add eax, ex1
	cmp eax, 0x1274181D
	jr.ne @failed
	
	adc eax, ex2
	adc eax, ex3
	adc eax, 0xFFFFFFFF
	cmp eax, 0xA120527D
	jr.ne @failed
	jr.cc @failed
	
	// Testing subs behaviors
	clrb
	mov eax, ex1
	sub eax, ex0
	cmp eax, 0x4E54BD55
	jr.ne @failed
	
	sub eax, ex3
	cmp eax, 0xF4CA0C27
	jr.ne @failed
	
	sbb eax, ex2
	sbb eax, ex1
	sbb eax, 0xFFFFFFFF
	clrz
	jr.ae @failed
	cmp eax, 0x4A103BD0
	jr.ne @failed
	
	// If the test has passed
	mov ebx, text_passed
	ba print_serial
	ret
	
	// If the test has failed
	failed:
	mov ebx, text_failed
	ba print_serial
	ret
.endscope

// Execute all the tests
.scope do_tests
	ba test_regs_movs
	ba test_movs_addresses
	ba test_movs_mem_wides
	ba test_conv_xchg
	ba test_stack
	ba test_interruption
	ba test_software_flags
	ba test_jumps
	ba test_adds_subs
	
	mov ebx, text_tests_done
	ba print_serial
	
	ret
.endscope
