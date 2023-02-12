#include "obstacle.h"

Obstacle::Obstacle(int x, int y, int width, int height) {
    m_rect.x = x;
    m_rect.y = y;
    m_rect.w = width;
    m_rect.h = height;
}

Obstacle::~Obstacle() {
}

void Obstacle::update(double delta) {
}

void Obstacle::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &m_rect);
}

SDL_Rect Obstacle::getRect() {
    return m_rect;
}

