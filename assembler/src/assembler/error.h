#ifndef ASM_ERROR_H
#define ASM_ERROR_H

#include <stdio.h>
#include <stdint.h>


/*
	Error Codes
*/

#define ERROR_NONE 0
#define ERROR_UNKNOWN 1
#define ERROR_SYMBOL_NOT_DEFINED 2
#define ERROR_EXPECTED_CHAR 3
#define ERROR_UNEXPECTED 4
#define ERROR_UNTERMINATED_STRING 5
#define ERROR_INVALID_NUMBER_POSFIX 6
#define ERROR_INVALID_CAST_TYPE 10
#define ERROR_EXPECTED_DATA_TYPE 11
#define ERROR_DIVISION_BY_ZERO 20
#define ERROR_UNEXISTENT_CONDITION_SPECIFIER 30
#define ERROR_UNSUPPLIED_CONDITION_SPECIFIER 31
#define ERROR_EXPECTED_END_OF_LINE 40
#define ERROR_NO_INSTRUCTION_PATTERN 50
#define ERROR_PREFIX_POSTDOT_MISSING 51
#define ERROR_MACRO_WRONG_ARGUMENTS 52
#define ERROR_ALREADY_DECLARATED_SYMBOL 60
#define ERROR_ALREADY_DECLARATED_MACRO 61
#define ERROR_EXPECTED_PROCESSOR_COMMAND 70
#define ERROR_EXPECTED_MACRO_NAME 71
#define ERROR_EXPECTED_MACRO_PARAM_NAME 72
#define ERROR_EXPECTED_CONSTANT_NAME 73
#define ERROR_EXPECTED_PATH_STRING 74
#define ERROR_EXPECTED_STRING 75
#define ERROR_FILE_DO_NOT_EXISTS 80
#define ERROR_ERROR_INVALID_PROCESSOR_NAME 81


/*
	Error Handling
*/

extern int asm_error_code;
extern intptr_t asm_error_v1;
extern intptr_t asm_error_v2;
extern intptr_t asm_error_v3;
extern intptr_t asm_error_v4;

#define throwError(error) {asm_error_code = error; log("@@@ ERROR Throwed at \"%s\" in line %d, in src file \"%s\" at offset %d with code 0x%X!\n", __FILE__, __LINE__, lexerCurrent()->path, lexerTell(), asm_error_code); return asm_error_code;}
#define tryCatchAndThrow(func) {int err_code = asm_error_code = func; if (err_code) {log("%% ERROR CATCHED at \"%s\" in line %d with code 0x%X and Throwed!\n", __FILE__, __LINE__, err_code); return err_code;}}

extern void asmErrorToString(char* buffer, int buffer_size);


#endif