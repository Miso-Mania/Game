#ifndef BOXFINISH_H
#define BOXFINISH_H

#include <SDL2/SDL.h>
#include "../coords.h"

class BoxFinish {
public:
/**
    @brief constructeur par défaut de la classe BoxFinish
    @param aucun
    */
    BoxFinish();
/**
    @brief constructeur de la classe BoxFinish, en paramètre les coordonnées de la box de fin
    @param int x, int y, int TILE_SIZE
    */
    BoxFinish(int x, int y, int TILE_SIZE) ;
/**
    @brief destructeur de la classe BoxFinish
    @param aucun
    */
    ~BoxFinish();
/**
    @brief fonction qui permet de renvoyer la box de fin
    @param BoxFinish* pic
    */
    void push_back(BoxFinish* pic);
/**
    @brief fonction qui permet de récupérer les coordonnées de la box de fin
    @param aucun
    @return SDL_Rect
    */
    SDL_Rect getRect();
/**
    @brief fonction qui permet de déplacer la box de fin
    @param double delta
    */
    void move(double delta);
/**
    @brief fonction qui permet de récupérer les coordonnées de la box de fin
    @param aucun
    @return Coords
    */
    Coords getCoords();
/**
    @brief fonction qui permet de tester la régression de la classe BoxFinish
    @param aucun
    */
    void testRegression();

private:
    Coords m_coords; // coordonnées de la box de fin
    SDL_Rect m_triangle; // coordonnées de la box de fin
    int width; // largeur de la box de fin
    int height; // hauteur de la box de fin
};

#endif // BOXFINISH_H