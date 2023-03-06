#include "BoxFinish.h"

BoxFinish::BoxFinish(int x, int y, int TILE_SIZE) {
    m_triangle.x = x;
    m_triangle.y = y;
    width = TILE_SIZE;
    height = 2 * TILE_SIZE;

    m_triangle={x,y,width,height};
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

