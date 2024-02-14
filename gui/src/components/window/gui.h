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

typedef Uint32 Element;

typedef struct _Element{
	_ElementType type;
	Sint32 x, y, width, height;
	Sint32 pad_x, pad_y;
	Uint32 text_color;
	Uint32 back_color, hover_color, hold_color;
	Uint32 fore_color;
	float alpha;
	float font_size;
	float fore_width;
	char* text;
	_Bool visible, active;
	_Bool hoverable, hovered, holdable, holded;
	void (*onClick)(Element el, int button, Uint32 x, Uint32 y);
	void (*onClickDown)(Element el, int button, Uint32 x, Uint32 y);
}_Element;
_Element _elements[MAX_GUI_ELEMENTS];
Uint32 _elements_top = 0;

void (*_onMouseScroll)(int x, int y);
void (*_onKeyDown)(Uint32 key, Uint32 input, _Bool ctrl, _Bool alt, _Bool shift, _Bool caps);


/*
	Elements creation and managment functions
*/

Element guiCreateLabel(char* text, Sint32 x, Sint32 y){
	if (_elements_top < MAX_GUI_ELEMENTS){
		_elements[_elements_top].type = TYPE_LABEL;
		_elements[_elements_top].text = text;
		_elements[_elements_top].text_color = COLOR_BLACK;
		_elements[_elements_top].alpha = 1;
		_elements[_elements_top].font_size = 1;
		_elements[_elements_top].x = x;
		_elements[_elements_top].y = y;
		_elements[_elements_top].visible = _elements[_elements_top].active = 1;
		_elements[_elements_top].onClick = NULL;
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
		_elements[_elements_top].alpha = 1;
		_elements[_elements_top].x = x;
		_elements[_elements_top].y = y;
		_elements[_elements_top].width = width;
		_elements[_elements_top].height = height;
		_elements[_elements_top].visible = _elements[_elements_top].active = 1;
		_elements[_elements_top].onClick = NULL;
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

void guiSetElementPadX(Element el, Sint32 x){
	_elements[el].pad_x = x;
}

void guiSetElementPadY(Element el, Sint32 y){
	_elements[el].pad_y = y;
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

void guiSetElementHoverColor(Element el, Uint32 color){
	_elements[el].hover_color = color;
	_elements[el].hoverable = 1;
}

void guiUnsetElementHoverColor(Element el){
	_elements[el].hoverable = 0;
}

void guiSetElementHoldColor(Element el, Uint32 color){
	_elements[el].hold_color = color;
	_elements[el].holdable = 1;
}

void guiUnsetElementHoldColor(Element el){
	_elements[el].holdable = 0;
}

void guiSetElementAlpha(Element el, float alpha){
	_elements[el].alpha = alpha;
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

void guiSetElementVisible(Element el, _Bool visible){
	_elements[el].visible = visible;
}

void guiSetElementActive(Element el, _Bool active){
	_elements[el].active = active;
}

void guiSetElementOnClick(Element el, void(*onclick)(Element e, int btn, Uint32 x, Uint32 y)){
	_elements[el].onClick = onclick;
}

void guiSetElementOnClickDown(Element el, void(*onclickdown)(Element e, int btn, Uint32 x, Uint32 y)){
	_elements[el].onClickDown = onclickdown;
}

void guiSetOnMouseScroll(void (*onMouseScroll)(int x, int y)){
	_onMouseScroll = onMouseScroll;
}

void guiSetOnKeyDown(void (*onKeyDown)(Uint32 key, Uint32 input, _Bool ctrl, _Bool alt, _Bool shift, _Bool caps)){
	_onKeyDown = onKeyDown;
}


/*
	Elements processing functions and GUI handling
*/

void guiStart() {
	//SDL_Init(SDL_INIT_EVERYTHING);

	sp_win = SDL_CreateWindow("LP432 Inspector", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 480, 0);
	sp_rnd = SDL_CreateRenderer(sp_win, 0, 0);

	SDL_StartTextInput();
	dwSetup();
}

int guiProcess() {
	typedef enum{
		EVENT_NONE,
		EVENT_MOUSE_MOTION,
		EVENT_MOUSE_DOWN,
		EVENT_MOUSE_UP,
	}EventType;
	static struct{
		EventType type;
		_Bool triggered;
		Sint32 x, y;
		int button;
		_Bool holding;
	}gui_event = {0};
	gui_event.type = EVENT_NONE;
	gui_event.triggered = 0;

	struct {
		_Bool triggered;
		Uint32 key, input;
		_Bool ctrl, alt, shift, caps;
	}key_event = {0};

	SDL_Event ev;
	while (sdlPollEvent(sp_win, &ev)){
		switch (ev.type){
			case SDL_QUIT: {
				return SDL_QUIT;
			}
			break;
			case SDL_WINDOWEVENT: {
				if (ev.window.event == SDL_WINDOWEVENT_CLOSE){
					return SDL_QUIT;
				}
			}
			break;
			case SDL_MOUSEMOTION: {
				gui_event.type = EVENT_MOUSE_MOTION;
				gui_event.triggered = 1;
				gui_event.x = ev.motion.x;
				gui_event.y = ev.motion.y;
			}
			break;
			case SDL_MOUSEBUTTONDOWN: {
				gui_event.type = EVENT_MOUSE_DOWN;
				gui_event.triggered = 1;
				gui_event.holding = 1;
				gui_event.button = ev.button.button;
				gui_event.x = ev.button.x;
				gui_event.y = ev.button.y;
			}
			break;
			case SDL_MOUSEBUTTONUP: {
				gui_event.type = EVENT_MOUSE_UP;
				gui_event.triggered = 1;
				gui_event.holding = 0;
				gui_event.button = ev.button.button;
				gui_event.x = ev.button.x;
				gui_event.y = ev.button.y;
			}
			break;
			case SDL_MOUSEWHEEL: {
				_onMouseScroll(ev.wheel.x, ev.wheel.y);
			}
			break;
			case SDL_TEXTINPUT: {
				key_event.input = *(Uint32*)&ev.text.text;
			}
			break;
			case SDL_KEYDOWN: {
				key_event.triggered = 1;
				key_event.key = ev.key.keysym.sym;
				//key_event.input = key_event.input? key_event.input: ev.key.keysym.sym;
				key_event.ctrl = (ev.key.keysym.mod&KMOD_CTRL) != 0;
				key_event.alt = (ev.key.keysym.mod&KMOD_ALT) != 0;
				key_event.shift = (ev.key.keysym.mod&KMOD_SHIFT) != 0;
				key_event.caps = (ev.key.keysym.mod&KMOD_CAPS) != 0;
			}
			break;
		}
	}

	if (key_event.triggered){
		_onKeyDown(key_event.key, key_event.input, key_event.ctrl, key_event.alt, key_event.shift, key_event.caps);
	}

	// Clear the background
	alpha = 1;
	rect_color = COLOR_WHITE;
	dwFillRect(0, 0, 800, 480);
	
	// Process the element
	for (int i = (int)_elements_top-1; i>=0; i--){
		// Process event on element
		switch (gui_event.type){
			case EVENT_MOUSE_DOWN: {
				if (_elements[i].active &&
					gui_event.x >= _elements[i].x && gui_event.x < (_elements[i].x+_elements[i].width) &&
					gui_event.y >= _elements[i].y && gui_event.y < (_elements[i].y+_elements[i].height)){
					gui_event.type = EVENT_NONE;
					_elements[i].holded = _elements[i].holdable;
					if (_elements[i].onClickDown){
						_elements[i].onClickDown((Element)i, gui_event.button, gui_event.x, gui_event.y);
					}
				}
			}
			break;
			case EVENT_MOUSE_UP: {
				if (_elements[i].active && _elements[i].holded){
					gui_event.type = EVENT_NONE;
					//printf("Element: x=%d; y=%d; w=%d; h=%d\n", _elements[i].x, _elements[i].y, _elements[i].width, _elements[i].height);
					if (_elements[i].onClick){
						_elements[i].onClick((Element)i, gui_event.button, gui_event.x, gui_event.y);
					}
				}
			}
			break;
		}

		// Reset hold state
		if (gui_event.triggered){
			_elements[i].hovered = 0;
			if (_elements[i].active && gui_event.type &&
				gui_event.x >= _elements[i].x && gui_event.x < (_elements[i].x+_elements[i].width) &&
				gui_event.y >= _elements[i].y && gui_event.y < (_elements[i].y+_elements[i].height)){
				gui_event.type = EVENT_NONE;
				_elements[i].hovered = _elements[i].hoverable;
			}
		}
		if (!gui_event.holding){
			_elements[i].holded = 0;
		}
	}
	// Render and process every element
	for (int i = 0; i<(int)_elements_top; i++){
		if (_elements[i].visible){
			// Render any box element layout
			alpha = _elements[i].alpha;
			rect_color = _elements[i].holded? _elements[i].hold_color: _elements[i].hovered? _elements[i].hover_color: _elements[i].back_color;
			dwFillRect(_elements[i].x, _elements[i].y, _elements[i].width, _elements[i].height);
			rect_color = _elements[i].fore_color;
			line_width = _elements[i].fore_width;
			dwStrokeRect(_elements[i].x, _elements[i].y, _elements[i].width, _elements[i].height);
			switch (_elements[i].type){
				// Render text only for labels
				case TYPE_LABEL: {
					text_color = _elements[i].text_color;
					dwText(_elements[i].text, _elements[i].x + _elements[i].pad_x, _elements[i].y + _elements[i].pad_y, _elements[i].font_size);
				}
				break;
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