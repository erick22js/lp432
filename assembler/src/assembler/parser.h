#ifndef ASM_PARSER_H
#define ASM_PARSER_H

#include "tokener.h"


/*
	Global Parser Properties
*/

typedef struct{
	bool phase_one;
	uint32 pc, bc;
	uint8* bin;
	uint32 bin_size;
}Parser;
extern Parser parser;

/*
	Expression parsing Functions
*/
extern int parserExpression(Value* out);

/*
	Parser High Layer Functions
*/
extern int parserParse(bool second, uint8** bin, uint32* bin_size);


#endif