#ifndef ASM_PATH_H
#define ASM_PATH_H

#include "common.h"


extern int getFullPath(char* destpath, char* relpath);
extern int combinePath(char* destpath, char* base, char* append);


#endif