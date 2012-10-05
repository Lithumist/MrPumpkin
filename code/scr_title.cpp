// scr_title.cpp
#include "scr_title.h"



//////////////////////
//  Varibles


//////////////////////
//  Functions

void scr_title_start()
{
}


void scr_title_step()
{
}


void scr_title_render_graphics()
{
		// Clear screen
		SDL_FillRect(gbl::S_screen, &gbl::S_screen->clip_rect, SDL_MapRGB(gbl::S_screen->format, 0xFF, 0xFF, 0xFF));

	// Draw title
	imageDraw(res::S_title,150,0);

		// Flip screen
		SDL_Flip(gbl::S_screen);
}