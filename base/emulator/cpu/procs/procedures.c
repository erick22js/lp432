#include "procedures.h"


/*
	Procedures Storage
*/

cpuInterr procNull(Cpu *cpu_s){
	cpu_s->iregs[0] = cpu_s->reg_lpc;
	cpu_s->iregs[1] = cpu_s->opcode;
	cpuThrowInterruption(INTR_INVALID_OPCODE);
	return 0;
}

cpuProc cpuProcedures[256] = {
	// 0x00
	[0x00] = proc00,
	[0x01] = proc01,
	[0x02] = proc02,
	procNull,
	[0x04] = proc04,
	[0x05] = proc05,
	[0x06] = proc06,
	[0x07] = proc07,
	[0x08] = proc08,
	[0x09] = proc09,
	[0x0A] = proc0A,
	[0x0B] = proc0B,
	[0x0C] = proc0C,
	[0x0D] = proc0D,
	[0x0E] = proc0E,
	[0x0F] = proc0F,

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
	[0x30] = proc30,
	[0x31] = proc31,
	[0x32] = proc32,
	procNull,
	[0x34] = proc34,
	[0x35] = proc35,
	[0x36] = proc36,
	[0x37] = proc37,
	[0x38] = proc38,
	[0x39] = proc39,
	[0x3A] = proc3A,
	procNull,
	[0x3C] = proc3C,
	[0x3D] = proc3D,
	procNull, procNull,

	// 0x40
	procNull, procNull, procNull, procNull,
	[0x44] = proc44,
	[0x45] = proc45,
	[0x46] = proc46,
	procNull,
	[0x48] = proc48,
	[0x49] = proc49,
	[0x4A] = proc4A,
	[0x4B] = proc4B,
	[0x4C] = proc4C,
	[0x4D] = proc4D,
	procNull,
	[0x4F] = proc4F,

	// 0x50
	[0x50] = proc50,
	[0x51] = proc51,
	[0x52] = proc52,
	[0x53] = proc53,
	[0x54] = proc54,
	[0x55] = proc55,
	[0x56] = proc56,
	[0x57] = proc57,
	[0x58] = proc58,
	[0x59] = proc59,
	[0x5A] = proc5A,
	[0x5B] = proc5B,
	[0x5C] = proc5C,
	[0x5D] = proc5D,
	[0x5E] = proc5E,
	[0x5F] = proc5F,

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
	[0x90] = proc90,
	[0x91] = proc91,
	[0x92] = proc92,
	[0x93] = proc93,
	[0x94] = proc94,
	[0x95] = proc95,
	[0x96] = proc96,
	[0x97] = proc97,
	[0x98] = proc98,
	[0x99] = proc99,
	[0x9A] = proc9A,
	[0x9B] = proc9B,
	[0x9C] = proc9C,
	[0x9D] = proc9D,
	[0x9E] = proc9E,
	[0x9F] = proc9F,

	// 0xA0
	[0xA0] = procA0,
	[0xA1] = procA1,
	[0xA2] = procA2,
	[0xA3] = procA3,
	[0xA4] = procA4,
	[0xA5] = procA5,
	[0xA6] = procA6,
	[0xA7] = procA7,
	[0xA8] = procA8,
	[0xA9] = procA9,
	[0xAA] = procAA,
	[0xAB] = procAB,
	procNull, procNull, procNull, procNull,

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
	[0xD0] = procD0,
	[0xD1] = procD1,
	[0xD2] = procD2,
	[0xD3] = procD3,
	procNull, procNull, procNull,
	[0xD7] = procD7,
	procNull, procNull, procNull, procNull, procNull,
	[0xDD] = procDD,
	[0xDE] = procDE,
	procNull,

	// 0xE0
	[0xE0] = procE0,
	[0xE1] = procE1,
	[0xE2] = procE2,
	procNull,
	[0xE4] = procE4,
	[0xE5] = procE5,
	[0xE6] = procE6,
	procNull,
	[0xE8] = procE8,
	[0xE9] = procE9,
	[0xEA] = procEA,
	[0xEB] = procNull, //procEB,
	[0xEC] = procEC,
	[0xED] = procED,
	[0xEE] = procEE,
	[0xEF] = procNull, //procEF,

	// 0xF0
	[0xF0] = procF0,
	[0xF1] = procF1,
	[0xF2] = procF2,
	[0xF3] = procF3,
	[0xF4] = procF4,
	[0xF5] = procF5,
	[0xF6] = procF6,
	[0xF7] = procF7,
	[0xF8] = procF8,
	[0xF9] = procF9,
	[0xFA] = procFA,
	[0xFB] = procNull, //procFB,
	[0xFC] = procNull, //procFC,
	[0xFD] = procNull, //procFD,
	[0xFE] = procNull, //procFE,
	[0xFF] = procNull, //procFF,
};
