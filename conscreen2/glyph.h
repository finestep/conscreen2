#pragma once

#include <SDL.h>

struct glyph {
	Uint8 value;
	SDL_Color fg;
	SDL_Color bg;
	glyph() : value(0), fg({ 0,0,0,255 }), bg({ 0,0,0,255 }) { }
	glyph(Uint8 val, SDL_Color fg, SDL_Color bg) : value(val), fg(fg), bg(bg) { }
};
