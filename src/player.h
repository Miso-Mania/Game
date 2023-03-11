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


class Player {
public:
    /// @brief constructeur de la classe Player
    Player ();
    /// @brief destructeur de la classe Player
    ~Player();
    /// @brief fonction qui permet de déplacer le joueur
    void move(double delta);
    /// @brief fonction qui permet de sauter
    void jump();
    /// @brief fonction qui permet d'appliquer la gravité au joueur
    void gravity(double delta);
    /// @brief fonction qui permet de savoir si le joueur est en collision avec un obstacle
    bool collidesWith(Obstacle *obstacle);
    /// @brief fonction qui permet de savoir si le joeur est en collision avec une S_Plateform
    bool collidesWith(S_Plateform *S_Plateform);
    ///@brief fonction qui permet de savoir si le joeur est en collision avec une M_Plateform
    bool collidesWith(M_Plateform *M_Plateform);
    ///@brief fonction qui permet de savoir si le joueur est en collision avec une L_Plateform
    bool collidesWith(L_Plateform *L_Plateform);
    /// @brief fonction qui permet de savoir si le joueur est en collision avec une pic
    bool collidesWith(Pic *pic);
    /// @brief fonction qui permet de savoir si le joeur est en collision avec le doublejumpport
    bool collidesWith(DoubleJumpPort *doubleJumpPort);
    /// @brief fonction qui permet de savoir si le joeur est en collision avec une Case
    bool collidesWith(Case *Case);
    /// @brief fonction qui permet de savoir si le joeur est en collision avec une D_Case
    bool collidesWith(D_Case *D_Case);
    /// @brief fonction qui permet de savoir si le joeur est en collision avec une BoxFinish
    bool collidesWith(BoxFinish *boxFinish);
    /// @brief fonction qui permet de repousser le joueur si il est en collision avec un obstacle
    void moveOutOf(Obstacle *obstacle);
    /// @brief fonction qui permet de repousser le joueur si il est en collision avec une S_Plateform
    void moveOutOf(S_Plateform *S_Plateform);
    /// @brief fonction qui permet de repousser le joueur si il est en collision avec une M_Plateform
    void moveOutOf(M_Plateform *M_Plateform);
    /// @brief fonction qui permet de repousser le joueur si il est en collision avec une L_Plateform
    void moveOutOf(L_Plateform *L_Plateform);
    /// @brief fonction qui permet de repousser le joueur si il est en collision avec une Case
    void moveOutOf(Case *Case);
    /// @brief fonction qui permet de repousser le joueur si il est en collision avec unu D_Case
    void moveOutOf(D_Case *D_Case);
    /// @brief fonction qui permet de repousser le joueur selon les coordonnées
    void moveOutOfCoords(Coords coords);
    /// @brief fonction qui permet de set la direction du joueur
    void setDirection(PlayerDirection direction);
    /// @brief fonction qui permet d'arreter la gravité
    void stopGravity();
    /// @brief fonction qui permet d'arreter le mouvement du joueur
    void stopMove();
    /// @brief fonction qui permet au joueur de faire un double saut
    void doubleJump();
    /// @brief fonction qui permet de connaitre la direction du joueur
    PlayerDirection getDirection();
    /// @brief fonction qui permet de connaitre les coordonnées du joueur
    SDL_Rect getRect();
    /// @brief fonction qui permet de déplacer le joueur a des coordonnées précises
    void setRect(SDL_Rect rect);
    /// @brief fonction qui permet de connaitre le temps depuis que le joueur n'est plus au sol
    void incTimeSinceTouchGround(double delta);
    //todo : faire la docu ici
    void decJumpBuffer(double delta);

    void moveTo(double x, double y);

    void updateRect();


private:
    Coords m_coords;
    /// @brief coordonnées du joueur
    SDL_Rect m_rect;
    /// @brief velocité du joueur
    double m_yVelocity;
    /// @brief direction du joueur
    PlayerDirection m_direction;
    /// @brief temps depuis que le joueur n'est plus au sol
    double timeSinceTouchGround;
    //todo : faire la docu ici
    double jumpBuffer;
    /// @brief booléen qui permet de savoir si le joueur a déja sauté
    bool haveJumped;
};

#endif // PLAYER_H
