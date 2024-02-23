#include "lexer.h"


//
//	LEXER GLOBALS
//

Lexer lexers[MAX_LEXER_DEPTH];
Lexer *clex = null;
u32 tl = 0;


//
//	LEXER FUNCTIONS
//

Lexer *lexOpenString(char* str) {
	if (tl>=MAX_LEXER_DEPTH){
		return null;
	}
	lexers[tl].length = strlen(str);
	lexers[tl].buffer = (u8*)str;
	lexers[tl].allocated = false;
	lexers[tl].path[0] = 0;
	lexers[tl].seek = 0;
	clex = &lexers[tl];
	tl++;
	return clex;
}

Lexer *lexOpenStream(u8* buffer, u32 size) {
	if (tl>=MAX_LEXER_DEPTH){
		return null;
	}
	lexers[tl].length = size;
	lexers[tl].buffer = buffer;
	lexers[tl].allocated = false;
	lexers[tl].path[0] = 0;
	lexers[tl].seek = 0;
	clex = &lexers[tl];
	tl++;
	return clex;
}

Lexer *lexOpenFile(char* path) {
	if (tl>=MAX_LEXER_DEPTH){
		return null;
	}
	FILE *file = null;
	if (!(file = fopen(path, "r"))){
		return null;
	}
	fseek(file, 0, SEEK_END);
	lexers[tl].length = ftell(file);
	fseek(file, 0, SEEK_SET);
	lexers[tl].buffer = calloc(lexers[tl].length, 1);
	//fread(lexers[tl].buffer, 1, lexers[tl].length, file);
	for (u32 i = 0; i<lexers[tl].length; i++){
		fseek(file, i, SEEK_SET);
		lexers[tl].buffer[i] = fgetc(file);
	}
	fseek(file, 0, SEEK_SET);
	fclose(file);
	lexers[tl].allocated = true;
	pathOpen(lexers[tl].path, path);
	lexers[tl].seek = 0;
	clex = &lexers[tl];
	tl++;
	return clex;
}

bool lexClose() {
	if (clex && clex->allocated){
		free(clex->buffer);
	}
	if (tl) {
		tl--;
		clex = &lexers[tl-1];
		return true;
	}
	clex = null;
	return false;
}

Lexer *lexCurrent() {
	return clex;
}

u8 lexGet() {
	if (!clex){
		return 0;
	}
	if (clex->seek >= clex->length){
		clex->seek++;
		return 0;
	}
	u8 chr = clex->buffer[clex->seek];
	clex->seek++;
	//printf("LEX: '%c' [%d]\n", chr, (clex->seek-1));
	return chr;
}

bool lexEnded() {
	if (!clex){
		return true;
	}
	return clex->seek >= clex->length;
}


int lexDepth() {
	return tl;
}

void lexPosition(u32 offset, u32 *line, u32 *collumn) {
	*line = 1, *collumn = 1;
	for (int i=0; i<(int)clex->length && i<(int)offset; i++){
		char chr = clex->buffer[i];
		if (chr=='\n'){
			(*line)++;
			(*collumn) = 0;
		}
		(*collumn)++;
	}
}

u32 lexTell() {
	if (!clex){
		return 0;
	}
	return clex->seek;
}

u32 lexSize() {
	if (!clex){
		return 0;
	}
	return clex->length;
}

void lexSeekSet(u32 offset) {
	if (!clex){
		return;
	}
	clex->seek = offset;
}

void lexSeekCur(i32 offset) {
	if (!clex){
		return;
	}
	clex->seek += offset;
}

char* lexCopyBuffer(u32 offset, u32 size) {
	if (!clex){
		return null;
	}
	char* buffer = calloc(size, 1);
	for (int i=0; i<(int)size && (i+offset)<(int)clex->length; i++){
		buffer[i] = clex->buffer[i+offset];
	}
	return buffer;
}


