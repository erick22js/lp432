#include "tokener.h"


//
//	NAMING REUSES
//
typedef char* _Name;
_Name __first_name = null;

#define _getName_NamePtr(name) (*(_Name*)(name))
#define _getName_Cstr(name) ((char*)((name)+sizeof(_Name*)))

char* reuseName(char* name){
	_Name *entry = &__first_name;

	while (*entry){
		if (strcmp(_getName_Cstr(*entry), name)==0){
			return _getName_Cstr(*entry);
		}
		entry = &_getName_NamePtr(*entry);
	}
	
	u32 len = strlen(name);
	_Name nentry = mem_alloc(sizeof(_Name*) + len+1);
	char* nname = _getName_Cstr(nentry);
	memcpy(nname, name, len);
	nname[len] = 0;
	*entry = (_Name)nentry;
	_getName_NamePtr(nentry) = null;
	return _getName_Cstr(*entry);
}

char* wrapString(char* cstr){
	int size = strlen(cstr);
	char *ncstr = mem_alloc(size+1);
	memcpy(ncstr, cstr, size+1);
	return ncstr;
}

char* wrapStringSized(char* cstr, int size){
	char *ncstr = mem_alloc(size+1);
	memcpy(ncstr, cstr, size+1);
	return ncstr;
}


//
//	INTERNAL FUNCTIONS
//

void tkrConsumeBlank(){
	seekCreate();
	do {
		u32 chr = lexGet();
		if (chrIsSpace(chr)){}
		else if (chr==';'){
			while (!chrIsNewLine(chr)){
				chr = lexGet();
			}
			lexSeekCur(-1);
		}
		else if (chr=='/'){
			chr = lexGet();
			if (chr=='/'){
				while (!chrIsNewLine(chr)){
					chr = lexGet();
				}
				lexSeekCur(-1);
			}
			else if (chr=='*'){
				while (!lexEnded()){
					chr = lexGet();
					if (chr=='*'){
						chr = lexGet();
						if (chr=='/'){
							break;
						}
						else {
								lexSeekCur(-1);
						}
					}
				}
			}
			else {
				lexSeekCur(-2);
				break;
			}
		}
		else if (chr=='\\'){
			chr = lexGet();
			if (chr=='\n'){}
			else {
				lexSeekCur(-2);
				break;
			}
		}
		else {
			break;
		}
		seekSave();
	} while(!lexEnded());
	seekRestore();
}

void tkrConsumeLeftLine() {
	u32 chr = 0;
	do {
		chr = lexGet();
	}while (!chrIsNewLine(chr));
}


//
//	NUMERIC DECODING
//

Error decNumberBin(Token *tk){
	u64 lit = 0;
	u32 chr = lexGet();
	while (chrIsBinary(chr)){
		lit <<= 1;
		lit += (chr-'0');
		chr = lexGet();
	}
	if (chr=='.'){
		f64 fp = 0;
		f64 div = 1.0;
		chr = lexGet();
		while (chrIsBinary(chr)){
			div /= 2;
			fp += (chr-'0')*div;
			chr = lexGet();
		}
		fp += lit;
		tk->value.fp = fp;
		tk->fp_lit = true;
	}
	else {
		tk->value.lit = lit;
	}
	lexSeekCur(-1);
	tk->type = TOKEN_LITERAL;
	return ERROR_NONE;
}

Error decNumberOctal(Token *tk){
	u64 lit = 0;
	u32 chr = lexGet();
	while (chrIsOctal(chr)){
		lit <<= 3;
		lit += (chr-'0');
		chr = lexGet();
	}
	if (chr=='.'){
		f64 fp = 0;
		f64 div = 1.0;
		chr = lexGet();
		while (chrIsOctal(chr)){
			div /= 8;
			fp += (chr-'0')*div;
			chr = lexGet();
		}
		fp += lit;
		tk->value.fp = fp;
		tk->fp_lit = true;
	}
	else {
		tk->value.lit = lit;
	}
	lexSeekCur(-1);
	tk->type = TOKEN_LITERAL;
	return ERROR_NONE;
}

