#include "obstacle.h"
#include "../coords.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Obstacle::Obstacle(int x, int y, int width, int height) {
    m_coords = Coords(x, y, width, height);
    m_rect.x = x * 40;
    m_rect.y = y * 40;
    m_rect.w = width * 40;
    m_rect.h = height * 40;
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

Coords Obstacle::getCoords() {
    return m_coords;
}
