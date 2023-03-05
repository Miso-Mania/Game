#include "L_Plateform.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

L_Plateform::L_Plateform(int x, int y) {
    m_rect.x = x;
    m_rect.y = y;
    m_rect.w = 7;
    m_rect.h = 1;
}

L_Plateform::~L_Plateform() {
}

void L_Plateform::move(double delta) {
}

void L_Plateform::push_back(L_Plateform* L_Plateform) {
}

SDL_Rect L_Plateform::getRect() {
    return m_rect;
}

