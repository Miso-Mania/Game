#include "game.h"
const int FPS = 60;
const int window_X_size = 1900;
const int window_Y_size = 1068;

Game::Game() : m_window(NULL), m_renderer(NULL), m_currentLevel(0) {
    // Initialisation de SDL
    SDL_Init(SDL_INIT_VIDEO);
    //on créé une fenetre  de 1920*1080, fullscreen et on la rend visible
    m_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_X_size, window_Y_size, SDL_WINDOW_FULLSCREEN);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // Chargement des niveaux
    Level* level = new Level();
    //sol
    level->addObstacle(0,window_Y_size - 50, 1900, 200);
    //mur gauche
    level->addPic(20, window_Y_size - 443); //bloc à gauche de l'écran
    level->addObstacle(0, window_Y_size-400, 300, window_Y_size);

    level->addPic(303, window_Y_size - 88);
    level->addPic(346, window_Y_size - 88);

    level->addObstacle(600, window_Y_size - 150, 100, 20); //à 300 px du bas de l'écran, et a 200 du bord gauche
    level->addPic(630, window_Y_size - 90);
    level->addPic(850, window_Y_size - 90);
    level->addObstacle(1050, window_Y_size - 150, 100, 20);
    level->addPic(1080, window_Y_size - 90);
    level->addPic(1350, window_Y_size - 90);
    level->addObstacle(1400, window_Y_size -90, 40, 40);
    level->addPic(1450, window_Y_size - 90);
    level->addPic(1500, window_Y_size - 90);
    level->addObstacle(1550, window_Y_size - 130, 40, 80);
    level->addPic(1675, window_Y_size - 90);
    level->addObstacle(1800, window_Y_size - 150, 100, 20);
    level->addPic(1830, window_Y_size - 90);


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
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                m_player.setDirection(PlayerDirection::LEFT);
                break;
            case SDLK_RIGHT:
                m_player.setDirection(PlayerDirection::RIGHT);
                break;
            case SDLK_SPACE:
                m_player.jump();
                break;
        }
    } else if (event.type == SDL_KEYUP) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                if (m_player.getDirection() == PlayerDirection::LEFT) {
                    m_player.setDirection(PlayerDirection::NONE);
                }
                break;
            case SDLK_RIGHT:
                if (m_player.getDirection() == PlayerDirection::RIGHT) {
                    m_player.setDirection(PlayerDirection::NONE);
                }
                break;
        }
    }

}

void Game::update(double delta) {
    // Mise à jour de la position du joueur
    m_player.move(delta);
    // Mise à jour de la gravité du joueur
    m_player.gravity(delta);
    // Collision du joueur avec les obstacles stop la gravité et évite de traverser les obstacles
    for (Obstacle* obstacle : m_levels[m_currentLevel]->getObstacles()) {
        if (m_player.collidesWith(obstacle)) {
            m_player.stopGravity();
            //m_player.stopMove();
        }
    }
    // perte si le joeur sort de l'écran
    if (m_player.getRect().y > window_Y_size) {
        m_player.setRect({200, 500, 32, 32});
    }
    // Mise à jour de la position des obstacles
    for (Obstacle* obstacle : m_levels[m_currentLevel]->getObstacles()) {
        obstacle->move(delta);
    }
    // Ajout d'un nouvel obstacle
    if (m_levels[m_currentLevel]->getObstacles().size() == 0 || m_levels[m_currentLevel]->getObstacles().back()->getRect().x < 400) {
        int x = 640;
        int y = 440;
        int width = 20 + rand() % 100;
        int height = 20;
        m_levels[m_currentLevel]->addObstacle(x, y, width, height);
    }
    // Mise à jour de la position des pics
    for (Pic* pic : m_levels[m_currentLevel]->getPics()) {
        pic->move(delta);
    }
    // Ajout d'un nouveau pic
    if (m_levels[m_currentLevel]->getPics().size() == 0 || m_levels[m_currentLevel]->getPics().back()->getRect().x < 400) {
        int x = 640;
        int y = 440;
        m_levels[m_currentLevel]->addPic(x, y);
    }
    // Collision du joueur avec les pics stop la partie
    for (Pic* pic : m_levels[m_currentLevel]->getPics()) {
        if (m_player.collidesWith(pic)) {
            m_currentLevel = 0;
            m_player = Player();
        }
    }
    // Mise à jour du niveau
    if (m_levels[m_currentLevel]->getObstacles().size() == 0) {
        m_currentLevel++;
    }
}

void Game::render() {
    // Effacement de l'écran
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    // Dessin du niveau
    SDL_SetRenderDrawColor(m_renderer, 0, 255, 0, 255);
    // Dessin du joueur
    SDL_SetRenderDrawColor(m_renderer, 0, 255, 255, 255);
    SDL_Rect playerRect = m_player.getRect();
    SDL_RenderFillRect(m_renderer, &playerRect);
    // Dessin des obstacles
    SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
    for (Obstacle* obstacle : m_levels[m_currentLevel]->getObstacles()) {
        SDL_Rect obstacleRect = obstacle->getRect();
        SDL_RenderFillRect(m_renderer, &obstacleRect);
    }
    // Dessin d'un pic
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 0, 255);
    for (Pic* pic : m_levels[m_currentLevel]->getPics()) {
        SDL_Rect picRect = pic->getRect();
        SDL_RenderFillRect(m_renderer, &picRect);
    }
    // Affichage
    SDL_RenderPresent(m_renderer);
}
