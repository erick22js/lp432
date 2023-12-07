#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

#include "inspector.h"
#include "gui.h"
#include "../common.h"


//
// GUI Properties
//
struct {
	char* name;
	char buffer[12];
	Element entry;
}gregs[16] = {
	{"EAX"},
	{"EDX"},
	{"ECX"},
	{"EBX"},
	{"EEX"},
	{"EHX"},
	{"EGX"},
	{"EFX"},
	{"EX0"},
	{"EX3"},
	{"EX2"},
	{"EX1"},
	{"EDS"},
	{"ESD"},
	{"ESP"},
	{"EFP"},
};
struct {
	char* name;
	char buffer[12];
	Element entry;
}fregs[16] = {
	{"F0"},
	{"F1"},
	{"F2"},
	{"F3"},
	{"F4"},
	{"F5"},
	{"F6"},
	{"F7"},
	{"F8"},
	{"F9"},
	{"F10"},
	{"F11"},
	{"F12"},
	{"F13"},
	{"F14"},
	{"F15"},
};
struct {
	char* name;
	char buffer[12];
	Element entry;
}oregs[16] = {
	{"I0"},
	{"I1"},
	{"I2"},
	{"I3"},
	{"I4"},
	{"I5"},
	{"I6"},
	{"I7"},
	{"S0"},
	{"S1"},
	{"S2"},
	{"S3"},
	{"S4"},
	{"S5"},
	{"S6"},
	{"S7"},
};
struct {
	char* name;
	Uint32* reg;
	char buffer[12];
	Element entry;
}cregs[6] = {
	{"PC", &g_cpu.reg_pc},
	{"ST", &g_cpu.reg_st},
	{"STD", &g_cpu.reg_std},
	{"PTD", &g_cpu.reg_ptd},
	{"ITD", &g_cpu.reg_itd},
	{"ISP", &g_cpu.reg_isp},
};
struct {
	char* name;
	Uint32 flag;
	Element entry;
}flags[] = {
	{"CF", FLAG_CF},
	{"BF", FLAG_BF},
	{"VF", FLAG_VF},
	{"NF", FLAG_NF},
	{"ZF", FLAG_ZF},
	{"OF", FLAG_OF},
	{"PM", FLAG_PM},
	{"SE", FLAG_SE},
	{"PE", FLAG_PE},
	{"IE", FLAG_IE},
	{"TI", FLAG_TI},
};

struct {
	char buffer[10];
	Element label;
}mem_adrs[16] = {0};
struct {
	char buffer[4];
	Element entry;
}mem[256];
Uint32 _sp_mem_badr = 0, _sp_mem_size = 8;
bool _sp_mem_mapped = false;
Element chk_mem_tr;
Element over_panel, over_text, over_value, caret;

char timer_buffer[127];
Element timer_label;


_Bool _sp_input_active = 0;
int _sp_input_seek = 0;
_Bool _sp_input_istext = 0;
char _sp_input_buffer[256] = {0};
void (*_sp_input_callback)(char* value, void* arg) = NULL;
void* _sp_input_arg = NULL;


//
//	Util Functions
//

uint32 spUtilTAddress(uint32 logical_adr){
	if (_sp_mem_mapped){
		return logical_adr;
	}
	else {
		return logical_adr;
	}
}


//
//	Manage Functions
//

