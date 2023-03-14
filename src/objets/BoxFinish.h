#ifndef BOXFINISH_H
#define BOXFINISH_H

#include <SDL2/SDL.h>
#include "../coords.h"

/// @brief classe BoxFinish
class BoxFinish {
public:
    /// @brief constructeur par défaut de la classe BoxFinish
    BoxFinish();
    /// @brief constructeur de la classe BoxFinish, en paramètre les coordonnées de la box de fin
    BoxFinish(int x, int y, int TILE_SIZE) ;
    /// @brief destructeur de la classe BoxFinish
    ~BoxFinish();
    /// @brief fonction qui permet de renvoyer la box de fin
    void push_back(BoxFinish* pic);
    /// @brief fonction qui permet de récupérer les coordonnées de la box de fin
    SDL_Rect getRect();
    /// @brief fonction qui permet de déplacer la box de fin
    void move(double delta);
    /// @brief fonction qui permet de récupérer les coordonnées de la box de fin
    Coords getCoords();
    /// @brief fonction qui permet de tester la régression de la classe BoxFinish
    void testRegression();

private:
    /// @brief coordonnées de la box de fin
    Coords m_coords;
    /// @brief rectangle de la box de fin
    SDL_Rect m_triangle;
    /// @brief largeur de la box de fin
    int width;
    /// @brief hauteur de la box de fin
    int height;
};

#endif // BOXFINISH_H