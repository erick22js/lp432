#ifndef GUI_INI_H
#define GUI_INI_H


/*
	Setting Definition
*/

#define INI_MAX_NAME_SIZE 31
#define INI_MAX_VALUE_SIZE 255


/*
	Types Definition
*/

#define INI_TRUE 1
#define INI_FALSE 0
#define INI_NULL 0

typedef struct IniObject IniObject;
typedef struct IniSection IniSection;


/*
	INI Object Handling
*/

extern IniObject *iniObjectCreate();
extern IniObject *iniObjectLoad(const char* path);
extern IniObject *iniObjectFromString(const char* src);
extern _Bool iniObjectSave(const char* path, IniObject *obj);
extern _Bool iniObjectToString(char* buffer, int limit, IniObject *obj);
extern _Bool iniObjectDestroy(IniObject *obj);


/*
	INI Object Manipulation
*/

extern _Bool iniObjectHasKey(IniObject *obj, const char* key);
extern _Bool iniObjectGetKeyAsBool(IniObject *obj, const char* key);
extern double iniObjectGetKeyAsNumber(IniObject *obj, const char* key);
extern long iniObjectGetKeyAsHex(IniObject *obj, const char* key);
extern const char* iniObjectGetKeyAsText(IniObject *obj, const char* key);
extern void iniObjectSetKeyAsNull(IniObject *obj, const char* key);
extern void iniObjectSetKeyAsBool(IniObject *obj, const char* key, _Bool value);
extern void iniObjectSetKeyAsNumber(IniObject *obj, const char* key, double number);
extern void iniObjectSetKeyAsInteger(IniObject *obj, const char* key, long number);
extern void iniObjectSetKeyAsHex(IniObject *obj, const char* key, long number);
extern void iniObjectSetKeyAsText(IniObject *obj, const char* key, const char* text);
extern _Bool iniObjectRemoveKey(IniObject *obj, const char* key);
extern IniSection *iniObjectCreateSection(IniObject *obj, const char* name);
extern IniSection *iniObjectGetSection(IniObject *obj, const char* name);
extern _Bool iniObjectRemoveSection(IniObject *obj, const char* name);


/*
	INI Section Manipulation
*/

extern _Bool iniSectionHasKey(IniSection *section, const char* key);
extern _Bool iniSectionGetKeyAsBool(IniSection *section, const char* key);
extern double iniSectionGetKeyAsNumber(IniSection *section, const char* key);
extern long iniSectionGetKeyAsHex(IniSection *section, const char* key);
extern const char* iniSectionGetKeyAsText(IniSection *section, const char* key);
extern void iniSectionSetKeyAsNull(IniSection *section, const char* key);
extern void iniSectionSetKeyAsBool(IniSection *section, const char* key, _Bool value);
extern void iniSectionSetKeyAsNumber(IniSection *section, const char* key, double number);
extern void iniSectionSetKeyAsInteger(IniSection *section, const char* key, long number);
extern void iniSectionSetKeyAsHex(IniSection *section, const char* key, long number);
extern void iniSectionSetKeyAsText(IniSection *section, const char* key, const char* text);
extern _Bool iniSectionRemoveKey(IniSection *section, const char* key);


#endif