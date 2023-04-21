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
    // on lance le jeu ssi le menu a retourné 0
    while (menu.menu() == 0)
    {
        Game game(menu.input, menu.level, menu.editorMode, menu.username, menu.speedrunMode);
        // on lance la boucle principale du jeu
        game.run();
        menu.skipIntro = true;
    }
    SDL_Quit();
    return 0;
}
