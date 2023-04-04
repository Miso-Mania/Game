#ifndef PLAYER_H
#define PLAYER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "objets/obstacle.h"
#include "playerdirection.h"
#include "objets/pic.h"
#include "objets/BoxFinish.h"
#include "objets/DoubleJumpPort.h"
#include "coords.h"
#include "objets/S_Plateform.h"
#include "objets/M_Plateform.h"
#include "objets/L_Plateform.h"
#include "objets/Case.h"
#include "objets/D_Case.h"
#include "objets/BoxCmgtGrav.h"
#include "enemy.h" 


class Player {
public:
/**
    @brief constructeur de la classe Player
    @param aucun
    */
    Player ();
/**
    @brief destructeur de la classe Player
    @param aucun
    */
    ~Player();
/**
    @brief fonction qui permet de déplacer le joueur
    @param double delta
    */
    void move(double delta);
/**
    @brief fonction qui permet de sauter
    @param aucun
    */
    void jump();
/**
    @brief fonction qui permet d'appliquer la gravité au joueur
    @param double delta
    */
    void gravity(double delta);
/**
    @brief fonction qui permet de savoir si le joueur est en collision avec un obstacle
    @param Obstacle *obstacle
    @return bool
    */
    bool collidesWith(Obstacle *obstacle);
/** 
    @brief fonction qui permet de savoir si le joeur est en collision avec une S_Plateform
    @param S_Plateform *S_Plateform
    @return bool
    */
    bool collidesWith(S_Plateform *S_Plateform);
/**
    @brief fonction qui permet de savoir si le joeur est en collision avec une M_Plateform
    @param M_Plateform *M_Plateform
    @return bool
    */
    bool collidesWith(M_Plateform *M_Plateform);
/**
    @brief fonction qui permet de savoir si le joueur est en collision avec une L_Plateform
    @param L_Plateform *L_Plateform
    @return bool
    */
    bool collidesWith(L_Plateform *L_Plateform);
/**
    @brief fonction qui permet de savoir si le joueur est en collision avec une pic
    @param Pic *pic
    @return bool
    */
    bool collidesWith(Pic *pic);
/**
    @brief fonction qui permet de savoir si le joueur est en collision avec un enemy
    @param Enemy *Enemy
    @return bool
    */
    bool collidesWith(Enemy *Enemy);
/**
    @brief fonction qui permet de savoir si le joeur est en collision avec le doublejumpport
    @param DoubleJumpPort *doubleJumpPort
    @return bool
    */
    bool collidesWith(DoubleJumpPort *doubleJumpPort);
/**
    @brief fonction qui permet de savoir si le joeur est en collision avec une Case
    @param Case *Case
    @return bool
    */
    bool collidesWith(Case *Case);
/**
    @brief fonction qui permet de savoir si le joeur est en collision avec une D_Case
    @param D_Case *D_Case
    @return bool
    */
    bool collidesWith(D_Case *D_Case);
/**
    @brief fonction qui permet de savoir si le joeur est en collision avec une BoxFinish
    @param BoxFinish *boxFinish
    @return bool
    */
    bool collidesWith(BoxFinish *boxFinish);
/**
    @brief fonction qui permet de savoir si le joeur est en collision avec une BoxCmgtGrav
    @param BoxCmgtGrav *BoxCmgtGrav
    @return bool
    */
    bool collidesWith(BoxCmgtGrav *BoxCmgtGrav);
/**
    @brief fonction qui permet de repousser le joueur si il est en collision avec un obstacle
    @param Obstacle *obstacle
    */
    void moveOutOf(Obstacle *obstacle);
/**
    @brief fonction qui permet de repousser le joueur si il est en collision avec une S_Plateform
    @param S_Plateform *S_Plateform
    */
    void moveOutOf(S_Plateform *S_Plateform);
/**
    @brief fonction qui permet de repousser le joueur si il est en collision avec une M_Plateform
    @param M_Plateform *M_Plateform
    */
    void moveOutOf(M_Plateform *M_Plateform);
/**
    @brief fonction qui permet de repousser le joueur si il est en collision avec une L_Plateform
    @param L_Plateform *L_Plateform
    */
    void moveOutOf(L_Plateform *L_Plateform);
/**
    @brief fonction qui permet de repousser le joueur si il est en collision avec une Case
    @param Case *Case
    */
    void moveOutOf(Case *Case);
/**
    @brief fonction qui permet de repousser le joueur si il est en collision avec unu D_Case
    @param D_Case *D_Case
    */
    void moveOutOf(D_Case *D_Case);
/**
    @brief fonction qui permet de repousser le joueur si il est en collision avec une BoxCmgtGrav
    @param BoxCmgtGrav *BoxCmgtGrav
    */
    void moveOutOf(BoxCmgtGrav *BoxCmgtGrav);
/**
    @brief fonction qui permet de repousser le joueur selon les coordonnées
    @param Coords coords
    */
    void moveOutOfCoords(Coords coords);
/**
    @brief fonction qui permet de set la direction du joueur
    @param PlayerDirection direction
    */
    void setDirection(PlayerDirection direction);
/**
    @brief fonction qui permet d'arreter la gravité
    @param aucun
    */
    void stopGravity();
/**
    @brief fonction qui permet d'arreter le mouvement du joueur
    @param aucun
    */
    void stopMove();
/**
    @brief fonction qui permet au joueur de faire un double saut
    @param aucun
    */
    void doubleJump();
/**
    @brief fonction qui permet de connaitre la direction du joueur
    @param aucun
    @return PlayerDirection
    */
    PlayerDirection getDirection();
/**
    @brief fonction qui permet de connaitre les coordonnées du joueur
    @param aucun
    @return Coords
    */
    SDL_Rect getRect();
/**
    @brief fonction qui permet de connaitre la gravité du joueur
    @param aucun
    @return double
    */
    double getGravity();
/**
    @brief set la gravité du joueur
    @param double gravity
    */
    void setGravity(double gravity);
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
    @brief fonction qui fait des test de régréssion sur la classe
    @param aucun
    */
    void testRegression();

/**
    @brief fonction qui retourne les coordonnées du joueur
    */
    Coords getCoords() const;
/**
    @brief fonction qui retourne onGround
    @return bool
    */
    bool getIsOnGround() const;
/**
   @brief fonction qui retourne si il faut afficher les particules sur le sol
   @return bool
   */
    bool showParticlesOnLand();

    bool hasCollided;
    

private:
    Coords m_coords; // Coordonnées du joueur
    SDL_Rect m_rect; // Rectangle du joueur
    double m_yVelocity; // Vitesse verticale du joueur
    PlayerDirection m_direction; // Direction du joueur
    double timeSinceTouchGround; // Temps depuis que le joueur est en contact avec le sol
    double jumpBuffer; // Temps avant que le joueur puisse sauter
    bool haveJumped; // Booléen qui permet de savoir si le joueur a sauté
    bool isOnGround; // Booléen qui permet de savoir si le joueur est en contact avec le sol
    bool oldIsOnGround; // Booléen qui permet de savoir si le joueur était en contact avec le sol avant la derniere update
};

#endif // PLAYER_H
