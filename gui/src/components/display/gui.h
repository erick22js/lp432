#ifndef GUI_GUI_H
#define GUI_GUI_H

#include "draw.h"


/*
	Elements Structure Definition
*/

#define MAX_GUI_ELEMENTS 1024

#define INVALID_ELEMENT -1

typedef enum {
	TYPE_LABEL,
	TYPE_DIV
}_ElementType;

typedef struct _Element{
	_ElementType type;
	Sint32 x, y, width, height;
	Uint32 text_color;
	Uint32 back_color;
	Uint32 fore_color;
	float font_size;
	float fore_width;
	char* text;
	void (*onClick)(Uint32 x, Uint32 y);
}_Element;
_Element _elements[MAX_GUI_ELEMENTS];
Uint32 _elements_top = 0;

typedef Uint32 Element;


/*
	Elements creation and managment functions
*/

Element guiCreateLabel(char* text, Sint32 x, Sint32 y){
	if (_elements_top < MAX_GUI_ELEMENTS){
		_elements[_elements_top].type = TYPE_LABEL;
		_elements[_elements_top].text = text;
		_elements[_elements_top].text_color = COLOR_BLACK;
		_elements[_elements_top].font_size = 1;
		_elements[_elements_top].x = x;
		_elements[_elements_top].y = y;
		_elements_top++;
	}
	else {
		return INVALID_ELEMENT;
	}
	return _elements_top-1;
}

Element guiCreateDiv(Sint32 x, Sint32 y, Sint32 width, Sint32 height){
	if (_elements_top < MAX_GUI_ELEMENTS){
		_elements[_elements_top].type = TYPE_DIV;
		_elements[_elements_top].back_color = COLOR_BLACK;
		_elements[_elements_top].fore_color = COLOR_BLACK;
		_elements[_elements_top].x = x;
		_elements[_elements_top].y = y;
		_elements[_elements_top].width = width;
		_elements[_elements_top].height = height;
		_elements_top++;
	}
	else {
		return INVALID_ELEMENT;
	}
	return _elements_top-1;
}

void guiSetElementX(Element el, Sint32 x){
	_elements[el].x = x;
}

void guiSetElementY(Element el, Sint32 y){
	_elements[el].y = y;
}

void guiSetElementWidth(Element el, Sint32 width){
	_elements[el].width = width;
}

void guiSetElementHeight(Element el, Sint32 height){
	_elements[el].height = height;
}

void guiSetElementTextColor(Element el, Uint32 color){
	_elements[el].text_color = color;
}

void guiSetElementBackColor(Element el, Uint32 color){
	_elements[el].back_color = color;
}

void guiSetElementForeColor(Element el, Uint32 color){
	_elements[el].fore_color = color;
}

void guiSetElementFontSize(Element el, float size){
	_elements[el].font_size = size;
}

void guiSetElementForeWidth(Element el, float width){
	_elements[el].fore_width = width;
}

void guiSetElementText(Element el, char* text){
	_elements[el].text = text;
}


/*
	Elements processing functions and GUI handling
*/

void guiStart() {
	SDL_Init(SDL_INIT_EVERYTHING);

	sp_win = SDL_CreateWindow("LP432 Inspector", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 480, 0);
	sp_rnd = SDL_CreateRenderer(sp_win, 0, 0);

	SDL_Surface *font_img = IMG_Load("../gui/font.png");
	sp_chars = SDL_CreateTextureFromSurface(sp_rnd, font_img);

	printf("Done!");
}

int guiProcess() {
	SDL_Event ev;
	while (SDL_PollEvent(&ev)){
		if (ev.type == SDL_QUIT){
			return SDL_QUIT;
		}
	}

	// Clear the background
	rect_color = COLOR_WHITE;
	dwFillRect(0, 0, 800, 480);

	// Render and process every element
	for (int i = 0; i<_elements_top; i++){
		switch (_elements[i].type){
			case TYPE_LABEL: {
				text_color = _elements[i].text_color;
				dwText(_elements[i].text, _elements[i].x, _elements[i].y, _elements[i].font_size);
			}
			break;
			case TYPE_DIV: {
				rect_color = _elements[i].back_color;
				dwFillRect(_elements[i].x, _elements[i].y, _elements[i].width, _elements[i].height);
				rect_color = _elements[i].fore_color;
				line_width = _elements[i].fore_width;
				dwStrokeRect(_elements[i].x, _elements[i].y, _elements[i].width, _elements[i].height);
			}
		}
	}

	SDL_RenderPresent(sp_rnd);
	return 0;
}

void guiClose() {
	SDL_DestroyRenderer(sp_rnd);
	SDL_DestroyWindow(sp_win);
	SDL_Quit();
}


#endif