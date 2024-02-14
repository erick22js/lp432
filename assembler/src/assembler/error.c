#include "error.h"
#include "lexer.h"
#include "symbol.h"


//
//	TYPES AND SYMBOLS DEFINITION
//

Error err_code = ERROR_NONE;
u32 err_offset = 0;
u32 err_params[4] = {0};
void* (err_refs[4]) = {0};



//
//	UTILITIES FUNCTIONS
//

void errSprint(char* out, int limit) {
	char* msg = mem_alloc(limit*sizeof(char));
	u32 line = 0, collumn = 0;
	lexPosition(err_offset, &line, &collumn);
	line += lexCurrent()->datas[0]? ((Macro*)lexCurrent()->refs[0])->line: 0;
	#define fmp(...)\
		{sprintf(msg, __VA_ARGS__); sprintf(out, "ERROR 0x%X in file \"%s\" in line %d on offset %d:\n\t%s\n", err_code, lexCurrent()->path, line, collumn, msg);}
	switch (err_code){
		case ERROR_SRC_FILE_NOT_OPEN: {
			fmp("Could not open src file");
		}
		break;
		case ERROR_UNEXPECTED_TOKEN: {
			fmp("Unexpected token");
		}
		break;
		case ERROR_UNEXPECTED_NAME: {
			fmp("Unexpected name");
		}
		break;
		case ERROR_EXPECTED_NAME: {
			fmp("Was expected a name");
		}
		break;
		case ERROR_EXPECTED_CLOSIN_BRACKET: {
			fmp("Was expected a closin bracket");
		}
		break;
		case ERROR_EXPECTED_CLOSIN_PAREN: {
			fmp("Was expected a closin paren");
		}
		break;
		case ERROR_EXPECTED_COMMAND: {
			fmp("Was expected a command name");
		}
		break;
		case ERROR_EXPECTED_STRING: {
			fmp("Was expected a string");
		}
		break;
		case ERROR_EXPECTED_IMMEDIATE: {
			fmp("Was expected a immediate literal value");
		}
		break;
		case ERROR_EXPECTED_CASTNAME: {
			fmp("Was expected a cast name");
		}
		break;
		case ERROR_EXPECTED_DATANAME: {
			fmp("Was expected a data type name");
		}
		break;
		case ERROR_EXPECTED_EOL: {
			fmp("Was expected a end of line");
		}
		break;
		case ERROR_INVALID_CASTING: {
			fmp("Invalid casting from/to types");
		}
		break;
		case ERROR_INVALID_OPERANDS: {
			fmp("Invalid operands operation type");
		}
		break;
		case ERROR_DIVISOR_ZERO: {
			fmp("Division by zero is not allowed");
		}
		break;
		case ERROR_MACRO_INSIDE_MACRO: {
			fmp("Cannot declare macro inside a macro declaration");
		}
		break;
		case ERROR_SKIP_INSIDE_MACRO: {
			fmp("Cannot skip file inside macro declaration");
		}
		break;
		case ERROR_EXPECTED_INSTRUCTION_SUFIX: {
			fmp("Was expected a sufix for instruction");
		}
		break;
		case ERROR_INSTRUCTION_NO_PATTERN: {
			fmp("No any instruction params pattern matched");
		}
		break;
		case ERROR_MACRO_NO_PATTERN: {
			fmp("The macro params pattern did not match");
		}
		break;
		case ERROR_SYMBOL_ALREADY_DEFINED: {
			fmp("A symbol with same name was previously defined");
		}
		break;
		case ERROR_SYMBOL_NOT_DEFINED: {
			fmp("A symbol with name was not defined");
		}
		break;
		case ERROR_UNMATCHED_SCOPE_LOCATION: {
			fmp("The current scope of program is not valid");
		}
		break;
		case ERROR_LEAVING_GLOBAL_SCOPE: {
			fmp("Cannot leave the global scope");
		}
		break;
		case ERROR_LEAVING_MACRO_SCOPE: {
			fmp("Cannot leave the macro scope");
		}
		break;
		default: {
			fmp("Unknown error");
		}
	}
	mem_free(msg);
}

