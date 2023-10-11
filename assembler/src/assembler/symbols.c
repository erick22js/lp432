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


// General
Value *findSymbol(const char* name){
	Scope *scope = scope_cur;
	while (scope){
		SymLabel *label = findSymLabel(scope_cur, name);
		if (label){
			return &label->value;
		}
		scope = scope->parent;
	}
	return null;
}

