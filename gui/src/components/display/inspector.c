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
};

struct {
	char buffer[10];
	Element label;
}mem_adrs[16] = {0};
struct {
	char buffer[4];
	Element entry;
}mem[256];
Element over_panel, over_text, over_value;

_Bool _sp_input_active = 0;
_Bool _sp_input_istext = 0;
char _sp_input_buffer[256];


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
	for (int i = 0; i<10; i++){
		guiSetElementBackColor(flags[i].entry, g_cpu.reg_st&flags[i].flag? COLOR_GREEN: COLOR_BLACK);
		guiSetElementHoverColor(flags[i].entry, g_cpu.reg_st&flags[i].flag? COLOR_LIME: COLOR_GRAY);
	}

	// Memory inspector
	for (int r = 0; r<16; r++){
		sprintf_s(mem_adrs[r].buffer, sizeof(mem_adrs[r].buffer), "%.8X\0", 0 + r*16);
	}
	for (int r = 0; r<16; r++){
		for (int c = 0; c<16; c++){
			Uint8 data = busRead(0 + r*16 + c);
			sprintf_s(mem[r*16 + c].buffer, sizeof(mem[r*16 + c].buffer), "%.2X\0", data);
		}
	}
}

void spInputNumeric(void *default_value, int type, const char* format){
	guiSetElementText(over_text, "Insert a Numeric value:");
	guiSetElementVisible(over_panel, 1);
	guiSetElementActive(over_panel, 1);
	guiSetElementVisible(over_text, 1);
	guiSetElementActive(over_text, 1);
	guiSetElementVisible(over_value, 1);
	guiSetElementActive(over_value, 1);
	_sp_input_active = 1;
	_sp_input_istext = 0;
	printf("0x%x\n", default_value);
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
	//sprintf_s(_sp_input_buffer, sizeof(_sp_input_buffer), "0x%X", default_value);
}

void spInputText(const char* default_value){
	guiSetElementText(over_text, "Insert a Text value:");
	guiSetElementVisible(over_panel, 1);
	guiSetElementActive(over_panel, 1);
	guiSetElementVisible(over_text, 1);
	guiSetElementActive(over_text, 1);
	guiSetElementVisible(over_value, 1);
	guiSetElementActive(over_value, 1);
	_sp_input_active = 1;
	_sp_input_istext = 1;
	if (default_value){
		sprintf_s(_sp_input_buffer, sizeof(_sp_input_buffer), "%s", default_value);
	}
	else {
		sprintf_s(_sp_input_buffer, sizeof(_sp_input_buffer), "");
	}
}

void spCloseInput(){
	_sp_input_active = 0;
	guiSetElementVisible(over_panel, 0);
	guiSetElementActive(over_panel, 0);
	guiSetElementVisible(over_text, 0);
	guiSetElementActive(over_text, 0);
	guiSetElementVisible(over_value, 0);
	guiSetElementActive(over_value, 0);
}


//
//	Process Functions
//

void spHStep(Element el, Uint32 x, Uint32 y){
	vmStep();
	spUpdate();
}

void spHReset(Element el, Uint32 x, Uint32 y){
	vmReset();
	spUpdate();
}

void spHEditGreg(Element el, Uint32 x, Uint32 y){
	int i = el-gregs[0].entry;
	spInputNumeric(&g_cpu.gregs[i], 0, "0x%X");
}

void spHEditFreg(Element el, Uint32 x, Uint32 y){
	int i = el-fregs[0].entry;
	spInputNumeric(&g_cpu.fregs[i], 3, "%lf");
}

void spHEditOreg(Element el, Uint32 x, Uint32 y){
	int i = el-oregs[0].entry;
	spInputNumeric(i<8? &g_cpu.iregs[i]: &g_cpu.sregs[i-8].base, i<8? 0: 0, "0x%X");
}

void spHEditCreg(Element el, Uint32 x, Uint32 y){
	int i = el-cregs[0].entry;
	spInputNumeric(cregs[i].reg, 0, "0x%X");
}

void spHToggleFlag(Element el, Uint32 x, Uint32 y){
	int i = el-flags[0].entry;
	if (g_cpu.reg_st&flags[i].flag){
		g_cpu.reg_st &= ~flags[i].flag;
	}
	else {
		g_cpu.reg_st |= flags[i].flag;
	}
	spUpdate();
}

void spHEditMAdr(Element el, Uint32 x, Uint32 y){
	int i = el-mem_adrs[0].label;
	uint32 data = 0;
	spInputNumeric(&data, 0, "0x%X");
}

void spHEditVMem(Element el, Uint32 x, Uint32 y){
	int i = el-mem[0].entry;
	uint32 data = busRead(i);
	spInputNumeric(&data, 0, "0x%X");
}

void spHOnKey(Uint32 key){
	if (key == SDLK_F9){
		vmStep();
		spUpdate();
	}
	if (key == SDLK_F1){
		vmReset();
		spUpdate();
	}
	if (key == SDLK_RETURN && _sp_input_active){
		spCloseInput();
	}
	if (key == SDLK_ESCAPE){
		spCloseInput();
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
	for (int i = 0; i<10; i++){
		guiCreateLabel(flags[i].name, 20 + i*35, 430);
	}
	for (int i = 0; i<10; i++){
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
	guiSetElementTextColor(over_value, COLOR_WHITE);
	guiSetElementFontSize(over_value, 2);
	guiSetElementVisible(over_value, 0);
	guiSetElementActive(over_value, 0);

	guiSetOnKeyDown(spHOnKey);

	spUpdate();

	printf("GUI Loaded!\n");
}

int spHandle() {
	return guiProcess();
}

void spEnd() {
	guiClose();
}
