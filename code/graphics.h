/*
	graphics.h

	Declares functions that manipulate graphics
*/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "global.h"
#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include <iostream>

SDL_Surface* imageLoad(std::string filename);
void imageDraw(SDL_Surface* surface, float xpos, float ypos);
void imageFree(SDL_Surface* surface);

#endif