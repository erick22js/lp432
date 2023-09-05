\---|x00 |x01 |x02 |x03 |x04 |x05 |x06 |x07 |x08 |x09 |x0A |x0B |x0C |x0D |x0E |x0F
-- |-- |-- |-- |-- |-- |-- |-- |-- |-- |-- |-- |-- |-- |-- |-- |--
x00|
x10|
x20|
x30|
x40|
x50|
x60|
x70|
x80|adc r8, r8|adc r16, r16|adc r32, r32
x90|
xA0|
xB0|
xC0|
xD0|
xE0|
xF0|

/\*
**Composing Instructions**
Groups of:
- Operands size: 8, 16 or 32-bits;
- Operands order;
Consider by:
- Registers as operand used ammount, or none;
- Memory access, with aside operands definition;
\*/


Row x00
- x00 ->
- x01 ->
- x02 ->
- x03 ->
- x04 ->
- x05 ->
- x06 ->
- x07 ->
- x08 ->
- x09 ->
- x0A -> 
- x0B -> 
- x0C ->
- x0D ->
- x0E ->
- x0F ->

Row x10
- x10 -> setc
- x11 -> clrc
- x12 -> setb
- x13 -> clrb
- x14 -> setv
- x15 -> clrv
- x16 -> setn
- x17 -> clrn
- x18 -> seto
- x19 -> clro
- x1A -> setp
- x1B -> clrp
- x1C -> seti
- x1D -> clri
Jump absolute and enable protected mode
- x1E -> jaep imm32
- x1F -> jaep r32

Row x20
- x20 -> jr imm16
- x21 -> jr.cc imm16
- x22 -> jr.cc r32, imm16
- x23 -> ja imm32
- x24 -> ja r32
- x25 -> ja.cc imm32
- x26 -> ja.cc r32, imm32
- x27 -> xjmp r32
- x28 -> br imm16
- x29 -> br.cc imm16
- x2A -> br.cc r32, imm16
- x2B -> ba imm32
- x2C -> ba r32
- x2D -> ba.cc imm32
- x2E -> ba.cc r32, imm32
- x2F -> xbch r32

Row x30
- x30 -> ret
- x31 -> iret
- x32 ->
- x33 ->
- x34 ->
- x35 ->
- x36 ->
- x37 ->
- x38 ->
- x39 ->
- x3A -> 
- x3B -> 
- x3C ->
- x3D ->
- x3E ->
- x3F ->

Row x40
- x40 ->
- x41 ->
- x42 ->
- x43 ->
- x44 ->
- x45 ->
- x46 ->
- x47 ->
- x48 -> cvbtw reg32, reg8
- x49 -> cvbtw reg32, data8
- x4A -> cvhtw reg32, reg16
- x4B -> cvhtw reg32, data16
- x4C -> cvbth reg16, reg8
- x4D -> cvbth reg16, data8
- x4E -> \[st instructions]
- x4F -> \[mv instructions]

Row x50
- x50 -> pop reg8
- x51 -> pop reg16
- x52 -> pop reg32
- x53 -> pop mem
- x54 -> psh reg8
- x55 -> psh reg16
- x56 -> psh reg32
- x57 -> psh mem
- x58 -> psh imm8
- x59 -> psh imm16
- x5A -> psh imm32
- x5B ->
- x5C ->
- x5D ->
- x5E ->
- x5F ->

Row x60
Load effective address (Loads data at pointed address given by value of source)
- x60 -> lea r8, r32
- x61 -> lea r16, r32
- x62 -> lea r32, r32
- x63 -> lea reg, mem
- x64 -> lea r8, r32, imm16
- x65 -> lea r16, r32, imm16
- x66 -> lea r32, r32, imm16
- x67 -> lea r32, r32, imm32
Store effective address (Stores data at pointed address given by value of source)
- x68 -> sea r32, r8
- x69 -> sea r32, r16
- x6A -> sea r32, r32
- x6B -> sea mem, reg
- x6C -> sea r32, imm16, r8
- x6D -> sea r32, imm16, r16
- x6E -> sea r32, imm16, r32
- x6F -> sea r32, imm32, r32

