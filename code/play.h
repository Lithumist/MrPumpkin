/*
	play.h

	Declares varibles and functions that make the playing screen work
*/

#ifndef PLAY_H
#define PLAY_H

#include "constant.h"
#include "global.h"
#include "graphics.h"
#include "resources.h"
#include "timer.h"
#include "level.h"


//////////////////////
//  Varibles

extern bool playing;
extern int levelReturnCode;

//////////////////////
//  Functions

int playLevel(std::string level_filename);

void gameLogic();
void gameRendering();

//////////////////////
//  Info
/*

playLevel() Return Codes:

0  level loaded and will now be played
1  level file could not be loaded


levelReturnCode:

-2  level not finished
-1  level not passed
 0  level passed

*/


#endif