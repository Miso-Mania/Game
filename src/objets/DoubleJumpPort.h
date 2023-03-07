#ifndef DOUBLEJUMPPORT_H
#define DOUBLEJUMPPORT_H

#include "SDL2/SDL.h"

/// @brief classe DoubleJumpPort
class DoubleJumpPort {
public:
    /// @brief constructeur de la classe DoubleJump, en paramètre les coordonnées de l'objet
    DoubleJumpPort(int x, int y, int TILE_SIZE);
    /// @brief destructeur de la classe DoubleJump
    ~DoubleJumpPort();
    /// @brief fonction qui permet de renvoyer l'objet
    void push_back(DoubleJumpPort* DoubleJumpPort);
    /// @brief fonction qui permet de récupérer les coordonnées de l'objet
    SDL_Rect getRect();
    /// @brief fonction qui permet de déplacer l'objet
    void move(double delta);

private:
    /// @brief coordonnées de l'objet
    SDL_Rect m_rect;
};

#endif // DOUBLEJUMPPORT