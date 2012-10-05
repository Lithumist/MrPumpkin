

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
#include "fps.h"
#include "timer.h"
#include "graphics.h"
#include "resources.h"
#include "scr_title.h"
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

	// Initialize fps regulator
	fpsCalc::GetInstance()->Init((double)cnst::TARGET_FPS);





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

	// Initialize title screen
	scr_title_start();





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



			case 2: // title

				scr_title_step();
				scr_title_render_graphics();

			break;

			case 3: // level select

				scr_title_step();
				scr_title_render_graphics();

			break;

			case 4: // play

				scr_title_step();
				scr_title_render_graphics();

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