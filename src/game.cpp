#include 'game.h'
using namespace std;

Game::Game() {
    isRunning = false;
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
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
    player = Player();
    platforms.push_back(Platform(0, 400, 800, 32));
    platforms.push_back(Platform(0, 300, 32, 32));
    platforms.push_back(Platform(768, 300, 32, 32));
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                    player.moveLeft();
                    break;
                case SDLK_RIGHT:
                    player.moveRight();
                    break;
                case SDLK_SPACE:
                    player.jump();
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void Game::update() {
    player.updatePosition();
    for (int i = 0; i < platforms.size(); i++) {
        if (platforms[i].isColliding(player)) {
            player.updatePosition();
        }
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    player.draw(renderer);
    for (int i = 0; i < platforms.size(); i++) {
        platforms[i].draw(renderer);
    }
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}
