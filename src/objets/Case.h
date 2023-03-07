#ifndef Case_H
#define Case_H
#include <SDL2/SDL.h>

/// @brief classe Case
class Case {
public:
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

private:
    /// @brief coordonnées de l'Case
    SDL_Rect m_rect;
};

#endif // Case
