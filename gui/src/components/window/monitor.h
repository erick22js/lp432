#ifndef WINDOW_MONITOR_H
#define WINDOW_MONITOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sdl_related.h"


/*
	Monitor Structure
*/

typedef struct{
	SDL_Window *wd;
	SDL_Renderer *rd;
	SDL_Texture *tex;
	Uint32* buffer;
	_Bool enable_display;
	int buff_wid, buff_hei;

	// Callback events
	void (*onKeyboardEvent)(SDL_Event *ev);
	void (*onMouseEvent)(SDL_Event *ev);
	void (*onWindowEvent)(SDL_Event *ev);
	void (*onOtherEvent)(SDL_Event *ev);
}Monitor;


/*
	Monitor Functions Handling
*/

extern void mntrOpen(Monitor *monitor, char* title, int width, int height, int buff_wid, int buff_hei, _Bool fullscreen, _Bool resizable, _Bool no_buttons);
extern void mntrRender(Monitor *monitor);
extern void mntrListen(Monitor *monitor);
extern void mntrUnlisten(Monitor *monitor);
extern void mntrClose(Monitor *monitor);


#endif