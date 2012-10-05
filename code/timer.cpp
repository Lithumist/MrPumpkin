// timer.cpp
#include "timer.h"




// Good luck...





timer::timer()
{
	paused = false;
	start_ticks = 0;
	paused_ticks = 0;
	paused_start_ticks = 0;
}

void timer::reset()
{
	start_ticks = SDL_GetTicks();
	paused = false;
	paused_start_ticks = 0;
	paused_ticks = 0;
}

int timer::get_time()
{
	if(!paused)
		return (int) (SDL_GetTicks() - start_ticks) - (paused_ticks);
	else
	{
		Uint32 t = SDL_GetTicks() - paused_start_ticks;
		return (int) (SDL_GetTicks() - start_ticks) - (t);
	}

}

void timer::toggle_pause()
{
	paused = !paused;
	if(paused==true)
		paused_start_ticks = SDL_GetTicks();
	else
		paused_ticks = SDL_GetTicks() - paused_start_ticks;
}

void timer::pause()
{
	paused = true;
	paused_start_ticks = SDL_GetTicks();

}

void timer::unpause()
{
	paused = false;
	paused_ticks = SDL_GetTicks() - paused_start_ticks;

}
bool timer::is_paused(){ return paused; }