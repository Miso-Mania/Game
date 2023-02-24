#include "tree.h"

Tree::Tree(int x, int y, int width, int height) {
    m_rect.x = x;
    m_rect.y = y;
    m_rect.w = width;
    m_rect.h = height;
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

