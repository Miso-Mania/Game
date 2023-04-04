#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "coords.h"
#include "objets/Case.h"
#include "objets/D_Case.h"
#include "enemydirection.h"

class Enemy {
    public:
    /**
    @brief constructeur par défaut de la classe Enemy
    @param aucun
    */
    Enemy();
/**
    @brief constructeur de la classe Enemy, en paramètre les coordonnées de l'enemy
    @param int x, int y, int TILE_SIZE
    */
    Enemy(int x, int y, int TILE_SIZE);
/**
    @brief destructeur de la classe Enemy
    @param aucun
    */
    ~Enemy();
/**
    @brief fonction qui permet de renvoyer l'enemy
    @param Enemy* Enemy
    */
    void push_back(Enemy* Enemy);
/**
    @brief fonction qui permet de récupérer les coordonnées de l'enemy
    @param aucun
    @return SDL_Rect
    */
    SDL_Rect getRect();
/**
    @brief fonction qui permet de déplacer l'enemy automatiquement
    @param double delta
    */
    void move(double delta);
/**
    @brief fonction qui permet de déplacer l'enemy automatiquement
    @param aucun
    */
    void move();
    
/**
    @brief fonction qui permet de savoir si le joeur est en collision avec une Case
    @param Case *Case
    @return bool
    */
    bool collidesWith(Case *Case);
/**
    @brief fonction qui permet de repousser le joueur selon les coordonnées
    @param Coords coords
    */
    void moveOutOfCoords(Coords coords);
/**
    @brief fonction qui permet de repousser le joueur si il est en collision avec une Case
    @param Case *Case
    */
    void moveOutOf(Case *Case);
/**
    @brief fonction qui permet de récupérer les coordonnées de l'enemy
    @param aucun
    @return Coords
    */
    Coords getCoords();
/**
    @brief fonction qui permet de set la direction de l'enemy
    @param EnemyDirection direction
    */
    void setDirection(EnemyDirection direction);
/**
    @brief fonction qui permet de connaitre la direction de l'enemy
    @param aucun
    @return PlayerDirection
    */
    EnemyDirection getDirection();

private:
    Coords m_coords; // coordonnées de l'enemy
    SDL_Rect m_rect; // rectangle de l'enemy
    EnemyDirection m_direction; // direction de l'enemy

};

#endif
