#include "symbols.h"
#include "text.h"

#define SYM_MAX_LABELS 8192


// Label
SymLabel sym_labels[SYM_MAX_LABELS];
int sym_labels_top = 0;

SymLabel *findSymLabel(const char* name){
	for (int i = 0; i<sym_labels_top; i++){
		if (strcmp(sym_labels[i].name, name) == 0){
			return &sym_labels[i];
		}
	}
	return null;
}
void storeSymLabel(const char* name, Value value){
	if (sym_labels_top < SYM_MAX_LABELS){
		sym_labels[sym_labels_top].name = textReuse(name);
		sym_labels[sym_labels_top].value = value;
		sym_labels_top++;
	}
	else {
		log("ERROR: LIMIT OF %d LABELS REACHED!", SYM_MAX_LABELS);
	}
}

// General
Value *findSymbol(const char* name){
	SymLabel *label = findSymLabel(name);
	if (label){
		return &label->value;
	}
	return null;
}

