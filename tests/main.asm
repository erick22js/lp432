.adr 4
.include "include.asm"
teste:
	adc gl, bl
	cs.adc eax, @+teste
ja.eqz eax, teste
