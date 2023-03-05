#include "BoxFinish.h"

BoxFinish::BoxFinish(int x, int y) {
    m_triangle.x = x;
    m_triangle.y = y;
    width = 1;
    height = 2;

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

