#ifndef ASM_ENCODER_H
#define ASM_ENCODER_H

#include "base.h"
#include "status.h"


//
//	ENCODER FUNCTIONS
//

void encOut8(u8 data);
void encOut16(u16 data);
void encOut32(u32 data);
void encOut64(u64 data);

void encInstruction(InstrEncode *enc, Value *args, int sufix);


#endif