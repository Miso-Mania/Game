#include "game.h"
#include <iostream>
#include <string>
#include <SDL2/SDL_mixer.h>
using namespace std;
int input = 444;
int level = 445;
int activity = 446;
bool editorMode = false;
bool speedrunMode = false;
int itemToBuy = 0;
int quitCollection = 0;
int chooseIcon = 444;
string username = "";

string auth()
{
    FILE *name = NULL;
    name = fopen("user/name.txt", "r");
    // on lit la valeur de name
    char nameValue[13];
    fgets(nameValue, 13, name);
    // on converti la valeur de name en string
    string nameString = nameValue;
    // on regarde si le nom est vide
    if (nameString == "")
    {
        // si le nom est vide on demande le nom
        cout << "Veuillez entrer votre nom : ";
        cin >> nameString;
        // on converti le nom en char
        char nameChar[13];
        strcpy(nameChar, nameString.c_str());
        // on écrit le nom dans le fichier
        name = fopen("user/name.txt", "w");
        fputs(nameChar, name);
        return nameString;
    }
    else
    {
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
                case SDLK_ESCAPE:
                    userinput = -2;
                    break;
                }
            }
        }
    }
    return userinput;
}

int menu(bool skipIntro)
{
    speedrunMode = false;
    if (!skipIntro)
    {
        // Initialisation de la SDL
        SDL_Init(SDL_INIT_VIDEO);

        SDL_Window *window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, 0);
        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        SDL_Surface *imageSurface = IMG_Load("assets/textures/splash.png");
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
        SDL_Rect dstRect = {0, 0, 400, 400};
        // initialisation de la musique
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
    }
    SDL_Window *menuWindow = SDL_CreateWindow("Menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
    SDL_Renderer *mainRenderer = SDL_CreateRenderer(menuWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface *activitySurface = IMG_Load("assets/textures/activity.png");
    SDL_Texture *activityTexture = SDL_CreateTextureFromSurface(mainRenderer, activitySurface);
    SDL_Rect mainRect = {0, 0, 1280, 720};
    SDL_RenderCopy(mainRenderer, activityTexture, NULL, &mainRect);
    SDL_RenderPresent(mainRenderer);
    // on demande au joueur de choisir entre le mode edition, le mode jeu ou le leaderboard, en fonction de l'input
    cout << "1 - Jouer" << endl;
    cout << "2 - Editeur" << endl;
    cout << "3 - Leaderboard" << endl;
    cout << "4 - Speedrun" << endl;
    cout << "5 - Shop" << endl;
    cout << "6 - Collection" << endl;
    cout << "Echap - Quitter" << endl;
    activity = getUserInput();

    // on ferme la fenêtre
    SDL_DestroyTexture(activityTexture);
    SDL_FreeSurface(activitySurface);

    if (activity == 2)
    {
        editorMode = true;
    }
    if (activity == 3)
    {
        cout << "Leaderboard" << endl;
        cout << "Voici le leaderboard pour chaque niveau :" << endl;
        for (int i = 0; i < 8; i++)
        {
            FILE *leaderboard = NULL;
            leaderboard = fopen(("times/level" + to_string(i) + ".txt").c_str(), "r");
            char tempsRecord[30];
            fgets(tempsRecord, 30, leaderboard);
            cout << "Niveau " << i << " : " << endl;
            cout << "Le record est : " << tempsRecord << endl;
        }
        return 1;
    }
    if (activity == 4)
    { // mode speedrun
        speedrunMode = true;
        level = 1;
    }
    if (activity == 5)

    { // mode shop

    SDL_Surface *shopSurface = IMG_Load("assets/textures/shop.png");
    SDL_Texture *shopTexture = SDL_CreateTextureFromSurface(mainRenderer, shopSurface);
    SDL_Rect mainRect = {0, 0, 1280, 720};
    SDL_RenderCopy(mainRenderer, shopTexture, NULL, &mainRect);
    //on affiche les items
    SDL_Surface *item1Surface = IMG_Load("assets/icons/1.png");
    SDL_Texture *item1Texture = SDL_CreateTextureFromSurface(mainRenderer, item1Surface);
    SDL_Rect item1Rect = {100, 132, 100, 100};
    SDL_RenderCopy(mainRenderer, item1Texture, NULL, &item1Rect);

    SDL_Surface *item2Surface = IMG_Load("assets/icons/2.png");
    SDL_Texture *item2Texture = SDL_CreateTextureFromSurface(mainRenderer, item2Surface);
    SDL_Rect item2Rect = {300, 132, 100, 100};
    SDL_RenderCopy(mainRenderer, item2Texture, NULL, &item2Rect);

    SDL_Surface *item3Surface = IMG_Load("assets/icons/3.png");
    SDL_Texture *item3Texture = SDL_CreateTextureFromSurface(mainRenderer, item3Surface);
    SDL_Rect item3Rect = {500, 132, 100, 100};
    SDL_RenderCopy(mainRenderer, item3Texture, NULL, &item3Rect);

    SDL_Surface *item4Surface = IMG_Load("assets/icons/4.png");
    SDL_Texture *item4Texture = SDL_CreateTextureFromSurface(mainRenderer, item4Surface);
    SDL_Rect item4Rect = {100, 362, 100, 100};
    SDL_RenderCopy(mainRenderer, item4Texture, NULL, &item4Rect);

    SDL_Surface *item5Surface = IMG_Load("assets/icons/5.png");
    SDL_Texture *item5Texture = SDL_CreateTextureFromSurface(mainRenderer, item5Surface);
    SDL_Rect item5Rect = {300, 362, 100, 100};
    SDL_RenderCopy(mainRenderer, item5Texture, NULL, &item5Rect);

    SDL_Surface *item6Surface = IMG_Load("assets/icons/6.png");
    SDL_Texture *item6Texture = SDL_CreateTextureFromSurface(mainRenderer, item6Surface);
    SDL_Rect item6Rect = {500, 362, 100, 100};
    SDL_RenderCopy(mainRenderer, item6Texture, NULL, &item6Rect);


    SDL_RenderPresent(mainRenderer);

    //on récupère l'argent du joueur
    FILE* moneyFile = NULL;
    moneyFile = fopen("user/coins.txt", "r");
    char moneyChar [7]; 
    fgets(moneyChar, 7,  moneyFile);
    int money = atoi(moneyChar);
    cout << "Vous avez " << money << " coins" << endl;
    fclose(moneyFile);

    itemToBuy = getUserInput();
    if (itemToBuy !=0){
        switch(itemToBuy)
        {
            case 1:
                if(money >= 150){
                    cout << "Vous avez acheté l'item 1" << endl;
                    FILE* iconFile = NULL;
                    iconFile = fopen("user/icon.txt", "w");
                    fputs("1", iconFile);
                    fclose(iconFile);
                    FILE* objFile = NULL;
                    objFile = fopen("user/icons/1.txt", "w");
                    fputs("1", objFile);
                    fclose(objFile);
                    money -= 150;
                    break;
                }
            case 2:
                if(money >= 150){
                    cout << "Vous avez acheté l'item 2" << endl;
                    FILE* iconFile = NULL;
                    iconFile = fopen("user/icon.txt", "w");
                    fputs("2", iconFile);
                    fclose(iconFile);
                    FILE* objFile2 = NULL;
                    objFile2 = fopen("user/icons/2.txt", "w");
                    fputs("1", objFile2);
                    fclose(objFile2);
                    money -= 150;
                    break;
                
                }
            case 3:
                if(money >= 150){
                    cout << "Vous avez acheté l'item 3" << endl;
                    FILE* iconFile = NULL;
                    iconFile = fopen("user/icon.txt", "w");
                    fputs("3", iconFile);
                    fclose(iconFile);
                    FILE* objFile3 = NULL;
                    objFile3 = fopen("user/icons/3.txt", "w");
                    fputs("1", objFile3);
                    fclose(objFile3);
                    money -= 150;
                    break;
                }
                case 4:
                if(money >= 350){
                    cout << "Vous avez acheté l'item 4" << endl;
                    FILE* iconFile = NULL;
                    iconFile = fopen("user/icon.txt", "w");
                    fputs("4", iconFile);
                    fclose(iconFile);
                    FILE* objFile4 = NULL;
                    objFile4 = fopen("user/icons/4.txt", "w");
                    fputs("1", objFile4);
                    fclose(objFile4);
                    money -= 350;
                    break;
                }
                case 5:
                if(money >= 350){
                    cout << "Vous avez acheté l'item 5" << endl;
                    FILE* iconFile = NULL;
                    iconFile = fopen("user/icon.txt", "w");
                    fputs("5", iconFile);
                    fclose(iconFile);
                    FILE* objFile5 = NULL;
                    objFile5 = fopen("user/icons/5.txt", "w");
                    fputs("1", objFile5);
                    fclose(objFile5);
                    money -= 350;
                    break;
                }
                case 6:
                if(money >= 350){
                    cout << "Vous avez acheté l'item 6" << endl;
                    FILE* iconFile = NULL;
                    iconFile = fopen("user/icon.txt", "w");
                    fputs("6", iconFile);
                    fclose(iconFile);
                    FILE* objFile6 = NULL;
                    objFile6 = fopen("user/icons/6.txt", "w");
                    fputs("1", objFile6);
                    fclose(objFile6);
                    money -= 350;
                    break;
                }
            default:
                cout << "Cet item n'est pas disponible" << endl;
                break;
        }
        FILE* moneyFile = NULL; //on actualise l'argent du joueur
        moneyFile = fopen("user/coins.txt", "w");
        fputs(to_string(money).c_str(), moneyFile);
        fclose(moneyFile);

    // on ferme la fenêtre
    SDL_DestroyTexture(shopTexture);
    SDL_FreeSurface(shopSurface);
    } 
    }
    if (activity == 6) //collection
    {
        
    SDL_Surface *collectionSurface = IMG_Load("assets/textures/cat-waves.png"); //temporaire
    SDL_Texture *collectionTexture = SDL_CreateTextureFromSurface(mainRenderer, collectionSurface);
    SDL_Rect mainRect = {0, 0, 1280, 720};
    SDL_RenderCopy(mainRenderer, collectionTexture, NULL, &mainRect);
    SDL_Surface *objSurface1 = IMG_Load("assets/icons/1.png");
    SDL_Texture *objTexture1 = SDL_CreateTextureFromSurface(mainRenderer, objSurface1);
    SDL_Surface *objSurface3 = IMG_Load("assets/icons/2.png");
    SDL_Texture *objTexture3 = SDL_CreateTextureFromSurface(mainRenderer, objSurface3);
    SDL_Surface *objSurface4 = IMG_Load("assets/icons/3.png");
    SDL_Texture *objTexture4 = SDL_CreateTextureFromSurface(mainRenderer, objSurface4);
    SDL_Surface *objSurface2 = IMG_Load("assets/icons/0.png");
    SDL_Texture *objTexture2 = SDL_CreateTextureFromSurface(mainRenderer, objSurface2);
    SDL_Rect objRect2 = {200 , 100, 200, 200};
    SDL_RenderCopy(mainRenderer, objTexture2, NULL, &objRect2);
    for (int e = 1; e < 3; e++)
    {
        FILE* objFile = NULL;
        objFile = fopen(("user/icons/" + to_string(e) + ".txt").c_str(), "r");
        cout << "opening file "<< "user/icons/" + to_string(e) + ".txt" << endl;
        char objChar [2]; 
        fgets(objChar, 2,  objFile);
        int obj = atoi(objChar);
        

        if (obj == 1){
            cout << "Vous possédez l'objet " << e << endl;  
            if(e == 1){
            
            SDL_Rect objRect1 = {410 + (e-1) * 210, 100, 200, 200};
            SDL_RenderCopy(mainRenderer, objTexture1, NULL, &objRect1);
            }
            if(e == 2){
            
            SDL_Rect objRect3 = {420 + (e-1) * 210 , 100, 200, 200};
            SDL_RenderCopy(mainRenderer, objTexture3, NULL, &objRect3);
            }
            if (e == 3){
            
            SDL_Rect objRect4 = {430 + (e-1) * 210 , 100, 200, 200};
            SDL_RenderCopy(mainRenderer, objTexture4, NULL, &objRect4);
            }
        }
        else{
            cout << "Vous ne possédez pas l'objet " << e << endl;
        }
        fclose(objFile);
        //si on remet pas à 0, tous les objets sont considérés comme possédés si on a au moins un objet
        obj = 0;
        objFile = NULL;
        objChar[0] = '\0';
    }
    SDL_RenderPresent(mainRenderer);
    chooseIcon = getUserInput();
    FILE* iconFile0 = NULL;
    FILE* iconFile = NULL;
    FILE* iconFile2 = NULL;
    switch(chooseIcon)
    {
        case 0:
            cout << "Vous avez choisi l'item 0" << endl;
            iconFile0 = fopen("user/icon.txt", "w");
            fputs("0", iconFile0);
            fclose(iconFile0);
            break;
        case 1:
            cout << "Vous avez choisi l'item 1" << endl;
            iconFile = fopen("user/icon.txt", "w");
            fputs("1", iconFile);
            fclose(iconFile);
            break;
        case 2:
            cout << "Vous avez choisi l'item 2" << endl;
            iconFile2 = fopen("user/icon.txt", "w");
            fputs("2", iconFile2);
            fclose(iconFile2);
            break;
        default:
            cout << "Cet item n'est pas disponible" << endl;
            break;
    }
    quitCollection = getUserInput();
    while (quitCollection != -2){ //tant que l'utilisateur ne quitte pas la collection
        quitCollection = getUserInput();
    }
    // on ferme la fenêtre
    SDL_DestroyTexture(collectionTexture);
    SDL_FreeSurface(collectionSurface);
    SDL_DestroyTexture(objTexture2);
    SDL_FreeSurface(objSurface2);
    SDL_DestroyTexture(objTexture1);
    SDL_FreeSurface(objSurface1);
    SDL_DestroyTexture(objTexture3);
    SDL_FreeSurface(objSurface3);
    SDL_DestroyTexture(objTexture4);
    SDL_FreeSurface(objSurface4);
    }
        
    if (activity == -2)
    {
        SDL_DestroyWindow(menuWindow);
        return 1; 
    }

    if (!speedrunMode)
    {
        SDL_Delay(100);
        // on ouvre le menu suivant
        SDL_Surface *levelSurface = IMG_Load("assets/textures/level.png");
        SDL_Texture *levelTexture = SDL_CreateTextureFromSurface(mainRenderer, levelSurface);
        SDL_RenderCopy(mainRenderer, levelTexture, NULL, &mainRect);
        SDL_RenderPresent(mainRenderer);
        // on demande le niveau
        level = getUserInput();

        if (level == -2)
        {
            SDL_DestroyTexture(levelTexture);
            SDL_FreeSurface(levelSurface);
            SDL_DestroyWindow(menuWindow);
            return 1;
        }
        if (level == 1 || level == 2 || level == 3 || level == 4 || level == 5 || level == 6 || level == 7 || level == 8 || level == 9 || level == 10)
        {
            SDL_DestroyTexture(levelTexture);
            SDL_FreeSurface(levelSurface);
        }
        else
        {
            cout << "Veuillez entrer un niveau valide" << endl;
            level = getUserInput();
        }
    }

    SDL_Surface *inputSurface = IMG_Load("assets/textures/input.png");
    SDL_Texture *inputTexture = SDL_CreateTextureFromSurface(mainRenderer, inputSurface);
    SDL_RenderCopy(mainRenderer, inputTexture, NULL, &mainRect);
    SDL_RenderPresent(mainRenderer);
    input = 0;
    // si l'input est clavier; on ferme la fenêtre
    do
    {
        input = getUserInput();
        cout << "Merci de choisir votre type d'imput" << endl;
    } while (!(input == 1 || input == 2 || input == -2));
    SDL_DestroyTexture(inputTexture);
    SDL_FreeSurface(inputSurface);
    SDL_DestroyWindow(menuWindow);
    if (input == -2)
    {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    username = auth();
    cout << "Bienvenue " << username << endl;
    bool skipIntro = false;
    // on lance le jeu ssi le menu a retourné 0
    while (menu(skipIntro) == 0)
    {
        Game game(input, level, editorMode, username, speedrunMode);
        // on lance la boucle principale du jeu
        game.run();
        skipIntro = true;
    }
    SDL_Quit();
    return 0;
}
