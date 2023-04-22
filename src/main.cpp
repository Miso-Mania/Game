#include "game.h"
#include "menu.h"
#include <iostream>
#include <string>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
using namespace std;
string username = "";

int main(int argc, char *argv[])
{
    Menu menu;
    username = menu.auth();
    cout << "Bienvenue " << username << endl;
    // we launch the game if the menu is closed
    while (menu.menu() == 0)
    {
        Game game(menu.input, menu.level, menu.editorMode, menu.username, menu.speedrunMode);
        //we launch the main loop of the game
        game.run();
        menu.skipIntro = true;
    }
    SDL_Quit();
    return 0;
}
