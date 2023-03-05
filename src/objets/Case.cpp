#include "Case.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Case::Case(int x, int y) {
    m_rect.x = x;
    m_rect.y = y;
    m_rect.w = 1;
    m_rect.h = 1;
}

Case::~Case() {
}

void Case::move(double delta) {
}

void Case::push_back(Case* Case) {
}

SDL_Rect Case::getRect() {
    return m_rect;
}

