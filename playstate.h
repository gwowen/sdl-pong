//introstate.h
#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include <SDL/SDL.h>
#include "gamestate.h"

class PlayState : public GameState {

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

  SDL_Surface* bg;

};

#endif
