#ifndef PLAYER_H
#define PLAYER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "obstacle.h"
#include "playerdirection.h"

class Player {
public:
    Player ();
    ~Player();
    void move(double delta);
    void jump();
    void gravity(double delta);
    bool collidesWith(Obstacle *obstacle);
    void setDirection(PlayerDirection direction);
    void stopGravity();
    PlayerDirection getDirection();
    SDL_Rect getRect();

private:
    SDL_Rect m_rect;
    double m_yVelocity;
    PlayerDirection m_direction;
};

#endif // PLAYER_H
