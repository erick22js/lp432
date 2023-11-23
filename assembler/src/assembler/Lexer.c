#include "lexer.h"
#include "text.h"
#include "path.h"

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
		/*
		lexer->src_len = strlen(src);
		lexer->src = (char*)mem_alloc(lexer->src_len+2);
		char* lsrc = textCopy(lexer->src, src);
		lsrc[lexer->src_len] = ' ';
		lsrc[lexer->src_len+1] = 0;
		*/
		lexer->limit = 0;
		lexer->status = 0;
		lexer->args = null;
		lexer->src = src;
		lexer->src_len = strlen(src)+1;
		getFullPath(lexer->path, './');

		lexer->seek = 0;
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
		getFullPath(lexer->path, path);
		lexer->limit = 0;
		lexer->status = 0;
		lexer->args = null;
		lexer->src = null;
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
		else{
			//mem_free(cur_lexer->src);
		}
		lexers_top--;
		cur_lexer = &lexers[lexers_top-1];
		return true;
	}
	return false;
}
Lexer *lexerCurrent() {
	return cur_lexer;
}
uint32 lexerGet(){
	if (!cur_lexer){
		return EOF;
	}
	if (cur_lexer->type == LEXER_TYPE_FILE){
		if (cur_lexer->limit && ftell(cur_lexer->file)>=cur_lexer->limit){
			return EOF;
		}
		return fgetc(cur_lexer->file);
	}
	else{
		uint32 chr = EOF;
		if (cur_lexer->seek < cur_lexer->src_len && (!cur_lexer->limit || cur_lexer->seek<cur_lexer->limit)){
			chr = cur_lexer->src[cur_lexer->seek];
		}
		if (chr == 0){
			chr = EOF;
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
		if (cur_lexer->limit && ftell(cur_lexer->file)>=cur_lexer->limit){
			return true;
		}
		return feof(cur_lexer->file);
	}
	else{
		if (cur_lexer->limit && cur_lexer->seek>=cur_lexer->limit){
			return true;
		}
		return cur_lexer->seek >= cur_lexer->src_len;
	}
}
bool hasRemainLexers(){
	return lexers_top != 0;
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
		if (feof(cur_lexer->file)){
			return;
		}
		fseek(cur_lexer->file, offset, SEEK_CUR);
	}
	else{
		cur_lexer->seek += offset;
	}
}
