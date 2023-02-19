#include "game.h"           //TODO: CREATE A DIFFERENT CLASS FOR OBSTACLES AND PLATTFORMS
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
const int FPS = 60;
const int window_X_size = 1900;
const int window_Y_size = 1068;

Game::Game() : m_window(NULL), m_renderer(NULL), m_currentLevel(0)
{
    // Initialisation de SDL
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    // on créé une fenetre  de 1920*1080, fullscreen et on la rend visible
    m_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_X_size, window_Y_size, SDL_WINDOW_FULLSCREEN);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    m_surface_player = IMG_Load("../assets/textures/icon.png");
    m_texture_player = SDL_CreateTextureFromSurface(m_renderer, m_surface_player);

    m_surface_pic = IMG_Load("../assets/textures/spikes.png");
    m_texture_pic = SDL_CreateTextureFromSurface(m_renderer, m_surface_pic);

    m_surface_obstacle = IMG_Load("../assets/textures/big-crate.png");
    m_texture_obstacle = SDL_CreateTextureFromSurface(m_renderer, m_surface_obstacle);

    // Chargement des niveaux
    Level *level = new Level();
    // index des hauteurs:
    // ligne la plus haute: window_Y_size - 1000

    // sol
    level->addObstacle(0, window_Y_size - 50, 1900, 200);
    // mur gauche
    level->addPic(20, window_Y_size - 443); // bloc à gauche de l'écran
    level->addObstacle(0, window_Y_size - 400, 300, window_Y_size);

    level->addPic(303, window_Y_size - 88);
    level->addPic(346, window_Y_size - 88);

    level->addObstacle(600, window_Y_size - 150, 100, 20); // à 300 px du bas de l'écran, et a 200 du bord gauche
    level->addPic(630, window_Y_size - 90);
    level->addPic(850, window_Y_size - 90);
    level->addObstacle(1050, window_Y_size - 150, 100, 20);
    level->addPic(1080, window_Y_size - 90);
    level->addPic(1350, window_Y_size - 90);
    level->addObstacle(1400, window_Y_size - 90, 40, 40);
    level->addPic(1450, window_Y_size - 90);
    level->addPic(1500, window_Y_size - 90);
    level->addObstacle(1550, window_Y_size - 130, 40, 80);
    level->addPic(1675, window_Y_size - 90);
    level->addObstacle(1800, window_Y_size - 170, 100, 20);
    level->addPic(1830, window_Y_size - 90);

    level->addObstacle(1645, window_Y_size - 300, 100, 20);
    level->addObstacle(850, window_Y_size - 400, 650, 20);
    level->addPic(990, window_Y_size - 443);
    level->addPic(1315, window_Y_size - 443);
    level->addObstacle(1125, window_Y_size - 500, 100, 20);
    level->addPic(1155, window_Y_size - 540);
    level->addObstacle(600, window_Y_size - 500, 100, 20);
    level->addObstacle(315, window_Y_size - 600, 100, 20);
    level->addObstacle(150, window_Y_size - 500, 100, 20);
    level->addPic(150, window_Y_size - 540);
    level->addPic(210, window_Y_size - 540);
    level->addObstacle(0, window_Y_size - 600, 120, 20);

    level->addObstacle(280, window_Y_size - 730, 340, 20);
    level->addPic(370, window_Y_size - 770);
    level->addObstacle(430, window_Y_size - 770, 40, 40);
    level->addPic(490, window_Y_size - 770);
    level->addObstacle(670, window_Y_size - 600, 100, 20);
    level->addPic(700, window_Y_size - 640);
    level->addObstacle(770, window_Y_size - 730, 100, 20);
    level->addObstacle(970, window_Y_size - 730, 240, 20);
    level->addPic(1070, window_Y_size - 770);
    level->addObstacle(1320, window_Y_size - 730, 100, 20);
    level->addObstacle(1520, window_Y_size - 730, 380, 20);
    level->addPic(1560, window_Y_size - 770);
    level->addObstacle(1620, window_Y_size - 770, 40, 40);
    level->addPic(1680, window_Y_size - 770);
    level->addObstacle(1740, window_Y_size - 810, 40, 80);
    level->addPic(1800, window_Y_size - 770);

    level->addObstacle(1537, window_Y_size - 930, 100, 20);
    level->addObstacle(1050, window_Y_size - 930, 340, 20);
    level->addPic(1140, window_Y_size - 970);
    level->addObstacle(1200, window_Y_size - 970, 40, 40);
    level->addPic(1260, window_Y_size - 970);
    level->addObstacle(850, window_Y_size - 930, 100, 20);
    level->addObstacle(600, window_Y_size - 930, 100, 20);
    level->addObstacle(200, window_Y_size - 930, 190, 20);
    level->addPic(275, window_Y_size - 970);
    level->addObstacle(0, window_Y_size - 930, 100, 20);

    level->addBoxFinish(16, window_Y_size - 1000);

    m_levels.push_back(level);
    // Chargement du joueur
    m_player = Player();
}

