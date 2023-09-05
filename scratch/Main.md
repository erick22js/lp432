
## Register

Are 16 general registers:
- EAX:32, AX:16 or AL:8 -> Accumulator;
- EDX:32, DX:16 or DL:8 -> Data;
- ECX:32, CX:16 or CL:8 -> Counter;
- EBX:32, BX:16 or BL:8 -> Base;
- EEX:32, EX:16 or EL:8 -> Register E;
- EFX:32, EX:16 or FL:8 -> Register F;
- EGX:32, GX:16 or GL:8 -> Register G;
- EHX:32, HX:16 or HL:8 -> Register H;
- EX0:32, X0:16 or L0:8 -> Register X0;
- EX1:32, X1:16 or L1:8 -> Register X1;
- EX2:32, X2:16 or L2:8 -> Register X2;
- EX3:32, X3:16 or L3:8 -> Register X3;
- EDS:32 -> Stream Source;
- ESD:32 -> Stream Destination;
- ESP:32 -> Stack Pointer;
- EFP:32 -> Frame Pointer;

Are the master registers:
- PC:32 -> Program Counter;
- ST:32 -> Program Status;

Are the segment registers:
- CS -> Code Segment;
- SS -> Stack Segment;
- DS -> Data Segment;
- AS -> Segment A;
- BS -> Segment B;
- CS -> Segment C;

Are the control registers:
- STD -> Segment Table Definition Address;
- PTD -> Pagining Table Definition Address;
- ITD -> Interruption Table Definition Address;

Are the floating pointer registers:
- F0, F1, F2, F3;
- F4, F5, F6, F7;
- F8, F9, F10, F11;
- F12, F13, F14, F15;

## Program Flags

The flags are the following:
- CF:0 -> Carry Flag
- BF:1 -> Borrow Flag
- VF:2 -> Overflow Flag
- ZF:3 -> Zero Flag
- OF:4 -> Odd Flag
- PM:16 -> Protected Mode
- VM:17 -> Virtual Mode
- EI:18 -> Enabled External Interruptions

## Instruction Encoding

The instructions may follow the next structure:
- OB -> Opcode base (1 or 2 bytes);
- OS -> Operand specifier (0 or more bytes);
- NS -> Index specifier (0 or 1 byte);
- NV -> Index value (0, 1, 2 or 4 bytes);
- MV -> Immediate value (0, 1, 2 or 4 bytes);

##### Opcode base - OB
A opcode base determines what the instruction operation. A instruction must have at least one opcode base, and no more than two bytes.

##### Operand specifier - OS
The operand specifier is a byte composed of the following structure:
- Reg1 (4 bits);
	The first operand register
- Descriptor / Reg2 (4 bits);
	The second argument, which can be a secondary register operand or descriptor data for instruction
Instructions can have multiple operands specifier or zero.

##### Index specifier - NS
The index specifier is a byte composed of the following structure:
- Regi (4 bits);
	The register used as base index address;
- Adrm (4 bits);
	The addressing mode of instruction;
Instructions cannot have more than one index specifier, but can have zero.

#### Index value - NV
Literal value used as index for addressing in instruction. Instructions cannot have more than one index value, but can have zero.

##### Immediate value - MV
Literal value used as constant data in instruction. Instructions can have multiple immediate values or zero.


## Addressing mode

List of Addressing Mode codes:
- x0 -> Absolute Address, \[Nv:u8]
- x1 -> Absolute Address, \[Nv:u16]
- x2 -> Absolute Address, \[Nv:u32]
- x3 -> Pointer Address, \[Regi:u32]
- x4 -> Indexed Address, \[Regi:u32 + Nv:s8]
- x5 -> Indexed Address, \[Regi:u32 + Nv:s16] 
- x6 -> Indexed Address, \[Regi:u32 + Nv:s32]
- x7 -> Pointered Address, \[Regi:u32 + Reg1:s32]
- x8 -> Pointered Address, \[Regi:u32 + Reg1:s32 + Nv:8]
- x9 -> Pointered Address, \[Regi:u32 + Reg1:s32 + Nv:s16]
- xA -> Pointered Address, \[Regi:u32 + Reg1:s32 + Nv:s32]
- xB -> Dynamic Address, \[Regi:u32 + Reg1:s32 * Reg2:u32]
- xC -> Dynamic Indexed Address, \[Regi:u32 + Reg1:s32 * Reg2:u32 + Nv:s16]
- xD -> Struct Address, \[Regi:u32 + Reg1:s32 * Nv:u8]
- xE -> Struct Address, \[Regi:u32 + Reg1:s32 * Nv:u16]
- xF -> Struct Address, \[Regi:u32 + Reg1:s32 * Nv:u32]
\* In case of need of another register, the instruction may fetch a new Operand Specifier (OS) before Index Value (NV).
\* The instruction determines the size of memory access.

