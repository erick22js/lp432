#include "lexer.h"

/*
	Storage Lexers
*/

#define MAX_LEXERS 32
Lexer lexers[32];
Lexer *cur_lexer = null;
int lexers_top = 0;


/*
	API Functions
*/
Lexer *lexerOpenString(const char* src){
	if (lexers_top < MAX_LEXERS){
		Lexer *lexer = &lexers[lexers_top];
		lexer->type = LEXER_TYPE_STRING;
		lexer->src = src;
		lexer->src_len = strlen(src);
		lexers_top++;
		cur_lexer = lexer;
		return lexer;
	}
	return null;
}
Lexer *lexerOpenFile(const char* path){
	if (lexers_top < MAX_LEXERS){
		Lexer *lexer = &lexers[lexers_top];
		lexer->type = LEXER_TYPE_FILE;
		if (fopen_s(&lexer->file, path, "r")){
			return null;
		}
		lexers_top++;
		cur_lexer = lexer;
		return lexer;
	}
	return null;
}
bool lexerClose(){
	if (!cur_lexer){
		return true;
	}
	if (lexers_top > 0){
		if (cur_lexer->type == LEXER_TYPE_FILE){
			fclose(cur_lexer->file);
		}
		lexers_top--;
		cur_lexer = &lexers[lexers_top];
		return true;
	}
	return false;
}
uint32 lexerGet(){
	if (!cur_lexer){
		return EOF;
	}
	if (cur_lexer->type == LEXER_TYPE_FILE){
		return fgetc(cur_lexer->file);
	}
	else{
		uint32 chr = EOF;
		if (cur_lexer->seek < cur_lexer->src_len){
			chr = cur_lexer->src[cur_lexer->seek];
		}
		cur_lexer->seek++;
		return chr;
	}
}
bool lexerEnded(){
	if (!cur_lexer){
		return true;
	}
	if (cur_lexer->type == LEXER_TYPE_FILE){
		return feof(cur_lexer->file);
	}
	else{
		return cur_lexer->seek >= cur_lexer->src_len;
	}
}
uint32 lexerTell(){
	if (!cur_lexer){
		return 0;
	}
	if (cur_lexer->type == LEXER_TYPE_FILE){
		return ftell(cur_lexer->file);
	}
	else{
		return cur_lexer->seek;
	}
}
void lexerSeekSet(uint32 address){
	if (!cur_lexer){
		return;
	}
	if (cur_lexer->type == LEXER_TYPE_FILE){
		fseek(cur_lexer->file, address, SEEK_SET);
	}
	else{
		cur_lexer->seek = address;
	}
}
void lexerSeekCur(int offset){
	if (!cur_lexer){
		return;
	}
	if (cur_lexer->type == LEXER_TYPE_FILE){
		fseek(cur_lexer->file, offset, SEEK_CUR);
	}
	else{
		cur_lexer->seek += offset;
	}
}
