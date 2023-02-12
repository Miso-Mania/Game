#ifndef SCREEN_H
#define SCREEN_H

#include <stdint.h>
#include <SDL2/SDL.h>

class Screen {
public:
    virtual ~Screen();
    virtual void update(double delta) = 0;
    virtual void render(SDL_Renderer *renderer) = 0;
    virtual void handleEvents(SDL_Event &event) = 0;
};

#endif


