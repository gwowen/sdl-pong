//playstate.cpp 
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "gamestate.h"
#include "gameengine.h"
#include "playstate.h"
#include "introstate.h"

PlayState PlayState::m_PlayState;

//=============================================================================
//INIT ROUTINE
//=============================================================================
void PlayState::Init() {
  SDL_Surface* temp = IMG_Load( "play.bmp" );

  bg = SDL_DisplayFormat( temp );

  SDL_FreeSurface( temp );

  printf( "PlayState Init\n" );
}

//==============================================================================
//CLEANUP ROUTINE
//==============================================================================
void PlayState::Cleanup() {
  SDL_FreeSurface( bg );
  printf( "PlayState cleanup\n" );
}

void PlayState::Pause() {
  printf( "PlayState Pause\n" );
}

void PlayState::Resume() {
  printf( "PlayState Resume\n" );
}

//==============================================================================
//EVENTS HANDLER
//==============================================================================
void PlayState::HandleEvents( GameEngine* game ) {

  SDL_Event event;

  if( SDL_PollEvent( &event ) ) {
    switch( event.type ) {
    case SDL_QUIT:
      game->Quit();
      break;

    case SDL_KEYDOWN:
      switch( event.key.keysym.sym ) {
      case SDLK_SPACE:
	game->ChangeState( IntroState::Instance() );
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

//==============================================================================
//MAIN GAME LOOP
//==============================================================================
void PlayState::Update( GameEngine * game ) {

}

//==============================================================================
//RENDERING CODE
//==============================================================================
void PlayState::Draw( GameEngine* game ) {
  SDL_BlitSurface( bg, NULL, game->screen, NULL );

  SDL_UpdateRect( game->screen, 0, 0, 0, 0 );
}
