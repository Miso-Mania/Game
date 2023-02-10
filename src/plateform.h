#ifndef PLATFORM_H
#define PLATFORM_H
#include <SDL2/SDL.h>

class Platform {
public:
    Platform();
    Plateform(int x, int y, int w, int h);
    ~Platform();
    void draw(SDL_Renderer *renderer);
    SDL_Rect getRect();
    bool isColliding(Player player);
private:
    SDL_Rect rect;
};

#endif // PLATFORM_H
