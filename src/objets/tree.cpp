#include "tree.h"

Tree::Tree(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 3, 2);
    m_rect.x = x * TILE_SIZE;
    m_rect.y = y * TILE_SIZE;
    m_rect.w = 3 * TILE_SIZE;
    m_rect.h = 2 * TILE_SIZE;
}

Tree::~Tree() {
}

void Tree::move(double delta) {
}

void Tree::push_back(Tree* Tree) {
}

SDL_Rect Tree::getRect() {
    return m_rect;
}

Coords Tree::getCoords() {
    return m_coords;
}