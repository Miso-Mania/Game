#include "game.h"           //TODO: CREATE A DIFFERENT CLASS FOR OBSTACLES AND PLATTFORMS
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
const int FPS = 60;
const int window_X_size = 1900;
const int window_Y_size = 1068;

Game::Game() : m_window(NULL), m_renderer(NULL), m_currentLevel(0)
{
    //* @brief Initialisation de SDL
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    //* @brief on créé une fenetre  de 1920*1080, fullscreen et on la rend visible
    m_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_X_size, window_Y_size, SDL_WINDOW_FULLSCREEN);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    //* @brief on charge les textures, et on les stocke dans des surfaces et des textures
    m_surface_player = IMG_Load("../assets/textures/icon.png");
    m_texture_player = SDL_CreateTextureFromSurface(m_renderer, m_surface_player);

    m_surface_pic = IMG_Load("../assets/textures/spikes.png");
    m_texture_pic = SDL_CreateTextureFromSurface(m_renderer, m_surface_pic);

    m_surface_obstacle = IMG_Load("../assets/textures/big-crate.png");
    m_texture_obstacle = SDL_CreateTextureFromSurface(m_renderer, m_surface_obstacle);
    //* @brief on créé un niveau
    Level *level = new Level();
    //* @brief we add the ground
    level->addObstacle(0, window_Y_size - 50, 1900, 200);
    //* @brief we load the level from the json file
    std::cout << "entering loadFromJSON" << std::endl;
    level->loadFromJSON("../niveaux/level1.json");
    cout << "pushing back level" << endl;
    //* @brief on renvoie le niveau
    m_levels.push_back(level);
    //* @brief Chargement du joueur
    m_player = Player();
}

Game::~Game()
{
    //* @brief Nettoyage de SDL
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    IMG_Quit();
    //* @brief on libère la mémoire
    SDL_FreeSurface(m_surface_player);
    SDL_DestroyTexture(m_texture_player);

    SDL_FreeSurface(m_surface_pic);
    SDL_DestroyTexture(m_texture_pic);
    
    SDL_FreeSurface(m_surface_obstacle);
    SDL_DestroyTexture(m_texture_obstacle);
    //* @brief on ferme SDL et on quitte le programme pour de bon cette fois ci
    SDL_Quit();
}

void Game::run()
{   
    bool running = true;
    while (running)
    {
        //* @brief Gestion des évènements
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            handleEvents(event);
            if (event.type == SDL_QUIT)
            {   
                running = false;
            }
        }
        //* @brief
        update(0.016);
        //* @brief
        render();
    }
}

void Game::handleEvents(SDL_Event &event)
{
    
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        //* @brief  on appuie sur la touche fleche gauche, on va à gauche    
        case SDLK_LEFT:
            m_player.setDirection(PlayerDirection::LEFT);
            break;
        //* @brief si on appuie sur la touche fleche droite, on va à droite
        case SDLK_RIGHT:
            m_player.setDirection(PlayerDirection::RIGHT);
            break;
        //* @brief si on appuie sur la touche espace, on saute        
        case SDLK_SPACE:
            m_player.jump();
            break;
        }
    }
    else if (event.type == SDL_KEYUP)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_LEFT:
            if (m_player.getDirection() == PlayerDirection::LEFT)
            {
                m_player.setDirection(PlayerDirection::NONE);
            }
            break;
        case SDLK_RIGHT:
            if (m_player.getDirection() == PlayerDirection::RIGHT)
            {
                m_player.setDirection(PlayerDirection::NONE);
            }
            break;
        }
    }
}

void Game::update(double delta)
{
    //* @brief Mise à jour de la position du joueur
    m_player.move(delta);
    //* @brief Mise à jour de la gravité du joueur
    m_player.gravity(delta);

    m_player.incTimeSinceTouchGround(delta);
    m_player.decJumpBuffer(delta);
    //* @brief Collision du joueur avec les obstacles stop la gravité et évite de traverser les obstacles
    for (Obstacle *obstacle : m_levels[m_currentLevel]->getObstacles())
    {
        if (m_player.collidesWith(obstacle))
        {
            m_player.moveOutOf(obstacle);
            //* @brief m_player.stopMove();
        }
    }
    //* @brief perte si le joeur sort de l'écran
    if (m_player.getRect().y > window_Y_size)
    {
        m_player.setRect({100, 600, 32, 32});
    }

    //* @brief le joueur gagne si il arrive entre y=0 et y=138 et x<0
    if (m_player.getRect().y < 138 && m_player.getRect().x < 0)
    {
        m_currentLevel++;
        m_player.setRect({100, 600, 32, 32});
    }
    //* @brief Mise à jour de la position des obstacles
    for (Obstacle *obstacle : m_levels[m_currentLevel]->getObstacles())
    {
        obstacle->move(delta);
    }
    //* @brief Mise à jour de la position des pics
    for (Pic *pic : m_levels[m_currentLevel]->getPics())
    {
        pic->move(delta);
    }
    //* @brief Collision du joueur avec les pics stop la partie
    for (Pic *pic : m_levels[m_currentLevel]->getPics())
    {
        if (m_player.collidesWith(pic))
        {
            m_currentLevel = 0;
            m_player = Player();
        }
    }
    //* @brief Mise à jour du niveau
    if (m_levels[m_currentLevel]->getObstacles().size() == 0)
    {
        m_currentLevel++;
    }
}

void Game::render()
{
    //* @brief Effacement de l'écran
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    //* @brief Dessin du niveau
    SDL_SetRenderDrawColor(m_renderer, 0, 255, 0, 255);
    //* @brief Dessin du joueur

    /* SDL_SetRenderDrawColor(m_renderer, 0, 255, 255, 255);
    SDL_Rect playerRect = m_player.getRect();
    SDL_RenderFillRect(m_renderer, &playerRect); */
    SDL_Rect playerRect = m_player.getRect();
    SDL_RenderCopy(m_renderer, m_texture_player, NULL, &playerRect);

    //* @brief Dessin des obstacles
    for (Obstacle *obstacle : m_levels[m_currentLevel]->getObstacles())
    {
        SDL_Rect obstacleRect = obstacle->getRect();
        SDL_RenderCopy(m_renderer, m_texture_obstacle, NULL, &obstacleRect);
    }
    //* @brief Dessin des pic
    for (Pic *pic : m_levels[m_currentLevel]->getPics())
    {
        SDL_Rect picRect = pic->getRect();
        SDL_RenderCopy(m_renderer, m_texture_pic, NULL, &picRect);
    }
    //* @brief Dessin de la fin du niveau
    SDL_SetRenderDrawColor(m_renderer, 125, 255, 66, 255);
    for (BoxFinish *box : m_levels[m_currentLevel]->getBoxFinish())
    {
        SDL_Rect boxFinishRect = box->getRect();
        SDL_RenderFillRect(m_renderer, &boxFinishRect);
    }

    //* @brief Affichage
    SDL_RenderPresent(m_renderer);

    //* @brief Affichage du message de victoire si le joueur a gagné
    if (m_levels[m_currentLevel]->getObstacles().size() == 0)
    {
        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
        SDL_RenderClear(m_renderer);
        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
        SDL_RenderPresent(m_renderer);
    }
}
