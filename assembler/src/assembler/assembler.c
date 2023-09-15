#include "assembler.h"
#include "processor.h"


/*
	API Functions
*/
int asmAssemblyString(const char* src, uint8** bin, uint32* bin_size){
	*bin = malloc(1);
	*bin_size = 1;

	lexerOpenString(src);
	while (!lexerEnded()){
		log("%c", lexerGet());
	}
	lexerClose();

	return ERROR_NONE;
}
int asmAssemblyFile(const char* path, uint8** bin, uint32* bin_size){

	return ERROR_NONE;
}

