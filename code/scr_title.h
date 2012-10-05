/*
	scr_title.h

	Declares varibles and functions that make the title screen work
*/

#ifndef SCR_TITLE_H
#define SCR_TITLE_H

#include "constant.h"
#include "global.h"
#include "graphics.h"
#include "resources.h"
#include "timer.h"


//////////////////////
//  Varibles

extern timer mainTimer;
extern bool displayMessage;


//////////////////////
//  Functions

void scr_title_start();
void scr_title_step();
void scr_title_render_graphics();


#endif