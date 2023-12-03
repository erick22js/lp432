#ifndef ASM_ERROR_H
#define ASM_ERROR_H


/*
	Error Codes
*/

#define ERROR_NONE 0x0000
#define ERROR_UNKNOWN 0x0001


/*
	Error Handling
*/

#define throwError(error) {log("@@@ ERROR Throwed at \"%s\" in line %d, in src file \"%s\" at offset %d with code 0x%X!\n", __FILE__, __LINE__, lexerCurrent()->path, lexerTell(), error); return error;}
#define tryCatchAndThrow(code) {int err_code = code; if (err_code) {log("%% ERROR CATCHED at \"%s\" in line %d with code 0x%X and Throwed!\n", __FILE__, __LINE__, err_code); return err_code;}}


#endif