void spUpdate(){
	for (int i = 0; i<16; i++){
		sprintf_s(gregs[i].buffer, sizeof(gregs[i].buffer), "0x%.8X\0", g_cpu.gregs[i]);
	}
	for (int i = 0; i<16; i++){
		sprintf_s(fregs[i].buffer, sizeof(fregs[i].buffer), "%.4Le\0", g_cpu.fregs[i]);
	}
	for (int i = 0; i<16; i++){
		sprintf_s(oregs[i].buffer, sizeof(oregs[i].buffer), (i<8? "0x%.8X\0": "0x%.2X\0"), (i<8? g_cpu.iregs[i]: g_cpu.sregs[i-8].base));
	}
	for (int i = 0; i<6; i++){
		sprintf_s(cregs[i].buffer, sizeof(cregs[i].buffer), "0x%.8X\0", *cregs[i].reg);
	}

	// Program flags
	for (int i = 0; i<11; i++){
		guiSetElementBackColor(flags[i].entry, g_cpu.reg_st&flags[i].flag? COLOR_GREEN: COLOR_BLACK);
		guiSetElementHoverColor(flags[i].entry, g_cpu.reg_st&flags[i].flag? COLOR_LIME: COLOR_GRAY);
	}

	// Timer status
	sprintf_s(timer_buffer, sizeof(timer_buffer), "PIT: %.10d  CTV: %.10d.%.2d", g_cpu.reg_pit, g_cpu.reg_ctv, g_cpu.reg_utv);

	// Mapped checkbox
	guiSetElementBackColor(chk_mem_tr, _sp_mem_mapped? COLOR_GREEN: COLOR_BLACK);
	guiSetElementHoverColor(chk_mem_tr, _sp_mem_mapped? COLOR_LIME: COLOR_GRAY);

	// Memory inspector
	for (int r = 0; r<16; r++){
		sprintf_s(mem_adrs[r].buffer, sizeof(mem_adrs[r].buffer), "%.8X\0", _sp_mem_badr + r*16);
	}
	for (int r = 0; r<16; r++){
		for (int c = 0; c<16; c++){
			Uint8 data = busRead(spUtilTAddress(_sp_mem_badr + r*16 + c));
			sprintf_s(mem[r*16 + c].buffer, sizeof(mem[r*16 + c].buffer), "%.2X\0", data);

			if (spUtilTAddress(g_cpu.reg_pc)==spUtilTAddress(_sp_mem_badr + r*16 + c)){
				guiSetElementBackColor(mem[r*16 + c].entry, COLOR_GREEN);
			}
			else {
				guiSetElementBackColor(mem[r*16 + c].entry, COLOR_YELLOW);
			}
		}
	}
}

void spInputNumeric(void *default_value, int type, const char* format, const char* message, void (*callback)(char* value, void* arg), void* arg){
	guiSetElementText(over_text, (char*)message);
	guiSetElementVisible(over_panel, 1);
	guiSetElementActive(over_panel, 1);
	guiSetElementVisible(over_text, 1);
	guiSetElementActive(over_text, 1);
	guiSetElementVisible(over_value, 1);
	guiSetElementActive(over_value, 1);
	guiSetElementVisible(caret, 1);
	_sp_input_active = 1;
	_sp_input_istext = 0;
	if (default_value){
		if (type==0){
			sprintf_s(_sp_input_buffer, sizeof(_sp_input_buffer), format, (*((uint32*)default_value)));
		}
		if (type==1){
			sprintf_s(_sp_input_buffer, sizeof(_sp_input_buffer), format, (*((sint64*)default_value)));
		}
		if (type==2){
			sprintf_s(_sp_input_buffer, sizeof(_sp_input_buffer), format, (*((float32*)default_value)));
		}
		if (type==3){
			sprintf_s(_sp_input_buffer, sizeof(_sp_input_buffer), format, (*((float64*)default_value)));
		}
	}
	else {
		sprintf_s(_sp_input_buffer, sizeof(_sp_input_buffer), "0");
	}
	_sp_input_seek = strlen(_sp_input_buffer);
	memset(_sp_input_buffer+_sp_input_seek, 0, sizeof(_sp_input_buffer)-_sp_input_seek);
	_sp_input_callback = callback;
	_sp_input_arg = arg;
}

void spInputText(const char* default_value, const char* message, void (*callback)(char* value, void* arg), void* arg){
	guiSetElementText(over_text, (char*)message);
	guiSetElementVisible(over_panel, 1);
	guiSetElementActive(over_panel, 1);
	guiSetElementVisible(over_text, 1);
	guiSetElementActive(over_text, 1);
	guiSetElementVisible(over_value, 1);
	guiSetElementActive(over_value, 1);
	guiSetElementVisible(caret, 1);
	_sp_input_active = 1;
	_sp_input_istext = 1;
	if (default_value){
		sprintf_s(_sp_input_buffer, sizeof(_sp_input_buffer), "%s", default_value);
	}
	else {
		sprintf_s(_sp_input_buffer, sizeof(_sp_input_buffer), "");
	}
	_sp_input_seek = strlen(_sp_input_buffer);
	memset(_sp_input_buffer+_sp_input_seek, 0, sizeof(_sp_input_buffer)-_sp_input_seek);
	_sp_input_callback = callback;
	_sp_input_arg = arg;
}

void spCloseInput(){
	_sp_input_active = 0;
	guiSetElementVisible(over_panel, 0);
	guiSetElementActive(over_panel, 0);
	guiSetElementVisible(over_text, 0);
	guiSetElementActive(over_text, 0);
	guiSetElementVisible(over_value, 0);
	guiSetElementActive(over_value, 0);
	guiSetElementVisible(caret, 0);
}

