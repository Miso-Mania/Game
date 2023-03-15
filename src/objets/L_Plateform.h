#ifndef L_Plateform_H
#define L_Plateform_H
#include <SDL2/SDL.h>
#include "../coords.h"

class L_Plateform {
public:
/**
    @brief constructeur par défaut de la classe L_Plateform
    @param aucun
    */
    L_Plateform();
/**
    @brief constructeur de la classe L_Plateform, en paramètre les coordonnées de la longue Plateform
    @param int x, int y, int TILE_SIZE
    */
    L_Plateform(int x, int y, int TILE_SIZE);
/**
    @brief destructeur de la classe L_Plateform
    @param aucun
    */
    ~L_Plateform();
/**
    @brief fonction qui permet de renvoyer la longue Plateform
    @param L_Plateform* L_Plateform
    */
    void push_back(L_Plateform* L_Plateform);
/**
    @brief fonction qui permet de récupérer les coordonnées de la longue Plateform
    @param aucun
    @return SDL_Rect
    */
    SDL_Rect getRect();
/**
    @brief fonction qui permet de déplacer la longue Plateform
    @param double delta
    */
    void move(double delta);
/**
    @brief fonction qui permet de récupérer les coordonnées de la L_Plateform
    @param aucun
    @return Coords
    */
    Coords getCoords();
/**
    @brief fonction qui permet de tester la régression de la classe L_Plateform
    @param aucun
    */
    void testRegression();

private:
    SDL_Rect m_rect; // rectangle de la longue Plateform
    Coords m_coords; // coordonnées de la longue Plateform
};

#endif // L_Plateform
