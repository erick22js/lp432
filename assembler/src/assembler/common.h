#ifndef EMU_COMMON_H
#define EMU_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>


/*
	Primitive Typedefs
*/

typedef _Bool bool;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef int8_t sint8;
typedef int16_t sint16;
typedef int32_t sint32;
typedef int64_t sint64;

typedef float float32;
typedef double float64;

struct Pci;


/*
	Primitive Values
*/

#define true 1
#define false 0
#define null ((void*)0)


/*
	Basic Operation Functions
*/

#define u8ToInt(data) ((int)((sint8)((uint8)(data))))
#define u16ToInt(data) ((int)((sint16)((uint16)(data))))
#define u32ToInt(data) ((int)((sint32)((uint32)(data))))

#define eval(v) (!!(v))
#define setBit(data, bit, v) (v? (data)|bit: (data)&(~bit))

#define mem_alloc(size) (malloc(size))
#define mem_free(ptr) (free(ptr))
#define mem_realloc(oldptr, size) (realloc(oldptr, size))


/*
	Basic Debug Functions
*/

#define log(...) {printf(__VA_ARGS__);}



#endif