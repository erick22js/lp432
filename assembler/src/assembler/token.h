#ifndef ASM_TOKEN_H
#define ASM_TOKEN_H

#include "common.h"


//
//	TOKEN TYPES AND STRUCT
//

typedef enum {
	TOKEN_NO,
	TOKEN_EOL,
	TOKEN_LITERAL,
	TOKEN_STRING,
	TOKEN_NAME,
	TOKEN_SYMBOL
} TokenType;

typedef struct {
	TokenType type;
	union {
		f64 fp;
		u64 lit;
		char* str;
	} value;
	bool fp_lit; // "true" means is a floating-point format
	u32 length;
	u32 position;
} Token;


//
//	TOKEN UTILITIES
//

void tkPrint(Token *tk);

#define tkIsSymbol(tk, sym) (tk.type == TOKEN_SYMBOL && (tk.value.lit == sym))
#define tkIsName(tk, name) (tk.type == TOKEN_STRING && (strcmp(tk.value.str, name)==0))


//
//	CHARACTERS UTILITIES
//

#define chrIsSpace(chr) (chr==' ' || chr=='\t' || (chr!=0 && chr!='\n' && chr<32))
#define chrIsNewLine(chr) (chr=='\n' || chr==0)
#define chrIsHexa(chr) ((chr>='0' && chr<='9') || (chr>='a' && chr<='f') || (chr>='A' && chr<='F'))
#define chrIsDecimal(chr) (chr>='0' && chr<='9')
#define chrIsOctal(chr) (chr>='0' && chr<='7')
#define chrIsBinary(chr) (chr=='0' || chr=='1')
#define chrIsName(chr) ((chr>='a' && chr<='z') || (chr>='A' && chr<='Z') || (chr>='0' && chr<='9') || chr=='_' || chr=='#')


#endif