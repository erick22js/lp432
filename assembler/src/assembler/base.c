#include "base.h"


DataName data_names[] = {
	{"Byte", TYPE_R8, TYPE_IMM8, TYPE_MEM8},
	{"Half", TYPE_R16, TYPE_IMM16, TYPE_MEM16},
	{"Word", TYPE_R32, TYPE_IMM32, TYPE_MEM32},
	{"SByte", TYPE_R8, TYPE_IMMS8, TYPE_MEMS8},
	{"SHalf", TYPE_R16, TYPE_IMMS16, TYPE_MEMS16},
	{"SWord", TYPE_R32, TYPE_IMMS32, TYPE_MEMS32},
};
const int data_names_length = sizeof(data_names)/sizeof(DataName);

extern DataName *findDataByName(const char* name){
	for (int i = 0; i<data_names_length; i++){
		if (strcmp(name, data_names[i].name) == 0){
			return &data_names[i];
		}
	}
	return null;
}


Reg regs[] = {
	{"eax", TYPE_R32, 0}, {"edx", TYPE_R32, 1}, {"ecx", TYPE_R32, 2}, {"ebx", TYPE_R32, 3},
	{"eex", TYPE_R32, 4}, {"ehx", TYPE_R32, 5}, {"egx", TYPE_R32, 6}, {"efx", TYPE_R32, 7},
	{"ex0", TYPE_R32, 8}, {"ex1", TYPE_R32, 9}, {"ex2", TYPE_R32, 10}, {"ex3", TYPE_R32, 11},
	{"eds", TYPE_R32, 12}, {"esd", TYPE_R32, 13}, {"esp", TYPE_R32, 14}, {"efp", TYPE_R32, 15},

	{"ax", TYPE_R16, 0}, {"dx", TYPE_R16, 1}, {"cx", TYPE_R16, 2}, {"bx", TYPE_R16, 3},
	{"ex", TYPE_R16, 4}, {"hx", TYPE_R16, 5}, {"gx", TYPE_R16, 6}, {"fx", TYPE_R16, 7},
	{"x0", TYPE_R16, 8}, {"x1", TYPE_R16, 9}, {"x2", TYPE_R16, 10}, {"x3", TYPE_R16, 11},
	{"ds", TYPE_R16, 12}, {"sd", TYPE_R16, 13}, {"sp", TYPE_R16, 14}, {"fp", TYPE_R16, 15},
	
	{"al", TYPE_R8, 0}, {"dl", TYPE_R8, 1}, {"cl", TYPE_R8, 2}, {"bl", TYPE_R8, 3},
	{"el", TYPE_R8, 4}, {"hl", TYPE_R8, 5}, {"gl", TYPE_R8, 6}, {"fl", TYPE_R8, 7},
	{"l0", TYPE_R8, 8}, {"l1", TYPE_R8, 9}, {"l2", TYPE_R8, 10}, {"l3", TYPE_R8, 11},
	
	{"f0", TYPE_FPR, 0}, {"f1", TYPE_FPR, 1}, {"f2", TYPE_FPR, 2}, {"f3", TYPE_FPR, 4},
	{"f4", TYPE_FPR, 4}, {"f5", TYPE_FPR, 5}, {"f6", TYPE_FPR, 6}, {"f7", TYPE_FPR, 7},
	{"f8", TYPE_FPR, 8}, {"f9", TYPE_FPR, 9}, {"f10", TYPE_FPR, 10}, {"f11", TYPE_FPR, 11},
	{"f12", TYPE_FPR, 12}, {"f13", TYPE_FPR, 13}, {"f14", TYPE_FPR, 14}, {"f15", TYPE_FPR, 15},
	
	{"ir0", TYPE_IR, 0}, {"ir1", TYPE_IR, 1}, {"ir2", TYPE_IR, 2}, {"ir3", TYPE_IR, 4},
	{"ir4", TYPE_IR, 4}, {"ir5", TYPE_IR, 5}, {"ir6", TYPE_IR, 6}, {"ir7", TYPE_IR, 7},
};
const int regs_length = sizeof(regs)/sizeof(Reg);

extern Reg *findRegByName(const char* name){
	for (int i = 0; i<regs_length; i++){
		if (strcmp(name, regs[i].name) == 0){
			return &regs[i];
		}
	}
	return null;
}


Ist isa[] = {
	{
		.mne = "nop",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x00, .desc = NO_DESC,
				.params_length = 0,
			}
		}
	},
	{
		.mne = "adc",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x80, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_R8, .encode = ENCODE_REGO },
				}
			},
			{
				.opcode = 0x82, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_R32, .encode = ENCODE_REGO },
				}
			},
			{
				.opcode = 0x83, .desc = 0x2,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 },
				}
			},
		}
	},
};
const int isa_length = sizeof(isa)/sizeof(Ist);

extern Ist *findInstructionByName(const char* name){
	for (int i = 0; i<isa_length; i++){
		if (strcmp(name, isa[i].mne) == 0){
			return &isa[i];
		}
	}
	return null;
}
