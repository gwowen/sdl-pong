//gameengine.h - game engine
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SDL/SDL.h>

#include <vector>

using namespace std;

class GameState;

class GameEngine {
public:
  void Init( const char* title, int width = 640, int height = 480,
	     int bpp = 0 );
  void Cleanup();

  void ChangeState( GameState* state );
  void PushState( GameState* state );
  void PopState();

  void HandleEvents();
  void Update();
  void Draw();

  bool Running() { return m_running; }
  void Quit() { m_running = false; }

  SDL_Surface* screen;

private:
  //the stack of states
  vector<GameState*> states;

  bool m_running;

};



#endif
