#include "game.h"

Game::Game() : m_window(NULL), m_renderer(NULL), m_currentLevel(0) {
    // Initialisation de SDL
    SDL_Init(SDL_INIT_VIDEO);
    m_window= SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // Chargement des niveaux
    Level* level = new Level();
    level->addObstacle(0, 0, 640, 20);
    level->addObstacle(0, 0, 20, 480);
    level->addObstacle(620, 0, 20, 480);
    level->addObstacle(0, 460, 640, 20);
    m_levels.push_back(level);
    // Chargement du joueur
    m_player = Player();
}

Game:: ~Game() {
    // Nettoyage de SDL
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Game::run() {
    bool running = true;
    while (running) {
        // Gestion des évènements
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            handleEvents (event);
            if (event.type == SDL_QUIT) {
                running = false;
            }
    }
    // Mise à jour
    update(0.016);
    // Affichage
    render();
    }
}

void Game::handleEvents(SDL_Event& event) {
    // Traitement des évènements de la souris et du clavier
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                m_player.setDirection(PlayerDirection::UP);
                break;
            case SDLK_DOWN:
                m_player.setDirection(PlayerDirection::DOWN);
                break;
            case SDLK_LEFT:
                m_player.setDirection(PlayerDirection::LEFT);
                break;
            case SDLK_RIGHT:
                m_player.setDirection(PlayerDirection::RIGHT);
                break;
            default:
                break;
        }
    }
}

void Game::update(double delta) {
    // Mise à jour de la position du joueur
    m_player.update(delta);
    // Mise à jour du niveau actuel
    m_levels[m_currentLevel]->update(delta);
    // Vérification des collisions
    for (Obstacle* obstacle : m_levels[m_currentLevel]->getObstacles()) {
        if (m_player.collidesWith(obstacle)) {
            m_player.setDirection(PlayerDirection::NONE);
        }
    }
}

void Game::render() {
    // Effacement de l'écran
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    // Dessin du joueur
    m_player.render(m_renderer);
    // Dessin du niveau
    m_levels[m_currentLevel]->render(m_renderer);
    // Affichage à l'écran
    SDL_RenderPresent(m_renderer);
}
