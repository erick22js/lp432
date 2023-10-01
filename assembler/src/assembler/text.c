#include "text.h"


_Text *_text_first = (_Text*)null;

char* textCopy(char* dest, const char* src){
	char* l_dest = dest;
	while (*src){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return l_dest;
}

const char* textReuse(const char* cstr){
	// Gets the pointer to the first entry
	_Text **text = &_text_first;

	// Iterates over a linked list of Texts
	while (*text){
		// Compares if current text matches the given one
		if (strcmp((*text)->cstr, cstr) == 0){
			return (*text)->cstr;
		}
		// Advances
		text = &(*text)->next;
	}
	// Allocate a Text entry with a c-string
	uint8* ntext = (uint8*)mem_alloc(sizeof(_Text) + strlen(cstr)+1);
	char* str = (char*)(ntext + sizeof(_Text));

	// Copies the content from one to another
	textCopy(str, cstr);

	// Saves the reference to the new entry and return allocated string
	*text = (_Text*)ntext;
	(*text)->next = (_Text*)null;
	(*text)->cstr = str;
	return str;
}
