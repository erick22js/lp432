#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

#include "inspector.h"
#include "../common.h"


// Global Control properties
extern const unsigned char vga_font[];
SDL_Window *sp_win;
SDL_Renderer *sp_rnd;
SDL_Texture *sp_chars;


//
//	Draw Functions
//
Uint32 text_color = 0xFFFFFF;
Uint32 rect_color = 0xFFFFFF;

float line_width = 1.0;

#define COLOR_BLACK 0x000000
#define COLOR_WHITE 0xFFFFFF
#define COLOR_GRAY 0x888888
#define COLOR_LIGHTGRAY 0xCCCCCC
#define COLOR_DARKGRAY 0x444444
#define COLOR_RED 0x0000FF
#define COLOR_BLUE 0xFF0000
#define COLOR_CYAN 0xFFFF00
#define COLOR_LIME 0x00FF00
#define COLOR_GREEN 0x00AA00
#define COLOR_YELLOW 0x00FFFF
#define COLOR_ORANGE 0x0066FF
#define COLOR_BROWN 0x004488
#define COLOR_VIOLET 0xFF00FF
#define COLOR_PURPLE 0xFF0088
#define COLOR_PINK 0x8800FF

void dwText(char* text, int left, int top, float size){
	SDL_SetTextureColorMod(sp_chars, text_color&0xFF, (text_color>>8)&0xFF, (text_color>>16)&0xFF);
	char chr = *text;
	while (chr){
		SDL_Rect src = {0, chr*12, 8, 12};
		SDL_Rect dest = {left, top, (int)(8*size), (int)(12*size)};
		SDL_RenderCopy(sp_rnd, sp_chars, &src, &dest);
		left += (int)(8*size);
		chr = *(++text);
	}
}

void dwFillRect(int left, int top, int width, int height){
	SDL_SetRenderDrawColor(sp_rnd, rect_color&0xFF, (rect_color>>8)&0xFF, (rect_color>>16)&0xFF, 0xFF);
	SDL_Rect dest = {left, top, width, height};
	SDL_RenderFillRect(sp_rnd, &dest);
}

void dwStrokeRect(int left, int top, int width, int height){
	SDL_SetRenderDrawColor(sp_rnd, rect_color&0xFF, (rect_color>>8)&0xFF, (rect_color>>16)&0xFF, 0xFF);
	SDL_RenderSetScale(sp_rnd, line_width, line_width);
	SDL_Point points[5] = {
		{(int)((left)/line_width), (int)((top)/line_width)},
		{(int)((left+width)/line_width), (int)((top)/line_width)},
		{(int)((left+width)/line_width), (int)((top+height)/line_width)},
		{(int)((left)/line_width), (int)((top+height)/line_width)},
		{(int)((left)/line_width), (int)((top)/line_width)},
	};
	SDL_RenderDrawLines(sp_rnd, points, 5);
	SDL_RenderSetScale(sp_rnd, 1, 1);
}


//
//	Control Functions
//
void spInit() {
	SDL_Init(SDL_INIT_EVERYTHING);

	sp_win = SDL_CreateWindow("LP432 Inspector", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 480, 0);
	sp_rnd = SDL_CreateRenderer(sp_win, 0, 0);

	SDL_Surface *font_img = IMG_Load("../gui/font.png");
	sp_chars = SDL_CreateTextureFromSurface(sp_rnd, font_img);

	printf("Done!");
}

int spHandle() {
	SDL_Event ev;
	while (SDL_PollEvent(&ev)){
		if (ev.type == SDL_QUIT){
			return SDL_QUIT;
		}
	}

	rect_color = COLOR_DARKGRAY;
	dwFillRect(0, 0, 800, 480);

	rect_color = COLOR_LIGHTGRAY;
	line_width = 2;
	dwStrokeRect(100, 100, 300, 300);

	text_color = COLOR_WHITE;
	dwText("Hello World!", 100, 100, 1.5);

	SDL_RenderPresent(sp_rnd);
	return 0;
}

void spEnd() {
	SDL_DestroyRenderer(sp_rnd);
	SDL_DestroyWindow(sp_win);
	SDL_Quit();
}
