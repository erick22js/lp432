ZERO:
.text "LP\\432"

.byte 0xE3, 20
.include "include.asm"
.include "include.asm"

.const oitenta 80
.const dezesseis 16

.macro add_one value:Imm32
	add eax, value+5
.endmacro

.macro sums dest:Greg16, data
	.byte 10, 20
	adc dest, data
	add_one 1
	add_one 2
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
