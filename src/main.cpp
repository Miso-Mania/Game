#include "game.h"
#include <iostream>
#include <SDL2/SDL_mixer.h>
using namespace std;
int input = 444;
int level = 445;
int activity = 446;
bool editorMode = false;

int getUserInput()
{
    int userinput = -1;
    while (userinput == -1)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
            {
                cout << "key pressed : " << event.key.keysym.sym << endl;
                switch (event.key.keysym.sym)
                {
                case SDLK_0:
                    userinput = 0;
                    break;
                case SDLK_1:
                    userinput = 1;
                    break;
                case SDLK_2:
                    userinput = 2;
                    break;
                case SDLK_3:
                    userinput = 3;
                    break;
                case SDLK_4:
                    userinput = 4;
                    break;
                case SDLK_5:
                    userinput = 5;
                    break;
                case SDLK_6:
                    userinput = 6;
                    break;
                case SDLK_7:
                    userinput = 7;
                    break;
                case SDLK_8:
                    userinput = 8;
                    break;
                case SDLK_9:
                    userinput = 9;
                    break;
                case SDLK_KP_0:
                    userinput = 0;
                    break;
                case SDLK_KP_1:
                    userinput = 1;
                    break;
                case SDLK_KP_2:
                    userinput = 2;
                    break;
                case SDLK_KP_3:
                    userinput = 3;
                    break;
                case SDLK_KP_4:
                    userinput = 4;
                    break;
                case SDLK_KP_5:
                    userinput = 5;
                    break;
                case SDLK_KP_6:
                    userinput = 6;
                    break;
                case SDLK_KP_7:
                    userinput = 7;
                    break;
                case SDLK_KP_8:
                    userinput = 8;
                    break;
                case SDLK_KP_9:
                    userinput = 9;
                    break;
                }
            }
        }
    }
    return userinput;
}

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
    //on demande le type d'input
    input = getUserInput();
    //si l'input est clavier; on ferme la fenêtre
    if (input == 1 || input == 2) {
        //on ferme la fenêtre
        SDL_DestroyTexture(inputTexture);
        SDL_FreeSurface(inputSurface);
        SDL_DestroyRenderer(inputRenderer);
        SDL_DestroyWindow(inputWindow);
        //on pause pour 0.1 seconde
        SDL_Delay(100);
        //on demande au joueur de choisir entre le mode edition, le mode jeu ou le leaderboard


        SDL_Window* activityWindow = SDL_CreateWindow("Actity", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
        SDL_Renderer* activityRenderer = SDL_CreateRenderer(activityWindow, -1, SDL_RENDERER_ACCELERATED);
        SDL_Surface* activitySurface = IMG_Load("assets/textures/activity.png");
        SDL_Texture* activityTexture = SDL_CreateTextureFromSurface(activityRenderer, activitySurface);
        SDL_Rect activityRect = {0, 0, 1280, 720};
        SDL_RenderCopy(activityRenderer, activityTexture, NULL, &activityRect);
        SDL_RenderPresent(activityRenderer);
        //on demande au joueur de choisir entre le mode edition, le mode jeu ou le leaderboard, en fonction de l'input
        activity = getUserInput();
        if (activity == 2){
            editorMode = true;
        }
        if (activity == 3){
            SDL_Quit();
        }

        //on ferme la fenêtre
        SDL_DestroyTexture(activityTexture);
        SDL_FreeSurface(activitySurface);
        SDL_DestroyRenderer(activityRenderer);
        SDL_DestroyWindow(activityWindow);
        
        //on pause pour 0.1 seconde
        SDL_Delay(100);
        

        



















        //on ouvre le menu suivant
        SDL_Window* levelWindow = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
        SDL_Renderer* levelRenderer = SDL_CreateRenderer(levelWindow, -1, SDL_RENDERER_ACCELERATED);
        SDL_Surface* levelSurface = IMG_Load("assets/textures/level.png");
        SDL_Texture* levelTexture = SDL_CreateTextureFromSurface(levelRenderer, levelSurface);
        SDL_Rect levelRect = {0, 0, 1280, 720};
        SDL_RenderCopy(levelRenderer, levelTexture, NULL, &levelRect);
        SDL_RenderPresent(levelRenderer);
        //on demande le niveau
        level = getUserInput();
        //si le niveau est 1; on ferme la fenêtre
        if (level == 1 || level == 2 || level == 3 || level == 4 || level == 5 || level == 6 || level == 7 || level == 8 || level == 9 || level == 10) {
            SDL_DestroyTexture(levelTexture);
            SDL_FreeSurface(levelSurface);
            SDL_DestroyRenderer(levelRenderer);
            SDL_DestroyWindow(levelWindow);
        }
        else {
            cout << "Veuillez entrer un niveau valide" << endl;
            level = getUserInput();
        }
    }
}   

int main(int argc, char* argv[]) {
    // on affiche le menu
    menu();
    // on crée une instance de la classe Game, en lui passant le type d'input et le niveau
    Game game(input, level, editorMode);
    // on lance la boucle principale du jeu
    game.run();
    SDL_Quit();
    return 0;
}
