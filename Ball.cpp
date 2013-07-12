//==============================================================================
//Ball.cpp - implementation of ball object
//==============================================================================
#include "Ball.h"

Ball::Ball() {
    ballXVel = BALL_VEL;
    ballYVel = BALL_VEL;
}

void Ball::Load( std::string file, int x, int y, int width, int height ) {
    GameObject::Load( file, x, y, width, height );
    }

void Ball::Loop( Uint32 deltaTicks, SDL_Rect batBox1, SDL_Rect batBox2 ) {
{
  objectBox.x += ballXVel * ( deltaTicks / 1000.f );

  if( objectBox.x < 0 )
    {
       objectBox.x = 0;
       ballXVel = -ballXVel;
      
    }
  else if( objectBox.x + objectBox.w > SCREEN_WIDTH )
    {
       objectBox.x = SCREEN_WIDTH - objectBox.w;
       ballXVel = -ballXVel;
    }
  
  objectBox.y += ballYVel * ( deltaTicks/ 1000.f );

  if ( objectBox.y < 0 )
    {
      objectBox.y = 0;
      ballYVel = -ballYVel;
    }
  else if( objectBox.y + objectBox.h > SCREEN_HEIGHT )
    {
      objectBox.y = SCREEN_HEIGHT - objectBox.h;
      ballYVel = -ballYVel;
    }
  
  else if( Collide( batBox1 ) || Collide( batBox2 ) ) {
      ballXVel = -ballXVel;
  }
}
    
}

void Ball::Render( SDL_Surface* renderDest ) {
    GameObject::Render( renderDest );
}

bool Ball::Collide( SDL_Rect collisionTarget ) {
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    
    leftA = objectBox.x;
    rightA = objectBox.x + objectBox.w;
    topA = objectBox.y;
    bottomA = objectBox.y + objectBox.h;
    
    leftB = collisionTarget.x;
    rightB = collisionTarget.x + collisionTarget.w;
    topB = collisionTarget.y;
    bottomB = collisionTarget.y + collisionTarget.h;
    
    if( bottomA <= topB )
    {
      return false;
    }

  if (topA >= bottomB )
    {
      return false;
    }

  if( rightA <= leftB )
    {
      return false;
    }

  if( leftA >= rightB )
    {
      return false;
    }

  return true;
    
}


void Ball::Cleanup() {
    GameObject::Cleanup();
}