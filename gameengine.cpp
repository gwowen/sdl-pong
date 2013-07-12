//gameengine.cpp 
#include <stdio.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "gameengine.h"
#include "gamestate.h"

bool GameEngine::Init( const char* title, int width, int height, int bpp ) {

  if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
      printf( "Failed to start SDL/n");
      return false;
  }

  SDL_WM_SetCaption( title, title );

  if( ( screen = SDL_SetVideoMode( width, height, bpp, 0 ) ) == NULL ) {
      printf( "Failed to create screen\n");
      return false;
  }

  m_running = true;

  printf( "GameEngine init\n" );
  
  return true;

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

    

