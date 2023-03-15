#ifndef M_Plateform_H
#define M_Plateform_H
#include <SDL2/SDL.h>
#include "../coords.h"

class M_Plateform {
public:
/**
    @brief constructeur par défaut de la classe M_Plateform
    @param aucun
    */
    M_Plateform();
/**
    @brief constructeur de la classe M_Plateform, en paramètre les coordonnées de la moyenne Plateforme
    @param int x, int y, int TILE_SIZE
    */
    M_Plateform(int x, int y, int TILE_SIZE);
/**
    @brief destructeur de la classe M_Plateform
    @param aucun
    */
    ~M_Plateform();
/**
    @brief fonction qui permet de renvoyer la moyenne Plateforme
    @param M_Plateform* M_Plateform
    */
    void push_back(M_Plateform* M_Plateform);
/**
    @brief fonction qui permet de récupérer les coordonnées de la moyenne Plateforme
    @param aucun
    @return SDL_Rect
    */
    SDL_Rect getRect();
/**
    @brief fonction qui permet de déplacer la moyenne Plateforme
    @param double delta
    */
    void move(double delta);
/**
    @brief fonction qui permet de récupérer les coordonnées de la M_Plateform
    @param aucun
    @return Coords
    */
    Coords getCoords();
/**
    @brief fonction qui permet de tester la régression de la classe M_Plateform
    @param aucun
    */
    void testRegression();

private:
    SDL_Rect m_rect; // rectangle de la moyenne Plateforme
    Coords m_coords; // coordonnées de la moyenne Plateforme
};

#endif // M_Plateform
