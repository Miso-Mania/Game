#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "coords.h"
#include "objets/Case.h"
#include "objets/D_Case.h"

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
    @brief fonction qui permet de récupérer les coordonnées de l'enemy
    @param aucun
    @return Coords
    */
    Coords getCoords();

private:
    Coords m_coords; // coordonnées de l'enemy
    SDL_Rect m_rect; // rectangle de l'enemy

};

#endif
