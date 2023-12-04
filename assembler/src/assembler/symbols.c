#include "symbols.h"
#include "text.h"


char sym_buffer[1024*1024*8];
int sym_top = 0;

Scope scope = {0};
Scope* scope_cur = &scope;
Scope* scope_first = &scope;


// Internal managment
#define sym_alloc(type) ((type*)(sym_buffer + ((sym_top+=sizeof(type)) - sizeof(type))))


// Scope
void scopeReset(){
	scope_cur = scope_first;
	scope_cur->ite = null;
}
void scopeEnter(){
	if (scope_cur->ite){
		if (!scope_cur->ite->next){
			scope_cur->ite->next = sym_alloc(Scope);
			scope_cur->ite->next->parent = scope_cur;
		}
		scope_cur->ite = scope_cur->ite->next;
	}
	else {
		if (!scope_cur->child){
			scope_cur->child = sym_alloc(Scope);
			scope_cur->child->parent = scope_cur;
		}
		scope_cur->ite = scope_cur->child;
	}
	scope_cur = scope_cur->ite;
}
bool scopeLeave(){
	scope_cur->ite = null;
	if (scope_cur->parent){
		scope_cur = scope_cur->parent;
		return true;
	}
	return false;
}


// Label
SymLabel *findSymLabel(Scope *scope, const char* name){
	SymLabel **cur_label = &scope->first_label;
	while (*cur_label){
		if (strcmp((*cur_label)->name, name) == 0){
			return *cur_label;
		}
		cur_label = &(*cur_label)->next;
	}
	return null;
}
void storeSymLabel(const char* name, Value value){
	SymLabel **cur_label = &scope_cur->first_label;
	while (*cur_label){
		cur_label = &(*cur_label)->next;
	}
	*cur_label = sym_alloc(SymLabel);
	(*cur_label)->name = textReuse(name);
	(*cur_label)->value = value;
	(*cur_label)->next = null;
}


// Constant
SymConst *findSymConst(Scope *scope, const char* name){
	SymConst **cur_const = &scope->first_const;
	while (*cur_const){
		if (strcmp((*cur_const)->name, name) == 0){
			return *cur_const;
		}
		cur_const = &(*cur_const)->next;
	}
	return null;
}
void storeSymConst(const char* name, Value value){
	SymConst **cur_const = &scope_cur->first_const;
	while (*cur_const){
		cur_const = &(*cur_const)->next;
	}
	*cur_const = sym_alloc(SymConst);
	(*cur_const)->name = textReuse(name);
	(*cur_const)->value = value;
	(*cur_const)->next = null;
}


// Macro
SymMacro* findMacro(const char* name) {
	Scope *scope = scope_cur;
	while (scope){
		SymMacro **cur_macro = &scope->first_macro;
		while (*cur_macro){
			if (strcmp((*cur_macro)->name, name) == 0){
				return *cur_macro;
			}
			cur_macro = &(*cur_macro)->next;
		}
		scope = scope->parent;
	}
	return null;
}
void storeSymMacro(SymMacro macro) {
	SymMacro **cur_macro = &scope_cur->first_macro;
	while (*cur_macro){
		cur_macro = &(*cur_macro)->next;
	}
	*cur_macro = sym_alloc(SymMacro);
	**cur_macro = macro;
	(*cur_macro)->name = textReuse(macro.name);
	for (int i = 0; i<(*cur_macro)->params_len; i++){
		(*cur_macro)->params[i].name = textReuse((*cur_macro)->params[i].name);
	}
	(*cur_macro)->next = null;
}


// Arguments
SymArg* findSymArg(const char* name){
	SymArg **cur_arg = &scope_cur->first_arg;
	while (*cur_arg){
		if (strcmp((*cur_arg)->name, name) == 0){
			return *cur_arg;
		}
		cur_arg = &(*cur_arg)->next;
	}
	return null;
}
void storeSymArg(const char* name, Value value){
	SymArg **cur_arg = &scope_cur->first_arg;
	while (*cur_arg){
		if (strcmp((*cur_arg)->name, name) == 0){
			(*cur_arg)->value = value;
			return;
		}
		cur_arg = &(*cur_arg)->next;
	}
	*cur_arg = sym_alloc(SymArg);
	(*cur_arg)->name = name;
	(*cur_arg)->value = value;
	(*cur_arg)->type = value.type;
	(*cur_arg)->next = null;
}


// Mark
Mark* mark_top = NULL;
Mark* mark_first = NULL;

bool hasMark(const char* name) {
	Mark *cur_mark = mark_first;
	while (cur_mark){
		if (strcmp(cur_mark->name, name) == 0){
			return true;
		}
		cur_mark = cur_mark->next;
	}
	return false;
}

bool setMark(const char* name) {
	Mark *cur_mark = mark_first;
	while (cur_mark){
		if (strcmp(cur_mark->name, name) == 0){
			return false;
		}
		cur_mark = cur_mark->next;
	}
	cur_mark = sym_alloc(Mark);
	cur_mark->name = name;
	cur_mark->next = null;

	if (mark_top){
		mark_top->next = cur_mark;
		mark_top = cur_mark;
	}
	else {
		mark_first = cur_mark;
		mark_top = cur_mark;
	}
	return true;
}

bool unsetMark(const char* name) {
	Mark *cur_mark = mark_first, *last_mark = null;
	while (cur_mark){
		if (strcmp(cur_mark->name, name) == 0){
			if (last_mark){
				last_mark->next = cur_mark->next;
			}
			else {
				mark_first = cur_mark->next;
			}
			if (mark_top==cur_mark){
				mark_top = last_mark;
			}
			return true;
		}
		last_mark = cur_mark;
		cur_mark = cur_mark->next;
	}
	return false;
}

void resetMarks() {
	mark_first = null;
	mark_top = null;
}


// General
Value *findSymbol(const char* name){
	Scope *scope = scope_cur;
	while (scope){
		SymLabel *label = findSymLabel(scope, name);
		if (label){
			return &label->value;
		}
		SymConst *constant = findSymConst(scope, name);
		if (constant){
			return &constant->value;
		}
		scope = scope->parent;
	}
	return null;
}

