
//
//	TEXTS
//

text_test_regs_movs: .text "Test 1: Data \"mov\" to and between regs..."
text_test_movs_adrm: .text "Test 2: Data \"mov\" in memory..."
text_test_mem_wides: .text "Test 3: Memory different wides access..."
text_test_conv_xchg: .text "Test 4: Differents wides extension and data exchanges..."
text_passed: .text "Passed!\n"
text_failed: .text "Failed!\n"
text_tests_done: .text "All tests done!\n"


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
	mov [ebx + 0xFFFFFF00:Byte], eax
	mov edx, [ebx + 0xFFFFFF00:Byte]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32 + NV:s16]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov [ebx + 0xFFFF0004:Half], eax
	mov edx, [ebx + 0xFFFF0004:Half]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32 + NV:s32]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov [ebx + 0x00000008:Word], eax
	mov edx, [ebx + 0x00000008:Word]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32 + reg1:s32]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 0x000C
	mov [ebx + ecx], eax
	mov edx, [ebx + ecx]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32 + reg1:s32 + NV:s8]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 0x0010
	mov [ebx + ecx + 0xFFFFFF00:Byte], eax
	mov edx, [ebx + ecx + 0xFFFFFF00:Byte]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32 + reg1:s32 + NV:s16]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 0x0010
	mov [ebx + ecx + 0xFFFF0004:Half], eax
	mov edx, [ebx + ecx + 0xFFFF0004:Half]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32 + reg1:s32 + NV:s32]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 0x0010
	mov [ebx + ecx + 0x00000008:Word], eax
	mov edx, [ebx + ecx + 0x00000008:Word]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32 + reg1:s32 * reg2:u32]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 0x000E
	mov eex, 2
	mov [ebx + ecx*eex], eax
	mov edx, [ebx + ecx*eex]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32 + reg1:s32 * reg2:u32 + NV:s16]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 0x000E
	mov eex, 2
	mov [ebx + ecx*eex + 0xFFFF0004:Half], eax
	mov edx, [ebx + ecx*eex + 0xFFFF0004:Half]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32 + reg1:s32 * NV:u8]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 2
	mov [ebx + ecx*0xFFFFFF12:Byte], eax
	mov edx, [ebx + ecx*0xFFFFFF12:Byte]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32 + reg1:s32 * NV:u16]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 2
	mov [ebx + ecx*0xFFFF0014:Half], eax
	mov edx, [ebx + ecx*0xFFFF0014:Half]
	cmp eax, edx
	jr.ne @failed
	
	// Testing [regi:u32 + reg1:s32 * NV:u16]
	mov eax, 0xBE1D01D0
	mov ebx, 0x0020
	mov ecx, 2
	mov [ebx + ecx*0x00000016:Word], eax
	mov edx, [ebx + ecx*0x00000016:Word]
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

// Execute all the tests
.scope do_tests
	ba test_regs_movs
	ba test_movs_addresses
	ba test_movs_mem_wides
	ba test_conv_xchg
	
	mov ebx, text_tests_done
	ba print_serial
	
	ret
.endscope
