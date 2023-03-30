#include "game.h"
#include <iostream>
#include <string>
#include <SDL2/SDL_mixer.h>
using namespace std;
int input = 444;
int level = 445;
int activity = 446;
bool editorMode = false;
string username = "";

string auth(){
    FILE* name = NULL;
    name = fopen("user/name.txt", "r");
    //on lit la valeur de name
    char nameValue[13];
    fgets(nameValue, 13, name);
    //on converti la valeur de name en string
    string nameString = nameValue;
    //on regarde si le nom est vide
    if (nameString == ""){
        //si le nom est vide on demande le nom
        cout << "Veuillez entrer votre nom : ";
        cin >> nameString;
        //on converti le nom en char
        char nameChar[13];
        strcpy(nameChar, nameString.c_str());
        //on écrit le nom dans le fichier
        name = fopen("user/name.txt", "w");
        fputs(nameChar, name);
        return nameString;
    } else {
        return nameString;
    }
    cout << "Connecté en temps que " << nameString << endl;
}

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

int menu() {
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

    Mix_Music *intro = Mix_LoadMUS("assets/music/gangsta.wav");
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
        SDL_Window* menuWindow = SDL_CreateWindow("Menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
        SDL_Renderer* mainRenderer = SDL_CreateRenderer(menuWindow, -1, SDL_RENDERER_ACCELERATED);
        SDL_Surface* activitySurface = IMG_Load("assets/textures/activity.png");
        SDL_Texture* activityTexture = SDL_CreateTextureFromSurface(mainRenderer, activitySurface);
        SDL_Rect mainRect = {0, 0, 1280, 720};
        SDL_RenderCopy(mainRenderer, activityTexture, NULL, &mainRect);
        SDL_RenderPresent(mainRenderer);
        //on demande au joueur de choisir entre le mode edition, le mode jeu ou le leaderboard, en fonction de l'input
        activity = getUserInput();
        if (activity == 2){
            editorMode = true;
        }
        if (activity == 3){
            cout << "Leaderboard" << endl;
             cout << "Voici le leaderboard pour chaque niveau :" << endl;
        for (int i = 0; i < 4; i++) {
            FILE* leaderboard = NULL;
            leaderboard = fopen(("times/level" + to_string(i) + ".txt").c_str(), "r");
            char tempsRecord[30];
            fgets(tempsRecord, 30, leaderboard);
            cout << "Niveau " << i << " : " << endl;
            cout << "Le record est : " <<  tempsRecord << endl;    

        }
    return 1;
        }

        //on ferme la fenêtre
        SDL_DestroyTexture(activityTexture);
        SDL_FreeSurface(activitySurface);      
        //on pause pour 0.1 seconde
        SDL_Delay(100);

        //on ouvre le menu suivant
        SDL_Surface* levelSurface = IMG_Load("assets/textures/level.png");
        SDL_Texture* levelTexture = SDL_CreateTextureFromSurface(mainRenderer, levelSurface);
        SDL_RenderCopy(mainRenderer, levelTexture, NULL, &mainRect);
        SDL_RenderPresent(mainRenderer);
        //on demande le niveau
        level = getUserInput();
        //si le niveau est 1; on ferme la fenêtre
        if (level == 1 || level == 2 || level == 3 || level == 4 || level == 5 || level == 6 || level == 7 || level == 8 || level == 9 || level == 10) {
            SDL_DestroyTexture(levelTexture);
            SDL_FreeSurface(levelSurface);
        }
        else {
            cout << "Veuillez entrer un niveau valide" << endl;
            level = getUserInput();
        }
        SDL_Surface* inputSurface = IMG_Load("assets/textures/input.png");
        SDL_Texture* inputTexture = SDL_CreateTextureFromSurface(mainRenderer, inputSurface);
        SDL_RenderCopy(mainRenderer, inputTexture, NULL, &mainRect);
        SDL_RenderPresent(mainRenderer);
        input = 0;
        //si l'input est clavier; on ferme la fenêtre
        do{
            input = getUserInput();
            cout << "Merci de choisir votre type d'imput" << endl;
        }while (!(input==1 || input ==2));
        SDL_DestroyTexture(inputTexture);
        SDL_FreeSurface(inputSurface);
        SDL_DestroyWindow(menuWindow);
        return 0;
}

int main(int argc, char* argv[]) {
    username = auth();
    cout << "Bienvenue " << username << endl;
    // on lance le jeu ssi le menu a retourné 0
    if (menu() == 0) {
         Game game(input, level, editorMode, username);
        // on lance la boucle principale du jeu
        game.run();
    }
    SDL_Quit();
    return 0;
}
