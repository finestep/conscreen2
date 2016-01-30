#pragma once

#include <SDL.h>
#include "glyphpad.h"
#include "glyph.h"

struct termscreen {
	const int sizeX, sizeY;
	glyphpad glyphs;
	SDL_Surface* scr; //???
};