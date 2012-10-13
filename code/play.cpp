// play.cpp
#include "play.h"



//////////////////////
//  Varibles

bool playing = false;
int levelReturnCode = -2;


//////////////////////
//  Functions

int playLevel(std::string level_filename)
{
	playing = true;
	std::cout << "Now playing level " << level_filename << std::endl;

	return 0; // ok
}


void gameLogic()
{
}


void gameRendering()
{
}