#ifndef ASM_LEXER_H
#define ASM_LEXER_H

#include "path.h"


//
//	STRUCTURE AND DATATYPES
//

#define MAX_LEXER_DEPTH 32

typedef struct Lexer Lexer;
struct Lexer{
	// File information
	Path path;
	
	// Buffer information
	bool allocated;
	u8* buffer;
	u32 length;
	u32 seek;
	
	// Arbitrary Data
	u32 datas[32];
	void* refs[32];
};


//
//	LEXER FUNCTIONS
//
Lexer *lexOpenString(char* str);
Lexer *lexOpenStream(u8* buffer, u32 size);
Lexer *lexOpenFile(char* path);
bool lexClose();
Lexer *lexCurrent();
u8 lexGet();
bool lexEnded();
int lexDepth();
void lexPosition(u32 offset, u32 *line, u32 *collumn);
u32 lexTell();
u32 lexSize();
void lexSeekSet(u32 offset);
void lexSeekCur(i32 offset);
char* lexCopyBuffer(u32 offset, u32 size);

//
//	POINTER MANIPULATION
//

#define seekCreate() u32 _s_ret = lexTell();
#define seekSave() {_s_ret = lexTell();}
#define seekRestore() {lexSeekSet(_s_ret);}


#endif