#include "player.h"
#include <iostream>
Player::Player(): m_coords(3, 15, 0.8, 0.8), m_rect({100, 600, 32, 32}), m_yVelocity(0), m_direction(PlayerDirection::NONE) {
}

Player::~Player() {
}

void Player::move(double delta) {
    if (m_direction == PlayerDirection::LEFT) {
        m_coords.x -= 5 * delta;
    } else if (m_direction == PlayerDirection::RIGHT) {
        m_coords.x += 5 * delta;
    }
}
// saute
// le joeur ne peut pas faire de double saut
// le joeur ne peut pas sauter si il n'est pas sur le sol
void Player::jump() {
    if (!haveJumped && timeSinceTouchGround < 0.2) {
        m_yVelocity = -13;
        haveJumped = true;
    } else {
        jumpBuffer = 0.1;
    }
}

void Player::gravity(double delta) {
    m_yVelocity += 25 * delta;
   m_coords.y += m_yVelocity * delta;
}

bool Player::collidesWith(Obstacle *obstacle) {
    Coords o_coords = obstacle->getCoords();
    if (m_coords.x + m_coords.w >= o_coords.x && m_coords.x <= o_coords.x + o_coords.w) {
        if (m_coords.y + m_coords.h >= o_coords.y  && m_coords.y <= o_coords.y + o_coords.h) {
            return true;
        }
    }
    //on fait la collision verticale avec les obstacles
        
    return false;
}

bool Player::collidesWith(Pic *pic) {
    Coords p_coords = pic->getCoords();
    if (m_coords.x + m_coords.w > p_coords.x && m_coords.x < p_coords.x + p_coords.w) {
        if (m_coords.y + m_coords.h > p_coords.y && m_coords.y < p_coords.y + p_coords.h) {
            return true;
        }
    }
    return false;
}

bool Player::collidesWith(DoubleJumpPort *DoubleJumpPort){
    SDL_Rect DoubleJumpPortRect= DoubleJumpPort->getRect();
    if (m_coords.x + m_coords.w > DoubleJumpPortRect.x && m_coords.x < DoubleJumpPortRect.x + DoubleJumpPortRect.w) {
        if (m_coords.y + m_coords.h > DoubleJumpPortRect.y && m_coords.y < DoubleJumpPortRect.y + DoubleJumpPortRect.h) {
            return true;
        }
    }
    return false;

    }

void Player::moveOutOf(Obstacle *obstacle){
    Coords o_coords = obstacle->getCoords();
    double intoTop = m_coords.y + m_coords.h - o_coords.y;
    double intoBottom = o_coords.y + o_coords.h - m_coords.y;
    double intoLeft = m_coords.x + m_coords.w - o_coords.x;
    double intoRight = o_coords.x + o_coords.w - m_coords.x;
    if (intoTop < intoBottom && intoTop < intoLeft && intoTop < intoRight) {
        m_coords.y -= intoTop;
        stopGravity();
        haveJumped = false;
        timeSinceTouchGround = 0;
        if (jumpBuffer > 0) {
            jump();
            jumpBuffer = 0;
        }
    } else if (intoBottom < intoTop && intoBottom < intoLeft && intoBottom < intoRight) {
        m_coords.y += intoBottom + 1;
        stopGravity();
    } else if (intoLeft < intoTop && intoLeft < intoBottom && intoLeft < intoRight) {
        m_coords.x -= intoLeft;
    } else if (intoRight < intoTop && intoRight < intoBottom && intoRight < intoLeft) {
        m_coords.x += intoRight;
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

void Player::doubleJump() {
    if (haveJumped) {
        m_yVelocity = -530;
        haveJumped = false;
    }
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
    m_coords.x = x;
    m_coords.y = y;
}

void Player::updateRect(){
    m_rect.x = m_coords.x * 40;
    m_rect.y = m_coords.y * 40;
}



