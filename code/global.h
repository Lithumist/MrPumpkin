/*
	global.h

	Declares a set of varibles that the whole program uses
*/

#ifndef GLOBAL_H
#define GLOBAL_H

#include "SDL.h"

namespace gbl
{

	extern bool loop;
	extern int state;

	extern SDL_Surface* S_screen;

	extern bool spacePressed;
	extern bool spaceIsDown;

}

#endif