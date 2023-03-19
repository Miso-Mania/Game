#include <iostream>
#include "game.h"

using namespace std;
void menu() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Surface* imageSurface = IMG_Load("assets/textures/splash.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_Rect dstRect = {0, 0, 400, 400};
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    SDL_RenderPresent(renderer);

    SDL_Delay(1000); // on attends une seconde avant d'ouvrir le jeu

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(imageSurface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

int main(int argc, char* argv[]) {
    
    menu();
    Game game;
    game.run();
    SDL_Quit();
    return 0;
}
