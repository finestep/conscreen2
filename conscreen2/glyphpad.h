#pragma once

#include "glyph.h"

struct glyphpad {
	const int sizeX, sizeY;
	glyph * data;

	inline glyphpad(int sx, int sy) : sizeX(sx), sizeY(sy) {
		data = new glyph[sizeX*sizeY];
	}
	inline ~glyphpad() {
		delete[] data;
	}

	inline glyph* glyphAt(int px, int py) {
		if (px < 0 || px >= sizeX
			|| py < 0 || py >= sizeY) return nullptr;
		return (data+px+sizeX*py);
	}
	inline void setGlyph(int px, int py, const glyph& g) {
		if (px < 0 || px >= sizeX
			|| py < 0 || py >= sizeY) return;
		glyphAt(px, py)->value = g.value;
		glyphAt(px, py)->fg = g.fg;
		glyphAt(px, py)->bg = g.bg;
	}
	inline void blitTo(glyphpad* other, int px, int py) {
		for (int ix = px; ix < sizeX;ix++)
			for (int iy = py; ix < sizeY; iy++) {
				other->setGlyph(px + ix, py + iy, *glyphAt(ix, iy));
			}
	}
};