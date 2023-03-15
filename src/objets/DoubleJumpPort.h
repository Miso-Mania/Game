#ifndef DOUBLEJUMPPORT_H
#define DOUBLEJUMPPORT_H

#include "SDL2/SDL.h"
#include "../coords.h"

class DoubleJumpPort {
public:
/**
    @brief constructeur par défaut de la classe DoubleJump
    @param aucun
    */
    DoubleJumpPort();
/**
    @brief constructeur de la classe DoubleJump, en paramètre les coordonnées de l'objet
    @param int x, int y, int TILE_SIZE
    */
    DoubleJumpPort(int x, int y, int TILE_SIZE);
/**
    @brief destructeur de la classe DoubleJump
    @param aucun
    */
    ~DoubleJumpPort();
/**
    @brief fonction qui permet de renvoyer l'objet
    @param DoubleJumpPort* DoubleJumpPort
    */
    void push_back(DoubleJumpPort* DoubleJumpPort);
/**
    @brief fonction qui permet de récupérer les coordonnées de l'objet
    @param aucun
    @return SDL_Rect
    */
    SDL_Rect getRect();
/**
    @brief fonction qui permet de déplacer l'objet
    @param double delta
    */
    void move(double delta);
/**
    @brief fonction qui permet de récupérer les coordonnées de l'objet
    @param aucun
    @return Coords
    */
    Coords getCoords();
/**
    @brief fonction qui permet de tester la régression de la classe DoubleJump
    @param aucun
    */
    void testRegression();

private:
    Coords m_coords; // coordonnées de l'objet
    SDL_Rect m_rect; // coordonnées de l'objet
};

#endif // DOUBLEJUMPPORT