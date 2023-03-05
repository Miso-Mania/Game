#include "M_Plateform.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

M_Plateform::M_Plateform(int x, int y) {
    m_rect.x = x;
    m_rect.y = y;
    m_rect.w = 5;
    m_rect.h = 1;
}

M_Plateform::~M_Plateform() {
}

void M_Plateform::move(double delta) {
}

void M_Plateform::push_back(M_Plateform* M_Plateform) {
}

SDL_Rect M_Plateform::getRect() {
    return m_rect;
}

