#include "token.h"
#include "logger.h"


//
//	TOKEN UTILITIES
//

void tkPrint(Token *tk) {
	return;
	switch (tk->type){
		case TOKEN_NO: {
			logDevInfo("TK: -no token- [%d]\n", tk->position);
		};
		break;
		case TOKEN_EOL: {
			logDevInfo("TK: EOL [%d]\n", tk->position);
		};
		break;
		case TOKEN_LITERAL: {
			if (tk->fp_lit){
				logDevInfo("TK: Literal = %g [%d]\n", (f32)tk->value.fp, tk->position);
			}
			else {
				logDevInfo("TK: Literal = 0x%X [%d]\n", (u32)tk->value.lit, tk->position);
			}
		};
		break;
		case TOKEN_STRING: {
			logDevInfo("TK: String:%d = \"%s\" [%d]\n", tk->length, tk->value.str, tk->position);
		};
		break;
		case TOKEN_NAME: {
			logDevInfo("TK: Name:%d = %s [%d]\n", tk->length, tk->value.str, tk->position);
		};
		break;
		case TOKEN_SYMBOL: {
			char c0 = ((tk->value.lit>>24)&0xFF);
			char c1 = ((tk->value.lit>>16)&0xFF);
			char c2 = ((tk->value.lit>>8)&0xFF);
			char c3 = (tk->value.lit&0xFF);
			logDevInfo("TK: Symbol = 0x%X '%c%c%c%c' [%d]\n", (int)tk->value.lit, c0, c1, c2, c3, tk->position);
		};
		break;
		default: {
			logDevInfo("TK: -unknown- [%d]\n", tk->position);
		};
		break;
	}
}
