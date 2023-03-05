#ifndef D_Case_H
#define D_Case_H
#include <SDL2/SDL.h>

/// @brief classe D_Case
class D_Case {
public:
    /// @brief constructeur de la classe D_Case, en paramètre les coordonnées de l'D_Case
    D_Case(int x, int y);
    /// @brief destructeur de la classe D_Case
    ~D_Case();
    /// @brief fonction qui permet de renvoyer l'D_Case
    void push_back(D_Case* D_Case);
    /// @brief fonction qui permet de récupérer les coordonnées de l'D_Case
    SDL_Rect getRect();
    /// @brief fonction qui permet de déplacer l'D_Case
    void move(double delta);

private:
    /// @brief coordonnées de l'D_Case
    SDL_Rect m_rect;
};

#endif // D_Case
