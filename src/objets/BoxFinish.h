#ifndef BOXFINISH_H
#define BOXFINISH_H

#include <SDL2/SDL.h>

class BoxFinish {
public:
    BoxFinish(int x, int y);
    ~BoxFinish();
    void push_back(BoxFinish* pic);
    SDL_Rect getRect();
    void move(double delta);

private:
    SDL_Rect m_triangle;
    int width;
    int height;
};

#endif // BOXFINISH_H