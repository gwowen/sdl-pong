#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include <SDL/SDL.h>
#include <vector>
#include <string>
#include "Surface.h"
#include "constants.h"

class GameObject {

 protected:

  SDL_Surface* imgObject;
public:
  static std::vector<GameObject*> ObjectList;

  SDL_Rect objectBox;

  int objXVel;
  int objYVel;

 public:
  GameObject();

  virtual ~GameObject();

 public:
  virtual void Load( std::string file, int x, int y, int width, int height );

  //virtual void Loop( Uint32 deltaTicks );

  virtual void Event();

  virtual void Render( SDL_Surface* renderDest );

  virtual void Cleanup();

};

#endif
