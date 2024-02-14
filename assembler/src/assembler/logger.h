#ifndef ASM_LOGGER_H
#define ASM_LOGGER_H

#include "common.h"


//
//	LOG PROPERTIES
//

extern FILE *__log_low;
extern FILE *__log_high;
extern bool __log_low_enable;
extern bool __log_high_enable;


//
//	LOG FUNCTION
//

// Initializes logger
#define logInit(dev_info_path, dev_info_enable, user_info_path, user_info_enable) {\
		char* dp = dev_info_path;\
		char* up = user_info_path;\
		__log_low = dp==null? stdout: fopen(dp, "w");\
		__log_low_enable = dev_info_enable;\
		__log_high = up==null? stdout: fopen(up, "w");\
		__log_high_enable = user_info_enable;\
	}

// Log every assembly internal detail
#define logDevInfo(...) {\
		if (__log_low && __log_low_enable){\
			fprintf(__log_low, __VA_ARGS__);\
		}\
	}

// Log every high level information
#define logUserInfo(...) {\
		if (__log_high && __log_high_enable){\
			fprintf(__log_high, __VA_ARGS__);\
		}\
	}

// Log to all outputs
#define logInfo(...) {\
		if (__log_low && __log_low_enable){\
			fprintf(__log_low, __VA_ARGS__);\
		}\
		if (__log_high && __log_high_enable){\
			if (__log_low!=__log_high) fprintf(__log_high, __VA_ARGS__);\
		}\
	}

// Flushes every log output
#define logFlush() {\
		if (__log_low){\
			fflush(__log_low);\
		}\
		if (__log_high){\
			fflush(__log_high);\
		}\
	}



#endif