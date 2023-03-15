#ifndef TREE_H
#define TREE_H

#include <SDL2/SDL.h>
#include "../coords.h"

class Tree {
public:
/**
    @brief constructeur par défaut de la classe Tree
    @param aucun
    */
    Tree();
/**
    @brief constructeur de la classe Tree avec des paramètres
    @param int x, int y, int TILE_SIZE
    */
    Tree(int x, int y, int TILE_SIZE);
/**
    @brief destructeur de la classe Tree
    @param aucun
    */
    ~Tree();
/**
    @brief fonction qui permet de renvoyer le Tree
    @param Tree* Tree
    */
    void push_back(Tree* Tree);
/**
    @brief fonction qui permet de récupérer les coordonnées de l'arbre
    @param aucun
    @return SDL_Rect
    */
    SDL_Rect getRect();
/**
    @brief fonction qui permet de déplacer le Tree
    @param double delta
    */
    void move(double delta);
/**
    @brief fonction qui permet de récupérer les coordonnées de l'arbre
    @param aucun
    @return Coords
    */
    Coords getCoords();
/**
    @brief fonction qui permet de tester la régression de la classe Tree
    @param aucun
    */
    void testRegression();

private:
    Coords m_coords; // coordonnées de l'arbre
    SDL_Rect m_rect; // rectangle de l'arbre
    
};

#endif // Tree_H