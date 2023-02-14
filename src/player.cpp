#include "player.h"

Player::Player(): m_rect({0, 0, 32, 32}), m_yVelocity(0) {
}

Player::~Player() {
}

void Player::move(double delta) {
    if (m_direction == PlayerDirection::LEFT) {
        m_rect.x -= 200 * delta;
    } else if (m_direction == PlayerDirection::RIGHT) {
        m_rect.x += 200 * delta;
    }
}

void Player::jump() {
    m_yVelocity = -500;
}

void Player::gravity(double delta) {
    m_yVelocity += 1000 * delta;
    m_rect.y += m_yVelocity * delta;
}

bool Player::collidesWith(Obstacle *obstacle) {
    SDL_Rect obstacleRect = obstacle->getRect();
    if (m_rect.x + m_rect.w >= obstacleRect.x && m_rect.x <= obstacleRect.x + obstacleRect.w) {
        if (m_rect.y + m_rect.h >= obstacleRect.y && m_rect.y <= obstacleRect.y + obstacleRect.h) {
            return true;
        }
    }
    return false;
}

bool Player::collidesWith(Pic *pic) {
    SDL_Rect picRect = pic->getRect();
    if (m_rect.x + m_rect.w >= picRect.x && m_rect.x <= picRect.x + picRect.w) {
        if (m_rect.y + m_rect.h >= picRect.y && m_rect.y <= picRect.y + picRect.h) {
            return true;
        }
    }
    return false;
}


void Player::stopGravity() {
    m_yVelocity = 0;
}

void Player::setDirection(PlayerDirection direction) {
    m_direction = direction;
}

PlayerDirection Player::getDirection() {
    return m_direction;
}

SDL_Rect Player::getRect() {
    return m_rect;
}








