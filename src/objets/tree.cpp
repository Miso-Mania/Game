#include "tree.h"

Tree::Tree(int x, int y, int TILE_SIZE) {
    m_rect.x = x;
    m_rect.y = y;
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

