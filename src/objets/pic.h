#ifndef PIC_H
#define PIC_H

#include <SDL2/SDL.h>
#include "../coords.h"

class Pic {
public:
/**
    @brief constructeur par défaut de la classe Pic
    @param aucun
    */
    Pic();
/**
    @brief constructeur de la classe Pic, en paramètre les coordonnées de la pic
    @param int x, int y, int TILE_SIZE
    */
    Pic(int x, int y, int TILE_SIZE);
/**
    @brief destructeur de la classe Pic
    @param aucun
    */
    ~Pic();
/**
    @brief fonction qui permet de renvoyer la pic
    @param Pic* pic
    */
    void push_back(Pic* pic);
/**
    @brief fonction qui permet de récupérer les coordonnées de la pic
    @param aucun
    @return SDL_Rect
    */
    SDL_Rect getRect();
/**
    @brief fonction qui permet de déplacer la pic
    @param double delta
    */
    void move(double delta);
/**
    @brief fonction qui permet de récupérer les coordonnées de la pic
    @param aucun
    @return Coords
     */
    Coords getCoords();
/**
    @brief fonction qui permet de tester la régression de la classe Pic
    @param aucun
    */
    void testRegression();

private:
    Coords m_coords; // coordonnées de la pic
    SDL_Rect m_triangle; //triangle de la pic
    int width; // largeur de la pic
    int height; // hauteur de la pic
};

#endif // PIC_H