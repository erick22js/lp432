#ifndef ASM_STATUS_H
#define ASM_STATUS_H

#include "common.h"


//
//	ASSEMBLER STATUS INFO STRUCURE
//

typedef struct AsmInfo {
	// static_exp behaves to ensure the expression evaluated will be well defined value during phase one
	bool phase_two, static_exp;
	u8* bin;
	u32 bin_size;
	u32 bs, ps; // Binary/Program seek
} AsmInfo;
extern AsmInfo asm_info;


#endif