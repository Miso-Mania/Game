#ifndef MENU_H
#define MENU_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


using namespace std;

class Menu {
public:
    /// @brief Constructeur de la classe Menu
    Menu();
    /// @brief Destructeur de la classe Menu
    ~Menu();
    /// @brief Fonction qui permet de lancer le menu
    void run();
    /// @brief Fonction qui permet de gérer les évènements
    void handleEvents(SDL_Event& event);
    /// @brief Fonction qui permet de mettre à jour le menu
    void update(double delta);
    /// @brief Fonction qui permet de dessiner le menu
    void render();

private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Surface * background;
    SDL_Texture * background_texture;
    SDL_Rect m_rect;
   

};


#endif // MENU_H

