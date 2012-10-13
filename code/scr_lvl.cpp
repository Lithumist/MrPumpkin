// scr_lvl.cpp
#include "scr_lvl.h"



//////////////////////
//  Varibles

int currentLevelSelected = 1;


//////////////////////
//  Functions

void scr_lvl_start()
{
	currentLevelSelected = 1;
}


void scr_lvl_step()
{

	if(gbl::spacePressed)
		gbl::state = 4; // play

}


void scr_lvl_render_graphics()
{
		// Clear screen
		SDL_FillRect(gbl::S_screen, &gbl::S_screen->clip_rect, SDL_MapRGB(gbl::S_screen->format, 0, 0, 0));

	// stuff

		// Flip screen
		SDL_Flip(gbl::S_screen);
}