#include "DoubleJumpPort.h"

DoubleJumpPort::DoubleJumpPort(int x, int y, int TILE_SIZE) {
    m_rect.x = x;
    m_rect.y = y;
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

