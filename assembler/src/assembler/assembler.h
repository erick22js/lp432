#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "common.h"
#include "error.h"


/*
	API Functions
*/
// Assembles src given by a string text, return zero on success or error code
extern int asmAssemblyString(const char* src, uint8** bin, uint32* bin_size);
// Assembles src given by a path text, return zero on success or error code
extern int asmAssemblyFile(const char* path, uint8** bin, uint32* bin_size);


#endif