//main.cpp
#include "gameengine.h"
#include "introstate.h"

int main( int argc, char *argv[] ) {
  GameEngine game;

  if(!game.Init( "Pong v3" )) {
      printf( "Game failed to initialize\n");
  }

  game.ChangeState( IntroState::Instance() );

  while( game.Running() ) {
    game.HandleEvents();
    game.Update();
    game.Draw();
  }

  game.Cleanup();

  return 0;
}
