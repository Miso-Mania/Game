#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "level.h"
#include "player.h"

using namespace std;

class Game {
public:
/**
    @brief constructeur de la classe Game
    @param aucun
    */
    Game();
/**
    @brief destructeur de la classe Game
    @param aucun
    */
    ~Game();
/**
    @brief fonction qui permet de lancer le jeu
    @param aucun
    */
    void run();
/**
    @brief fonction qui permet de gérer les évènements
    @param SDL_Event& event
    */
    void handleEvents(SDL_Event& event);
/**
    @brief fonction qui permet de mettre à jour le jeu
    @param double delta
    */
    void update(double delta);
/**
    @brief fonction qui permet de dessiner le jeu
    @param aucun
    */
    void render();

private:
    SDL_Window *m_window; // fenêtre du jeu
    SDL_Renderer *m_renderer; // renderer du jeu
    SDL_Rect m_rect; // rectangle du jeu

    SDL_Texture *m_texture_player; // texture du joueur
    SDL_Surface *m_surface_player; // surface du joueur

    SDL_Texture *m_texture_pic; // texture du pic
    SDL_Surface *m_surface_pic; // surface du pic

    SDL_Texture *m_texture_obstacle; // texture de l'obstacle
    SDL_Surface *m_surface_obstacle; // surface de l'obstacle

    SDL_Texture *m_texture_background; // texture du background
    SDL_Surface *m_surface_background; // surface du background

    SDL_Texture *m_texture_Trees; // texture des arbres
    SDL_Surface *m_surface_Trees; // surface des arbres

    SDL_Texture *m_texture_BoxFinish; // texture de la boite de fin
    SDL_Surface *m_surface_BoxFinish; // surface de la boite de fin

    SDL_Texture *m_texture_DoubleJumpPort; // texture du portail de double saut
    SDL_Surface *m_surface_DoubleJumpPort; // surface du portail de double saut

    SDL_Texture *m_texture_S_Plateform; // texture de la petie plateforme 
    SDL_Surface *m_surface_S_Plateform; // surface de la petie plateforme 

    SDL_Texture *m_texture_M_Plateform; // texture de la moyenne plateforme 
    SDL_Surface *m_surface_M_Plateform; // surface de la moyenne plateforme 

    SDL_Texture *m_texture_L_Plateform; // texture de la longue plateforme 
    SDL_Surface *m_surface_L_Plateform; // surface de la longue plateforme 

    SDL_Texture *m_texture_Case; // texture de la caisse
    SDL_Surface *m_surface_Case; // surface de la caisse

    SDL_Texture *m_texture_D_Case; // texture de la double caisse
    SDL_Surface *m_surface_D_Case; // surface de la double caisse

    SDL_Texture *m_texture_BoxCmgtGrav; // texture de la boite de gestion de la gravité
    SDL_Surface *m_surface_BoxCmgtGrav; // surface de la boite de gestion de la gravité

    Player m_player; // joueur du jeu

    vector<Level*> m_levels; // vecteur de niveaux

    int m_currentLevel; // niveau actuel

    double timer; // timer// @brief niveau actuel
};
#endif // GAME_H

