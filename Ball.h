/* 
 * File:   Ball.h
 * Author: gareth
 *
 * Created on 15 June 2013, 19:07
 */

#ifndef BALL_H
#define	BALL_H
#include "GameObject.h"

class Ball: public GameObject {
    
    public:
        int ballXVel;
        int ballYVel;
    
    public:
        Ball();
        
        bool Load( std:: string file, int x, int y, int width, int height );
        
        void Loop( Uint32 deltaTicks, SDL_Rect batBox1, SDL_Rect batBox2 );
        
        void Render( SDL_Surface* renderDest );
        
        bool Collide( SDL_Rect collisionTarget );
        
        void Cleanup();
};



#endif	/* BALL_H */

