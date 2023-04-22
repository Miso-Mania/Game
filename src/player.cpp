#include "player.h"
#include <iostream>
#include <assert.h>
Player::Player(): hasCollided(false), m_coords(1, 23, 1.44, 1.44), m_rect({100, 600, 38, 38}), m_yVelocity(0), m_direction(PlayerDirection::NONE), timeSinceTouchGround(0), jumpBuffer(0), isOnGround(false), oldIsOnGround(false) {
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

void Player::jump() {
    if (!haveJumped && timeSinceTouchGround < 0.2) {
        m_yVelocity = -13;
        haveJumped = true;
        isOnGround = false;
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

bool Player::collidesWith(BoxCmgtGrav *BoxCmgtGrav) {
    return m_coords.isColliding(BoxCmgtGrav->getCoords());
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

void Player::moveOutOf(BoxCmgtGrav *BoxCmgtGrav){
    moveOutOfCoords(BoxCmgtGrav->getCoords());
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

double Player::getGravity() {
    return m_yVelocity;
}

void Player::setGravity(double gravity) {
    m_yVelocity = gravity;
}

void Player::setJumpBuffer(double jumpBuffer) {
    this->jumpBuffer = jumpBuffer;
}

void Player::setTimeSinceTouchGround(double timeSinceTouchGround) {
    this->timeSinceTouchGround = timeSinceTouchGround;
}

void Player::moveTo(double x, double y){
    m_coords.x = x;
    m_coords.y = y;
}

void Player::updateRect(){
    m_rect.x = m_coords.x * 40;
    m_rect.y = m_coords.y * 40;
    m_rect.w = m_coords.w * 40;
    m_rect.h = m_coords.h * 40;
}

Coords Player::getCoords() const {
    return m_coords;
}

bool Player::getIsOnGround() const {
    return isOnGround;
}

bool Player::showParticlesOnLand() {
    bool r = !oldIsOnGround && isOnGround;
    if (!hasCollided) {
        isOnGround = false;
    }
    oldIsOnGround = isOnGround;
    return r;
}

void Player::testRegression () {
    // regresion test of the class Player
    std::cout <<"Test de Regression de la classe Player :"<<std::endl;
    std::cout<<"Test du constructeur de la classe Player:"<<std::endl;
    Player player = Player();
    assert(player.m_direction == PlayerDirection::NONE);
    assert(player.m_yVelocity == 0);
    assert(player.m_rect.x == 100);
    assert(player.m_rect.y == 600);
    assert(player.m_rect.w == 38);
    assert(player.m_rect.h == 38);
    assert(player.m_coords.x == 1);
    assert(player.m_coords.y == 23);
    assert(player.m_coords.w == 1.44);
    assert(player.m_coords.h == 1.44);
    std::cout<<"Test du constructeur de la classe Player reussi"<<std::endl;
    std::cout<<"Test du destructeur de la classe Player:"<<std::endl;
    player.~Player();
    assert(player.m_direction == PlayerDirection::NONE);
    assert(player.m_yVelocity == 0);
    assert(player.m_rect.x == 100);
    assert(player.m_rect.y == 600);
    assert(player.m_rect.w == 38);
    assert(player.m_rect.h == 38);
    assert(player.m_coords.x == 1);
    assert(player.m_coords.y == 23);
    assert(player.m_coords.w == 1.44);
    assert(player.m_coords.h == 1.44);
    std::cout<<"Test du destructeur de la classe Player reussi"<<std::endl;
    std::cout<<"Test de la methode move de la classe Player:"<<std::endl;
    Player p2 = Player();
    p2.move(0.1);
    if(p2.m_direction == PlayerDirection::RIGHT){
        assert(p2.m_coords.x == 3.1);
    }
    else if(p2.m_direction == PlayerDirection::LEFT){
        assert(p2.m_coords.x == 2.9);
    }
    else{
        assert(p2.m_coords.x == 1);
    }
    std::cout<<"Test de la methode move de la classe Player reussi"<<std::endl;
    std::cout<<"Test de la methode jump de la classe Player:"<<std::endl;
    Player p3 = Player();
    p3.jump();
    if (!p3.haveJumped && p3.timeSinceTouchGround < 0.2) {
        assert(p3.m_yVelocity == -13);
        assert(p3.haveJumped == true);
        assert (p3.isOnGround == false);
    }
    else{
        assert(p3.jumpBuffer == 0);
    }
    std::cout<<"Test de la methode jump de la classe Player reussi"<<std::endl;
    std::cout<<"Test de la methode gravity de la classe Player:"<<std::endl;
    Player p4 = Player();
    p4.gravity(1);
    assert(p4.m_yVelocity == 25);
    assert(p4.m_coords.y == 48);
    std::cout<<"Test de la methode gravity de la classe Player reussi"<<std::endl;
    std::cout <<"Test de la methode collidesWith de la classe Player:"<<std::endl;
    Player p5 = Player();
    bool x;
    bool y;
    Obstacle *obstacle = new Obstacle(1, 23, 1, 1);
    x = p5.collidesWith(obstacle);
    assert(x == 1);
    delete obstacle;
    Obstacle *obstacle2 = new Obstacle(12, 35, 1, 1);
    y = p5.collidesWith(obstacle2);
    assert(y == 0);
    delete obstacle2;
    std::cout<<"Test de la methode collidesWith de la classe Player reussi"<<std::endl;
    std::cout<<"Test de la methode moveOutOfCoords de la classe Player:"<<std::endl;
    Player p6 = Player();
    p6.moveOutOfCoords(Coords(1, 22, 1, 1));
    double intoTop= p6.m_coords.y + p6.m_coords.h - 22;
    double intoBottom = 22 + 1 - p6.m_coords.y;
    double intoLeft = p6.m_coords.x + p6.m_coords.w - 1;
    double intoRight = 1 + 1 - p6.m_coords.x;
    if (intoTop < intoBottom && intoTop < intoLeft && intoTop < intoRight){
        assert(p6.m_coords.y == -21.56);
        assert(p6.m_yVelocity == 0);
        bool x = p6.haveJumped;
        assert(x == 0);
        assert(p6.timeSinceTouchGround == 0);
        if (p6.jumpBuffer > 0) {
            if (!p6.haveJumped && p6.timeSinceTouchGround < 0.2) {
                assert(p6.m_yVelocity == -13);
                assert(p6.haveJumped == true);
                assert (p6.isOnGround == false);
            }
            else{
                assert(p6.jumpBuffer == 0);
                }
        assert (p6.jumpBuffer == 0);
        }
        assert (p6.isOnGround == true);
        assert (p6.hasCollided == true);

    }
    else if (intoBottom < intoTop && intoBottom < intoLeft && intoBottom < intoRight){
        assert(p6.m_coords.y == 23);
        assert(p6.m_yVelocity == 0);
    }
    else if (intoLeft < intoTop && intoLeft < intoBottom && intoLeft < intoRight){
        assert(p6.m_coords.x == -0.44);
    }
    else if (intoRight < intoTop && intoRight < intoBottom && intoRight < intoLeft){
        assert(p6.m_coords.x == 2.44);
    }
    else{
        assert(p6.m_coords.x == 1);
        assert(p6.m_coords.y == 22);
    }
    std::cout<<"Test de la methode moveOutOfCoords de la classe Player reussi"<<std::endl;
    std::cout<<"Test de la methode moveOutOf de la classe Player:"<<std::endl;
    Player p7 = Player();
    Obstacle *obstacle3 = new Obstacle(10, 35, 2, 2);
    p7.moveOutOf(obstacle3);
    double intoTop2= p7.m_coords.y + p7.m_coords.h - 35;
    double intoBottom2 = 35 + 2 - p7.m_coords.y;
    double intoLeft2 = p7.m_coords.x + p7.m_coords.w - 10;
    double intoRight2 = 10 + 2 - p6.m_coords.x;
    if (intoTop2 < intoBottom2 && intoTop2 < intoLeft2 && intoTop2 < intoRight2){
        assert(p7.m_coords.y == -34.56);
        assert(p7.m_yVelocity == 0);
        bool x = p7.haveJumped;
        assert(x == 0);
        assert(p7.timeSinceTouchGround == 0);
        if (p7.jumpBuffer > 0) {
            if (!p7.haveJumped && p7.timeSinceTouchGround < 0.2) {
                assert(p7.m_yVelocity == -13);
                assert(p7.haveJumped == true);
                assert (p7.isOnGround == false);
            }
            else{
                assert(p7.jumpBuffer == 0);
                }
        assert (p7.jumpBuffer == 0);
        }
        assert (p7.isOnGround == true);
        assert (p7.hasCollided == true);

    }
    else if (intoBottom2 < intoTop2 && intoBottom2 < intoLeft2 && intoBottom2 < intoRight2){
        assert(p7.m_coords.y == 37);
        assert(p7.m_yVelocity == 0);
    }
    else if (intoLeft2 < intoTop2 && intoLeft2 < intoBottom2 && intoLeft2 < intoRight2){
        assert(p7.m_coords.x == 1);
    }
    else if (intoRight2 < intoTop2 && intoRight2 < intoBottom2 && intoRight2 < intoLeft2){
        assert(p7.m_coords.x == 12.44);
    }
    else{
        assert(p7.m_coords.x == 10);
        assert(p7.m_coords.y == 35);
    }
    delete obstacle3;
    std::cout<<"Test de la methode moveOutOf de la classe Player reussi"<<std::endl;
    std::cout<<"Test de la methode incTimeSinceTouchGround de la classe Player:"<<std::endl;
    Player p8 = Player();
    p8.incTimeSinceTouchGround(0.1);
    assert(p8.timeSinceTouchGround == 0.1);
    std::cout<<"Test de la methode incTimeSinceTouchGround de la classe Player reussi"<<std::endl;
    std::cout<<"Test de la methode decJumpBuffer de la classe Player:"<<std::endl;
    Player p9 = Player();
    p9.decJumpBuffer(0.1);
    if (p9.jumpBuffer > 0){
        assert(p9.jumpBuffer == -0.9);
    }
    std::cout<< "Test de la methode decJumpBuffer de la classe Player reussi" << std::endl;
    std::cout<< "Test de la methode stopGravity de la classe Player:" << std::endl;
    Player p10 = Player();
    p10.stopGravity();
    assert(p10.m_yVelocity == 0);
    std::cout<< "Test de la methode stopGravity de la classe Player reussi" << std::endl;
    std::cout<< "Test de la methode stopMove de la classe Player:" << std::endl;
    Player p11 = Player();
    p11.stopMove();
    assert(p11.m_direction == PlayerDirection::NONE);
    std::cout<< "Test de la methode stopMove de la classe Player reussi" << std::endl;
    std::cout<< "Test de la methode doubleJump de la classe Player:" << std::endl;
    Player p12 = Player();
    p12.doubleJump();
    if (haveJumped) {
        assert(p12.m_yVelocity == -13);
        assert(p12.haveJumped == false);
    }
    std::cout<< "Test de la methode doubleJump de la classe Player reussi" << std::endl;
    std::cout<< "Test de la methode setDirection de la classe Player:" << std::endl;
    Player p13 = Player();
    p13.setDirection(PlayerDirection::LEFT);
    assert(p13.m_direction == PlayerDirection::LEFT);
    p13.setDirection(PlayerDirection::RIGHT);
    assert(p13.m_direction == PlayerDirection::RIGHT);
    p13.setDirection(PlayerDirection::NONE);
    assert(p13.m_direction == PlayerDirection::NONE);
    std::cout<< "Test de la methode setDirection de la classe Player reussi" << std::endl;
    std::cout<< "Test de la methode getDirection de la classe Player:" << std::endl;
    Player p14 = Player();
    PlayerDirection direction = p14.getDirection();
    assert(direction == PlayerDirection::NONE);
    std::cout<< "Test de la methode getDirection de la classe Player reussi" << std::endl;
    std::cout<< "Test de la methode getRect de la classe Player:" << std::endl;
    Player p15 = Player();
    SDL_Rect rect = p15.getRect();
    assert(rect.x == 100);
    assert(rect.y == 600);
    assert(rect.w == 38);
    assert(rect.h == 38);
    std::cout<< "Test de la methode getRect de la classe Player reussi" << std::endl;
    std::cout<< "Test de la methode setRect de la classe Player:" << std::endl;
    Player p16 = Player();
    SDL_Rect rect2 = {10, 20, 30, 40};
    p16.setRect(rect2);
    assert(p16.m_rect.x == 10);
    assert(p16.m_rect.y == 20);
    assert(p16.m_rect.w == 30);
    assert(p16.m_rect.h == 40);
    std::cout<< "Test de la methode setRect de la classe Player reussi" << std::endl;
    std::cout<< "Test de la methode getGravity de la classe Player:" << std::endl;
    Player p17 = Player();
    double gravity = p17.getGravity();
    assert(gravity == 0);
    std::cout<< "Test de la methode getGravity de la classe Player reussi" << std::endl;
    std::cout<< "Test de la methode setGravity de la classe Player:" << std::endl;
    Player p18 = Player();
    p18.setGravity(0.1);
    assert(p18.m_yVelocity == 0.1);
    std::cout<< "Test de la methode setGravity de la classe Player reussi" << std::endl;
    std::cout<< "Test de la methode setJumpBuffer de la classe Player:" << std::endl;
    Player p19 = Player();
    p19.setJumpBuffer(0.1);
    assert(p19.jumpBuffer == 0.1);
    std::cout<< "Test de la methode setJumpBuffer de la classe Player reussi" << std::endl;
    std::cout<< "Test de la methode moveTo de la classe Player:" << std::endl;
    Player p20 = Player();
    p20.moveTo(10, 20);
    assert(p20.m_coords.x == 10);
    assert(p20.m_coords.y == 20);
    std::cout<< "Test de la methode moveTo de la classe Player reussi" << std::endl;
    std::cout<< "Test de la methode updateRect de la classe Player:" << std::endl;
    Player p21 = Player();
    p21.updateRect();
    assert(p21.m_rect.x == 40);
    assert(p21.m_rect.y == 920);
    assert(p21.m_rect.w == 57);
    assert(p21.m_rect.h == 57);
    std::cout<< "Test de la methode updateRect de la classe Player reussi" << std::endl;
    std::cout<< "Test de la methode getCoords de la classe Player:" << std::endl;
    Player p22 = Player();
    Coords coords = p22.getCoords();
    assert(coords.x == 1);
    assert(coords.y == 23);
    assert(coords.w == 1.44);
    assert(coords.h == 1.44);
    std::cout<< "Test de la methode getCoords de la classe Player reussi" << std::endl;
    std::cout<<"Test de la methode getIsOnGround de la classe Player:"<<std::endl;
    Player p23 = Player();
    bool isOnGround = p23.getIsOnGround();
    assert(isOnGround == false);
    std::cout<< "Test de la methode getIsOnGround de la classe Player reussi" << std::endl;
    std::cout<<"Test de la methode showParticlesOnLand de la classe Player:"<<std::endl;
    Player p24 = Player();
    p24.showParticlesOnLand();
    bool r= !oldIsOnGround && isOnGround;
    if (hasCollided) {
        assert(isOnGround == false);
    }
    oldIsOnGround = isOnGround;
    assert(r == false);
    std::cout<< "Test de la methode showParticlesOnLand de la classe Player reussi" << std::endl;
}
