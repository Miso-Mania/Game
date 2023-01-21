#ifndef SQUARE_H
#define SQUARE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>



class Square
{
public:
    int x, y;

    int Red, Green, Blue;
    Square();
    ~Square();
    /* void init() const;  
    void update();
    void render() const;
    void handleEvent(SDL_Event event);
    void clean();

private:
    SDL_Rect m_rect;
    SDL_Color m_color;
    SDL_Renderer* m_renderer; */
};
#endif
