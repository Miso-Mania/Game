#ifndef PLAYER_H
#define PLAYER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "objets/obstacle.h"
#include "playerdirection.h"
#include "objets/pic.h"
#include "objets/BoxFinish.h"


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
    /// @brief fonction qui permet de savoir si le joueur est en collision avec une pic
    bool collidesWith(Pic *pic);
    /// @brief fonction qui permet de repousse le joueur si il est en collision avec un obstacle
    void moveOutOf(Obstacle *obstacle);
    /// @brief fonction qui permet de set la direction du joueur
    void setDirection(PlayerDirection direction);
    /// @brief fonction qui permet d'arreter la gravité
    void stopGravity();
    /// @brief fonction qui permet d'arreter le mouvement du joueur
    void stopMove();
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
    double phX, phY;
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
