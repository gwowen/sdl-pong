//introstate.h
#ifndef PLAYSTATEAI_H
#define PLAYSTATEAI_H

#include <SDL/SDL.h>
#include "gamestate.h"
#include "Surface.h"
#include "GameObject.h"
#include "Bat.h"
#include "Timer.h"
#include "constants.h"
#include "Ball.h"

class PlayStateAI : public GameState {
    
    private:
        Bat myBat1;
        
        Bat AIBat;
        
        Ball myBall;
        
        Timer delta;
        
        Timer fps;

 public:
  void Init();
  void Cleanup();
  
  void Pause();
  void Resume();

  void HandleEvents( GameEngine* game );
  void Update( GameEngine* game );
  void Draw( GameEngine* game );

  static PlayStateAI* Instance() {
    return &m_PlayStateAI;
  }

 protected:
  PlayStateAI() { } 

 private:
  static PlayStateAI m_PlayStateAI;



};

#endif
