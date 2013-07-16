//=============================================================================
//Bat.h - inherits from GameObject
//=============================================================================
#ifndef _BAT_H_
#define _BAT_H_

#include "GameObject.h"

class Bat: public GameObject {
    public:
        int batXVel;
        int batYVel;
        int batRealMiddle;
 public:
  Bat();

  void Load( std::string file, int x, int y, int width, int height );

  void Loop( Uint32 deltaTicks);

  void Render( SDL_Surface* renderDest );

  void Cleanup();
};

#endif
