#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "coords.h"
#include "objets/Case.h"
#include "objets/D_Case.h"
#include "objets/BoxCmgtGrav.h"
#include "enemydirection.h"

class Enemy {
    public:
    Enemy (int x, int y, int TILE_SIZE);
    ~Enemy();
    void move(double delta);
    void push_back(Case* Case);
    void gravity(double delta);
    bool collidesWith(Case *Case);
    void moveOutOf(Case *Case);
    void moveOutOfCoords(Coords coords);
    void stopGravity();
    void stopMove();
    void moveTo(double x, double y);
    void updateRect();
    bool getIsOnGround() const;
    bool showParticlesOnLand();
    SDL_Rect getRect();
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
