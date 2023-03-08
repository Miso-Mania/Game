#include "S_Plateform.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

S_Plateform::S_Plateform(int x, int y, int TILE_SIZE) {
    m_rect.x = x;
    m_rect.y = y;
    m_rect.w = 3 * TILE_SIZE    ;
    m_rect.h = TILE_SIZE;
}

S_Plateform::~S_Plateform() {
}

void S_Plateform::move(double delta) {
}

void S_Plateform::push_back(S_Plateform* S_Plateform) {
}

SDL_Rect S_Plateform::getRect() {
    return m_rect;
}

Coords S_Plateform::getCoords() {
    return m_coords;
}
