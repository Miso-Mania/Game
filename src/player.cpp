#include "player.h"

Player::Player(): m_rect({100, 600, 32, 32}), m_yVelocity(0), m_direction(PlayerDirection::NONE) {
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
    if (canJump && timeSinceTouchGround < 0.2) {
        m_yVelocity = -500;
        canJump = false;
    } else {
        jumpBuffer = 0.2;
    }
}

void Player::gravity(double delta) {
    m_yVelocity += 1000 * delta;
    m_rect.y += m_yVelocity * delta;
}

bool Player::collidesWith(Obstacle *obstacle) {
    SDL_Rect obstacleRect = obstacle->getRect();
    if (m_rect.x + m_rect.w >= obstacleRect.x && m_rect.x <= obstacleRect.x + obstacleRect.w) {
        if (m_rect.y + m_rect.h >= obstacleRect.y -7  && m_rect.y <= obstacleRect.y + obstacleRect.h) {
            return true;
        }
    }
    //on fait la collision verticale avec les obstacles
        
    return false;
}

bool Player::collidesWith(Pic *pic) {
    SDL_Rect picRect = pic->getRect();
    if (m_rect.x + m_rect.w > picRect.x && m_rect.x < picRect.x + picRect.w) {
        if (m_rect.y + m_rect.h > picRect.y && m_rect.y < picRect.y + picRect.h) {
            return true;
        }
    }
    return false;
}

void Player::moveOutOf(Obstacle *obstacle){
    SDL_Rect obstacleRect = obstacle->getRect();
    int intoTop = m_rect.y + m_rect.h - obstacleRect.y;
    int intoBottom = obstacleRect.y + obstacleRect.h - m_rect.y;
    int intoLeft = m_rect.x + m_rect.w - obstacleRect.x;
    int intoRight = obstacleRect.x + obstacleRect.w - m_rect.x;
    if (intoTop < intoBottom && intoTop < intoLeft && intoTop < intoRight) {
        m_rect.y -= intoTop;
        stopGravity();
        canJump = true;
        timeSinceTouchGround = 0;
        if (jumpBuffer > 0) {
            jump();
            jumpBuffer = 0;
        }
    } else if (intoBottom < intoTop && intoBottom < intoLeft && intoBottom < intoRight) {
        m_rect.y += intoBottom + 1;
        stopGravity();
    } else if (intoLeft < intoTop && intoLeft < intoBottom && intoLeft < intoRight) {
        m_rect.x -= intoLeft;
    } else if (intoRight < intoTop && intoRight < intoBottom && intoRight < intoLeft) {
        m_rect.x += intoRight;
    }
}

void Player::incTimeSinceTouchGround(double delta) {
    timeSinceTouchGround += delta;
}

void Player::decJumpBuffer(double delta) {
    if (jumpBuffer > 0) jumpBuffer -= delta;
}

void Player::stopGravity() {
    m_yVelocity = 0;
}

void Player::stopMove() {
    m_direction = PlayerDirection::NONE;
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

void Player::setRect(SDL_Rect rect) {
    m_rect = rect;
}






