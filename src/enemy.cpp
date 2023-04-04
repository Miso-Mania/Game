#include "enemy.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <assert.h>
using namespace std;

Enemy::Enemy():m_direction(EnemyDirection::NONE) {
    m_coords = Coords();
    m_rect = SDL_Rect();
}

Enemy::Enemy(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 1, 1);
    m_rect.x = x * TILE_SIZE;
    m_rect.y = y * TILE_SIZE;
    m_rect.w = TILE_SIZE;
    m_rect.h = TILE_SIZE;
}

Enemy::~Enemy() {
}

void Enemy::move(double delta) {
    if (m_direction == EnemyDirection::LEFT) {
        m_coords.x -= 5 * delta;
    } else if (m_direction == EnemyDirection::RIGHT) {
        m_coords.x += 5 * delta;
    }
}

void Enemy::push_back(Enemy* Enemy) {
}

bool Enemy::collidesWith(Case *Case) {
    return m_coords.isColliding(Case->getCoords());
}

//fonction qui permet de repousser le joueur selon les coordonnées et de le faire avancer dans le sens opposé
void Enemy::moveOutOfCoords(Coords coords) {
    if (m_coords.isColliding(coords)) {
        if (m_coords.x < coords.x) {
            m_coords.x = coords.x - m_coords.w;
        } else if (m_coords.x > coords.x) {
            m_coords.x = coords.x + coords.w;
        }
        if (m_coords.y < coords.y) {
            m_coords.y = coords.y - m_coords.h;
        } else if (m_coords.y > coords.y) {
            m_coords.y = coords.y + coords.h;
        }
    }
}

void Enemy::moveOutOf(Case *Case) {
    moveOutOfCoords(Case->getCoords());
}

SDL_Rect Enemy::getRect() {
    return m_rect;
}

Coords Enemy::getCoords() {
    return m_coords;
}

void Enemy::setDirection(EnemyDirection direction) {
    m_direction = direction;
}

EnemyDirection Enemy::getDirection() {
    return m_direction;
}











