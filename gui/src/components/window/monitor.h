#ifndef WINDOW_MONITOR_H
#define WINDOW_MONITOR_H

#include <stdio.h>
#include <stdlib.h>

#include "sdl_related.h"


/*
	Monitor Structure
*/

typedef struct{
	SDL_Window *wd;
	SDL_Renderer *rd;
	SDL_Texture *tex;
	Uint32* buffer;
	int buff_wid, buff_hei;
}Monitor;


/*
	Monitor Functions Handling
*/

extern void mntrOpen(Monitor *monitor, char* title, int width, int height, int buff_wid, int buff_hei);
extern void mntrRender(Monitor *monitor);
extern void mntrListen(Monitor *monitor, SDL_Event *ev);
extern void mntrClose(Monitor *monitor);


#endif