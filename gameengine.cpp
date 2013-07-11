//gameengine.cpp 
#include <stdio.h>

#include <SDL/SDL.h>
#include "gameengine.h"
#include "gamestate.h"

void GameEngine::Init( const char* title, int width, int height, int bpp ) {

  SDL_Init( SDL_INIT_EVERYTHING );

  SDL_WM_SetCaption( title, title );

  screen = SDL_SetVideoMode( width, height, bpp, 0 );

  m_running = true;

  printf( "GameEngine init\n" );

}

void GameEngine::Cleanup() {
  //cleanup all states
  while( !states.empty() ) {
    states.back()->Cleanup();
    states.pop_back(); 
      }

  printf( "GameEngine cleanup\n" );

  SDL_Quit();
}

void GameEngine::ChangeState( GameState* state ) {
  //cleanup current state
  if( !states.empty() ) {
    states.back()->Cleanup();
    states.pop_back();
  }

  //store and init new state
  states.push_back( state );
  states.back()->Init();
}

void GameEngine::PushState( GameState* state ) {
  //pause current state
  if( !states.empty() ) {
    states.back()->Pause();
  }

  //store and init new state
  states.push_back( state );
  states.back()->Init();
}

void GameEngine::PopState() {
  //cleanup current state
  if( !states.empty() ) {
    states.back()->Cleanup();
    states.pop_back();
  }

  //resume previous state
  if( !states.empty() ) {
    states.back()->Resume();
  }
}

void GameEngine::HandleEvents() {
  //let the state handle events
  states.back()->HandleEvents( this );
}

void GameEngine::Update() {
  //let the state update the game
  states.back()->Update( this );
}

void GameEngine::Draw() {
  //let the state draw the screen
  states.back()->Draw( this );
}

    

