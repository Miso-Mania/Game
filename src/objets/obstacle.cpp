#include "obstacle.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Obstacle::Obstacle(int x, int y, int width, int height) {
    m_rect.x = x;
    m_rect.y = y;
    m_rect.w = width;
    m_rect.h = height;
}

Obstacle::~Obstacle() {
}

void Obstacle::move(double delta) {
}

void Obstacle::push_back(Obstacle* obstacle) {
}

SDL_Rect Obstacle::getRect() {
    return m_rect;
}

