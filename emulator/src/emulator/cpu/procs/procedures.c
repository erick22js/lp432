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
	[0x20] = proc20,
	[0x21] = proc21,
	[0x22] = proc22,
	[0x23] = proc23,
	[0x24] = proc24,
	[0x25] = proc25,
	[0x26] = proc26,
	[0x27] = proc27,
	[0x28] = proc28,
	[0x29] = proc29,
	[0x2A] = proc2A,
	[0x2B] = proc2B,
	[0x2C] = proc2C,
	[0x2D] = proc2D,
	[0x2E] = proc2E,
	[0x2F] = proc2F,

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
	[0x60] = proc60,
	[0x61] = proc61,
	[0x62] = proc62,
	[0x63] = proc63,
	[0x64] = proc64,
	[0x65] = proc65,
	[0x66] = proc66,
	[0x67] = proc67,
	[0x68] = proc68,
	[0x69] = proc69,
	[0x6A] = proc6A,
	[0x6B] = proc6B,
	[0x6C] = proc6C,
	[0x6D] = proc6D,
	[0x6E] = proc6E,
	[0x6F] = proc6F,

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
	[0x80] = proc80,
	[0x81] = proc81,
	[0x82] = proc82,
	[0x83] = proc83,
	[0x84] = proc84,
	[0x85] = proc85,
	[0x86] = proc86,
	[0x87] = proc87,
	[0x88] = proc88,
	[0x89] = proc89,
	[0x8A] = proc8A,
	[0x8B] = proc8B,
	[0x8C] = proc8C,
	[0x8D] = proc8D,
	[0x8E] = proc8E,
	[0x8F] = proc8F,

	// 0x90
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,

	// 0xA0
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,
	procNull, procNull, procNull, procNull, procNull, procNull, procNull, procNull,

	// 0xB0
	[0xB0] = procB0,
	[0xB1] = procB1,
	[0xB2] = procB2,
	[0xB3] = procB3,
	[0xB4] = procB4,
	[0xB5] = procB5,
	[0xB6] = procB6,
	[0xB7] = procB7,
	[0xB8] = procB8,
	[0xB9] = procB9,
	[0xBA] = procBA,
	[0xBB] = procBB,
	procNull, procNull,
	[0xBE] = procBE,
	[0xBF] = procBF,

	// 0xC0
	[0xC0] = procC0,
	[0xC1] = procC1,
	[0xC2] = procC2,
	[0xC3] = procC3,
	[0xC4] = procC4,
	[0xC5] = procC5,
	[0xC6] = procC6,
	[0xC7] = procC7,
	[0xC8] = procC8,
	[0xC9] = procC9,
	[0xCA] = procCA,
	[0xCB] = procCB,
	[0xCC] = procCC,
	[0xCD] = procCD,
	[0xCE] = procCE,
	[0xCF] = procCF,

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
