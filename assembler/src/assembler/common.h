#ifndef ASM_COMMON_H
#define ASM_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>


//
//	TYPES DEFINITION
//

typedef _Bool bool;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float f32;
typedef double f64;


//
//	VALUES DEFINITION
//

#define null 0
#define false 0
#define true 1


//
//	UTIL FUNCTIONS
//

// Data Sign Extension

#define u8ToInt(data) ((int)((i8)((u8)data)))

#define u16ToInt(data) ((int)((i16)((u16)data)))

#define u32ToInt(data) ((int)((i32)((u32)data)))

// Memory Allocation

#define mem_alloc(size) (malloc(size))

#define mem_realloc(ptr, size) (realloc(ptr, size))

#define mem_free(ptr) (free(ptr))


//
//	ASSEMBLER CONFIGURATIONS
//

#define MAX_NAME_LENGTH 255
#define MAX_STRING_LENGTH 65535
#define MAX_CMD_PARAMS 4


#endif