//playstate.cpp 
//STANDARD LIBRARY INCLUDES
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

//GAME STATE INCLUDES
#include "gamestate.h"
#include "gameengine.h"
#include "playstate.h"
#include "introstate.h"

//GAME OBJECT/DRAWING CODE INCLUDES
#include "Surface.h"
#include "GameObject.h"
#include "Bat.h"
#include "Timer.h"
#include "constants.h"
#include "Ball.h"

PlayState PlayState::m_PlayState;

//=============================================================================
//INIT ROUTINE
//=============================================================================
void PlayState::Init() {
  //SDL_Surface* temp = IMG_Load( "play.bmp" );
  
  myBat1.Load( "bat.png", 20, 20, 10, 101);
  
  myBat2.Load( "bat.png", 620, 20, 10, 101);
  
  myBall.Load( "ball.png", 400, 300, 20, 20);
  
  GameObject::ObjectList.push_back( &myBat1 );
  GameObject::ObjectList.push_back( &myBat2 );
  GameObject::ObjectList.push_back( &myBall );
  
  delta.startTimer();

  //bg = SDL_DisplayFormat( temp );

  //SDL_FreeSurface( temp );

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
      
      if( event.type == SDL_QUIT ) {
          game->Quit();
      }

    if( event.type == SDL_KEYDOWN ) {
      switch( event.key.keysym.sym ) {
                case SDLK_w: myBat1.batYVel -= BAT_VEL; break;
                case SDLK_s: myBat1.batYVel += BAT_VEL; break;
                case SDLK_UP: myBat2.batYVel -= BAT_VEL; break;
                case SDLK_DOWN: myBat2.batYVel += BAT_VEL; break;
                case SDLK_ESCAPE: game->Quit();
          case SDLK_SPACE: game->ChangeState( IntroState::Instance() );
      default: break;
      }
    }
    else if( event.type == SDL_KEYUP ) {
	switch( event.key.keysym.sym ) {
                case SDLK_w: myBat1.batYVel += BAT_VEL; break;
                case SDLK_s: myBat1.batYVel -= BAT_VEL; break;
                case SDLK_UP: myBat2.batYVel += BAT_VEL; break;
                case SDLK_DOWN: myBat2.batYVel -= BAT_VEL; break;
	default: break;
	}
      }
  }
    /*switch( event.type ) {
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
  }*/
  
}

//==============================================================================
//MAIN GAME LOOP
//==============================================================================
void PlayState::Update( GameEngine * game ) {
    myBat1.Loop( delta.get_ticks() );
    myBat2.Loop( delta.get_ticks() );
    myBall.Loop( delta.get_ticks(), myBat1.objectBox, myBat2.objectBox );
    delta.startTimer();
}

//==============================================================================
//RENDERING CODE
//==============================================================================
void PlayState::Draw( GameEngine* game ) {
  //SDL_BlitSurface( bg, NULL, game->screen, NULL );
    SDL_FillRect( game->screen, &game->screen->clip_rect, 
            SDL_MapRGB( game->screen->format, 0xFF, 0xFF, 0xFF ));
    
    for( int i = 0; i < GameObject::ObjectList.size(); i++ ) {
        if( !GameObject::ObjectList[ i ] ) continue;
        GameObject::ObjectList[ i ]->Render( game->screen );
    }
    
    SDL_Flip( game->screen );
    
    if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ) {
        SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
    }

  //SDL_UpdateRect( game->screen, 0, 0, 0, 0 );
}
