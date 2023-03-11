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
    return m_coords.isColliding(obstacle->getCoords());
}

bool Player::collidesWith(S_Plateform *S_Plateform) {
    return m_coords.isColliding(S_Plateform->getCoords());
}

bool Player::collidesWith(M_Plateform *M_Plateform) {
    return m_coords.isColliding(M_Plateform->getCoords());
}

bool Player::collidesWith(L_Plateform *L_Plateform) {
    return m_coords.isColliding(L_Plateform->getCoords());
}

bool Player::collidesWith(Pic *Pic) {
    return m_coords.isColliding(Pic->getCoords());
}

bool Player::collidesWith(DoubleJumpPort *DoubleJumpPort){
    return m_coords.isColliding(DoubleJumpPort->getCoords());
}

bool Player::collidesWith(Case *Case) {
    return m_coords.isColliding(Case->getCoords());
}

bool Player::collidesWith(D_Case *D_Case) {
    return m_coords.isColliding(D_Case->getCoords());
}

bool Player::collidesWith(BoxFinish *BoxFinish) {
    return m_coords.isColliding(BoxFinish->getCoords());
}

void Player::moveOutOfCoords(Coords coords){
    double intoTop = m_coords.y + m_coords.h - coords.y;
    double intoBottom = coords.y + coords.h - m_coords.y;
    double intoLeft = m_coords.x + m_coords.w - coords.x;
    double intoRight = coords.x + coords.w - m_coords.x;
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
        m_coords.y += intoBottom;
        stopGravity();
    } else if (intoLeft < intoTop && intoLeft < intoBottom && intoLeft < intoRight) {
        m_coords.x -= intoLeft;
    } else if (intoRight < intoTop && intoRight < intoBottom && intoRight < intoLeft) {
        m_coords.x += intoRight;
    }
}

void Player::moveOutOf(Obstacle *obstacle){
    moveOutOfCoords(obstacle->getCoords());
}

void Player::moveOutOf(S_Plateform *S_Plateform){
    moveOutOfCoords(S_Plateform->getCoords());
}

void Player::moveOutOf(M_Plateform *M_Plateform){
    moveOutOfCoords(M_Plateform->getCoords());
}

void Player::moveOutOf(L_Plateform *L_Plateform){
    moveOutOfCoords(L_Plateform->getCoords());
}

void Player::moveOutOf(Case *Case){
    moveOutOfCoords(Case->getCoords());
}

void Player::moveOutOf(D_Case *D_Case){
    moveOutOfCoords(D_Case->getCoords());
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
        m_yVelocity = -13;
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



