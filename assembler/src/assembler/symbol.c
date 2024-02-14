#include "symbol.h"



//
//	SYMBOLS AND STRUCTS DATAS
//

Scope *scope_cur = null,
*scope_first = null;
u32 scope_depth = 0;


//
//	HANDLING FUNCTIONS
//

// Label
Label *labelFind(char* name, Scope *scope) {
	Label **entry = &scope->label;
	while (*entry){
		if (strcmp((*entry)->name, name)==0){
			return *entry;
		}
		entry = &(*entry)->next;
	}
	return null;
}

Label *labelStore(char* name, u32 address) {
	Label **entry = &scope_cur->label;
	while (*entry){
		if (strcmp((*entry)->name, name)==0){
			return *entry;
		}
		entry = &(*entry)->next;
	}
	
	(*entry) = mem_alloc(sizeof(Label));
	(*entry)->name = name;
	(*entry)->address = address;
	(*entry)->next = null;
	return (*entry);
}

// Const
Const *constFind(char* name, Scope *scope) {
	Const **entry = &scope->constant;
	while (*entry){
		if (strcmp((*entry)->name, name)==0){
			return *entry;
		}
		entry = &(*entry)->next;
	}
	return null;
}

Const *constStore(char* name, Value val) {
	Const **entry = &scope_cur->constant;
	while (*entry){
		if (strcmp((*entry)->name, name)==0){
			return *entry;
		}
		entry = &(*entry)->next;
	}
	
	(*entry) = mem_alloc(sizeof(Const));
	(*entry)->name = name;
	(*entry)->value = val;
	(*entry)->next = null;
	return (*entry);
}

// Symbols values
bool symvHas(char* name) {
	Scope *scope = scope_cur;
	while (scope){
		Label *label = labelFind(name, scope);
		if (label){
			return true;
		}
		Const *constant = constFind(name, scope);
		if (constant){
			return true;
		}
		scope = scope->father;
	}
	return false;
}

bool symvHasInCurrentScope(char* name) {
	Scope *scope = scope_cur;
	Label *label = labelFind(name, scope);
	if (label){
		return true;
	}
	Const *constant = constFind(name, scope);
	if (constant){
		return true;
	}
	return false;
}

bool symvLoad(char* name, Value *out) {
	Scope *scope = scope_cur;
	while (scope){
		Label *label = labelFind(name, scope);
		if (label){
			out->type = TYPE_IMM;
			out->val.lit = label->address;
			return true;
		}
		Const *constant = constFind(name, scope);
		if (constant){
			*out = constant->value;
			return true;
		}
		scope = scope->father;
	}
	return false;
}

// Mark
Mark *markFind(char* name) {
	Mark **entry = &scope_first->mark;
	while (*entry){
		if (strcmp((*entry)->name, name)==0){
			return *entry;
		}
		entry = &(*entry)->next;
	}
	return null;
}

Mark *markStore(char* name) {
	Mark **entry = &scope_first->mark;
	while (*entry){
		if (strcmp((*entry)->name, name)==0){
			return *entry;
		}
		entry = &(*entry)->next;
	}
	
	(*entry) = mem_alloc(sizeof(Mark));
	(*entry)->name = name;
	(*entry)->next = null;
	return (*entry);
}

bool markRemove(char* name) {
	Mark **entry = &scope_first->mark, **last = null;
	while (*entry){
		if (strcmp((*entry)->name, name)==0){
			if (!last){
				scope_first->mark = (*entry)->next;
			}
			else {
				(*last)->next = (*entry)->next;
			}
			mem_free((*entry));
			return true;
		}
		last = entry;
		entry = &(*entry)->next;
	}
	return false;
}

void markReset() {
	Mark *mark = scope_first->mark;
	// This is literally thrown problem below the carpet
	// I just don't wanna focus on solving this problem, highly chances of be a SO's problem
	/*while (mark){
		mem_free(mark);
		mark = mark->next;
	}*/
	scope_first->mark = null;
}

// Macro
Macro *macroFindInScope(char* name, Scope *scope) {
	Macro **entry = &scope->macro;
	while (*entry){
		if (strcmp((*entry)->name, name)==0){
			return *entry;
		}
		entry = &(*entry)->next;
	}
	return null;
}

Macro *macroFind(char* name) {
	Scope *scope = scope_cur;
	while (scope){
		Macro **entry = &scope->macro;
		while (*entry){
			if (strcmp((*entry)->name, name)==0){
				return *entry;
			}
			entry = &(*entry)->next;
		}
		scope = scope->father;
	}
	return null;
}

Macro *macroStore(char* name, u8* src, u32 src_len, Param* params, u32 params_len) {
	Macro **entry = &scope_cur->macro;
	while (*entry){
		if (strcmp((*entry)->name, name)==0){
			return *entry;
		}
		entry = &(*entry)->next;
	}
	
	(*entry) = mem_alloc(sizeof(Macro));
	(*entry)->name = name;
	(*entry)->src = src;
	(*entry)->src_len = src_len;
	for (int i=0; i<(int)params_len && i<MAX_CMD_PARAMS; i++){
		(*entry)->params[i] = params[i];
	}
	(*entry)->params_len = params_len;
	(*entry)->next = null;
	return (*entry);
}

// Scope
void scopeRestart() {
	if (!scope_first){
		scope_first = (Scope*)mem_alloc(sizeof(Scope));
		memset(scope_first, 0, sizeof(Scope));
	}
	/*while (scope_cur){
		scope_cur->ite = null;
		scope_cur = scope_cur->father;
	}*/
	Scope *rs = scope_first;
	rs->ite = null;
	while (rs){
		rs->ite = null;
		if (rs->child){
			rs = rs->child;
			continue;
		}
		if (rs->next){
			rs = rs->next;
			continue;
		}
		while (rs->father && !rs->father->next){
			rs = rs->father;
		}
		if (!rs->father){
			break;
		}
		rs = rs->father->next;
	}
	
	scope_cur = scope_first;
	scope_depth = 1;
	logDevInfo("SCP: Restarted {%p} - depth %d\n", scope_cur, scope_depth);
}

Scope *scopeEnter() {
	if (!scope_cur->child){
		scope_cur->child = (Scope*)mem_alloc(sizeof(Scope));
		memset(scope_cur->child, 0, sizeof(Scope));
		scope_cur->child->father = scope_cur;
	}
	else if (scope_cur->ite && !scope_cur->ite->next){
		scope_cur->ite->next = (Scope*)mem_alloc(sizeof(Scope));
		memset(scope_cur->ite->next, 0, sizeof(Scope));
		scope_cur->ite->next->father = scope_cur;
	}
	
	if (!scope_cur->ite){
		scope_cur->ite = scope_cur->child;
	}
	else {
		scope_cur->ite = scope_cur->ite->next;
	}
	scope_cur = scope_cur->ite;
	scope_depth++;
	logDevInfo("SCP: Entered {%p} - depth %d\n", scope_cur, scope_depth);
	return scope_cur;
}

Scope *scopeCurrent() {
	return scope_cur;
}

int scopeLeave() {
	scope_cur->ite = null;
	scope_cur = scope_cur->father;
	scope_depth--;
	logDevInfo("SCP: Leaved {%p} - depth %d\n", scope_cur, scope_depth);
	return scope_depth;
}

int scopeDepth() {
	return scope_depth;
}
