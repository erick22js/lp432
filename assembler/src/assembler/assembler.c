#include "assembler.h"
#include "parser.h"


/*
	Internal Functions
*/

int asmAssembly(Lexer*(*opener)(const char*), const char* src, uint8** bin, uint32* bin_size) {
	opener(src);
	int err = parserParse(true, bin, bin_size);
	if (err){
		log("\n\n\nCompilation FAILED!!!\n\n");
		return err;
	}

	opener(src);
	err = parserParse(false, bin, bin_size);
	if (err){
		log("\n\n\nCompilation FAILED!!!\n\n");
		return err;
	}
	
	log("\n\n\nCompilation SUCCESS!!!\n\n");
	return ERROR_NONE;
}

/*
	API Functions
*/
int asmAssemblyString(const char* src, uint8** bin, uint32* bin_size){
	return asmAssembly(lexerOpenString, src, bin, bin_size);
}
int asmAssemblyFile(const char* path, uint8** bin, uint32* bin_size){
	return asmAssembly(lexerOpenFile, path, bin, bin_size);
}

