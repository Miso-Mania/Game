#ifndef Case_H
#define Case_H
#include <SDL2/SDL.h>

#include "../coords.h"
class Case {
public:
/**
    @brief constructeur par défaut de la classe Case
    @param aucun
    */
    Case();
/**
    @brief constructeur de la classe Case, en paramètre les coordonnées de la Case
    @param int x, int y, int TILE_SIZE
    */
    Case(int x, int y, int TILE_SIZE);
/**
    @brief destructeur de la classe Case
    @param aucun
    */
    ~Case();
/**
    @brief fonction qui permet de renvoyer la Case
    @param Case* Case
    */
    void push_back(Case* Case);
/**
    @brief fonction qui permet de récupérer les coordonnées de la Case
    @param aucun
    @return SDL_Rect
    */
    SDL_Rect getRect();
/**
    @brief fonction qui permet de déplacer la Case
    @param double delta
    */
    void move(double delta);
/**
    @brief fonction qui permet de récupérer les coordonnées de la Case
    @param aucun
    @return Coords
    */
    Coords getCoords();
/**
    @brief fonction qui permet de tester la régression de la classe Case
    @param aucun
    */
    void testRegression();

private:
    Coords m_coords; // coordonnées de la Case
    SDL_Rect m_rect; // rectangle de la Case
};

#endif // Case
