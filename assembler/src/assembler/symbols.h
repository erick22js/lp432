#ifndef ASM_SYMBOLS_H
#define ASM_SYMBOLS_H

#include "base.h"


/*
	Symbols Structures
*/

// Label
typedef struct{
	const char* name;
	Value value;
}SymLabel;

extern SymLabel sym_labels[];
extern int sym_labels_top;

extern SymLabel *findSymLabel(const char* name);
extern void storeSymLabel(const char* name, Value value);

// General
extern Value *findSymbol(const char* name);

#endif