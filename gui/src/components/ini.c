#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "ini.h"


/*
//
//	TEST CODE
//


IniObject *obj = iniObjectCreate();

iniObjectSetKeyAsNull(obj, "valor_lixo");
iniObjectRemoveKey(obj, "valor_lixo");
iniObjectSetKeyAsNull(obj, "valor_lixo");

iniObjectSetKeyAsNull(obj, "valor1");
iniObjectRemoveKey(obj, "valor_lixo");
iniObjectSetKeyAsNull(obj, "valor_lixo");
iniObjectRemoveKey(obj, "valor_lixo");
iniObjectSetKeyAsNull(obj, "valor2");
iniObjectSetKeyAsNull(obj, "valor_lixo");
iniObjectRemoveKey(obj, "valor_lixo");
iniObjectSetKeyAsNull(obj, "valor3");

iniObjectSetKeyAsNull(obj, "valor_lixo");
iniObjectSetKeyAsBool(obj, "valor2", INI_TRUE);
iniObjectSetKeyAsBool(obj, "valor4", INI_FALSE);
iniObjectSetKeyAsBool(obj, "valor5", INI_TRUE);
iniObjectRemoveKey(obj, "valor_lixo");

iniObjectSetKeyAsNumber(obj, "valor5", 150);
iniObjectSetKeyAsNumber(obj, "valor6", 1024.25);
iniObjectSetKeyAsNumber(obj, "valor7", 0);

iniObjectSetKeyAsText(obj, "valor7", "teste1");
iniObjectSetKeyAsText(obj, "valor8", "teste de texto com espaçamento");

printf("valor1=%s\n", iniObjectGetKeyAsText(obj, "valor1"));
printf("valor2=%s&%d\n", iniObjectGetKeyAsText(obj, "valor2"), iniObjectGetKeyAsBool(obj, "valor2"));
printf("valor3=%s\n", iniObjectGetKeyAsText(obj, "valor3"));
printf("valor4=%s&%d\n", iniObjectGetKeyAsText(obj, "valor4"), iniObjectGetKeyAsBool(obj, "valor4"));
printf("valor5=%s&%lf\n", iniObjectGetKeyAsText(obj, "valor5"), iniObjectGetKeyAsNumber(obj, "valor5"));
printf("valor6=%s&%lf\n", iniObjectGetKeyAsText(obj, "valor6"), iniObjectGetKeyAsNumber(obj, "valor6"));
printf("valor7=%s\n", iniObjectGetKeyAsText(obj, "valor7"));
printf("valor8=%s\n", iniObjectGetKeyAsText(obj, "valor8"));

iniObjectRemoveKey(obj, "valor1");
iniObjectRemoveKey(obj, "valor5");
iniObjectRemoveKey(obj, "valor8");

printf("\nvalor5=%s&%d&%lf\n", iniObjectGetKeyAsText(obj, "valor5"), iniObjectGetKeyAsBool(obj, "valor1"), iniObjectGetKeyAsNumber(obj, "valor1"));

iniObjectCreateSection(obj, "sessao_lixo");
iniObjectRemoveSection(obj, "sessao_lixo");

IniSection *sec1 = iniObjectCreateSection(obj, "sessao1");
iniObjectCreateSection(obj, "sessao_lixo");
iniObjectRemoveSection(obj, "sessao_lixo");
iniObjectCreateSection(obj, "sessao_lixo");
IniSection *sec2 = iniObjectCreateSection(obj, "sessao2");

iniSectionSetKeyAsNull(sec2, "valor_lixo");
iniSectionRemoveKey(sec2, "valor_lixo");
iniSectionSetKeyAsNull(sec2, "valor_lixo");

iniSectionSetKeyAsNull(sec2, "valor1");
iniSectionRemoveKey(sec2, "valor_lixo");
iniSectionSetKeyAsNull(sec2, "valor_lixo");
iniSectionRemoveKey(sec2, "valor_lixo");
iniSectionSetKeyAsNull(sec2, "valor2");
iniSectionSetKeyAsNull(sec2, "valor_lixo");
iniSectionRemoveKey(sec2, "valor_lixo");
iniSectionSetKeyAsNull(sec2, "valor3");

iniSectionSetKeyAsNull(sec2, "valor_lixo");
iniSectionSetKeyAsBool(sec2, "valor2", INI_TRUE);
iniSectionSetKeyAsBool(sec2, "valor4", INI_FALSE);
iniSectionSetKeyAsBool(sec2, "valor5", INI_TRUE);
iniSectionRemoveKey(sec2, "valor_lixo");

iniSectionSetKeyAsNumber(sec2, "valor5", 150);
iniSectionSetKeyAsNumber(sec2, "valor6", 1024.25);
iniSectionSetKeyAsNumber(sec2, "valor7", 0);

iniSectionSetKeyAsText(sec2, "valor7", "teste1");
iniSectionSetKeyAsText(sec2, "valor8", "teste de texto com espaçamento");

printf("valor1=%s\n", iniSectionGetKeyAsText(sec2, "valor1"));
printf("valor2=%s&%d\n", iniSectionGetKeyAsText(sec2, "valor2"), iniSectionGetKeyAsBool(sec2, "valor2"));
printf("valor3=%s\n", iniSectionGetKeyAsText(sec2, "valor3"));
printf("valor4=%s&%d\n", iniSectionGetKeyAsText(sec2, "valor4"), iniSectionGetKeyAsBool(sec2, "valor4"));
printf("valor5=%s&%lf\n", iniSectionGetKeyAsText(sec2, "valor5"), iniSectionGetKeyAsNumber(sec2, "valor5"));
printf("valor6=%s&%lf\n", iniSectionGetKeyAsText(sec2, "valor6"), iniSectionGetKeyAsNumber(sec2, "valor6"));
printf("valor7=%s\n", iniSectionGetKeyAsText(sec2, "valor7"));
printf("valor8=%s\n", iniSectionGetKeyAsText(sec2, "valor8"));

iniSectionRemoveKey(sec2, "valor1");
iniSectionRemoveKey(sec2, "valor5");
iniSectionRemoveKey(sec2, "valor8");

printf("\nvalor5=%s&%d&%lf\n", iniSectionGetKeyAsText(sec2, "valor5"), iniSectionGetKeyAsBool(sec2, "valor1"), iniSectionGetKeyAsNumber(sec2, "valor1"));

IniSection *sec3 = iniObjectCreateSection(obj, "sessao3");
iniObjectRemoveSection(obj, "sessao_lixo");

iniObjectSave("teste.ini", obj);
iniObjectDestroy(obj);

IniObject *obj2 = iniObjectLoad("teste.ini");
iniObjectSave("teste2.ini", obj2);
iniObjectDestroy(obj2);


*/


