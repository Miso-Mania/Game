#include "L_Plateform.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

L_Plateform::L_Plateform(int x, int y, int TILE_SIZE) {
    m_rect.x = x;
    m_rect.y = y;
    m_rect.w = 7 * TILE_SIZE;
    m_rect.h = TILE_SIZE;
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

