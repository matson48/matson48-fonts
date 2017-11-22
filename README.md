# matson48 Fonts

I toyed around with the idea of making a small ASCII art game engine a bit ago, but wasn't quite sure what to do about a font for it. 

I wanted a bitmap font that hadn't been ripped from anything, had a permissive license, had tall letters, had Codepage 437 characters, and could be easily displayed without using a third party font rendering library.

After realizing this basically meant I could use no font ever, I gave up and just drew my own.

And, realizing other people have probably been in the same situation, I'm releasing my work to the public.

## Contents

The `fixed-width` folder has fixed width fonts, in which every character is the same width. Included is (currently just one) font in `.bmp` format, and small libraries for drawing text in a variety of programming languages.

(The font being `.bmp` is only important for the SDL drawing code, which currently uses [SDL's built in bitmap loader](https://wiki.libsdl.org/SDL_LoadBMP) [instead of SDL_image](https://www.libsdl.org/projects/SDL_image/), to facilitate programming with pure SDL. I... was interested in saving space aggressively.)

At some point I will try to draw at least one variable width bitmap font, once I figure out how to keep track of the character widths and stuff.

The filename of the fonts will have the dimensions, followed by a title, then the character set.

The filenames of the code files are prefixed by `m48-font` (m48 standing for matson48, my screenname), followed by the name of the graphics library it uses. These code files define methods prefixed by `m48_font` that will draw text with the fonts in that folder. 

Currently you will have to manually alter the code files to refer to the file and character sizes you want---I may or may not come up with a better way to handle this later.

Fonts and code snippets will appear in different formats and languages as I need them.

So probably pretty slowly.

## Todo

These are my top priorities for this:

* Make script to auto-convert fonts to [BMFonts](http://www.angelcode.com/products/bmfont/), which many game engines and graphics libraries have built-in support for.
* Make sure my text drawing code actually works. (Right now, the code's been taken from working programs, but I haven't tested these separated out versions yet.)

## License

Fonts and code under zlib license. 

Despite being designed for code, the zlib license comes closest to the terms I want for these fonts, and is very simple to understand.

If this is a problem, let me know.