void spInputGetI32(uint32* out){
	if (_sp_input_buffer[0]==0){
		*out = 0;
		return;
	}
	if (_sp_input_buffer[0]=='0'){
		if (_sp_input_buffer[1]=='x' || _sp_input_buffer[2]=='x'){
			sscanf_s(_sp_input_buffer+2, "%x", out);
			return;
		}
	}
	sscanf_s(_sp_input_buffer, "%d", out);
}

void spInputGetF64(float64* out){
	if (_sp_input_buffer[0]==0){
		*out = 0;
		return;
	}
	sscanf_s(_sp_input_buffer, "%lf", out);
}


//
//	Callback Input Functions
//

void spIGreg(char* value, void* arg){
	spInputGetI32(arg);
	spUpdate();
}

void spIFreg(char* value, void* arg){
	spInputGetF64(arg);
	spUpdate();
}

void spIOreg(char* value, void* arg){
	int idx = (int)arg;
	if (idx<8){
		spInputGetI32(&g_cpu.iregs[idx]);
	}
	else {
		spInputGetI32(&g_cpu.sregs[idx].base);
	}
	spUpdate();
}

void spICreg(char* value, void* arg){
	spInputGetI32(arg);
	spUpdate();
}

void spIPit(char* value, void* arg){
	spInputGetI32(&g_cpu.reg_pit);
	g_cpu.reg_ctv = g_cpu.reg_utv = 0;
	spUpdate();
}

void spIMadr(char* value, void* arg){
	//_sp_mem_badr
	spInputGetI32(&_sp_mem_badr);
	spUpdate();
}

void spIVmem(char* value, void* arg){
	//_sp_mem_badr
	Uint32 data = 0;
	spInputGetI32(&data);
	if (_sp_mem_size==8){
		busWrite(spUtilTAddress(_sp_mem_badr + (int)arg), (uint8)data);
	}
	else if (_sp_mem_size==16){
		busWrite(spUtilTAddress(_sp_mem_badr + (int)arg), (uint8)data);
		busWrite(spUtilTAddress(_sp_mem_badr + (int)arg + 1), (uint8)(data>>8));
	}
	else {
		busWrite(spUtilTAddress(_sp_mem_badr + (int)arg), (uint8)data);
		busWrite(spUtilTAddress(_sp_mem_badr + (int)arg + 1), (uint8)(data>>8));
		busWrite(spUtilTAddress(_sp_mem_badr + (int)arg + 2), (uint8)(data>>16));
		busWrite(spUtilTAddress(_sp_mem_badr + (int)arg + 3), (uint8)(data>>24));
	}
	spUpdate();
}

char sp_rom_path[256];
Uint32 sp_rom_offset = 0;
Uint32 sp_rom_size = 0;

void spIMenuLoadOffset(char* value, void* arg){
	spInputGetI32(&sp_rom_offset);
	iniObjectSetKeyAsHex(config, "default_rom_offset", sp_rom_offset);
	cfgFlush();

	FILE *file;
	errno_t err;
	if ((err = fopen_s(&file, sp_rom_path, "rb"))){
		printf("Error on loading file at path \"%s\", cause => %i\n", sp_rom_path, err);
		return;
	}
	if (!file){
		printf("File in path \"%s\" does not exists!\n", sp_rom_path);
		return;
	}

	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	fseek(file, 0, SEEK_SET);

	while (size){
		busWrite(sp_rom_offset, fgetc(file)&0xFF);
		sp_rom_offset++;
		size--;
	}
	fclose(file);

	spUpdate();
}

void spIMenuLoad(char* value, void* arg){
	Uint32 data = iniObjectGetKeyAsHex(config, "default_rom_offset");
	sprintf_s(sp_rom_path, sizeof(sp_rom_path), "%s", value);
	iniObjectSetKeyAsText(config, "default_rom_path", value);
	spInputNumeric(&data, 0, "0x%X\0", "Insert offset for ROM loading in memory:", spIMenuLoadOffset, NULL);
}

void spIMenuSaveSize(char* value, void* arg){
	spInputGetI32(&sp_rom_size);
	iniObjectSetKeyAsInteger(config, "default_rom_size", sp_rom_size);
	cfgFlush();

	remove(sp_rom_path);
	FILE *file;
	errno_t err;
	if ((err = fopen_s(&file, sp_rom_path, "wb"))){
		printf("Error on loading file at path \"%s\", cause => %i\n", sp_rom_path, err);
		return;
	}

	while (sp_rom_size){
		fputc(busRead(sp_rom_offset), file);
		sp_rom_offset++;
		sp_rom_size--;
	}
	fclose(file);

	spUpdate();
}

