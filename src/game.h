#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "level.h"
#include "player.h"

using namespace std;

//* @brief classe Game
class Game {
public:
    //* @brief constructeur de la classe Game
    Game();
    //* @brief destructeur de la classe Game
    ~Game();
    //* @brief fonction qui permet de lancer le jeu
    void run();
    //* @brief fonction qui permet de gérer les évènements
    void handleEvents(SDL_Event& event);
    //* @brief fonction qui permet de mettre à jour le jeu
    void update(double delta);
    //* @brief fonction qui permet de dessiner le jeu
    void render();

private:
    //* @brief FENETRE
    SDL_Window *m_window;
    //* @brief RENDERER
    SDL_Renderer *m_renderer;
    //* @brief RECTANGLE
    SDL_Rect m_rect;

    //* @brief Texture du joueur
    SDL_Texture *m_texture_player;
    //* @brief Surface du joueur
    SDL_Surface *m_surface_player;

    //* @brief Texture du pic
    SDL_Texture *m_texture_pic;
    //* @brief Surface du pic
    SDL_Surface *m_surface_pic;

    //* @brief Texture de l'obstacle
    SDL_Texture *m_texture_obstacle;
    //* @brief Surface de l'obstacle
    SDL_Surface *m_surface_obstacle;

    //* @brief Texture de la box de fin
    Player m_player;

    //* @brief vecteur de niveau 
    vector<Level*> m_levels;

    //* @brief niveau actuel
    int m_currentLevel;
};
#endif // GAME_H

