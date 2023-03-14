# include "BoxCmgtGrav.h"

BoxCmgtGrav::BoxCmgtGrav(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 1, 3);
    
    m_rect.x = x * TILE_SIZE;
    m_rect.y = y * TILE_SIZE;
    // definit la taille et la forme de la box
    m_rect.w = TILE_SIZE;
    m_rect.h = 3*TILE_SIZE;

}

BoxCmgtGrav::~BoxCmgtGrav() {
}

void BoxCmgtGrav::move(double delta) {
}

void BoxCmgtGrav::push_back(BoxCmgtGrav* BoxCmgtGrav) {
}

SDL_Rect BoxCmgtGrav::getRect() {
    return m_rect;
}

Coords BoxCmgtGrav::getCoords() {
    return m_coords;
}
