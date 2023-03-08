#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SDL2/SDL.h>
#include "../coords.h"

/// @brief classe Obstacle
class Obstacle {
public:
    /// @brief constructeur de la classe Obstacle, en paramètre les coordonnées de l'obstacle
    Obstacle(int x, int y, int width, int height);
    /// @brief destructeur de la classe Obstacle
    ~Obstacle();
    /// @brief fonction qui permet de renvoyer l'obstacle
    void push_back(Obstacle* obstacle);
    /// @brief fonction qui permet de récupérer les coordonnées de l'obstacle
    SDL_Rect getRect();
    /// @brief fonction qui permet de déplacer l'obstacle
    void move(double delta);

    Coords getCoords();

private:
    /// @brief coordonnées de l'obstacle
    SDL_Rect m_rect;

    Coords m_coords;
};

#endif // OBSTACLE_H