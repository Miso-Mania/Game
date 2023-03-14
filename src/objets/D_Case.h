#ifndef D_Case_H
#define D_Case_H
#include <SDL2/SDL.h>

#include "../coords.h"

class D_Case {
public:
/**
    @brief constructeur par défaut de la classe D_Case
    @param aucun
    */
    D_Case();
/**
    @brief constructeur de la classe D_Case, en paramètre les coordonnées de la double Case
    @param int x, int y, int TILE_SIZE
    */
    D_Case(int x, int y, int TILE_SIZE);
/**
    @brief destructeur de la classe D_Case
    @param aucun
    */
    ~D_Case();
/**
    @brief fonction qui permet de renvoyer la double Case
    @param D_Case* D_Case
    */
    void push_back(D_Case* D_Case);
/**
    @brief fonction qui permet de récupérer les coordonnées de la double Case
    @param aucun
    @return SDL_Rect
    */
    SDL_Rect getRect();
/**
    @brief fonction qui permet de déplacer la double Case
    @param double delta
    */
    void move(double delta);
/**
    @brief fonction qui permet de récupérer les coordonnées de la double Case
    @param aucun
    @return Coords
    */
    Coords getCoords();
/**
    @brief fonction qui permet de tester la régression de la classe D_Case
    @param aucun
    */
    void testRegression();

private:
    Coords m_coords; // coordonnées de la double Case
    SDL_Rect m_rect; // rectangle de la double Case
};

#endif // D_Case
