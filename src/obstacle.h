#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Obstacle {
public:
    Obstacle(int x, int y, int width, int height);
    ~Obstacle();
    void update(double delta);
    void render(SDL_Renderer *renderer);
    SDL_Rect getRect();
    void push_back(Obstacle* obstacle);

private:
    SDL_Rect m_rect;
};

#endif // OBSTACLE_H