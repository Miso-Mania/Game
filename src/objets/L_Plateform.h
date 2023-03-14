#ifndef L_Plateform_H
#define L_Plateform_H
#include <SDL2/SDL.h>
#include "../coords.h"

/// @brief classe L_Plateform
class L_Plateform {
public:
    /// @brief constructeur par défaut de la classe L_Plateform
    L_Plateform();
    /// @brief constructeur de la classe L_Plateform, en paramètre les coordonnées de l'L_Plateform
    L_Plateform(int x, int y, int TILE_SIZE);
    /// @brief destructeur de la classe L_Plateform
    ~L_Plateform();
    /// @brief fonction qui permet de renvoyer l'L_Plateform
    void push_back(L_Plateform* L_Plateform);
    /// @brief fonction qui permet de récupérer les coordonnées de l'L_Plateform
    SDL_Rect getRect();
    /// @brief fonction qui permet de déplacer l'L_Plateform
    void move(double delta);
    /// @brief fonction qui permet de récupérer les coordonnées de la L_Plateform
    Coords getCoords();
    /// @brief fonction qui permet de tester la régression de la classe L_Plateform
    void testRegression();

private:
    /// @brief coordonnées de l'L_Plateform
    SDL_Rect m_rect;
    /// @brief coordonnées de l'L_Plateform
    Coords m_coords;
};

#endif // L_Plateform