/*
	Types Definition
*/

typedef struct IniPairKey IniPairKey;
struct IniPairKey {
	char key[INI_MAX_NAME_SIZE+1];
	char value[INI_MAX_VALUE_SIZE+1];
	IniPairKey *next;
};

typedef struct IniStorager {
	IniPairKey *first, *last;
}IniStorager;

typedef struct IniContainer {
	IniSection *first, *last;
}IniContainer;

struct IniObject {
	IniStorager storager;
	IniContainer container;
};
struct IniSection {
	char name[INI_MAX_NAME_SIZE+1];
	IniStorager storager;
	IniSection *next;
};


/*
	INI Utilities
*/

#define iniCreateKey(storager) \
	/* Search for a match pair key */\
	IniPairKey *pair_key = storager.first;\
	while (pair_key){\
		if (strcmp(pair_key->key, key)==0){\
			break;\
		}\
		pair_key = pair_key->next;\
	}\
	\
	/* Create a new one if do not exists*/\
	if (!pair_key){\
		pair_key = (IniPairKey*)malloc(sizeof(IniPairKey));\
		memset(pair_key, INI_NULL, sizeof(IniPairKey));\
		memcpy_s(pair_key->key, INI_MAX_NAME_SIZE, key, strlen(key));\
		pair_key->key[INI_MAX_NAME_SIZE] = 0;\
		\
		if (!storager.first){\
			storager.first = storager.last = pair_key;\
		}\
		else {\
			storager.last->next = pair_key;\
			storager.last = pair_key;\
		}\
	}\


/*
	INI Object Handling
*/

extern IniObject *iniObjectCreate() {
	IniObject *obj = (IniObject*)malloc(sizeof(IniObject));
	memset(obj, INI_NULL, sizeof(IniObject));
	return obj;
}

