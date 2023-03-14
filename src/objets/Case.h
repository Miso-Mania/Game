#ifndef Case_H
#define Case_H
#include <SDL2/SDL.h>

#include "../coords.h"

/// @brief classe Case
class Case {
public:
    /// @brief constructeur par défaut de la classe Case
    Case();
    /// @brief constructeur de la classe Case, en paramètre les coordonnées de l'Case
    Case(int x, int y, int TILE_SIZE);
    /// @brief destructeur de la classe Case
    ~Case();
    /// @brief fonction qui permet de renvoyer l'Case
    void push_back(Case* Case);
    /// @brief fonction qui permet de récupérer les coordonnées de l'Case
    SDL_Rect getRect();
    /// @brief fonction qui permet de déplacer l'Case
    void move(double delta);
    /// @brief fonction qui permet de récupérer les coordonnées de l'Case
    Coords getCoords();
    /// @brief fonction qui permet de tester la régression de la classe Case
    void testRegression();

private:
    /// @brief coordonnées de l'Case
    Coords m_coords;
    /// @brief rectangle de l'Case
    SDL_Rect m_rect;
};

#endif // Case
