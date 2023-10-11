#ifndef ASM_SYMBOLS_H
#define ASM_SYMBOLS_H

#include "base.h"


/*
	Symbols Structures
*/

extern char sym_buffer[];
extern int sym_top;

// Label
struct SymLabel;
typedef struct SymLabel SymLabel;
struct SymLabel{
	const char* name;
	Value value;
	SymLabel *next;
};

extern void storeSymLabel(const char* name, Value value);


// Scope
struct Scope;
typedef struct Scope Scope;
struct Scope{
	const char* name;
	SymLabel *first_label;
	Scope *parent;
	Scope *child;
	Scope *ite;
	Scope *next;
};
extern Scope* scope_cur;
extern Scope* scope_first;

extern void scopeReset();
extern void scopeEnter();
extern bool scopeLeave();


// General
extern SymLabel *findSymLabel(Scope *cur_scope, const char* name);
extern Value *findSymbol(const char* name);

#endif