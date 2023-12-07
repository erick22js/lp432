#include "monitor.h"


/*
	Monitor Functions Handling
*/

void mntrOpen(Monitor *monitor, char* title, int width, int height, int buff_wid, int buff_hei) {
	monitor->wd = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	monitor->rd = SDL_CreateRenderer(monitor->wd, 0, SDL_RENDERER_ACCELERATED);
	monitor->tex = SDL_CreateTexture(monitor->rd, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, buff_wid, buff_hei);
	monitor->buff_wid = buff_wid;
	monitor->buff_hei = buff_hei;
	monitor->buffer = malloc(buff_wid*buff_hei*4);
	memset(monitor->buffer, 0, buff_wid*buff_hei*4);
}

void mntrRender(Monitor *monitor){
	SDL_UpdateTexture(monitor->tex, NULL, monitor->buffer, monitor->buff_wid*4);
	SDL_RenderCopy(monitor->rd, monitor->tex, NULL, NULL);
	SDL_RenderPresent(monitor->rd);
}

void mntrListen(Monitor *monitor, SDL_Event *ev){
	return sdlPollEvent(monitor->wd, ev);
}

void mntrClose(Monitor *monitor){
	SDL_DestroyRenderer(monitor->rd);
	monitor->rd = NULL;
	SDL_DestroyWindow(monitor->wd);
	monitor->wd = NULL;
	free(monitor->buffer);
	monitor->buffer = NULL;
}