extern IniObject *iniObjectLoad(const char* path) {
	FILE *file = INI_NULL;
	if (fopen_s(&file, path, "r")) {
		return INI_NULL;
	}

	IniObject *obj = iniObjectCreate();
	IniSection *sec = INI_NULL;

	while (!feof(file)){
		int chr = 0;
		while (!feof(file) && (chr==0 || chr==' ' || chr=='\t' || chr=='\n' || chr=='\r')){
			chr = fgetc(file);
		}
		if (feof(file)){
			break;
		}

		// Section initializer
		if (chr=='['){
			char name[INI_MAX_NAME_SIZE+1];
			int i = 0;
			chr = fgetc(file);
			while (!feof(file) && !(chr=='\n' || chr=='\r' || chr==']')){
				if (i<INI_MAX_NAME_SIZE && chr!=' ' && chr!='\t'){
					name[i] = chr;
					i++;
				}
				chr = fgetc(file);
			}
			name[i] = 0;
			sec = iniObjectCreateSection(obj, name);
		}
		// Comment initializer
		else if (chr==';'){}
		// Pair key name initializer
		else {
			char key[INI_MAX_NAME_SIZE+1];
			int ki = 0;
			while (!feof(file) && !(chr=='\n' || chr=='\r' || chr=='=')){
				if (ki<INI_MAX_NAME_SIZE && chr!=' ' && chr!='\t'){
					key[ki] = chr;
					ki++;
				}
				chr = fgetc(file);
			}
			key[ki] = 0;

			if (chr=='='){
				char value[INI_MAX_VALUE_SIZE+1];
				int vi = 0;
				chr = fgetc(file);
				while (!feof(file) && (chr==0 || chr==' ' || chr=='\t')){
					chr = fgetc(file);
				}
				while (!feof(file) && !(chr=='\n' || chr=='\r')){
					if (vi<INI_MAX_VALUE_SIZE){
						value[vi] = chr;
						vi++;
					}
					chr = fgetc(file);
				}
				value[vi] = 0;

				if (sec){
					iniSectionSetKeyAsText(sec, key, value);
				}
				else {
					iniObjectSetKeyAsText(obj, key, value);
				}
			}
		}
		// Trimming end of left line
		while (!feof(file) && !(chr=='\n' || chr=='\r')){
			chr = fgetc(file);
		}
	}

	fclose(file);
	return obj;
}

extern IniObject *iniObjectFromString(const char* src) {
	// TODO
	return INI_NULL;
}

extern _Bool iniObjectSave(const char* path, IniObject *obj) {
	FILE *file = INI_NULL;
	if (fopen_s(&file, path, "w")) {
		return INI_FALSE;
	}

	// First, copy the base values
	IniPairKey *pair_key = obj->storager.first;
	while (pair_key){
		fprintf_s(file, "%s = %s", pair_key->key, pair_key->value);
		fprintf_s(file, "\n");
		pair_key = pair_key->next;
	}

	// Now the sections with their values
	IniSection *section = obj->container.first;
	while (section){
		fprintf_s(file, "\n[%s]\n", section->name);
		
		IniPairKey *pair_key = section->storager.first;
		while (pair_key){
			fprintf_s(file, "  %s = %s", pair_key->key, pair_key->value);
			fprintf_s(file, "\n");
			pair_key = pair_key->next;
		}
		
		section = section->next;
	}
	
	fclose(file);
	return INI_TRUE;
}

extern _Bool iniObjectToString(char* buffer, int limit, IniObject *obj) {
	// TODO
	buffer[0] = 0;
	return INI_FALSE;
}

extern _Bool iniObjectDestroy(IniObject *obj) {
	// Remove the object properties
	IniPairKey *pair_key = obj->storager.first;
	while (pair_key){
		IniPairKey *next = pair_key->next;
		free(pair_key);
		pair_key = next;
	}

	// Remove each object sections
	IniSection *section = obj->container.first;
	while (section){
		IniSection *next_section = section->next;

		IniPairKey *pair_key = section->storager.first;
		while (pair_key){
			IniPairKey *next = pair_key->next;
			free(pair_key);
			pair_key = next;
		}

		free(section);
		section = next_section;
	}

	// Remove the object
	free(obj);
	return INI_TRUE;
}


/*
	INI Object Manipulation
*/

extern _Bool iniObjectHasKey(IniObject *obj, const char* key) {
	IniPairKey *pair_key = obj->storager.first;
	while (pair_key){
		if (strcmp(pair_key->key, key)==0){
			return INI_TRUE;
		}
		pair_key = pair_key->next;
	}
	return INI_FALSE;
}

extern _Bool iniObjectGetKeyAsBool(IniObject *obj, const char* key) {
	IniPairKey *pair_key = obj->storager.first;
	while (pair_key){
		if (strcmp(pair_key->key, key)==0){
			return strcmp(pair_key->value, "false") && strcmp(pair_key->value, "null") && strcmp(pair_key->value, "0") && strcmp(pair_key->value, "")? INI_TRUE: INI_FALSE;
		}
		pair_key = pair_key->next;
	}
	return INI_FALSE;
}

