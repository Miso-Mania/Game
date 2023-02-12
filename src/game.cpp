#include "game.h"
using namespace std;

Game::Game() :
    window(NULL), renderer(NULL), isRunning(true), player(0, 0, 20, 20) {
    platforms.push_back(Platform(0, 500, 800, 100));
    }

Game::~Game() {
    clean();
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }
        }
        isRunning = true;
    }
    player = Player(0, 0, 50, 50);
    platforms.push_back(Platform(0, 500, 800, 100));
    platforms.push_back(Platform(0, 400, 200, 100));
    platforms.push_back(Platform(600, 400, 200, 100));
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    player.update();
    for (int i = 0; i < platforms.size(); i++) {
        if (platforms[i].isColliding(player)) {
            player.onCollision(platforms[i]);
        }
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    player.render(renderer);
    for (int i = 0; i < platforms.size(); i++) {
        platforms[i].draw(renderer);
    }
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::running() {
    return isRunning;
}




