#ifndef PLAYER_H
#define PLAYER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Player {
public:
    Player (int x, int y, int w, int h);
    ~Player();
    void handleEvent(SDL_Event& e);
    void move();
    void render(SDL_Renderer* renderer);
    SDL_Rect getRect();
    void onCollision(SDL_Rect platformRect);
    void update();
private:
    int mVelX, mVelY;
    int mPosX, mPosY;
    int WIDTH, HEIGHT;
    SDL_Rect rect;
    bool isJumping;
    int jumpHeight;
    int jumpSpeed;
};

#endif // PLAYER_H
