// scr_title.cpp
#include "scr_title.h"



//////////////////////
//  Varibles

timer mainTimer;
bool displayMessage = false;


//////////////////////
//  Functions

void scr_title_start()
{
	mainTimer.reset();
}


void scr_title_step()
{

	if(mainTimer.get_time()>=500) // every half-second
	{
		displayMessage = !displayMessage;
		mainTimer.reset();
	}

}


void scr_title_render_graphics()
{
		// Clear screen
		SDL_FillRect(gbl::S_screen, &gbl::S_screen->clip_rect, SDL_MapRGB(gbl::S_screen->format, 0, 0, 0));

	// Draw title
	imageDraw(res::S_title,140,0);

	// Draw message
	if(displayMessage)
		imageDraw(res::S_message,270,570);

		// Flip screen
		SDL_Flip(gbl::S_screen);
}