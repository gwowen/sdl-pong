#include "GameObject.h"

std::vector<GameObject*> GameObject::ObjectList;

GameObject::GameObject() {
    
  objectBox.x = 0;
  objectBox.y = 0;
  objectBox.w = 0;
  objectBox.h = 0;
  imgObject = NULL;

}

GameObject::~GameObject() {

}
void GameObject::Load( std::string file, int x, int y, int width, int height ) {
  objectBox.x = x;
  objectBox.y = y;
  objectBox.w = width;
  objectBox.h = height;

}

void GameObject::Event() {
}

void GameObject::Render( SDL_Surface* renderDest ) {
  Surface::surfaceDraw( objectBox.x, objectBox.y, imgObject, renderDest );
}

void GameObject::Cleanup() {
  SDL_FreeSurface( imgObject );
  imgObject = NULL;
}





 
