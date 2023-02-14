#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SDL2/SDL.h>

class Obstacle {
public:
    Obstacle(int x, int y, int width, int height);
    ~Obstacle();
    void push_back(Obstacle* obstacle);
    SDL_Rect getRect();
    void move(double delta);

private:
    SDL_Rect m_rect;
};

#endif // OBSTACLE_H