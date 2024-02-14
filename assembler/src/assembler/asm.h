#ifndef ASM_H
#define ASM_H

#include "common.h"
#include "error.h"
#include "path.h"


//
//	ASSEMBLER FUNCTIONS
//

Error asmFile(char* path, u8** out, u32 *out_size);
Error asmCString(char* cstr, char* vpath, u8** out, u32 *out_size);


#endif