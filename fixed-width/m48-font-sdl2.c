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

// This may not be the best C in the world. I'm used to dynamic languages

#include "m48-font-sdl2.h"

// Font filename and character width and height are stored in header file

// Private global vars for this module
static SDL_Renderer* renderer;
static SDL_Texture* font_texture; 

// All methods return -1 on error and 0 on success.

int m48_font_initialize(SDL_Renderer* _renderer) {
    int result;
	
	// Store reference to already initialized SDL renderer
    renderer = _renderer;

    // Load font as surface
    SDL_Surface* font_surface;
    font_surface = SDL_LoadBMP(FONT_FILENAME);
    if (!font_surface) return -1;

    // Make black transparent
    result = SDL_SetColorKey(font_surface, SDL_TRUE, 
                             SDL_MapRGB(font_surface->format, 0, 0, 0));
    if (result < 0) return -1;

    // Turn surface into texture, discard surface
    font_texture = SDL_CreateTextureFromSurface(renderer, 
                                                font_surface);
    SDL_FreeSurface(font_surface);
    if (!font_texture) return -1;

    return 0;
}

int m48_font_shutdown() {
    // Free texture (which user does not have access to)
    SDL_DestroyTexture(font_texture);
}

int m48_font_draw_char(unsigned char character, int x, int y) {
    // Sanity check
    if (!renderer) return -1;

    // Initialize rectangles needed for rendering
    SDL_Rect source = {
        character*FONT_CHAR_W, 0,             // x, y
        FONT_CHAR_W, FONT_CHAR_H              // width, height
    };

    SDL_Rect destination = {
        x, y, 
        FONT_CHAR_W, FONT_CHAR_H
    };

    // Render character to renderer
    SDL_RenderCopyEx(renderer, font_texture, 
                     &source, &destination, 
                     0, 0, 0);
					 
	return 0;
}

int m48_font_draw_text(const char* text, int x, int y) {
    // Sanity check
    if (!renderer) return -1;

    // Loop through characters in text, rendering each until reaching '\0'
    char* character = (char*)text;
    unsigned int index = 0;

    while (*character) { 
        m48_font_draw_char(*character, x+index*FONT_CHAR_W, y);
        character++;
        index++;
    }
}
