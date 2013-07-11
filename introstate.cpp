//introstate.cpp 
#include <stdio.h>

#include <SDL/SDL.h>
#include "gameengine.h"
#include "gamestate.h"
#include "introstate.h"
#include "playstate.h"

IntroState IntroState::m_IntroState;

void IntroState::Init() {
  SDL_Surface* temp = SDL_LoadBMP( "start.bmp" );

  bg = SDL_DisplayFormat( temp );

  SDL_FreeSurface( temp );

  printf( "IntroState Init\n" );
}

void IntroState::Cleanup() {
  SDL_FreeSurface( bg );
  printf( "IntroState cleanup\n" );
}

void IntroState::Pause() {
  printf( "IntroState Pause\n" );
}

void IntroState::Resume() {
  printf( "IntroState Resume\n" );
}

void IntroState::HandleEvents( GameEngine* game ) {

  SDL_Event event;

  if( SDL_PollEvent( &event ) ) {
    switch( event.type ) {
    case SDL_QUIT:
      game->Quit();
      break;

    case SDL_KEYDOWN:
      switch( event.key.keysym.sym ) {
      case SDLK_SPACE:
	game->ChangeState( PlayState::Instance() );
	break;

      case SDLK_ESCAPE:
	game->Quit();
	break;
        
       default:break;
      }
      break;
    }
  }
}


void IntroState::Update( GameEngine * game ) {

}

void IntroState::Draw( GameEngine* game ) {
  SDL_BlitSurface( bg, NULL, game->screen, NULL );

  SDL_UpdateRect( game->screen, 0, 0, 0, 0 );
}

