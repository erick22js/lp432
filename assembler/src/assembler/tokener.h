#ifndef ASM_TOKENER_H
#define ASM_TOKENER_H

#include "token.h"
#include "lexer.h"
#include "error.h"


//
//	UTILITIES FUNCTIONS
//

char* reuseName(char* name);
char* wrapString(char* cstr);
char* wrapStringSized(char* cstr, int size);
void tkrConsumeBlank();
void tkrConsumeLeftLine();
Error tkrFetch(Token *tk);


#endif