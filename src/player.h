#ifndef PLAYER_H
#define PLAYER_H
#include <SDL2/SDL.h>

class Player {
public:
    Player();
    ~Player();
    void moveLeft();
    void moveRight();
    void jump();
    void uptadePosition();
    void draw(SDL_Renderer *renderer);
    SDL_Rect getRect();
private:
    SDL_Rect rect;
    int speed_x, speed_y;
};

#endif // PLAYER_H
