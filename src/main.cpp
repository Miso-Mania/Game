#include <iostream>
#include "game.h"

using namespace std;
int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Surface* imageSurface = IMG_Load("assets/textures/menu-splashscreen.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    if (texture == NULL) {
        cout << "feur " << SDL_GetError() << endl;
    }
    if (imageSurface == NULL) {
        cout << "feur mais 2" << SDL_GetError() << endl;
    }

    SDL_Rect dstRect = {0, 0, 800, 600};
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(imageSurface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    Game game;
    game.run();
    SDL_Quit();
    return 0;
}