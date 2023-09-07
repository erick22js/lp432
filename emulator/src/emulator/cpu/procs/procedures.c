#include "procedures.h"


/*
	Procedures Storage
*/

cpuInterr procNull(){cpuThrowInterruption(INTR_INVALID_OPCODE); return 0;}
cpuInterr procNop(){return 0;}

cpuProc cpuProcedures[256] = {
	// 0x00
	[0x00] = procNop,
	procNull, procNull, procNull, procNull, procNull, procNull, procNull,
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,

	// 0x10
	[0x10] = proc10,
	[0x11] = proc11,
	[0x12] = proc12,
	[0x13] = proc13,
	[0x14] = proc14,
	[0x15] = proc15,
	[0x16] = proc16,
	[0x17] = proc17,
	[0x18] = proc18,
	[0x19] = proc19,
	[0x1A] = proc1A,
	[0x1B] = proc1B,
	[0x1C] = proc1C,
	[0x1D] = proc1D,
	[0x1E] = proc1E,
	[0x1F] = proc1F,

	// 0x20
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,

	// 0x30
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,

	// 0x40
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,

	// 0x50
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,

	// 0x60
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,

	// 0x70
	[0x70] = proc70,
	[0x71] = proc71,
	[0x72] = proc72,
	[0x73] = proc73,
	[0x74] = proc74,
	[0x75] = proc75,
	[0x76] = proc76,
	[0x77] = proc77,
	[0x78] = proc78,
	[0x79] = proc79,
	[0x7A] = proc7A,
	[0x7B] = proc7B,
	procNull, procNull, procNull, procNull,

	// 0x80
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,

	// 0x90
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,

	// 0xA0
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,

	// 0xB0
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,

	// 0xC0
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,

	// 0xD0
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,

	// 0xE0
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,

	// 0xF0
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,
};