Error decNumberDecimal(Token *tk, u32 chr){
	u64 lit = 0;
	while (chrIsDecimal(chr)){
		lit *= 10;
		lit += chr-'0';
		chr = lexGet();
	}
	if (chr=='.'){
		f64 fp = 0;
		f64 div = 1.0;
		chr = lexGet();
		while (chrIsDecimal(chr)){
			div /= 10;
			fp += (chr-'0')*div;
			chr = lexGet();
		}
		fp += lit;
		tk->value.fp = fp;
		tk->fp_lit = true;
	}
	else {
		tk->value.lit = lit;
	}
	lexSeekCur(-1);
	tk->type = TOKEN_LITERAL;
	return ERROR_NONE;
}

Error decNumberHexa(Token *tk){
	u64 lit = 0;
	u32 chr = lexGet();
	while (chrIsHexa(chr)){
		lit <<= 4;
		lit += chr>='0' && chr<='9'? chr-'0': chr>='a' && chr<='f'? chr-'a'+10: chr>='A' && chr<='F'? chr-'A'+10: 0;
		chr = lexGet();
	}
	if (chr=='.'){
		f64 fp = 0;
		f64 div = 1.0;
		chr = lexGet();
		while (chrIsHexa(chr)){
			div /= 16;
			fp += (chr>='0' && chr<='9'? chr-'0': chr>='a' && chr<='f'? chr-'a'+10: chr>='A' && chr<='F'? chr-'A'+10: 0)*div;
			chr = lexGet();
		}
		fp += lit;
		tk->value.fp = fp;
		tk->fp_lit = true;
	}
	else {
		tk->value.lit = lit;
	}
	lexSeekCur(-1);
	tk->type = TOKEN_LITERAL;
	return ERROR_NONE;
}

Error decNumber(Token *tk, u32 fchr){
	if (fchr=='0'){
		fchr = lexGet();
		
		if (fchr=='x' || fchr=='X'){
			errTryCatch(
				decNumberHexa(tk)
			);
		}
		else if (fchr=='o' || fchr=='O'){
			errTryCatch(
				decNumberOctal(tk)
			);
		}
		else if (fchr=='b' || fchr=='B'){
			errTryCatch(
				decNumberBin(tk)
			);
		}
		else {
			lexSeekCur(-1);
			errTryCatch(
				decNumberDecimal(tk, '0')
			);
		}
	}
	else {
		errTryCatch(
			decNumberDecimal(tk, fchr)
		);
	}
	return ERROR_NONE;
}


//
//	GENERAL TEXT DECODING
//

Error decEscape(char *out){
	char chr = lexGet();
	
	switch (chr){
		case 'N':
		case 'n': {
			*out = '\n';
		}
		break;
		case 'T':
		case 't': {
			*out = '\t';
		}
		break;
		case 'R':
		case 'r': {
			*out = '\r';
		}
		break;
		case '0': {
			*out = 0;
		}
		break;
		default: {
			*out = chr;
		}
	}
	
	return ERROR_NONE;
}

Error decName(Token *tk, u32 chr) {
	char name[MAX_NAME_LENGTH+1];
	u32 i = 0;
	while (chrIsName(chr)){
		if (i<=MAX_NAME_LENGTH){
			name[i] = chr;
			i++;
		}
		chr = lexGet();
	}
	name[i] = 0;
	lexSeekCur(-1);
	
	tk->type = TOKEN_NAME;
	tk->value.str = reuseName(name);
	tk->length = i;
	return ERROR_NONE;
}

Error decCharacter(Token *tk) {
	u64 character = 0;
	u32 chr = lexGet();
	u32 i = 0;
	while (!lexEnded() && chr!='\''){
		if (chr=='\\'){
			errTryCatch(
				decEscape((char*)&chr)
			);
		}
		
		character <<= 8;
		character |= chr;
		i++;
		chr = lexGet();
	}
	
	tk->type = TOKEN_LITERAL;
	tk->value.lit = character;
	tk->length = i;
	return ERROR_NONE;
}

