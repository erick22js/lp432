#include "sdl_related.h"


/*
	SDL Control Functions
*/

int sdlPollEvent(SDL_Window *wd, SDL_Event *ev) {
	if (!SDL_GetWindowFlags(wd)&SDL_WINDOW_INPUT_FOCUS){
		return 0;
	}
	int code = 0;
	while ((code = SDL_PollEvent(ev))){
		if (ev->type == SDL_WINDOWEVENT && SDL_GetWindowID(wd) != ev->window.windowID){
			continue;
		}
		else if (SDL_GetWindowID(wd) == ev->window.windowID){
			return code;
		}
	}
	return 0;
}