void spIMenuSaveOffset(char* value, void* arg){
	Uint32 data = (uint32)iniObjectGetKeyAsNumber(config, "default_rom_size");
	spInputGetI32(&sp_rom_offset);
	iniObjectSetKeyAsHex(config, "default_rom_offset", sp_rom_offset);
	spInputNumeric(&data, 0, "0x%X\0", "Insert length for ROM saving:", spIMenuSaveSize, NULL);
}

void spIMenuSave(char* value, void* arg){
	Uint32 data = iniObjectGetKeyAsHex(config, "default_rom_offset");
	sprintf_s(sp_rom_path, sizeof(sp_rom_path), "%s", value);
	iniObjectSetKeyAsText(config, "default_rom_path", value);
	spInputNumeric(&data, 0, "0x%X\0", "Insert offset in memory to ROM saving:", spIMenuSaveOffset, NULL);
}


//
//	Process Functions
//

void spHStep(Element el, int btn, Uint32 x, Uint32 y){
	vmStep();
	spUpdate();
}

void spHReset(Element el, int btn, Uint32 x, Uint32 y){
	vmReset();
	spUpdate();
}

void spHEditGreg(Element el, int btn, Uint32 x, Uint32 y){
	int i = el-gregs[0].entry;
	static char msg[128];
	sprintf_s(msg, sizeof(msg), "Insert value for register %s:", gregs[i].name);
	spInputNumeric(&g_cpu.gregs[i], 0, "0x%X\0", msg, spIGreg, &g_cpu.gregs[i]);
}

void spHEditFreg(Element el, int btn, Uint32 x, Uint32 y){
	int i = el-fregs[0].entry;
	double one = 1.0;
	static char msg[128];
	sprintf_s(msg, sizeof(msg), "Insert value for register %s:", fregs[i].name);
	spInputNumeric(&g_cpu.fregs[i], 3, modf(g_cpu.fregs[i], &one)? "%lg\0": "%lg.0\0", msg, spIFreg, &g_cpu.fregs[i]);
}

void spHEditOreg(Element el, int btn, Uint32 x, Uint32 y){
	int i = el-oregs[0].entry;
	static char msg[128];
	sprintf_s(msg, sizeof(msg), "Insert value for register %s:", oregs[i].name);
	spInputNumeric(i<8? &g_cpu.iregs[i]: &g_cpu.sregs[i-8].base, i<8? 0: 0, "0x%X\0", msg, spIOreg, (void*)i);
}

void spHEditCreg(Element el, int btn, Uint32 x, Uint32 y){
	int i = el-cregs[0].entry;
	static char msg[128];
	sprintf_s(msg, sizeof(msg), "Insert value for register %s:", cregs[i].name);
	spInputNumeric(cregs[i].reg, 0, "0x%X\0", msg, spICreg, cregs[i].reg);
}

void spHToggleFlag(Element el, int btn, Uint32 x, Uint32 y){
	int i = el-flags[0].entry;
	if (g_cpu.reg_st&flags[i].flag){
		g_cpu.reg_st &= ~flags[i].flag;
	}
	else {
		g_cpu.reg_st |= flags[i].flag;
	}
	spUpdate();
}

void spHToggleMemTr(Element el, int btn, Uint32 x, Uint32 y){
	_sp_mem_mapped = !_sp_mem_mapped;
	spUpdate();
}

void spHEditPit(Element el, int btn, Uint32 x, Uint32 y){
	uint32 data = g_cpu.reg_pit;
	spInputNumeric(&data, 0, "%d\0", "Insert value for registers PIT:", spIPit, null);
}

void spHEditMAdr(Element el, int btn, Uint32 x, Uint32 y){
	int i = el-mem_adrs[0].label;
	uint32 data = _sp_mem_badr;
	spInputNumeric(&data, 0, "0x%X\0", "Insert value for memory address:", spIMadr, (void*)i);
}

