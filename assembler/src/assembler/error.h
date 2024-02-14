#ifndef ASM_ERROR_H
#define ASM_ERROR_H

#include "logger.h"


//
//	TYPES AND SYMBOLS DEFINITION
//

typedef u32 Error;

#define ERROR_NONE 0
#define ERROR_UNKNOWN 1

#define ERROR_SRC_FILE_NOT_OPEN 0x08

#define ERROR_UNEXPECTED_TOKEN 0x10
#define ERROR_UNEXPECTED_NAME 0x11
#define ERROR_EXPECTED_NAME 0x14
#define ERROR_EXPECTED_CLOSIN_BRACKET 0x15
#define ERROR_EXPECTED_CLOSIN_PAREN 0x16
#define ERROR_EXPECTED_COMMAND 0x18
#define ERROR_EXPECTED_STRING 0x19
#define ERROR_EXPECTED_IMMEDIATE 0x1A
#define ERROR_EXPECTED_CASTNAME 0x1B
#define ERROR_EXPECTED_DATANAME 0x1C
#define ERROR_EXPECTED_EOL 0x1F

#define ERROR_INVALID_CASTING 0x20
#define ERROR_INVALID_OPERANDS 0x21
#define ERROR_DIVISOR_ZERO 0x22

#define ERROR_MACRO_INSIDE_MACRO 0x30
#define ERROR_SKIP_INSIDE_MACRO 0x31

#define ERROR_EXPECTED_INSTRUCTION_SUFIX 0x40
#define ERROR_INSTRUCTION_NO_PATTERN 0x41
#define ERROR_MACRO_NO_PATTERN 0x42

#define ERROR_SYMBOL_ALREADY_DEFINED 0x50
#define ERROR_MACRO_SAME_NAME 0x51
#define ERROR_SYMBOL_NOT_DEFINED 0x58

#define ERROR_UNMATCHED_SCOPE_LOCATION 0x70
#define ERROR_LEAVING_GLOBAL_SCOPE 0x71
#define ERROR_LEAVING_MACRO_SCOPE 0x72


extern Error err_code;
extern u32 err_offset;
extern u32 err_params[4];
extern void* (err_refs[4]);


//
//	UTILITIES FUNCTIONS
//

#define errThrow(err) { logDevInfo("ERR: Throwed error at file \"%s\" at line %d\n", __FILE__, __LINE__); err_code = err; return err; }
#define errTryCatch(operation) { Error err = operation; if (err){ logDevInfo("ERR: Catched error at file \"%s\" at line %d\n", __FILE__, __LINE__); return err; } }

void errSprint(char* out, int limit);


#endif