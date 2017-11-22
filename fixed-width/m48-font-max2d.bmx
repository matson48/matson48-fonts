Rem Start

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

End Rem

SuperStrict

Private 

Global font_image:TImage
Const character_w: Byte = 8
Const character_h: Byte = 16

Public

Function m48_font_initialize()
	' Store old mask (transparent) color so we don't screw with user's state
	Local old_r:int, old_g:int, old_b:int
	GetMaskColor old_r, old_g, old_b
	
	' Load font with black being transparent, and image filtering off
	SetMaskColor 0, 0, 0
	font_image = LoadImage("8x16-thin-codepage-437.bmp", maskedimage)
	
	' Restore original mask color
	SetMaskColor old_r, old_g, old_b
End Function

Function m48_font_draw_char(char: Byte, x: Int, y: Int)
	DrawSubImageRect(
		font_image, ..
		x, y, character_w, character_h, ..               ' Dest rectangle
		char*character_w, 0, character_w, character_h .. ' Source rectangle
	)
End Function

Function m48_font_draw_text(text: String, x: Int, y: Int)
	Local index:Int = 0
	For index = 0 To text.length-1
		draw_char(text[index], x+index*character_w, y)
	Next
End Function
