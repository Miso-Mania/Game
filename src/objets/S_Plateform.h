#ifndef S_Plateform_H
#define S_Plateform_H
#include <SDL2/SDL.h>
#include "../coords.h"

class S_Plateform {
public:
/**
    @brief constructeur par défaut de la classe S_Plateform
    @param aucun
    */
    S_Plateform();
/**
    @brief constructeur de la classe S_Plateform, en paramètre les coordonnées de la petite plateforme
    @param int x, int y, int TILE_SIZE
    */
    S_Plateform(int x, int y, int TILE_SIZE);
/**
    @brief destructeur de la classe S_Plateform
    @param aucun
    */
    ~S_Plateform();
/**
    @brief fonction qui permet de renvoyer la petite plateforme
    @param S_Plateform* S_Plateform
    */
    void push_back(S_Plateform* S_Plateform);
/**
    @brief fonction qui permet de récupérer les coordonnées de la petite plateforme
    @param aucun
    @return SDL_Rect
    */
    SDL_Rect getRect();
/**
    @brief fonction qui permet de déplacer la petite plateforme
    @param double delta
    */
    void move(double delta);
/**
    @brief fonction qui permet de récupérer les coordonnées de la S_Plateform
    @param aucun
    @return Coords
    */
    Coords getCoords();
/**
    @brief fonction qui permet de tester la régression de la classe S_Plateform
    @param aucun
    */
    void testRegression();

private:
    SDL_Rect m_rect; // rectangle de la petite plateforme
    Coords m_coords; // coordonnées de la petite plateforme
};

#endif // S_Plateform
