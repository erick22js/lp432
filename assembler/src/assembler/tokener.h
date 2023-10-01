#ifndef ASM_TOKENER_H
#define ASM_TOKENER_H
#include "lexer.h"
#include "error.h"
#include "text.h"


/*
	Settings
*/

#define MAX_IDENTIFIER_SIZE 31
#define MAX_STRING_SIZE 255


/*
	Characters Related
*/

#define charIsBreakLine(chr) (chr=='\n')
#define charIsBlank(chr) (chr<=' ' && !charIsBreakLine(chr))
#define charIsNumeric(chr) (chr>='0' && chr<='9')
#define charIsLetter(chr) ((chr>='a' && chr<='z')||(chr>='A' && chr<='Z')||(chr=='_'))
#define charIsAlpha(chr) (charIsLetter(chr)||charIsNumeric(chr))


/*
	Token Related
*/

typedef enum{
	TOKEN_INTEGER,
	TOKEN_REAL,
	TOKEN_STRING,
	TOKEN_IDENTIFIER,
	TOKEN_SYMBOL,
	TOKEN_NEW_LINE,
	TOKEN_END_OF_FILE,
}TokenType;

typedef struct{
	TokenType kind;
	union{
		sint64 integer;
		float64 real;
		const char* string;
	}value;
}Token;


/*
	Common Fetch Functions
*/
#define createSeek() uint32 ret = lexerTell();
#define saveSeek() {ret = lexerTell();}
#define restoreSeek() {lexerSeekSet(ret);}

// Consume the left line, returns the index where the character is not blank, -1 otherwise
extern int tkrConsumeLine();

// Consume any detected space
extern void tkrConsumeSpace();

// Detect the tokener ended fetch
extern bool tkrEnded();

// Detect the tokener not ended fetch
extern bool tkrNotEnded();

// Fetch the next token, return error code
extern int tkrFetchToken(Token *tk);

// Print the given token
extern void tkrPrint(Token *tk);


/*
	Token comparations
*/
#define tkIsSymbol(tk, sym) (tk.kind == TOKEN_SYMBOL && tk.value.integer == sym)
#define tkIsIdentifier(tk, name) (tk.kind == TOKEN_IDENTIFIER && strcmp(name, tk.value.string) == 0)


#endif