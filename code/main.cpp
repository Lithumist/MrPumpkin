

/*
***
**
** Mr Pumpkin
**
** Pedro Custodio
**
** 2012
**
***
*/


#include "constant.h"
#include "global.h"
#include "SDL.h"


SDL_Event event;


/** Main function **/
int main(int argc, char* args[])
{
	//
	// Initialize program

	// Init SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// Open window
	gbl::S_screen = SDL_SetVideoMode((int)cnst::WINDOW_WIDTH,(int)cnst::WINDOW_HEIGHT,32,SDL_SWSURFACE);

	// Set caption
	SDL_WM_SetCaption(cnst::WINDOW_CAPTION.c_str(), NULL);





	//
	// Load resources

	// Graphics
	//

	// Sounds
	//





	//
	// Initialize game

	// Subheading
	//





	//
	// Main loop

	while(gbl::loop)
	{

		/*Events*/
		 while(SDL_PollEvent(&event))
		 {
			 if(event.type == SDL_QUIT)
				 gbl::loop = false;
		 }

		/*Logic*/

		/*Graphics rendering*/

		 // Clear screen
		 SDL_FillRect(gbl::S_screen, &gbl::S_screen->clip_rect, SDL_MapRGB(gbl::S_screen->format, 0xFF, 0xFF, 0xFF));

		 // Flip screen
		 SDL_Flip(gbl::S_screen);

		/*Sound rendering*/

	}




	//
	// Shutdown

	// SDL
	SDL_Quit();

	// Free images
	//

	// Bye
	return 0;
}