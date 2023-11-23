.byte 10, 20
.include "include.asm"

.const oitenta 80
.const dezesseis 16

.macro sums dest:Reg16, data
	.byte 10, 20
	adc dest, data
	add eax, 1
	.byte 30, 40
.endmacro

.scope
	.byte 30, 40 
	teste:
		.byte 50, 60
		adc eax, @+teste2
	teste2:
.endscope
.byte 70, dezesseis

.scope
	sums bx, 99

	etiqueta:
	ja.eqz eax, etiqueta
.endscope
final:
.byte 90, 100
