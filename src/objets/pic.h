#ifndef PIC_H
#define PIC_H

#include <SDL2/SDL.h>
#include "../coords.h"

/// @brief classe Pic
class Pic {
public:
    /// @brief constructeur de la classe Pic, en paramètre les coordonnées de la pic
    Pic(int x, int y, int TILE_SIZE);
    /// @brief destructeur de la classe Pic
    ~Pic();
    /// @brief fonction qui permet de renvoyer la pic
    void push_back(Pic* pic);
    /// @brief fonction qui permet de récupérer les coordonnées de la pic
    SDL_Rect getRect();
    /// @brief fonction qui permet de déplacer la pic
    void move(double delta);

    Coords getCoords();

private:
    Coords m_coords;
    /// @brief coordonnées du rectangle du pic
    SDL_Rect m_triangle;
    /// @brief largeur de la pic
    int width;
    /// @brief hauteur de la pic
    int height;
};

#endif // PIC_H