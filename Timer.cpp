#include "SDL/SDL.h"
#include "Timer.h"

//constructor of Timer
Timer::Timer()
{
  //initialize the variables
  startTicks = 0;
  pausedTicks = 0;
  paused = false;
  started = false;
}

//start: starts timer, uses SDL_GetTicks() to get the time value
void Timer::startTimer()
{
  started = true;

  paused = false;

  startTicks = SDL_GetTicks();
}

//stop: stops timer
void Timer::stopTimer()
{
  started = false;
  
  paused = false;
}

int Timer::get_ticks()
{
  //if timer is running
  if( started == true ) 
    {
      //if timer is paused
      if( paused == true )
	{
	  //return number of ticks when timer was paused
	  return pausedTicks;
	}
      else
	{
	  //return current time minus start time
	  return SDL_GetTicks() - startTicks;
	}
    }

  //if timer isn't running
  return 0;
}

//pause: pauses timer, stores the time elapsed in a variable called pausedTicks
void Timer::pauseTimer()
{
  if( ( started == true ) && ( paused == false ) )
    {
      paused = true;
      pausedTicks = SDL_GetTicks() - startTicks;
    }
}

//unpause: unpauses timer, sets starting value of timer using pausedTicks and then resets it
void Timer::unpauseTimer()
{
  if( paused == true  )
    {
      paused = false;
      startTicks = SDL_GetTicks() - pausedTicks;
      pausedTicks = 0;
    }
}

//is_started/paused: returns bool values of started and paused
bool Timer::is_started()
{
  return started;
}

bool Timer::is_paused()
{
  return paused;
}
