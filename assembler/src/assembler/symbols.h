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


// Constant
struct SymConst;
typedef struct SymConst SymConst;
struct SymConst{
	const char* name;
	Value value;
	SymConst *next;
};

extern void storeSymConst(const char* name, Value value);


// Macro
struct SymMacro;
typedef struct SymMacro SymMacro;
struct SymMacro{
	const char* name;
	const char* src;
	struct {
		const char* name;
		DataType type;
	}params[4];
	int params_len;
	uint32 start, end;
	SymMacro *next;
};


// Arguments
struct SymArg;
typedef struct SymArg SymArg;
struct SymArg{
	const char* name;
	Value value;
	DataType type;
	SymArg *next;
};

extern SymMacro* findMacro(const char* name);
extern void storeSymMacro(SymMacro macro);


// Scope
struct Scope;
typedef struct Scope Scope;
struct Scope{
	const char* name;
	SymLabel *first_label;
	SymConst *first_const;
	SymMacro *first_macro;
	SymArg *first_arg;
	Scope *parent;
	Scope *child;
	Scope *ite;
	Scope *next;
};
extern Scope* scope_cur;
extern Scope* scope_first;

extern SymArg* findSymArg(const char* name);
extern void storeSymArg(const char* name, Value value);

extern void scopeReset();
extern void scopeEnter();
extern bool scopeLeave();


// Mark
struct Mark;
typedef struct Mark Mark;
struct Mark {
	const char* name;
	Mark *next;
};
extern Mark* mark_top;
extern Mark* mark_first;

extern bool hasMark(const char* name);
extern bool setMark(const char* name);
extern bool unsetMark(const char* name);
extern void resetMarks();


// General
extern SymLabel *findSymLabel(Scope *cur_scope, const char* name);
extern Value *findSymbol(const char* name);

#endif