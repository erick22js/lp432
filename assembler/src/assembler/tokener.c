#include "tokener.h"


/*
	Common Fetch Functions
*/

// Consume the left line, returns the index where the character is not blank, -1 otherwise
int tkrConsumeLine() {
	uint32 chr = lexerGet();
	int offset = -1;
	while (!charIsBreakLine(chr) && !lexerEnded()){
		if (!charIsBlank(chr) && offset==(-1)) {
			offset = lexerTell()-1;
		}
		chr = lexerGet();
	}
	return offset;
}

// Consume any detected space
void tkrConsumeSpace() {
	createSeek();
	uint32 chr = lexerGet();

	while (!lexerEnded()){
		if (charIsBlank(chr)){
			// The character is a space
			saveSeek();
		}
		else{
			restoreSeek();
			break;
		}
		chr = lexerGet();
	}
}

// Detect the tokener ended fetch
bool tkrEnded() {
	return lexerEnded();
}

// Detect the tokener not ended fetch
bool tkrNotEnded() {
	return !lexerEnded();
}

// Fetch the next token, return error code
int tkrFetchToken(Token *tk) {
	tkrConsumeSpace();
	uint32 initial = lexerGet();

	// Return no character on end of file detected
	if (initial == EOF){
		tk->kind = TOKEN_END_OF_FILE;
		tk->value.integer = 0;
		return 0;
	}
	// Detect if precursor is a end of file
	else if (charIsBreakLine(initial)){
		tk->kind = TOKEN_NEW_LINE;
		tk->value.integer = '\n';
		return 0;
	}
	// Detect if precursor is a number
	else if (charIsNumeric(initial)){
		uint64 value = 0;
		uint32 chr = initial;
		while (charIsNumeric(chr)){
			value = (value*10) + (chr-'0');
			chr = lexerGet();
		}
		lexerSeekCur(-1);
		tk->kind = TOKEN_INTEGER;
		tk->value.integer = value;
		return 0;
	}
	// Detect if precursor is a identifier
	else if (charIsAlpha(initial)){
		char identifier[MAX_IDENTIFIER_SIZE+1];
		uint32 chr = initial;
		uint32 s = 0;
		while (charIsAlpha(chr) && s<MAX_IDENTIFIER_SIZE){
			identifier[s] = chr;
			chr = lexerGet();
			s++;
		}
		identifier[s] = 0;
		lexerSeekCur(-1);
		tk->kind = TOKEN_IDENTIFIER;
		tk->value.string = textReuse(identifier);
		return 0;
	}
	// Detect if precursor is a string
	else if (initial == '"'){
		char string[MAX_STRING_SIZE+1];
		uint32 chr = lexerGet();
		uint32 s = 0;
		while (chr != EOF && chr != '"' && s<MAX_STRING_SIZE){
			string[s] = chr;
			chr = lexerGet();
			s++;
		}
		string[s] = 0;

		if (chr == EOF){
			// Error: Non-terminated string
			return ERROR_UNKNOWN;
		}

		tk->kind = TOKEN_STRING;
		tk->value.string = textReuse(string);
		return 0;
	}
	// Detect if precursor is a symbol
	else {
		// TODO
		tk->kind = TOKEN_SYMBOL;
		tk->value.integer = initial;
		return 0;
	}
	return 0;
}

void tkrPrint(Token *tk){
	switch (tk->kind){
		case TOKEN_INTEGER:{
			log("TOKEN_INTEGER: %lli\n", tk->value.integer);
		}
		break;
		case TOKEN_REAL:{
			log("TOKEN_REAL: %f\n", tk->value.real);
		}
		break;
		case TOKEN_STRING:{
			log("TOKEN_STRING: \"%s\"\n", tk->value.string);
		}
		break;
		case TOKEN_IDENTIFIER:{
			log("TOKEN_IDENTIFIER: %s\n", tk->value.string);
		}
		break;
		case TOKEN_NEW_LINE:{
			log("TOKEN_NEW_LINE\n");
		}
		break;
		case TOKEN_END_OF_FILE:{
			log("TOKEN_END_OF_FILE\n");
		}
		break;
		case TOKEN_SYMBOL:{
			log("TOKEN_SYMBOL: '%c'\n", ((uint32)tk->value.integer));
		}
		break;
		default: {
			log("TOKEN_UNKNOWN\n");
		}
	}
};
