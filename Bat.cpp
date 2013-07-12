//==============================================================================
//Bat.cpp - implementation of bat object
//==============================================================================
#include "Bat.h"

Bat::Bat() {
    batXVel = 0;
    batYVel = 0;
}

bool Bat::Load( std::string file, int x, int y, int width, int height ) {
  if( !GameObject::Load( file, x, y, width, height ) ) {
      printf("Failed to load bat object\n");
    return false;
  }

  return true;
}

void Bat::Loop( Uint32 deltaTicks ) {
  //GameObject::Loop( deltaTicks );
     objectBox.y += batYVel * ( deltaTicks/ 1000.f );
  if ( objectBox.y < 0 )
    {
      objectBox.y = 0;
    }
   
  else if( objectBox.y + objectBox.h > SCREEN_HEIGHT )
    {
     objectBox.y = SCREEN_HEIGHT - objectBox.h;
    }
}

void Bat::Render( SDL_Surface* renderDest ) {
  GameObject::Render( renderDest );
}

void Bat::Cleanup() {
  GameObject::Cleanup();
}