Game::~Game()
{
    // Nettoyage de SDL
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    IMG_Quit();
    SDL_FreeSurface(m_surface_player);
    SDL_DestroyTexture(m_texture_player);

    SDL_FreeSurface(m_surface_pic);
    SDL_DestroyTexture(m_texture_pic);
    
    SDL_FreeSurface(m_surface_obstacle);
    SDL_DestroyTexture(m_texture_obstacle);

    SDL_Quit();
}

void Game::run()
{
    bool running = true;
    while (running)
    {
        // Gestion des évènements
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            handleEvents(event);
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }
        // Mise à jour
        update(0.016);
        // Affichage
        render();
    }
}

void Game::handleEvents(SDL_Event &event)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
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
    // Mise à jour de la position du joueur
    m_player.move(delta);
    // Mise à jour de la gravité du joueur
    m_player.gravity(delta);

    m_player.incTimeSinceTouchGround(delta);
    m_player.decJumpBuffer(delta);
    // Collision du joueur avec les obstacles stop la gravité et évite de traverser les obstacles
    for (Obstacle *obstacle : m_levels[m_currentLevel]->getObstacles())
    {
        if (m_player.collidesWith(obstacle))
        {
            m_player.moveOutOf(obstacle);
            // m_player.stopMove();
        }
    }
    // perte si le joeur sort de l'écran
    if (m_player.getRect().y > window_Y_size)
    {
        m_player.setRect({100, 600, 32, 32});
    }

    // le joueur gagne si il arrive entre y=0 et y=138 et x<0
    if (m_player.getRect().y < 138 && m_player.getRect().x < 0)
    {
        m_currentLevel++;
        m_player.setRect({100, 600, 32, 32});
    }
    // Mise à jour de la position des obstacles
    for (Obstacle *obstacle : m_levels[m_currentLevel]->getObstacles())
    {
        obstacle->move(delta);
    }
    // Mise à jour de la position des pics
    for (Pic *pic : m_levels[m_currentLevel]->getPics())
    {
        pic->move(delta);
    }
    // Collision du joueur avec les pics stop la partie
    for (Pic *pic : m_levels[m_currentLevel]->getPics())
    {
        if (m_player.collidesWith(pic))
        {
            m_currentLevel = 0;
            m_player = Player();
        }
    }
    // Mise à jour du niveau
    if (m_levels[m_currentLevel]->getObstacles().size() == 0)
    {
        m_currentLevel++;
    }
}

void Game::render()
{
    // Effacement de l'écran
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    // Dessin du niveau
    SDL_SetRenderDrawColor(m_renderer, 0, 255, 0, 255);
    // Dessin du joueur

    /* SDL_SetRenderDrawColor(m_renderer, 0, 255, 255, 255);
    SDL_Rect playerRect = m_player.getRect();
    SDL_RenderFillRect(m_renderer, &playerRect); */
    SDL_Rect playerRect = m_player.getRect();
    SDL_RenderCopy(m_renderer, m_texture_player, NULL, &playerRect);

    // Dessin des obstacles
    for (Obstacle *obstacle : m_levels[m_currentLevel]->getObstacles())
    {
        SDL_Rect obstacleRect = obstacle->getRect();
        SDL_RenderCopy(m_renderer, m_texture_obstacle, NULL, &obstacleRect);
    }
    // Dessin des pic
    for (Pic *pic : m_levels[m_currentLevel]->getPics())
    {
        SDL_Rect picRect = pic->getRect();
        SDL_RenderCopy(m_renderer, m_texture_pic, NULL, &picRect);
    }
    // Dessin de la fin du niveau
    SDL_SetRenderDrawColor(m_renderer, 125, 255, 66, 255);
    for (BoxFinish *box : m_levels[m_currentLevel]->getBoxFinish())
    {
        SDL_Rect boxFinishRect = box->getRect();
        SDL_RenderFillRect(m_renderer, &boxFinishRect);
    }

    // Affichage
    SDL_RenderPresent(m_renderer);

    // Affichage du message de victoire si le joueur a gagné
    if (m_levels[m_currentLevel]->getObstacles().size() == 0)
    {
        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
        SDL_RenderClear(m_renderer);
        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
        SDL_RenderPresent(m_renderer);
    }
}
