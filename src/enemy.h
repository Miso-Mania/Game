#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "coords.h"
#include "objets/obstacle.h"
#include "objets/BoxFinish.h"
#include "objets/DoubleJumpPort.h"
#include "objets/S_Plateform.h"
#include "objets/M_Plateform.h"
#include "objets/L_Plateform.h"
#include "objets/Case.h"
#include "objets/D_Case.h"
#include "objets/BoxCmgtGrav.h"
#include "enemydirection.h"

class Enemy {
    public:
    /**
    @brief constructeur de la classe Player
    @param int x, int y, int TILE_SIZE
    */
    Enemy (int x, int y, int TILE_SIZE);
/**
    @brief destructeur de la classe Player
    @param aucun
    */
    ~Enemy();
/**
    @brief fonction qui permet de déplacer le joueur
    @param double delta
    */
    void move(double delta);
    void Enemy::gravity(double delta);
/**
    @brief fonction qui permet de savoir si le joeur est en collision avec une Case
    @param Case *Case
    @return bool
    */
    bool collidesWith(Case *Case);
/**
    @brief fonction qui permet de repousser le joueur si il est en collision avec une Case
    @param Case *Case
    */
    void moveOutOf(Case *Case);
/**
/**
    @brief fonction qui permet de repousser le joueur selon les coordonnées
    @param Coords coords
    */
    void moveOutOfCoords(Coords coords);
    void stopGravity();
/**
    @brief fonction qui permet d'arreter le mouvement du joueur
    @param aucun
    */
    void stopMove();
    EnemyDirection Enemy::getDirection();
    SDL_Rect Enemy::getRect();
    double Enemy::getGravity();
    void Enemy::setGravity(double gravity);
/**
    @brief setJumpBuffer du joueur
    @param double jumpBuffer
    */
    void setJumpBuffer(double jumpBuffer);
/**
    @brief setTimeSinceTouchGround du joueur 
    @param double timeSinceTouchGround
    */
    void setTimeSinceTouchGround(double timeSinceTouchGround);
/**
    @brief fonction qui permet de déplacer le joueur a des coordonnées précises
    @param SDL_Rect rect
    */
    void setRect(SDL_Rect rect);
/**
    @brief incTimeSinceTouchGround du joueur
    @param double delta
    */
    void incTimeSinceTouchGround(double delta);
/**
    @brief decJumpBuffer du joueur
    @param double delta
    */
    void decJumpBuffer(double delta);
/**
    @brief moveTo permet de déplacer le joueur a des coordonnées précises
    @param double x, double y
    */
    void moveTo(double x, double y);
/**
    @brief updateRect permet de mettre a jour les coordonnées du joueur
    @param aucun
    */
    void updateRect();
/**
    @brief fonction qui retourne les coordonnées du joueur
    */
    Coords getCoords() const;
/**
    @brief fonction qui retourne onGround
    @return bool
    */
    bool getIsOnGround() const;
    bool showParticlesOnLand();

    bool hasCollided;
    

private:
    Coords m_coords; // Coordonnées du joueur
    SDL_Rect m_rect; // Rectangle du joueur
    double m_yVelocity; // Vitesse verticale du joueur
    double timeSinceTouchGround; // Temps depuis que le joueur est en contact avec le sol
    double jumpBuffer; // Temps avant que le joueur puisse sauter
    bool haveJumped; // Booléen qui permet de savoir si le joueur a sauté
    bool isOnGround; // Booléen qui permet de savoir si le joueur est en contact avec le sol
    bool oldIsOnGround; // Booléen qui permet de savoir si le joueur était en contact avec le sol avant la derniere update
    EnemyDirection m_direction; // Direction du joueur

};

#endif
