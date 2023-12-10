#ifndef WINDOW_SDL_RELATED_H
#define WINDOW_SDL_RELATED_H

#include <stdio.h>
#include <SDL.h>
#include <SDL_syswm.h>
#include <SDL_image.h>


/*
	SDL Control Functions
*/

extern int sdlPollEvent(SDL_Window *wd, SDL_Event *ev);
extern int sdlDiscardEvent(SDL_Window *wd, SDL_Event *ev);


#endif