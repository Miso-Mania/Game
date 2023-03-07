#include "player.h"

Player::Player(): phX(100), phY(600), m_rect({100, 600, 32, 32}), m_yVelocity(0), m_direction(PlayerDirection::NONE) {
}

Player::~Player() {
}

void Player::move(double delta) {
    if (m_direction == PlayerDirection::LEFT) {
        phX -= 200 * delta;
    } else if (m_direction == PlayerDirection::RIGHT) {
        phX += 200 * delta;
    }
}
// saute
// le joeur ne peut pas faire de double saut
// le joeur ne peut pas sauter si il n'est pas sur le sol
void Player::jump() {
    if (!haveJumped && timeSinceTouchGround < 0.2) {
        m_yVelocity = -530;
        haveJumped = true;
    } else {
        jumpBuffer = 0.1;
    }
}

void Player::gravity(double delta) {
    m_yVelocity += 1000 * delta;
   phY += m_yVelocity * delta;
}

bool Player::collidesWith(Obstacle *obstacle) {
    SDL_Rect obstacleRect = obstacle->getRect();
    if (phX + m_rect.w >= obstacleRect.x && phX <= obstacleRect.x + obstacleRect.w) {
        if (phY + m_rect.h >= obstacleRect.y -7  && phY <= obstacleRect.y + obstacleRect.h) {
            return true;
        }
    }
    //on fait la collision verticale avec les obstacles
        
    return false;
}

bool Player::collidesWith(Pic *pic) {
    SDL_Rect picRect = pic->getRect();
    if (phX + m_rect.w > picRect.x && phX < picRect.x + picRect.w) {
        if (phY + m_rect.h > picRect.y && phY < picRect.y + picRect.h) {
            return true;
        }
    }
    return false;
}

void Player::moveOutOf(Obstacle *obstacle){
    SDL_Rect obstacleRect = obstacle->getRect();
    int intoTop = phY + m_rect.h - obstacleRect.y;
    int intoBottom = obstacleRect.y + obstacleRect.h - phY;
    int intoLeft = phX + m_rect.w - obstacleRect.x;
    int intoRight = obstacleRect.x + obstacleRect.w - phX;
    if (intoTop < intoBottom && intoTop < intoLeft && intoTop < intoRight && intoTop > 0) {
        phY -= intoTop;
        stopGravity();
        haveJumped = false;
        timeSinceTouchGround = 0;
        if (jumpBuffer > 0) {
            jump();
            jumpBuffer = 0;
        }
    } else if (intoBottom < intoTop && intoBottom < intoLeft && intoBottom < intoRight) {
        phY += intoBottom + 1;
        stopGravity();
    } else if (intoLeft < intoTop && intoLeft < intoBottom && intoLeft < intoRight) {
        phX -= intoLeft;
    } else if (intoRight < intoTop && intoRight < intoBottom && intoRight < intoLeft) {
        phX += intoRight;
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

void Player::moveTo(double x, double y){
    phX = x;
    phY = y;
}

void Player::updateRect(){
    m_rect.x = phX;
    m_rect.y = phY;
}



