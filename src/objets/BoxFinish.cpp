#include "BoxFinish.h"

BoxFinish::BoxFinish(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 1, 2);
    m_triangle.x = x * TILE_SIZE;
    m_triangle.y = y * TILE_SIZE;
    m_triangle.w = TILE_SIZE;
    m_triangle.h = 2 * TILE_SIZE;
}

BoxFinish::~BoxFinish() {
}

void BoxFinish::move(double delta) {
}

void BoxFinish::push_back(BoxFinish* BoxFinish) {
}

SDL_Rect BoxFinish::getRect() {
    return m_triangle;
}

Coords BoxFinish::getCoords() {
    return m_coords;
}