void spHEditVMem(Element el, int btn, Uint32 x, Uint32 y){
	int i = el-mem[0].entry;
	static char msg[128];
	_sp_mem_size = btn==1? 8: btn==2? 16: 32;
	sprintf_s(msg, sizeof(msg), _sp_mem_size==8? "Insert 8-bit value to memory in address 0x%X:": _sp_mem_size==16? "Insert 16-bit value to memory in address 0x%X:": "Insert 32-bit value to memory in address 0x%X:", (_sp_mem_badr + i));
	uint32 data = 0;
	if (_sp_mem_size==8){
		data = busRead(spUtilTAddress(_sp_mem_badr + i));
	}
	else if (_sp_mem_size==16){
		data = busRead(spUtilTAddress(_sp_mem_badr + i)) | (busRead(spUtilTAddress(_sp_mem_badr + i + 1))<<8);
	}
	else {
		data = busRead(spUtilTAddress(_sp_mem_badr + i)) | (busRead(spUtilTAddress(_sp_mem_badr + i + 1))<<8) | (busRead(spUtilTAddress(_sp_mem_badr + i + 2))<<16) | (busRead(spUtilTAddress(_sp_mem_badr + i + 3))<<24);
	}
	spInputNumeric(&data, 0, "0x%X\0", msg, spIVmem, (void*)i);
}

void spHMenuLoadRom(Element el, int btn, Uint32 x, Uint32 y){
	spInputText(iniObjectGetKeyAsText(config, "default_rom_path"), "Insert path for ROM loading from:", spIMenuLoad, NULL);
}

void spHMenuSaveRom(Element el, int btn, Uint32 x, Uint32 y){
	spInputText(iniObjectGetKeyAsText(config, "default_rom_path"), "Insert path for ROM saving to:", spIMenuSave, NULL);
}

void spHEditInput(Element el, int btn, Uint32 x, Uint32 y){
	x = (x-50)/16;
	if (x >= strlen(_sp_input_buffer)){
		_sp_input_seek = strlen(_sp_input_buffer);
	}
	else if (x < 0){
		_sp_input_seek = 0;
	}
	else {
		_sp_input_seek = x;
	}
}

void spHOnMouseScroll(int x, int y){
	if (y > 0){
		_sp_mem_badr -= 0x40;
		spUpdate();
	}
	else {
		_sp_mem_badr += 0x40;
		spUpdate();
	}
}

void spHOnKey(Uint32 key, Uint32 input, _Bool ctrl, _Bool alt, _Bool shift, _Bool caps){
	//printf("=Key 0x%x ctrl=%d alt=%d shift=%d caps=%d\n", key, ctrl, alt, shift, caps);
	if (_sp_input_active){
		if (key==SDLK_LSHIFT || key==SDLK_RSHIFT || key==SDLK_LALT || key==SDLK_RALT ||
			key==SDLK_LCTRL || key==SDLK_RCTRL || key==SDLK_CAPSLOCK){
			// Dispose keys
		}
		else if (key == SDLK_RETURN && _sp_input_active){
			spCloseInput();
			_sp_input_callback(_sp_input_buffer, _sp_input_arg);
		}
		else if (key == SDLK_ESCAPE){
			spCloseInput();
		}
		else if (key==SDLK_BACKSPACE){
			if (shift){
				for (int i = 0; i<(int)(sizeof(_sp_input_buffer)-_sp_input_seek-1); i++){
					_sp_input_buffer[i] = _sp_input_buffer[i+_sp_input_seek];
				}
				_sp_input_seek = 0;
			}
			else if (_sp_input_seek > 0){
				_sp_input_seek--;
				for (int i = _sp_input_seek; i<(int)(sizeof(_sp_input_buffer)-_sp_input_seek-1); i++){
					_sp_input_buffer[i] = _sp_input_buffer[i+1];
				}
			}
		}
		else if (key==SDLK_DELETE){
			if (shift){
				for (int i = _sp_input_seek; i<(int)(sizeof(_sp_input_buffer)-1); i++){
					_sp_input_buffer[i] = 0;
				}
			}
			else {
				for (int i = _sp_input_seek; i<(int)(sizeof(_sp_input_buffer)-_sp_input_seek-1); i++){
					_sp_input_buffer[i] = _sp_input_buffer[i+1];
				}
			}
		}
		else if (key==SDLK_LEFT){
			if (_sp_input_seek > 0){
				_sp_input_seek--;
			}
		}
		else if (key==SDLK_RIGHT){
			if (_sp_input_buffer[_sp_input_seek]!=0){
				_sp_input_seek++;
			}
		}
		else if (key==SDLK_HOME){
			_sp_input_seek = 0;
		}
		else if (key==SDLK_END){
			_sp_input_seek = strlen(_sp_input_buffer);
		}
		else if (ctrl){
			if (key=='v'){
				char* content = SDL_GetClipboardText();
				char* og = content;
				int gap = strlen(content);
				/**
				// Inserting content: more dynamic
				for (int i = sizeof(_sp_input_buffer)-2; i>_sp_input_seek; i--){
					if (gap<=i){
						_sp_input_buffer[i] = _sp_input_buffer[i-gap];
					}
				}
				for (int i = _sp_input_seek; i<(_sp_input_seek+gap) && i<(sizeof(_sp_input_buffer)-1); i++){
					_sp_input_buffer[i] = *content;
					content++;
				}
				_sp_input_seek += gap;
				_sp_input_seek = _sp_input_seek>=sizeof(_sp_input_buffer)? sizeof(_sp_input_buffer)-2: _sp_input_seek;
				*/
				// Replacing content: more intuitive (preferable)
				_sp_input_buffer[0] = 0;
				for (int i = 0; i<(sizeof(_sp_input_buffer)-1) && content[i]; i++){
					_sp_input_buffer[i+1] = 0;
					_sp_input_buffer[i] = content[i];
				}
				_sp_input_seek = gap;
				/**/

				SDL_free(og);
			}
			if (key=='c'){
				SDL_SetClipboardText(_sp_input_buffer);
			}
		}
		else if (alt){

		}
		else {
			char chr = input;
			/*if ((chr>='a' && chr<='z') && (shift || caps)){
				chr -= 0x20;
			}*/
			if (_sp_input_seek < (sizeof(_sp_input_buffer)-1)){
				for (int i = sizeof(_sp_input_buffer)-2; i>_sp_input_seek; i--){
					_sp_input_buffer[i] = _sp_input_buffer[i-1];
				}
				_sp_input_buffer[_sp_input_seek] = chr;
				_sp_input_seek++;
			}
		}
	}
	else {
		if (key == SDLK_F9){
			vmStep();
			spUpdate();
		}
		if (key == SDLK_F1){
			vmReset();
			spUpdate();
		}
		if (key == SDLK_PAGEUP){
			_sp_mem_badr -= 0x100;
			spUpdate();
		}
		if (key == SDLK_PAGEDOWN){
			_sp_mem_badr += 0x100;
			spUpdate();
		}
	}
}


