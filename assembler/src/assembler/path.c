#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>

#include "path.h"


int getFullPath(char* destpath, char* relpath) {
	return GetFullPathName(relpath, 512, destpath, null);
}

int combinePath(char *dst, char *pth1, char *pth2) {
	if(pth1 == NULL && pth2 == NULL) {
		strcpy(dst, "");
	}
	else if(pth2 == NULL || strlen(pth2) == 0) {
		strcpy(dst, pth1);
	}
	else if(pth1 == NULL || strlen(pth1) == 0) {
		strcpy(dst, pth2);
	} 
	else {
		char directory_separator[] = "/";
#ifdef WIN32
		directory_separator[0] = '\\';
#endif
		const char *last_char = pth1;
		while(*last_char != '\0')
			last_char++;        
		int append_directory_separator = 0;
		if(strcmp(last_char, directory_separator) != 0) {
			append_directory_separator = 1;
		}
		strcpy(dst, pth1);
		if(append_directory_separator)
			strcat(dst, directory_separator);
		strcat(dst, pth2);
	}

	char *rm, *fn;
	int l;
	while((rm = strstr (dst, "/../")) != NULL) {
		for(fn = (rm - 1); fn >= dst; fn--) {
			if(*fn == '/') {
				l = strlen(rm + 4);
				memcpy(fn + 1, rm + 4, l);
				*(fn + l + 1) = 0;
				break;
			}
		}
	}
	return 0;
}
