#include "enemy.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <assert.h>
using namespace std;

Enemy::Enemy() {
    m_coords = Coords();
    m_rect = SDL_Rect();
}

Enemy::Enemy(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 2, 1);
    m_rect.x = x * TILE_SIZE;
    m_rect.y = y * TILE_SIZE;
    m_rect.w = 2 * TILE_SIZE;
    m_rect.h = 3 * TILE_SIZE;
}

Enemy::~Enemy() {
}

void Enemy::push_back(Enemy* Enemy) {
}



SDL_Rect Enemy::getRect() {
    return m_rect;
}

Coords Enemy::getCoords() {
    return m_coords;
}







