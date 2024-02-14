#ifndef ASM_EXPRESSION_H
#define ASM_EXPRESSION_H

#include "tokener.h"
#include "base.h"
#include "status.h"
#include "symbol.h"


//
//	EXPRESSION SCANNING
//

Error expFetch(Value *out);
Error expArgumentsFetch(Value *args, int *args_len);
void expPrint(Value *out);


#endif