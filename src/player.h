#ifndef PLAYER_H
#define PLAYER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "objets/obstacle.h"
#include "playerdirection.h"
#include "objets/pic.h"
#include "objets/BoxFinish.h"


class Player {
public:
    Player ();
    ~Player();
    void move(double delta);
    void jump();
    void gravity(double delta);
    bool collidesWith(Obstacle *obstacle);
    bool collidesWith(Pic *pic);
    void moveOutOf(Obstacle *obstacle);
    void setDirection(PlayerDirection direction);
    void stopGravity();
    void stopMove();
    PlayerDirection getDirection();
    SDL_Rect getRect();
    void setRect(SDL_Rect rect);
    void incTimeSinceTouchGround(double delta);
    void decJumpBuffer(double delta);


private:
    SDL_Rect m_rect;
    double m_yVelocity;
    PlayerDirection m_direction;
    double timeSinceTouchGround;
    double jumpBuffer;
    bool canJump;
};

#endif // PLAYER_H
