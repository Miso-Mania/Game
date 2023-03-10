#include "pic.h"

Pic::Pic(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 1, 1);
    
    m_triangle.x = x * TILE_SIZE;
    m_triangle.y = y * TILE_SIZE;
    // definit la taille et la forme du pic
    m_triangle.w = TILE_SIZE;
    m_triangle.h = TILE_SIZE;

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

Coords Pic::getCoords() {
    return m_coords;
}
