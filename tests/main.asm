.adr 4
.include "include.asm"
teste:
	adc gl, bl
	adc eax, @+teste
