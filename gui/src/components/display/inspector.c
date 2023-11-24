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
}flags[] = {
	{"CF"},
	{"BF"},
	{"VF"},
	{"NF"},
	{"ZF"},
	{"OF"},
	{"PM"},
	{"SE"},
	{"PE"},
	{"IE"},
};

//
//	Process Functions
//

//
//	Main Functions
//
void spInit() {
	guiStart();

	// Decorative text
	guiCreateLabel("LP432 Virtual Machine - Inspector", 250, 20);

	// Registers
	for (int i = 0; i<16; i++){
		guiCreateLabel(gregs[i].name, 20, 70 + i*20);
		guiCreateLabel("0x00000000", 50, 70 + i*20);
	}
	for (int i = 0; i<16; i++){
		guiCreateLabel(fregs[i].name, 150, 70 + i*20);
		guiCreateLabel("0.0000E+00", 180, 70 + i*20);
	}
	for (int i = 0; i<16; i++){
		guiCreateLabel(oregs[i].name, 280, 70 + i*20);
		guiCreateLabel(i<8? "0x00000000": "0x00", 310, 70 + i*20);
	}

	// Program flags
	for (int i = 0; i<10; i++){
		guiCreateLabel(flags[i].name, 20 + i*35, 410);
		guiCreateDiv(20 + i*35, 430, 15, 15);
	}

	// Memory inspector
	for (int c = 0; c<16; c++){
		static char* (offset[16]) = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
		guiCreateLabel(offset[c], 475 + c*20, 130);
	}
	for (int r = 0; r<16; r++){
		guiCreateLabel("00000000", 400, 150 + r*20);
		for (int c = 0; c<16; c++){
			guiCreateLabel("00", 470 + c*20, 150 + r*20);
		}
	}

	// Control panel
	Element step_btn = guiCreateDiv(410, 70, 70, 30);
	guiCreateLabel("Step", 420, 80);
	guiSetElementBackColor(step_btn, COLOR_WHITE);
	guiSetElementForeColor(step_btn, COLOR_BLACK);
	guiSetElementForeWidth(step_btn, 2);

	Element reset_btn = guiCreateDiv(490, 70, 70, 30);
	guiCreateLabel("Reset", 500, 80);
	guiSetElementBackColor(reset_btn, COLOR_WHITE);
	guiSetElementForeColor(reset_btn, COLOR_BLACK);
	guiSetElementForeWidth(reset_btn, 2);
}

int spHandle() {
	return guiProcess();
}

void spEnd() {
	guiClose();
}
