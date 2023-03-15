#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SDL2/SDL.h>
#include "../coords.h"

/// @brief classe Obstacle
class Obstacle {
public:
/**
    @brief constructeur par défaut de la classe Obstacle
    @param aucun
    */
    Obstacle();
/**
    @brief constructeur de la classe Obstacle, en paramètre les coordonnées de l'obstacle
    @param int x, int y, int width, int height
    */
    Obstacle(int x, int y, int width, int height);
/**
    @brief destructeur de la classe Obstacle
    @param aucun
    */
    ~Obstacle();
/**
    @brief fonction qui permet de renvoyer l'obstacle
    @param Obstacle* obstacle
    */
    void push_back(Obstacle* obstacle);
/**
    @brief fonction qui permet de récupérer les coordonnées de l'obstacle
    @param aucun
    @return SDL_Rect m_rect
    */
    SDL_Rect getRect();
/**
    @brief fonction qui permet de déplacer l'obstacle
    @param double delta
    */
    void move(double delta);
/**
    @brief fonction qui permet de récupérer les coordonnées de l'obstacle
    @param aucun
    @return Coords m_coords
    */
    Coords getCoords();
/**
    @brief fonction qui permet de tester la régression de la classe Obstacle
    @param aucun
    */
    void testRegression();

private:
    SDL_Rect m_rect; // rectangle de l'obstacle
    Coords m_coords; // coordonnées de l'obstacle
};

#endif // OBSTACLE_H