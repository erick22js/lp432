#ifndef ASM_PATH_H
#define ASM_PATH_H

#include "common.h"


//
//	PATH CONFIGURATION
//

#define PATH_SEPARATOR '/'
#define MAX_PATH_SIZE 255
typedef char Path[MAX_PATH_SIZE+1];
typedef char* PathPtr;

#define PATH_ERROR 1


//
//	PATH FUNCTIONS
//

bool pathIsAbsolute(PathPtr out);
int pathOpen(PathPtr out, char* in);
int pathCombine(PathPtr out, char* in);


#endif