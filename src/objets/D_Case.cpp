#include "D_Case.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

D_Case::D_Case(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 2, 2);
    m_rect.x = x * TILE_SIZE;
    m_rect.y = y * TILE_SIZE;
    m_rect.w = 2 * TILE_SIZE;
    m_rect.h = 2 * TILE_SIZE;
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

Coords D_Case::getCoords() {
    return m_coords;
}