#include "logger.h"


//
//	LOG PROPERTIES
//

FILE *__log_low = null;
FILE *__log_high = null;
bool __log_low_enable = false;
bool __log_high_enable = false;
