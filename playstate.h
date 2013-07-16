//introstate.h
#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include <SDL/SDL.h>
#include "gamestate.h"
#include "Surface.h"
#include "GameObject.h"
#include "Bat.h"
#include "Timer.h"
#include "constants.h"
#include "Ball.h"

class PlayState : public GameState {
    
    private:
        Bat myBat1;
        
        Bat myBat2;
        
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

  static PlayState* Instance() {
    return &m_PlayState;
  }

 protected:
  PlayState() { } 

 private:
  static PlayState m_PlayState;


};

#endif
