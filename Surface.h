//==============================================================================
//Surface.h - contains surface functions
//==============================================================================
#ifndef _SURFACE_H_
#define _SURFACE_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string>

//==============================================================================
class Surface {
 public:
  Surface();

 public:
  static SDL_Surface* surfaceLoad( std::string filename );

  static bool surfaceDraw( int x, int y, SDL_Surface* source, SDL_Surface* destination );

};
//==============================================================================
#endif
