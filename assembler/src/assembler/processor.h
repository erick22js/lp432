#ifndef ASM_PROCESSOR_H
#define ASM_PROCESSOR_H
#include "lexer.h"

/*
	Common Fetch Functions
*/
#define createSeek() uint32 ret = lexerTell();
#define saveSeek() {ret = lexerTell();}
#define restoreSeek() {lexerSeekSet(ret);}

uint32 errorStatus = ERROR_NONE;

// Consume any detected space
void lexerConsumeSpace() {
	createSeek();
	uint32 chr = lexerGet();

	do {
		if (chr==' ' || chr=='\t'){
			// The character is a space
			saveSeek();
		}
		else {
			restoreSeek();
			break;
		}
		chr = lexerGet();
	}while (!lexerEnded());
}

// Consume any detected symbol
uint32 lexerFetchSymbol(){
	createSeek();
	uint32 symbol = lexerGet();
	if (symbol == EOF){
		return 0;
	}
	return symbol;
}



#endif