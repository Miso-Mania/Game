#ifndef BOXCMGTGRAV_H
#define BOXCMGTGRAV_H

#include "SDL2/SDL.h"
#include "../coords.h"

class BoxCmgtGrav {
public:
/**
    @brief constructeur par défaut de la classe BoxCmgtGrav
    @param aucun
    */
    BoxCmgtGrav();
/**
    @brief constructeur de la classe BoxCmgtGrav, en paramètre les coordonnées de l'objet
    @param int x, int y, int TILE_SIZE
    */
    BoxCmgtGrav(int x, int y, int TILE_SIZE);
/**
    @brief destructeur de la classe BoxCmgtGrav
    @param aucun
    */
    ~BoxCmgtGrav();
/**
    @brief fonction qui permet de renvoyer l'objet
    @param BoxCmgtGrav* BoxCmgtGrav
    */
    void push_back(BoxCmgtGrav* BoxCmgtGrav);
/**
    @brief fonction qui permet de récupérer les coordonnées de l'objet
    @param aucun
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
    */
    Coords getCoords();
/**
    @brief fonction qui permet de tester la classe
    @param aucun
    */
    void testRegression();
private:
        Coords m_coords; // coordonnées de l'objet
        SDL_Rect m_rect; // coordonnées de l'objet
};

#endif // BOXCMGTGRAV