extern double iniObjectGetKeyAsNumber(IniObject *obj, const char* key) {
	IniPairKey *pair_key = obj->storager.first;
	while (pair_key){
		if (strcmp(pair_key->key, key)==0){
			double number = 0;
			sscanf_s(pair_key->value, "%Lf", &number);
			return number;
		}
		pair_key = pair_key->next;
	}
	return 0;
}

extern long iniObjectGetKeyAsHex(IniObject *obj, const char* key) {
	IniPairKey *pair_key = obj->storager.first;
	while (pair_key){
		if (strcmp(pair_key->key, key)==0){
			long number = 0;
			sscanf_s(pair_key->value, "0x%x", &number);
			return number;
		}
		pair_key = pair_key->next;
	}
	return 0;
}

extern const char* iniObjectGetKeyAsText(IniObject *obj, const char* key) {
	IniPairKey *pair_key = obj->storager.first;
	while (pair_key){
		if (strcmp(pair_key->key, key)==0){
			return pair_key->value;
		}
		pair_key = pair_key->next;
	}
	return INI_NULL;
}

extern void iniObjectSetKeyAsNull(IniObject *obj, const char* key) {
	iniCreateKey(obj->storager);
	sprintf_s(pair_key->value, INI_MAX_VALUE_SIZE, "null\0");
}

extern void iniObjectSetKeyAsBool(IniObject *obj, const char* key, _Bool value) {
	iniCreateKey(obj->storager);
	sprintf_s(pair_key->value, INI_MAX_VALUE_SIZE, value? "true": "false");
}

extern void iniObjectSetKeyAsNumber(IniObject *obj, const char* key, double number) {
	iniCreateKey(obj->storager);
	sprintf_s(pair_key->value, INI_MAX_VALUE_SIZE, "%Lf", number);
}

extern void iniObjectSetKeyAsInteger(IniObject *obj, const char* key, long number) {
	iniCreateKey(obj->storager);
	sprintf_s(pair_key->value, INI_MAX_VALUE_SIZE, "%li", number);
}

extern void iniObjectSetKeyAsHex(IniObject *obj, const char* key, long number) {
	iniCreateKey(obj->storager);
	sprintf_s(pair_key->value, INI_MAX_VALUE_SIZE, "0x%X", number);
}

extern void iniObjectSetKeyAsText(IniObject *obj, const char* key, const char* text) {
	iniCreateKey(obj->storager);
	sprintf_s(pair_key->value, INI_MAX_VALUE_SIZE, "%s\0", text);
}

extern _Bool iniObjectRemoveKey(IniObject *obj, const char* key) {
	IniPairKey *pair_key = obj->storager.first, *last_pair_key = INI_NULL;
	while (pair_key){
		if (strcmp(pair_key->key, key)==0){
			break;
		}
		last_pair_key = pair_key;
		pair_key = pair_key->next;
	}

	if (last_pair_key){
		last_pair_key->next = pair_key->next;
	}
	else {
		obj->storager.first = pair_key->next;
	}

	if (!pair_key->next){
		obj->storager.last = last_pair_key;
	}

	free(pair_key);
	return INI_NULL;
}

extern IniSection *iniObjectCreateSection(IniObject *obj, const char* name) {
	IniSection *section = obj->container.first;
	while (section){
		if (strcmp(section->name, name) == 0){
			return section;
		}
		section = section->next;
	}

	section = (IniSection*)malloc(sizeof(IniSection));
	memset(section, INI_NULL, sizeof(IniSection));

	memcpy_s(section->name, INI_MAX_NAME_SIZE, name, strlen(name));
	section->name[INI_MAX_NAME_SIZE] = 0;

	if (!obj->container.first){
		obj->container.first = obj->container.last = section;
	}
	else {
		obj->container.last->next = section;
		obj->container.last = section;
	}

	return section;
}

extern IniSection *iniObjectGetSection(IniObject *obj, const char* name) {
	IniSection *section = obj->container.first;
	while (section){
		if (strcmp(section->name, name) == 0){
			return section;
		}
		section = section->next;
	}
	return INI_NULL;
}

