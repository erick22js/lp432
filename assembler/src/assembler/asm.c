#include "asm.h"
#include "parser.h"


//
//	ASSEMBLER FUNCTIONS
//

void asmOutputError(){
	char msg[MAX_PATH_SIZE*4];
	errSprint(msg, sizeof(msg));
	logInfo("\n%s\n", msg);
	logInfo("\tCOMPILATION FAIL!!!\n\n\n");
}
void asmOutputSuccess(){
	logInfo("\n\tCOMPILATION SUCCESS!\n\n\n");
}

Error asmFile(char* path, u8** out, u32 *out_size) {
	Error err = ERROR_NONE;
	
	lexOpenFile(path);
	if ((err = psrParse(false))){
		asmOutputError();
		return err;
	}
	
	lexOpenFile(path);
	if ((err = psrParse(true))){
		asmOutputError();
		return err;
	}
	
	asmOutputSuccess();
	
	*out = asm_info.bin;
	*out_size = asm_info.bin_size;
	return ERROR_NONE;
}

Error asmCString(char* cstr, char* vpath, u8** out, u32 *out_size) {
	Error err = ERROR_NONE;
	
	pathOpen(lexOpenString(cstr)->path, vpath);
	if ((err = psrParse(false))){
		asmOutputError();
		return err;
	}
	
	pathOpen(lexOpenString(cstr)->path, vpath);
	if ((err = psrParse(true))){
		asmOutputError();
		return err;
	}
	
	asmOutputSuccess();
	
	*out = asm_info.bin;
	*out_size = asm_info.bin_size;
	
	return ERROR_NONE;
}
