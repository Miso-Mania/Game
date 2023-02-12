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
    void update(double delta);
    void render(SDL_Renderer *renderer);
    void handleEvents(SDL_Event &event);
    void jump();
    bool collidesWith(Obstacle *obstacle);
    void setDirection(PlayerDirection direction);

private:
    SDL_Rect m_rect;
    double m_yVelocity;
    PlayerDirection m_direction;
};

#endif // PLAYER_H
