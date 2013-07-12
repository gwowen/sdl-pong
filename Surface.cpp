//==============================================================================
//Surface.cpp
//==============================================================================
#include "Surface.h"

Surface::Surface() {
}

SDL_Surface* Surface::surfaceLoad( std::string filename ) {
  
  SDL_Surface* tempImage = NULL;

  SDL_Surface* optimisedImage = NULL;

  tempImage = IMG_Load( filename.c_str() );

  if( tempImage != NULL )
    {
      optimisedImage = SDL_DisplayFormat( tempImage );

      SDL_FreeSurface( tempImage );

      if( optimisedImage != NULL )
	{
	  Uint32 colorKey = SDL_MapRGB( optimisedImage->format, 0, 0xFF, 0xFF );

	  SDL_SetColorKey( optimisedImage, SDL_SRCCOLORKEY, colorKey );
	}
    }

  return optimisedImage;
}

bool Surface::surfaceDraw( int x, int y, SDL_Surface* source, SDL_Surface* destination ) {

  if( source == NULL || destination == NULL ) {
    printf( "Source is null" );
    return false;
  }

  SDL_Rect blitLoc;

  blitLoc.x = x;
  blitLoc.y = y;

  SDL_BlitSurface( source, NULL, destination, &blitLoc );

  return true;
}
