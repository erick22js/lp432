#ifndef EMU_CPU_H
#define EMU_CPU_H

#include "../common.h"


/*
	State Properties of CPU
*/

// General Purpose Registers
#define GREG_EAX 0x0
#define GREG_EDX 0x1
#define GREG_ECX 0x2
#define GREG_EBX 0x3
#define GREG_EEX 0x4
#define GREG_EHX 0x5
#define GREG_EGX 0x6
#define GREG_EFX 0x7
#define GREG_EX0 0x8
#define GREG_EX1 0x9
#define GREG_EX2 0xA
#define GREG_EX3 0xB
#define GREG_ESS 0xC
#define GREG_ESD 0xD
#define GREG_ESP 0xE
#define GREG_EFP 0xF
#define GREG_TOTAL 16

// Segment Registers
#define SREG_S0 0x0
#define SREG_S1 0x1
#define SREG_S2 0x2
#define SREG_S3 0x3
#define SREG_S4 0x4
#define SREG_S5 0x5
#define SREG_S6 0x6
#define SREG_S7 0x7
#define SREG_TOTAL 8

// Floating Point Registers
#define FREG_TOTAL 16

// Interruption Registers
#define IREG_I0 0x0
#define IREG_I1 0x1
#define IREG_I2 0x2
#define IREG_I3 0x3
#define IREG_I4 0x4
#define IREG_I5 0x5
#define IREG_I6 0x6
#define IREG_I7 0x7
#define IREG_TOTAL 8

// Program Flags Bit
#define FLAG_CF 0x00000001
#define FLAG_BF 0x00000002
#define FLAG_VF 0x00000004
#define FLAG_NF 0x00000008
#define FLAG_ZF 0x00000010
#define FLAG_OF 0x00000020
#define FLAG_PM 0x00010000
#define FLAG_SE 0x00020000
#define FLAG_PE 0x00040000
#define FLAG_IE 0x00080000
#define FLAG_TI 0x00100000

typedef int cpuInterr;

typedef struct{
	uint8 selector;
	uint8 flags;
	uint32 base;
	uint32 limit;
}CpuSegment;

struct Cpu{
	/*
		Registers
	*/
	// General Purpose Registers
	uint32 gregs[GREG_TOTAL];
	
	// Master Registers
	uint32 reg_pc; // Program Counter
	uint32 reg_lpc; // Program Counter
	uint32 reg_st; // Program State

	// MMU Control Registers
	uint32 reg_std; // Segment Table Address
	uint32 reg_ptd; // Pagining Table Address
	uint32 reg_itd; // Interruption Table Address
	uint32 reg_isp; // Interruption Stack Pointer

	// Timer Control Registers
	uint32 reg_pit; // Programmed Interval Timer
	uint32 reg_ctv; // Current Timer Value
	uint32 reg_utv; // Current Under Timer Value

	// Segment Registers
	CpuSegment sregs[SREG_TOTAL];

	// Floating Point Registers
	float64 fregs[FREG_TOTAL];

	// Interruption Registers
	uint32 iregs[IREG_TOTAL];

	/*
		Code Storage
	*/
	uint8 opcode;
	bool prefix;
	uint8 os_regm, os_rego, os_desc;
	uint32 mv;

	/*
		Process Storage
	*/
	uint32 mem_adr;
	uint32 code;
	uint32 data;
	cpuInterr interrupt;

	/*
		External Interrupt State
	*/
	bool request_external;
	uint16 request_port;

	/*
		State of Machine
	*/
	bool halted;
	bool waiting;

	/*
		Out Conections
	*/
	Emu *emu;
	Pci *pci;
	uint8 (*busRead)(uint32 adr);
	void (*busWrite)(uint32 adr, uint8 data);
};
//extern Cpu cpu_s;

/*
	Control Functions for CPU
*/
// General Purpose Registers Access
#define cpuReadReg8(reg) ((uint8)(cpu_s->gregs[reg]&0xFF))
#define cpuWriteReg8(reg, data) {cpu_s->gregs[reg] = (cpu_s->gregs[reg]&0xFFFFFF00)|((data)&0xFF);}
#define cpuReadReg16(reg) ((uint16)(cpu_s->gregs[reg]&0xFFFF))
#define cpuWriteReg16(reg, data) {cpu_s->gregs[reg] = (cpu_s->gregs[reg]&0xFFFF0000)|((data)&0xFFFF);}
#define cpuReadReg32(reg) (cpu_s->gregs[reg])
#define cpuWriteReg32(reg, data) {cpu_s->gregs[reg] = (uint32)(data);}

// Timing Control
#define emuCpuCycles(cycles) {uint32 c_cycles = cycles; cpu_s->reg_utv += c_cycles; emuCycles(cpu_s->emu, c_cycles);}

// Program Flow Control
#define cpuJumpTo(adr) {cpu_s->reg_pc = (adr);}
#define cpuJumpBy(off) {cpu_s->reg_pc = cpu_s->reg_lpc + (sint32)(off);}

extern bool cpuRequestInterrupt(Cpu *cpu_s, uint16 port);

extern void cpuReset(Cpu *cpu_s);
extern void cpuStep(Cpu *cpu_s);


#endif