//
//	Main Functions
//
void spInit() {
	guiStart();

	// Decorative text
	guiCreateLabel("LP432 Virtual Machine - Inspector", 250, 20);

	// Registers
	for (int i = 0; i<16; i++){
		guiCreateLabel(gregs[i].name, 20, 50 + i*20);
	}
	for (int i = 0; i<16; i++){
		Element entry = guiCreateLabel(gregs[i].buffer/*"0x00000000"*/, 50, 50 + i*20);
		guiSetElementBackColor(entry, COLOR_YELLOW);
		guiSetElementHoverColor(entry, COLOR_ORANGE);
		guiSetElementHoldColor(entry, COLOR_RED);
		guiSetElementWidth(entry, 80);
		guiSetElementHeight(entry, 20);
		guiSetElementOnClick(entry, spHEditGreg);
		//guiSetElementVisible(entry, 0);
		gregs[i].buffer[0] = 0;
		gregs[i].entry = entry;
	}
	for (int i = 0; i<16; i++){
		guiCreateLabel(fregs[i].name, 150, 50 + i*20);
	}
	for (int i = 0; i<16; i++){
		Element entry = guiCreateLabel(fregs[i].buffer/*"0.0000E+00"*/, 180, 50 + i*20);
		guiSetElementBackColor(entry, COLOR_YELLOW);
		guiSetElementHoverColor(entry, COLOR_ORANGE);
		guiSetElementHoldColor(entry, COLOR_RED);
		guiSetElementWidth(entry, 80);
		guiSetElementHeight(entry, 20);
		guiSetElementOnClick(entry, spHEditFreg);
		//guiSetElementActive(entry, 0);
		fregs[i].buffer[0] = 0;
		fregs[i].entry = entry;
	}
	for (int i = 0; i<16; i++){
		guiCreateLabel(oregs[i].name, 280, 50 + i*20);
	}
	for (int i = 0; i<16; i++){
		Element entry = guiCreateLabel(oregs[i].buffer/*i<8? "0x00000000": "0x00"*/, 310, 50 + i*20);
		guiSetElementBackColor(entry, COLOR_YELLOW);
		guiSetElementHoverColor(entry, COLOR_ORANGE);
		guiSetElementHoldColor(entry, COLOR_RED);
		guiSetElementWidth(entry, 80);
		guiSetElementHeight(entry, 20);
		guiSetElementOnClick(entry, spHEditOreg);
		oregs[i].buffer[0] = 0;
		oregs[i].entry = entry;
	}
	for (int i = 0; i<6; i++){
		guiCreateLabel(cregs[i].name, 20 + (i>>1)*130, 380 + (i&1)*20);
	}
	for (int i = 0; i<6; i++){
		Element entry = guiCreateLabel(cregs[i].buffer/*"0x00000000"*/, 50 + (i>>1)*130, 380 + (i&1)*20);
		guiSetElementBackColor(entry, COLOR_YELLOW);
		guiSetElementHoverColor(entry, COLOR_ORANGE);
		guiSetElementHoldColor(entry, COLOR_RED);
		guiSetElementWidth(entry, 80);
		guiSetElementHeight(entry, 20);
		guiSetElementOnClick(entry, spHEditCreg);
		//guiSetElementVisible(entry, 0);
		cregs[i].buffer[0] = 0;
		cregs[i].entry = entry;
	}

	// Program flags
	for (int i = 0; i<11; i++){
		guiCreateLabel(flags[i].name, 20 + i*35, 430);
	}
	for (int i = 0; i<11; i++){
		Element entry = guiCreateDiv(20 + i*35, 450, 15, 15);
		guiSetElementBackColor(entry, COLOR_BLACK);
		guiSetElementHoverColor(entry, COLOR_GRAY);
		guiSetElementHoldColor(entry, COLOR_WHITE);
		guiSetElementWidth(entry, 15);
		guiSetElementHeight(entry, 15);
		guiSetElementForeColor(entry, COLOR_BLACK);
		guiSetElementForeWidth(entry, 3);
		guiSetElementOnClick(entry, spHToggleFlag);
		flags[i].entry = entry;
	}

	// Memory translator
	guiCreateLabel("V.View", 400, 130);
	chk_mem_tr = guiCreateDiv(450, 130, 15, 15);
	guiSetElementBackColor(chk_mem_tr, COLOR_BLACK);
	guiSetElementHoverColor(chk_mem_tr, COLOR_GRAY);
	guiSetElementHoldColor(chk_mem_tr, COLOR_WHITE);
	guiSetElementWidth(chk_mem_tr, 15);
	guiSetElementHeight(chk_mem_tr, 15);
	guiSetElementForeColor(chk_mem_tr, COLOR_BLACK);
	guiSetElementForeWidth(chk_mem_tr, 3);
	guiSetElementOnClick(chk_mem_tr, spHToggleMemTr);

	// Memory inspector
	for (int c = 0; c<16; c++){
		static char* (offset[16]) = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
		guiCreateLabel(offset[c], 475 + c*20, 130);
	}
	for (int r = 0; r<16; r++){
		Element label = guiCreateLabel(mem_adrs[r].buffer/*"00000000"*/, 400, 150 + r*20);
		guiSetElementBackColor(label, COLOR_YELLOW);
		guiSetElementHoverColor(label, COLOR_ORANGE);
		guiSetElementHoldColor(label, COLOR_RED);
		guiSetElementWidth(label, 70);
		guiSetElementHeight(label, 20);
		guiSetElementOnClick(label, spHEditMAdr);
		mem_adrs[r].buffer[0] = 0;
		mem_adrs[r].label = label;
	}
	for (int r = 0; r<16; r++){
		for (int c = 0; c<16; c++){
			Element entry = guiCreateLabel(mem[r*16 + c].buffer/*"00"*/, 470 + c*20, 150 + r*20);
			guiSetElementBackColor(entry, COLOR_YELLOW);
			guiSetElementHoverColor(entry, COLOR_ORANGE);
			guiSetElementHoldColor(entry, COLOR_RED);
			guiSetElementWidth(entry, 20);
			guiSetElementHeight(entry, 20);
			guiSetElementOnClick(entry, spHEditVMem);
			mem[r*16 + c].buffer[0] = 0;
			mem[r*16 + c].entry = entry;
		}
	}

	// Menu panel
	Element menu_load = guiCreateLabel("load ROM", 10, 10);
	guiSetElementBackColor(menu_load, COLOR_WHITE);
	guiSetElementHoverColor(menu_load, COLOR_LIGHTGRAY);
	guiSetElementHoldColor(menu_load, COLOR_GRAY);
	guiSetElementForeColor(menu_load, COLOR_BLACK);
	guiSetElementWidth(menu_load, 70);
	guiSetElementHeight(menu_load, 16);
	guiSetElementPadX(menu_load, 2);
	guiSetElementPadY(menu_load, 4);
	guiSetElementForeWidth(menu_load, 1);
	guiSetElementOnClick(menu_load, spHMenuLoadRom);

	Element menu_save = guiCreateLabel("save ROM", 90, 10);
	guiSetElementBackColor(menu_save, COLOR_WHITE);
	guiSetElementHoverColor(menu_save, COLOR_LIGHTGRAY);
	guiSetElementHoldColor(menu_save, COLOR_GRAY);
	guiSetElementForeColor(menu_save, COLOR_BLACK);
	guiSetElementWidth(menu_save, 70);
	guiSetElementHeight(menu_save, 16);
	guiSetElementPadX(menu_save, 2);
	guiSetElementPadY(menu_save, 4);
	guiSetElementForeWidth(menu_save, 1);
	guiSetElementOnClick(menu_save, spHMenuSaveRom);

	// Control panel
	Element step_btn = guiCreateDiv(410, 50, 70, 30);
	guiCreateLabel("Step", 420, 60);
	guiSetElementBackColor(step_btn, COLOR_WHITE);
	guiSetElementHoverColor(step_btn, COLOR_LIGHTGRAY);
	guiSetElementHoldColor(step_btn, COLOR_GRAY);
	guiSetElementForeColor(step_btn, COLOR_BLACK);
	guiSetElementForeWidth(step_btn, 2);
	guiSetElementOnClick(step_btn, spHStep);

	Element reset_btn = guiCreateDiv(490, 50, 70, 30);
	guiCreateLabel("Reset", 500, 60);
	guiSetElementBackColor(reset_btn, COLOR_WHITE);
	guiSetElementHoverColor(reset_btn, COLOR_LIGHTGRAY);
	guiSetElementHoldColor(reset_btn, COLOR_GRAY);
	guiSetElementForeColor(reset_btn, COLOR_BLACK);
	guiSetElementForeWidth(reset_btn, 2);
	guiSetElementOnClick(reset_btn, spHReset);

	timer_label = guiCreateLabel(timer_buffer, 410, 90);
	sprintf_s(timer_buffer, sizeof(timer_buffer), "PIT: %.10d  CTV: %.10d.%.2d", 0, 0, 0);
	guiSetElementBackColor(timer_label, COLOR_YELLOW);
	guiSetElementHoverColor(timer_label, COLOR_ORANGE);
	guiSetElementHoldColor(timer_label, COLOR_RED);
	guiSetElementWidth(timer_label, 125);
	guiSetElementHeight(timer_label, 20);
	guiSetElementOnClick(timer_label, spHEditPit);

	// Over-panel
	over_panel = guiCreateDiv(0, 0, 800, 480);
	guiSetElementAlpha(over_panel, 0.75f);
	guiSetElementVisible(over_panel, 0);
	guiSetElementActive(over_panel, 0);

	over_text = guiCreateLabel("Insert a Input value:", 20, 20);
	guiSetElementTextColor(over_text, COLOR_WHITE);
	guiSetElementFontSize(over_text, 2);
	guiSetElementVisible(over_text, 0);
	guiSetElementActive(over_text, 0);

	over_value = guiCreateLabel(_sp_input_buffer, 50, 70);
	guiSetElementBackColor(over_value, COLOR_BLACK);
	guiSetElementHoverColor(over_value, COLOR_DARKGRAY);
	guiSetElementHoldColor(over_value, COLOR_GRAY);
	guiSetElementTextColor(over_value, COLOR_WHITE);
	guiSetElementWidth(over_value, 700);
	guiSetElementHeight(over_value, 20);
	guiSetElementFontSize(over_value, 2);
	guiSetElementVisible(over_value, 0);
	guiSetElementActive(over_value, 0);
	guiSetElementOnClickDown(over_value, spHEditInput);

	caret = guiCreateDiv(50, 70, 12, 20);
	guiSetElementBackColor(caret, COLOR_WHITE);
	guiSetElementVisible(caret, 0);
	guiSetElementActive(caret, 0);

	guiSetOnMouseScroll(spHOnMouseScroll);
	guiSetOnKeyDown(spHOnKey);

	spUpdate();

	printf("GUI Loaded!\n");
}

int spHandle() {
	guiSetElementX(caret, 52 + _sp_input_seek*16);
	guiSetElementAlpha(caret, SDL_GetTicks()&0x100? 1.0f: 0.0f);

	return guiProcess();
}

void spEnd() {
	guiClose();
}
