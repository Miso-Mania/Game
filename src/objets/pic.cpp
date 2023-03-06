#include "pic.h"

Pic::Pic(int x, int y, int TILE_SIZE) {
    m_triangle.x = x;
    m_triangle.y = y;
    // definit la taille et la forme du pic
    width = TILE_SIZE;
    height = TILE_SIZE;

    m_triangle={x,y,width,height};
}

Pic::~Pic() {
}

void Pic::move(double delta) {
}

void Pic::push_back(Pic* pic) {
}

SDL_Rect Pic::getRect() {
    return m_triangle;
}

