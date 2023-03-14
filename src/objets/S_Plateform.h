#ifndef S_Plateform_H
#define S_Plateform_H
#include <SDL2/SDL.h>
#include "../coords.h"

/// @brief classe S_Plateform
class S_Plateform {
public:
    /// @brief constructeur par défaut de la classe S_Plateform
    S_Plateform();
    /// @brief constructeur de la classe S_Plateform, en paramètre les coordonnées de l'S_Plateform
    S_Plateform(int x, int y, int TILE_SIZE);
    /// @brief destructeur de la classe S_Plateform
    ~S_Plateform();
    /// @brief fonction qui permet de renvoyer l'S_Plateform
    void push_back(S_Plateform* S_Plateform);
    /// @brief fonction qui permet de récupérer les coordonnées de l'S_Plateform
    SDL_Rect getRect();
    /// @brief fonction qui permet de déplacer l'S_Plateform
    void move(double delta);
    /// @brief fonction qui permet de récupérer les coordonnées de la S_Plateform
    Coords getCoords();
    /// @brief fonction qui permet de tester la régression de la classe S_Plateform
    void testRegression();

private:
    /// @brief coordonnées de l'S_Plateform
    SDL_Rect m_rect;
    /// @brief coordonnées de l'S_Plateform
    Coords m_coords;
};

#endif // S_Plateform
