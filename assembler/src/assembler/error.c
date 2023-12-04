#include "error.h"


/*
	Error Handling
*/

int asm_error_code = 0;
int asm_error_v1 = 0;
int asm_error_v2 = 0;
int asm_error_v3 = 0;
int asm_error_v4 = 0;

void asmErrorToString(char* buffer, int buffer_size) {
	char* format = "unknown error";
	switch (asm_error_code){
		case ERROR_SYMBOL_NOT_DEFINED: format = "symbol with the name '%s' not defined"; break;
		case ERROR_EXPECTED_CHAR: format = "was expected a '%c' token"; break;
		case ERROR_UNEXPECTED: format = "was not expected a %d token"; break;
		case ERROR_UNTERMINATED_STRING: format = "was detected a non terminated string"; break;
		case ERROR_INVALID_NUMBER_POSFIX: format = "invalid number posfix"; break;
		case ERROR_INVALID_CAST_TYPE: format = "invalid casting to data type \"%s\""; break;
		case ERROR_EXPECTED_DATA_TYPE: format = "was expected a data type name"; break;
		case ERROR_DIVISION_BY_ZERO: format = "the divider cannot be zero"; break;
		case ERROR_UNEXISTENT_CONDITION_SPECIFIER: format = "the condition specifier with name \"%s\" does not exists"; break;
		case ERROR_UNSUPPLIED_CONDITION_SPECIFIER: format = "the instruction requires a condition specifier"; break;
		case ERROR_EXPECTED_END_OF_LINE: format = "was expected the end of line"; break;
		case ERROR_NO_INSTRUCTION_PATTERN: format = "does not exists a varyation from instruction \"%s\" with the given parameters"; break;
		case ERROR_PREFIX_POSTDOT_MISSING: format = "was expected a dot following prefix name"; break;
		case ERROR_MACRO_WRONG_ARGUMENTS: format = "the macro \"%s\" was invoked with wrong arguments"; break;
		case ERROR_ALREADY_DECLARATED_SYMBOL: format = "declaring symbol with a name \"%s\" while another with same name exists"; break;
		case ERROR_ALREADY_DECLARATED_MACRO: format = "declaring macro with a name \"%s\" while another with same name exists"; break;
		case ERROR_EXPECTED_PROCESSOR_COMMAND: format = "expected processor command"; break;
		case ERROR_EXPECTED_MACRO_NAME: format = "expected a identifier as macro name"; break;
		case ERROR_EXPECTED_MACRO_PARAM_NAME: format = "expected a identifier as macro parameter name"; break;
		case ERROR_EXPECTED_CONSTANT_NAME: format = "expected a identifier as constant name"; break;
		case ERROR_EXPECTED_PATH_STRING: format = "expected a string for path"; break;
		case ERROR_EXPECTED_STRING: format = "expected a string"; break;
		case ERROR_FILE_DO_NOT_EXISTS: format = "file in include path \"%s\" do not exists or could not be open"; break;
		case ERROR_ERROR_INVALID_PROCESSOR_NAME: format = "invalid processor name \"%s\""; break;
	}
	sprintf_s(buffer, buffer_size, format, asm_error_v1, asm_error_v2, asm_error_v3, asm_error_v4);
}
