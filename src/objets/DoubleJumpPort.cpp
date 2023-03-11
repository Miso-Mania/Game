#include "DoubleJumpPort.h"

DoubleJumpPort::DoubleJumpPort(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 1, 1);
    m_rect.x = x * TILE_SIZE;
    m_rect.y = y * TILE_SIZE;
    m_rect.w = TILE_SIZE;
    m_rect.h = TILE_SIZE;
}

DoubleJumpPort::~DoubleJumpPort() {
}

void DoubleJumpPort::move(double delta) {
}

void DoubleJumpPort::push_back(DoubleJumpPort* DoubleJumpPort) {
}

SDL_Rect DoubleJumpPort::getRect() {
    return m_rect;
}

Coords DoubleJumpPort::getCoords() {
    return m_coords;
}
