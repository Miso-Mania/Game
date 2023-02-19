#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "level.h"
#include "player.h"

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
    SDL_Rect m_rect;

    SDL_Texture *m_texture_player;
    SDL_Surface *m_surface_player;
    SDL_Texture *m_texture_pic;
    SDL_Surface *m_surface_pic;

    Player m_player;
    vector<Level*> m_levels;
    int m_currentLevel;
};


#endif // GAME_H

