#include "enemy.h"
#include <iostream>
#include <assert.h>
using namespace std;

Enemy:: Enemy (int x, int y, int TILE_SIZE): hasCollided(false), m_direction(EnemyDirection::NONE), m_yVelocity(0), timeSinceTouchGround(0), jumpBuffer(0), isOnGround(false), oldIsOnGround(false) {
    m_coords = Coords(x, y, 2, 2);
    m_rect.x = x * TILE_SIZE;
    m_rect.y = y * TILE_SIZE;
    m_rect.w = TILE_SIZE;
    m_rect.h = TILE_SIZE;
}

Enemy:: ~Enemy () {
}

void Enemy::move(double delta) {
    if (m_direction == EnemyDirection::LEFT) {
        m_coords.x -= 5 * delta;
    } else if (m_direction == EnemyDirection::RIGHT) {
        m_coords.x += 5 * delta;
    }
}

void Enemy::push_back (Case* Case) {
}

void Enemy::gravity(double delta) {
    m_yVelocity += 25 * delta;
   m_coords.y += m_yVelocity * delta;
}

bool Enemy::collidesWith(Case *Case) {
    return m_coords.isColliding(Case->getCoords());
}

void Enemy::moveOutOfCoords(Coords coords){
    double intoTop = m_coords.y + m_coords.h - coords.y;
    double intoBottom = coords.y + coords.h - m_coords.y;
    double intoLeft = m_coords.x + m_coords.w - coords.x;
    double intoRight = coords.x + coords.w - m_coords.x;
    if (intoTop < intoBottom && intoTop < intoLeft && intoTop < intoRight) {
        m_coords.y -= intoTop;
        stopGravity();
        haveJumped = false;
        timeSinceTouchGround = 0;
        isOnGround = true;
        hasCollided = true;
    } else if (intoBottom < intoTop && intoBottom < intoLeft && intoBottom < intoRight) {
        m_coords.y += intoBottom;
        stopGravity();
    } else if (intoLeft < intoTop && intoLeft < intoBottom && intoLeft < intoRight) {
        m_coords.x -= intoLeft;
    } else if (intoRight < intoTop && intoRight < intoBottom && intoRight < intoLeft) {
        m_coords.x += intoRight;
    }
}

void Enemy::stopGravity() {
    m_yVelocity = 0;
}

void Enemy::stopMove() {
    m_direction = EnemyDirection::NONE;
}

void Enemy::moveOutOf(Case *Case) {
    moveOutOfCoords(Case->getCoords());
}

void Enemy::moveTo(double x, double y){
    m_coords.x = x;
    m_coords.y = y;
}

void Enemy::updateRect(){
    m_rect.x = m_coords.x * 40;
    m_rect.y = m_coords.y * 40;
    m_rect.w = m_coords.w * 40;
    m_rect.h = m_coords.h * 40;
}

bool Enemy::getIsOnGround() const {
    return isOnGround;
}

bool Enemy::showParticlesOnLand() {
    bool r = !oldIsOnGround && isOnGround;
    if (!hasCollided) {
        isOnGround = false;
    }
    oldIsOnGround = isOnGround;
    return r;
}

SDL_Rect Enemy::getRect() {
    return m_rect;
}












