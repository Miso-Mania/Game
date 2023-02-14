#ifndef PIC_H
#define PIC_H

#include <SDL2/SDL.h>

class Pic {
public:
    Pic(int x, int y);
    ~Pic();
    void push_back(Pic* pic);
    SDL_Rect getRect();
    void move(double delta);

private:
    SDL_Rect m_triangle;
    int width;
    int height;
};

#endif // PIC_H