extern _Bool iniObjectRemoveSection(IniObject *obj, const char* name) {
	IniSection *section = obj->container.first, *last_section = INI_NULL;
	while (section){
		if (strcmp(section->name, name) == 0){
			break;
		}
		last_section = section;
		section = section->next;
	}

	if (last_section){
		last_section->next = section->next;
	}
	else {
		obj->container.first = section->next;
	}

	if (!section->next){
		obj->container.last = last_section;
	}

	// Removing all keys from section
	IniPairKey *pair_key = section->storager.first;
	while (pair_key){
		IniPairKey *next = pair_key->next;
		free(pair_key);
		pair_key = next;
	}

	// Removing the section itself
	free(section);

	return INI_NULL;
}


/*
	INI Section Manipulation
*/

extern _Bool iniSectionHasKey(IniSection *section, const char* key) {
	IniPairKey *pair_key = section->storager.first;
	while (pair_key){
		if (strcmp(pair_key->key, key)==0){
			return INI_TRUE;
		}
		pair_key = pair_key->next;
	}
	return INI_FALSE;
};

extern _Bool iniSectionGetKeyAsBool(IniSection *section, const char* key) {
	IniPairKey *pair_key = section->storager.first;
	while (pair_key){
		if (strcmp(pair_key->key, key)==0){
			return strcmp(pair_key->value, "false") && strcmp(pair_key->value, "null") && strcmp(pair_key->value, "0") && strcmp(pair_key->value, "")? INI_TRUE: INI_FALSE;
		}
		pair_key = pair_key->next;
	}
	return INI_FALSE;
};

extern double iniSectionGetKeyAsNumber(IniSection *section, const char* key) {
	IniPairKey *pair_key = section->storager.first;
	while (pair_key){
		if (strcmp(pair_key->key, key)==0){
			double number = 0;
			sscanf_s(pair_key->value, "%Lf", &number);
			return number;
		}
		pair_key = pair_key->next;
	}
	return 0;
};

extern long iniSectionGetKeyAsHex(IniSection *section, const char* key) {
	IniPairKey *pair_key = section->storager.first;
	while (pair_key){
		if (strcmp(pair_key->key, key)==0){
			long number = 0;
			sscanf_s(pair_key->value, "0x%x", &number);
			return number;
		}
		pair_key = pair_key->next;
	}
	return 0;
};

extern const char* iniSectionGetKeyAsText(IniSection *section, const char* key) {
	IniPairKey *pair_key = section->storager.first;
	while (pair_key){
		if (strcmp(pair_key->key, key)==0){
			return pair_key->value;
		}
		pair_key = pair_key->next;
	}
	return INI_NULL;
};

extern void iniSectionSetKeyAsNull(IniSection *section, const char* key) {
	iniCreateKey(section->storager);
	sprintf_s(pair_key->value, INI_MAX_VALUE_SIZE, "null\0");
};

extern void iniSectionSetKeyAsBool(IniSection *section, const char* key, _Bool value) {
	iniCreateKey(section->storager);
	sprintf_s(pair_key->value, INI_MAX_VALUE_SIZE, value? "true": "false");
};

extern void iniSectionSetKeyAsNumber(IniSection *section, const char* key, double number) {
	iniCreateKey(section->storager);
	sprintf_s(pair_key->value, INI_MAX_VALUE_SIZE, "%Lf", number);
};

extern void iniSectionSetKeyAsInteger(IniSection *section, const char* key, long number) {
	iniCreateKey(section->storager);
	sprintf_s(pair_key->value, INI_MAX_VALUE_SIZE, "%li", number);
};

extern void iniSectionSetKeyAsHex(IniSection *section, const char* key, long number) {
	iniCreateKey(section->storager);
	sprintf_s(pair_key->value, INI_MAX_VALUE_SIZE, "0x%X", number);
};

extern void iniSectionSetKeyAsText(IniSection *section, const char* key, const char* text) {
	iniCreateKey(section->storager);
	sprintf_s(pair_key->value, INI_MAX_VALUE_SIZE, "%s\0", text);
};

extern _Bool iniSectionRemoveKey(IniSection *section, const char* key) {
	IniPairKey *pair_key = section->storager.first, *last_pair_key = INI_NULL;
	while (pair_key){
		if (strcmp(pair_key->key, key)==0){
			break;
		}
		last_pair_key = pair_key;
		pair_key = pair_key->next;
	}

	if (last_pair_key){
		last_pair_key->next = pair_key->next;
	}
	else {
		section->storager.first = pair_key->next;
	}

	if (!pair_key->next){
		section->storager.last = last_pair_key;
	}

	free(pair_key);
	return INI_NULL;
};


