

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
#include "graphics.h"
#include "resources.h"
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
	res::S_title = imageLoad("resources/graphics/title.png");

	// Sounds
	//





	//
	// Initialize game

	// Set state to title screen
	gbl::state = 2;





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

		 switch(gbl::state)
		 {



			case 2: //title

				/*Logic*/

				/*Graphics rendering*/

				// Clear screen
				SDL_FillRect(gbl::S_screen, &gbl::S_screen->clip_rect, SDL_MapRGB(gbl::S_screen->format, 0xFF, 0xFF, 0xFF));

				// Draw title
				imageDraw(res::S_title,150,0);

				// Flip screen
				SDL_Flip(gbl::S_screen);

			break;



		 }//switch


	}//while




	//
	// Shutdown

	// SDL
	SDL_Quit();

	// Free images
	imageFree(res::S_title);

	// Bye
	return 0;
}