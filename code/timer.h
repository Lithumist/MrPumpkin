/*
	timer.h

	Declares a timer class
*/

#ifndef TIMER_H
#define TIMER_H

#include "SDL.h"


class timer
{public:

	timer();

	void reset();
	int get_time(); // in miliseconds

	void toggle_pause();
	void pause();
	void unpause();
	bool is_paused();

private:

	bool paused;
	Uint32 start_ticks;
	Uint32 paused_ticks;
	Uint32 paused_start_ticks;

};


#endif