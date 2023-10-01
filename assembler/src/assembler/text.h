#ifndef ASM_TEXT_H
#define ASM_TEXT_H

#include "common.h"


struct _Text;
typedef struct _Text _Text;
struct _Text{
	_Text *next;
	const char* cstr;
};
extern _Text *_text_first;

extern char* textCopy(char* dest, const char* src);

extern const char* textReuse(const char* cstr);


#endif