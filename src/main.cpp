#include <iostream>
#include "game.h"
#include "menu.h"
using namespace std;

int main(int argc, char *argv[]) {
    Menu menu; 
    menu.run();
    Game game;
    game.run();

    return 0;
}