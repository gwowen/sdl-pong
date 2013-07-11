//==============================================================================
//Timer.h
//==============================================================================
#ifndef _TIMER_H_
#define _TIMER_H_

//create a class for timer
class Timer
{
private:
  //clock time when timer started
  int startTicks;

  //the ticks stored when the timer was paused
  int pausedTicks;

  //timer status
  bool paused;
  bool started;

public:
  //initializes variables
  Timer();

  //clock activities
  void startTimer();
  void stopTimer();
  void pauseTimer();
  void unpauseTimer();

  //gets timer's time
  int get_ticks();

  //checks status of timer
  bool is_started();
  bool is_paused();
};

#endif
