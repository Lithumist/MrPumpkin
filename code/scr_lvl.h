/*
	scr_lvl.h

	Declares varibles and functions that make the level select screen work
*/

#ifndef SCR_LVL_H
#define SCR_LVL_H

#include "constant.h"
#include "global.h"
#include "graphics.h"
#include "resources.h"
#include "timer.h"


//////////////////////
//  Varibles

extern int currentLevelSelected;

//////////////////////
//  Functions

void scr_lvl_start();
void scr_lvl_step();
void scr_lvl_render_graphics();


#endif