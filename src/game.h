#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "level.h"
#include "player.h"
#include "plateform.h" 

using namespace std;

class Game {
public:
    Game();
    ~Game();
    void run();
    void handleEvents(SDL_Event& event);
    void update(double delta);
    void render();

private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    Player m_player;
    vector<Level*> m_levels;
    int m_currentLevel;
    vector<Platform*> m_platforms;
};


#endif // GAME_H