Error decString(Token *tk) {
	char str[MAX_STRING_LENGTH+1];
	u32 chr = lexGet();
	u32 i = 0;
	while (!lexEnded() && chr!='"'){
		if (chr=='\\'){
			errTryCatch(
				decEscape((char*)&chr)
			);
		}
		
		if (i<=MAX_STRING_LENGTH){
			str[i] = chr;
			i++;
		}
		chr = lexGet();
	}
	str[i] = 0;
	
	tk->type = TOKEN_STRING;
	tk->value.str = wrapStringSized(str, i);
	tk->length = i;
	return ERROR_NONE;
}


//
//	UTILITIES FUNCTIONS
//

Error _tkrFetch(Token *tk){
	tkrConsumeBlank();
	tk->position = lexTell();
	tk->length = 0;
	tk->fp_lit = false;
	
	u32 chr = lexGet();
	if (chrIsNewLine(chr)){
		tk->type = TOKEN_EOL;
		tk->value.lit = 0;
	}
	else if (chrIsDecimal(chr)){
		errTryCatch(
			decNumber(tk, chr)
		);
	}
	else if (chrIsName(chr)){
		errTryCatch(
			decName(tk, chr)
		);
	}
	else if (chr=='\"'){
		errTryCatch(
			decString(tk)
		);
	}
	else if (chr=='\''){
		errTryCatch(
			decCharacter(tk)
		);
	}
	else {
		switch (chr){
			case '\\': {
				chr = lexGet();
				if (chr=='n' || chr=='N'){
					tk->type = TOKEN_EOL;
					tk->value.lit = 0;
					return ERROR_NONE;
				}
				lexSeekCur(-2);
			}
			break;
			case '|': {
				chr = lexGet();
				if (chr=='|'){
					tk->type = TOKEN_SYMBOL;
					tk->value.lit = *(u16*)"||";
					return ERROR_NONE;
				}
				chr = '|';
				lexSeekCur(-1);
			}
			break;
			case '&': {
				chr = lexGet();
				if (chr=='&'){
					tk->type = TOKEN_SYMBOL;
					tk->value.lit = *(u16*)"&&";
					return ERROR_NONE;
				}
				chr = '&';
				lexSeekCur(-1);
			}
			break;
			case '=': {
				chr = lexGet();
				if (chr=='='){
					tk->type = TOKEN_SYMBOL;
					tk->value.lit = *(u16*)"==";
					return ERROR_NONE;
				}
				chr = '=';
				lexSeekCur(-1);
			}
			break;
			case '!': {
				chr = lexGet();
				if (chr=='='){
					tk->type = TOKEN_SYMBOL;
					tk->value.lit = *(u16*)"!=";
					return ERROR_NONE;
				}
				chr = '!';
				lexSeekCur(-1);
			}
			break;
			case '>': {
				chr = lexGet();
				if (chr=='='){
					tk->type = TOKEN_SYMBOL;
					tk->value.lit = *(u16*)">=";
					return ERROR_NONE;
				}
				else if (chr=='>'){
					tk->type = TOKEN_SYMBOL;
					tk->value.lit = *(u16*)">>";
					return ERROR_NONE;
				}
				chr = '>';
				lexSeekCur(-1);
			}
			break;
			case '<': {
				chr = lexGet();
				if (chr=='='){
					tk->type = TOKEN_SYMBOL;
					tk->value.lit = *(u16*)"<=";
					return ERROR_NONE;
				}
				else if (chr=='<'){
					tk->type = TOKEN_SYMBOL;
					tk->value.lit = *(u16*)"<<";
					return ERROR_NONE;
				}
				chr = '<';
				lexSeekCur(-1);
			}
			break;
		}
		tk->type = TOKEN_SYMBOL;
		tk->value.lit = chr;
	}
	
	return ERROR_NONE;
}

Error tkrFetch(Token *tk){
	errTryCatch(
		_tkrFetch(tk)
	);
	//tkPrint(tk);
	return ERROR_NONE;
}

