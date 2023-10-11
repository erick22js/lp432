.byte 10, 20
.include "include.asm"

.scope
	.byte 30, 40 
	teste:
		.byte 50, 60
		cs.adc eax, @+teste2
	teste2:
.endscope
.byte 70, 80
etiqueta:
ja.eqz eax, etiqueta
.byte 90, 100
