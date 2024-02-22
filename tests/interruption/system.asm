.onmark
.mark

.include "interruption.asm"

//
//	MEMORY SYMBOLS
//

.const char_vector 0x2000 // Length: 0xD20

//
//	CODE TEXT
//

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
