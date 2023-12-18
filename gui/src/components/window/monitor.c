#include <Windows.h>
#include "monitor.h"


/*
	Monitor Functions Handling
*/

void mntrOpen(Monitor *monitor, char* title, int width, int height, int buff_wid, int buff_hei, _Bool fullscreen, _Bool resizable, _Bool no_buttons) {
	memset(monitor, 0, sizeof(Monitor));
	monitor->wd = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, (fullscreen? SDL_WINDOW_FULLSCREEN: 0)|(resizable? SDL_WINDOW_RESIZABLE: 0));
	if (no_buttons){
		// OS: Windows code
		SDL_SysWMinfo wmInfo;
		SDL_VERSION(&wmInfo.version);
		SDL_GetWindowWMInfo(monitor->wd, &wmInfo);
		HWND hwnd = wmInfo.info.win.window;
		SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_SYSMENU);
	}
	monitor->rd = SDL_CreateRenderer(monitor->wd, 0, SDL_RENDERER_ACCELERATED);
	monitor->tex = SDL_CreateTexture(monitor->rd, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, buff_wid, buff_hei);
	monitor->buff_wid = buff_wid;
	monitor->buff_hei = buff_hei;
	monitor->enable_display = 1;
	monitor->buffer = malloc(buff_wid*buff_hei*4);
	memset(monitor->buffer, 0, buff_wid*buff_hei*4);
}

void mntrRender(Monitor *monitor){
	if (monitor->enable_display){
		SDL_UpdateTexture(monitor->tex, NULL, monitor->buffer, monitor->buff_wid*4);
		SDL_RenderCopy(monitor->rd, monitor->tex, NULL, NULL);
	}
	else {
		SDL_SetRenderDrawColor(monitor->rd, 0, 0, 0, 255);
		SDL_RenderDrawRect(monitor->rd, NULL);
	}
	SDL_RenderPresent(monitor->rd);
}

void mntrListen(Monitor *monitor){
	SDL_Event ev;
	while (sdlPollEvent(monitor->wd, &ev)){
		if (ev.type == SDL_KEYDOWN || ev.type == SDL_KEYUP){
			//printf("Key Event on window\n");
			if (monitor->onKeyboardEvent){
				monitor->onKeyboardEvent(&ev);
			}
		}
		else if (ev.type == SDL_MOUSEBUTTONDOWN || ev.type == SDL_MOUSEBUTTONUP || ev.type == SDL_MOUSEMOTION){
			//printf("Mouse Event on window\n");
			if (monitor->onMouseEvent){
				monitor->onMouseEvent(&ev);
			}
		}
		else if (ev.type == SDL_WINDOWEVENT || ev.type == SDL_QUIT){
			//printf("Window Event on window\n");
			if (monitor->onWindowEvent){
				monitor->onWindowEvent(&ev);
			}
		}
		else {
			//printf("Other Event on window\n");
			if (monitor->onOtherEvent){
				monitor->onOtherEvent(&ev);
			}
		}
	}
}

void mntrUnlisten(Monitor *monitor){
	SDL_Event ev;
	while (sdlDiscardEvent(monitor->wd, &ev)){}
}

void mntrClose(Monitor *monitor){
	SDL_DestroyRenderer(monitor->rd);
	monitor->rd = NULL;
	SDL_DestroyWindow(monitor->wd);
	monitor->wd = NULL;
	free(monitor->buffer);
	monitor->buffer = NULL;
}

