/***************************************************************************
Code from: https://github.com/matson48/matson48-fonts

Copyright (c) 2017 matson48

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
***************************************************************************/

#include "SDL.h"

#define FONT_CHAR_W 8
#define FONT_CHAR_H 16
#define FONT_FILENAME "8x16-thin-codepage-437.bmp"

extern int m48_font_initialize(SDL_Renderer* _renderer);
extern int m48_font_shutdown();
extern int m48_font_draw_char(unsigned char character, int x, int y);
extern int m48_font_draw_text(const char* text, int x, int y);
