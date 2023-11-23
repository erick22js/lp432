#ifndef ASM_LEXER_H
#define ASM_LEXER_H

#include "common.h"


typedef enum{
	LEXER_TYPE_STRING,
	LEXER_TYPE_FILE
}LexerType;

typedef struct{
	LexerType type;

	// String properties
	const char* src;
	uint32 src_len;

	// File properties
	char path[512];
	FILE *file;

	// Common properties
	uint32 limit;
	uint32 status;
	void *args;
	uint32 seek;
}Lexer;

/*
	API Functions
*/
// Open a string lexer, return a pointer to lexer on success or null on error
extern Lexer *lexerOpenString(const char* src);
// Open a file lexer, return a pointer to lexer on success or null on error
extern Lexer *lexerOpenFile(const char* path);
// Closes the last open lexer
extern bool lexerClose();
// Retrieve the current lexer
extern Lexer *lexerCurrent();
// Fetch the next character on lexer
extern uint32 lexerGet();
// Verify if the current lexer is ended
extern bool lexerEnded();
// Verify if has remaining lexers
extern bool hasRemainLexers();
// Tell the current address in lexer stream
extern uint32 lexerTell();
// Sets the current address in lexer stream
extern void lexerSeekSet(uint32 address);
// Move through current address in lexer stream
extern void lexerSeekCur(int offset);


#endif