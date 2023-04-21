#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
using namespace std;

class Menu
{
private:
    SDL_Window *menuWindow;
    SDL_Renderer *mainRenderer;
    
public:
    Menu();
    ~Menu();
    string auth();
    int getUserInput();
    int menu();

    int input;
    int level;
    int activity;
    bool editorMode;
    bool speedrunMode;
    int itemToBuy;
    int quitCollection;
    int chooseIcon;
    string username;
    bool skipIntro;
};



#endif // MENU_H