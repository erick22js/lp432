#ifndef ASM_SYMBOL_H
#define ASM_SYMBOL_H

#include "base.h"
#include "path.h"
#include "logger.h"


//
//	SYMBOLS AND STRUCTS DATAS
//

// Label datatype
typedef struct Label Label;
struct Label{
	char* name;
	u32 address;
	Label *next;
};

// Constant datatype
typedef struct Const Const;
struct Const{
	char* name;
	Value value;
	Const *next;
};

// Mark
typedef struct Mark Mark;
struct Mark{
	char* name;
	Mark* next;
};

// Macro datatype
typedef struct Macro Macro;
struct Macro{
	char* name;
	u8* src;
	u32 src_len;
	u32 line;
	Path path;
	Param params[MAX_CMD_PARAMS];
	u32 params_len;
	Macro *next;
};

// Scope datatype
typedef struct Scope Scope;
struct Scope{
	// First item pointers
	Label *label;
	Const *constant;
	Mark *mark;
	Macro *macro;
	
	// relatives
	Scope *child, *ite, *father, *next;
	
	// Arbitrary Data
	u32 datas[32];
	void* refs[32];
};


//
//	HANDLING FUNCTIONS
//

// Label
Label *labelFind(char* name, Scope *scope);
Label *labelStore(char* name, u32 address);

// Const
Const *constFind(char* name, Scope *scope);
Const *constStore(char* name, Value val);

// Symbols values
bool symvHas(char* name);
bool symvHasInCurrentScope(char* name);
bool symvLoad(char* name, Value *out);

// Mark
Mark *markFind(char* name);
Mark *markStore(char* name);
bool markRemove(char* name);
void markReset();

// Macro
Macro *macroFindInScope(char* name, Scope *scope);
Macro *macroFind(char* name);
Macro *macroStore(char* name, u8* src, u32 src_len, Param* params, u32 params_len);

// Scope
void scopeRestart();
Scope *scopeEnter();
Scope *scopeCurrent();
int scopeLeave();
int scopeDepth();


#endif