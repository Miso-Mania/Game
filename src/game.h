#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "plateform.h"
#include "player.h"
using namespace std;

class Game {
public:
    Game();
    ~Game();
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running();

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    Player player;
    vector<Platform> platforms;
};

#endif // GAME_H

