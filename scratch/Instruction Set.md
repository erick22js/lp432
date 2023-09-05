
## Groups

Data Moviment
- mov

Arithmetic
- adc
- add
- and
- div
- lsh
- lrot
- mul
- or
- not
- rrot
- rsh
- sbb
- sub
- xor

Data test
- cmp
- test

Program Flow
- br
- brl
- jmp
- jl
- ret

System Control
- iret

## Encoding


## Adc

Adds immediate with carry to register
- x00 x0::os imm8 | adc r8, imm8
- x00 x0::os imm16 | adc r16, imm16
- x00 x0::os imm32 | adc r32, imm32

Adds value with carry between register
- x00 os | adc r8, r8
- x00 os | adc r16, r16
- x00 os | adc r32, r32

Adds memory with carry to register
- x00 x0::os ns | adc r8, \[adr]:Byte
- x00 x0::os ns | adc r16, \[adr]:Half
- x00 x0::os ns | adc r32, \[adr]:Word


## Mov

Moves immediate to register
- x00 x0::os imm8 | mov r8, imm8
- x00 x0::os imm16 | mov r16, imm16
- x00 x0::os imm32 | mov r32, imm32

Moves value between register
- x00 os | mov r8, r8
- x00 os | mov r16, r16
- x00 os | mov r32, r32

Moves register to memory
- x00 x0::os ns | mov \[adr]:Byte, r8
- x00 x0::os ns | mov \[adr]:Half, r16
- x00 x0::os ns | mov \[adr]:Word, r32

Moves memory to register
- x00 x0::os ns | mov r8, \[adr]:Byte
- x00 x0::os ns | mov r16, \[adr]:Half
- x00 x0::os ns | mov r32, \[adr]:Word

Moves immediate to memory
- x00 ns imm8 | mov \[adr]:Byte, imm8
- x00 \ns imm16 | mov \[adr]:Half, imm16
- x00 \ns imm32 | mov \[adr]:Word, imm32



