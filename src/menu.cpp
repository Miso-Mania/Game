#include "menu.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
const int FPS = 60;
const int window_X_size = 1900;
const int window_Y_size = 1068;

using namespace std;

Menu::Menu() : m_window(NULL), m_renderer(NULL) {
    // Initialisation de SDL
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    //on créé une fenetre  de 1920*1080, fullscreen et on la rend visible
    m_window = SDL_CreateWindow("Menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_X_size, window_Y_size, SDL_WINDOW_FULLSCREEN);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);    

    //on charge l'image de fond
    SDL_Surface* background = IMG_Load("assets/textures/tree.png");
    SDL_Texture* background_texture = SDL_CreateTextureFromSurface(m_renderer, background);
    
    
}

Menu:: ~Menu() {
    // Nettoyage de SDL
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_FreeSurface(background);
    SDL_DestroyTexture(background_texture);

    IMG_Quit();
    SDL_Quit();
}

void Menu::run() {
    bool running = true;
    while (running) {
        // Gestion des évènements
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            handleEvents (event);
            if (event.type == SDL_QUIT) {
                running = false;
            }
    }
    // Mise à jour
    update(0.016);
    // Affichage
    render();
    }
}

void Menu::handleEvents(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                //on fermme la fenetre, et on libère la mémoire avant de lancé le jeu
                SDL_DestroyRenderer(m_renderer);
                SDL_DestroyWindow(m_window);

                break;

        }
    } 

}

void Menu::update(double delta) {
 
    
   cout<<"update"<<endl;
}

void Menu::render() {
    SDL_RenderClear(m_renderer);

    // on affiche l'image de fond
    SDL_RenderCopy(m_renderer, background_texture, NULL, NULL);  

    SDL_RenderPresent(m_renderer);

}