Row x70
- x70 -> mov r8, r8
- x71 -> mov r16, r16
- x72 -> mov r32, r32
- x73 -> mov reg, data
- x74 -> mov mem8, imm8
- x75 -> mov mem16, imm16
- x76 -> mov mem32, imm32
- x77 -> mov mem, reg
- x78 -> xchg r8, r8
- x79 -> xchg r16, r16
- x7A -> xchg r32, r32
- x7B -> xchg reg, mem
- x7C ->
- x7D ->
- x7E ->
- x7F ->

Row x80
- x80 -> adc r8, r8
- x81 -> adc r16, r16
- x82 -> adc r32, r32
- x83 -> adc reg, data
- x84 -> add r8, r8
- x85 -> add r16, r16
- x86 -> add r32, r32
- x87 -> add reg, data
- x88 -> sbb r8, r8
- x89 -> sbb r16, r16
- x8A -> sbb r32, r32
- x8B -> sbb reg, data
- x8C -> sub r8, r8
- x8D -> sub r16, r16
- x8E -> sub r32, r32
- x8F -> sub reg, data

Row x90
- x90 -> mul r8, r8
- x91 -> mul r16, r16
- x92 -> mul r32, r32
- x93 -> mul reg, data
- x94 ->
- x95 ->
- x96 ->
- x97 ->
- x98 -> div r8, r8
- x99 -> div r16, r16
- x9A -> div r32, r32
- x9B -> div reg, data
- x9C ->
- x9D ->
- x9E ->
- x9F ->

Row xA0
- xA0 -> mod r8, r8
- xA1 -> mod r16, r16
- xA2 -> mod r32, r32
- xA3 -> mod reg, data
- xA4 -> cmp r8, r8
- xA5 -> cmp r16, r16
- xA6 -> cmp r32, r32
- xA7 -> cmp reg, data
- xA8 -> inc reg
- xA9 -> dec reg
- xAA -> neg reg
- xAB -> test data
- xAC ->
- xAD ->
- xAE -> 
- xAF ->

Row xB0
- xB0 -> and r8, r8
- xB1 -> and r16, r16
- xB2 -> and r32, r32
- xB3 -> and reg, data
- xB4 -> or r8, r8
- xB5 -> or r16, r16
- xB6 -> or r32, r32
- xB7 -> or reg, data
- xB8 -> xor r8, r8
- xB9 -> xor r16, r16
- xBA -> xor r32, r32
- xBB -> xor reg, data
- xBC -> not reg
- xBD -> bswap reg
Bit tests and operations set, clear and reset
- xBE -> \[bt], \[bts], \[btc], \[btt]
Bit scan foward or backward
- xBF -> \[bsf], \[bsb]

Row xC0
- xC0 -> lsh r8, r8
- xC1 -> lsh r16, r16
- xC2 -> lsh r32, r32
- xC3 -> lsh reg, data
- xC4 -> rsh r8, r8
- xC5 -> rsh r16, r16
- xC6 -> rsh r32, r32
- xC7 -> rsh reg, data
- xC8 -> lrot r8, r8
- xC9 -> lrot r16, r16
- xCA -> lrot r32, r32
- xCB -> lrot reg, data
- xCC -> rrot r8, r8
- xCD -> rrot r16, r16
- xCE -> rrot r32, r32
- xCF -> rrot reg, data

Row xD0
- xD0 -> \[float data move]
- xD1 -> \[float arithmetic]
- xD2 ->
- xD3 ->
- xD4 ->
- xD5 ->
- xD6 ->
- xD7 ->
- xD8 ->
- xD9 ->
- xDA -> 
- xDB -> 
- xDC ->
- xDD ->
- xDE ->
- xDF ->

Row xE0
- xE0 ->
- xE1 ->
- xE2 ->
- xE3 ->
- xE4 ->
- xE5 ->
- xE6 ->
- xE7 ->
- xE8 ->
- xE9 ->
- xEA -> 
- xEB -> 
- xEC ->
- xED ->
- xEE ->
- xEF ->

Row xF0
- xF0 ->
- xF1 ->
- xF2 ->
- xF3 ->
- xF4 ->
- xF5 ->
- xF6 ->
- xF7 ->
- xF8 ->
- xF9 ->
- xFA -> 
- xFB -> 
- xFC ->
- xFD ->
- xFE ->
- xFF ->
