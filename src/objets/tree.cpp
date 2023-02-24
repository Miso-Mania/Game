#include "tree.h"

Tree::Tree(int x, int y) {
    m_rect.x = x;
    m_rect.y = y;

    m_rect={x,y};
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

