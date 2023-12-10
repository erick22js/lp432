#include "sdl_related.h"


/*
	SDL Control Functions
*/
static SDL_Event stack_evs[128] = {0};
static int stack_top = 0;

int sdlPollEvent(SDL_Window *wd, SDL_Event *ev) {
	int code = 0;
	while ((code = SDL_PollEvent(ev))){
		if (SDL_GetWindowID(wd) != ev->window.windowID){
			if (stack_top < 128 && (SDL_GetWindowFlags(SDL_GetWindowFromID(ev->window.windowID))&SDL_WINDOW_INPUT_FOCUS)){
				stack_evs[stack_top] = *ev;
				stack_top++;
			}
			continue;
		}
		else if (SDL_GetWindowID(wd) == ev->window.windowID && (SDL_GetWindowFlags(wd)&SDL_WINDOW_INPUT_FOCUS)){
			return code;
		}
	}

	for (int i = 0; i<stack_top; i++){
		SDL_PushEvent(&stack_evs[i]);
	}
	stack_top = 0;
	return 0;
}

int sdlDiscardEvent(SDL_Window *wd, SDL_Event *ev) {
	int code = 0;
	while ((code = SDL_PollEvent(ev))){
		if (SDL_GetWindowID(wd) != ev->window.windowID){
			if (stack_top < 128 && (ev->window.windowID != SDL_GetWindowID(wd))){
				stack_evs[stack_top] = *ev;
				stack_top++;
			}
			continue;
		}
		else if (SDL_GetWindowID(wd) == ev->window.windowID && (SDL_GetWindowFlags(wd)&SDL_WINDOW_INPUT_FOCUS)){
			return code;
		}
	}

	for (int i = 0; i<stack_top; i++){
		SDL_PushEvent(&stack_evs[i]);
	}
	stack_top = 0;
	return 0;
}

