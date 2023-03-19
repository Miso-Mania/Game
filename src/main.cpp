#include "game.h"
#include <iostream>
#include <SDL2/SDL_mixer.h>

using namespace std;
void menu() {
    // Initialisation de la SDL
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Surface* imageSurface = IMG_Load("assets/textures/splash.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_Rect dstRect = {0, 0, 400, 400};
    //initialisation de la musique
    if (Mix_Init(MIX_INIT_MP3) != MIX_INIT_MP3)
    {
        std::cerr << "Failed to initialize SDL2 Mixer: " << Mix_GetError() << std::endl;
    }

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) != 0)
    {
        std::cerr << "Failed to open audio device: " << Mix_GetError() << std::endl;
    }

    Mix_Music *intro = Mix_LoadMUS("assets/music/intro.mp3");
    if (!intro)
    {
        std::cerr << "Failed to load intro file: " << Mix_GetError() << std::endl;
    }

    if (Mix_PlayMusic(intro, -1) != 0)
    {
        std::cerr << "Failed to play intro: " << Mix_GetError() << std::endl;
    }
    Mix_PlayMusic(intro, 1);
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    SDL_RenderPresent(renderer);

    SDL_Delay(1500); // on attends une seconde avant d'ouvrir le jeu
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(imageSurface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* inputWindow = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
    SDL_Renderer* inputRenderer = SDL_CreateRenderer(inputWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface* inputSurface = IMG_Load("assets/textures/input.png");
    SDL_Texture* inputTexture = SDL_CreateTextureFromSurface(inputRenderer, inputSurface);
    SDL_Rect inputRect = {0, 0, 1280, 720};
    SDL_RenderCopy(inputRenderer, inputTexture, NULL, &inputRect);
    SDL_RenderPresent(inputRenderer);
    
    SDL_Delay(1500); // on attends une seconde avant d'ouvrir le jeu
    SDL_DestroyTexture(inputTexture);
    SDL_FreeSurface(inputSurface);
    SDL_DestroyRenderer(inputRenderer);
    SDL_DestroyWindow(inputWindow);
    
}   

int main(int argc, char* argv[]) {
    
    menu();
    Game game;
    game.run();
    SDL_Quit();
    return 0;
}
