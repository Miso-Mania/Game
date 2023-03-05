#include "D_Case.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

D_Case::D_Case(int x, int y) {
    m_rect.x = x;
    m_rect.y = y;
    m_rect.w = 2;
    m_rect.h = 2;
}

D_Case::~D_Case() {
}

void D_Case::move(double delta) {
}

void D_Case::push_back(D_Case* D_Case) {
}

SDL_Rect D_Case::getRect() {
    return m_rect;
}

