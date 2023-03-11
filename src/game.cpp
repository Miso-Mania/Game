#include "game.h"           //TODO: CREATE A DIFFERENT CLASS FOR OBSTACLES AND PLATTFORMS
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const int FPS = 60;
const int window_X_size = 1900;
const int window_Y_size = 1068;
const int NUM_TILES_X = 48;
const int NUM_TILES_Y = 27;




Game::Game() : m_window(NULL), m_renderer(NULL), m_currentLevel(0)
{
    std::cout << "Select the level that you want to load" << std::endl;
    std::cout << "1: level1" << std::endl;
    std::cout << "2: level2" << std::endl;
    std::cout << "3: Debug Level" << std::endl;
    
    int levelnumber;
    std::cin >> levelnumber;
    std::cout << "You selected level " << levelnumber << std::endl;
    
    // Initialisation de SDL
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    std::cout << "SDL initialized" << std::endl;
    // on créé une fenetre  de 1920*1080, fullscreen et on la rend visible
    m_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_X_size, window_Y_size, SDL_WINDOW_FULLSCREEN);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    std::cout << "Window created" << std::endl;
    int width, height;
    SDL_GetWindowSize(m_window, &width, &height);
    cout << "width " << width << endl;
    const int TILE_SIZE = width / NUM_TILES_X;
    cout << "TILE_SIZE: " << TILE_SIZE << endl;
    m_surface_player = IMG_Load("assets/textures/icon.png");
    m_texture_player = SDL_CreateTextureFromSurface(m_renderer, m_surface_player);

    m_surface_pic = IMG_Load("assets/textures/spikes.png");
    m_texture_pic = SDL_CreateTextureFromSurface(m_renderer, m_surface_pic);

    m_surface_obstacle = IMG_Load("assets/textures/big-crate.png");
    m_texture_obstacle = SDL_CreateTextureFromSurface(m_renderer, m_surface_obstacle);

    m_surface_background = IMG_Load("assets/textures/back.png");
    m_texture_background = SDL_CreateTextureFromSurface(m_renderer, m_surface_background);

    m_surface_Trees = IMG_Load("assets/textures/tree.png");
    m_texture_Trees = SDL_CreateTextureFromSurface(m_renderer, m_surface_Trees);

    m_surface_S_Plateform = IMG_Load("assets/textures/S_Plateform.png");
    m_texture_S_Plateform = SDL_CreateTextureFromSurface(m_renderer, m_surface_S_Plateform);

    m_surface_M_Plateform = IMG_Load("assets/textures/M_Plateform.png");
    m_texture_M_Plateform = SDL_CreateTextureFromSurface(m_renderer, m_surface_M_Plateform);

    m_surface_L_Plateform = IMG_Load("assets/textures/L_Plateform.png");
    m_texture_L_Plateform = SDL_CreateTextureFromSurface(m_renderer, m_surface_L_Plateform);

    m_surface_Case = IMG_Load("assets/textures/block-big.png");
    m_texture_Case = SDL_CreateTextureFromSurface(m_renderer, m_surface_Case);

    m_surface_D_Case = IMG_Load("assets/textures/big-crate.png");
    m_texture_D_Case = SDL_CreateTextureFromSurface(m_renderer, m_surface_D_Case);

    m_surface_DoubleJumpPort = IMG_Load("assets/textures/nkm.png");
    m_texture_DoubleJumpPort = SDL_CreateTextureFromSurface(m_renderer, m_surface_DoubleJumpPort);

    std::cout << "textures loaded" << endl;



    Level *level = new Level();
    //we add the ground
    level->addObstacle(0, 23, 50, 6);
    //we load the level from the json file
    level->loadFromJSON("niveaux/level" + std::to_string(levelnumber) + ".json", TILE_SIZE);
    std::cout << "pushing back level" << endl;
    
    m_levels.push_back(level);
    // Chargement du joueur
    m_player = Player();
    std::cout << "player created" << endl;
    timer = 0;
    std::cout << "timer created" << endl;
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

    SDL_FreeSurface(m_surface_background);
    SDL_DestroyTexture(m_texture_background);

    SDL_FreeSurface(m_surface_Trees);
    SDL_DestroyTexture(m_texture_Trees);

    SDL_FreeSurface(m_surface_DoubleJumpPort);
    SDL_DestroyTexture(m_texture_DoubleJumpPort);

    SDL_FreeSurface(m_surface_BoxFinish);
    SDL_DestroyTexture(m_texture_BoxFinish);

    SDL_FreeSurface(m_surface_S_Plateform);
    SDL_DestroyTexture(m_texture_S_Plateform);

    SDL_FreeSurface(m_surface_M_Plateform);
    SDL_DestroyTexture(m_texture_M_Plateform);

    SDL_FreeSurface(m_surface_L_Plateform);
    SDL_DestroyTexture(m_texture_L_Plateform);

    SDL_FreeSurface(m_surface_Case);
    SDL_DestroyTexture(m_texture_Case);

    SDL_FreeSurface(m_surface_D_Case);
    SDL_DestroyTexture(m_texture_D_Case);


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
    timer += delta;
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
        m_player.moveTo(3, 15);
        timer = 0;
    }

    // Collision du joueur avec la S_Plateformes stop la gravité et évite de traverser les obstacles
    for (S_Plateform *s_plateform : m_levels[m_currentLevel]->getS_Plateform())
    {
        if (m_player.collidesWith(s_plateform))
        {
            m_player.moveOutOf(s_plateform);
            // m_player.stopMove();
        }
    }   
    // Collision du joueur avec la M_Plateformes stop la gravité et évite de traverser les obstacles
    for (M_Plateform *m_plateform : m_levels[m_currentLevel]->getM_Plateform())
    {
        if (m_player.collidesWith(m_plateform))
        {
            m_player.moveOutOf(m_plateform);
            // m_player.stopMove();
        }
    }
    // Collision du joueur avec la L_Plateformes stop la gravité et évite de traverser les obstacles
    for (L_Plateform *l_plateform : m_levels[m_currentLevel]->getL_Plateform())
    {
        if (m_player.collidesWith(l_plateform))
        {
            m_player.moveOutOf(l_plateform);
            // m_player.stopMove();
        }
    }

    // Collision du joueur avec la Case stop la gravité et évite de traverser les obstacles
    for (Case *Case : m_levels[m_currentLevel]->getCase())
    {
        if (m_player.collidesWith(Case))
        {
            m_player.moveOutOf(Case);
        }
    }

    // Collision du joueur avec la D_Case stop la gravité et évite de traverser les obstacles
    for (D_Case *d_case : m_levels[m_currentLevel]->getD_Case())
    {
        if (m_player.collidesWith(d_case))
        {
            m_player.moveOutOf(d_case);
        }
    }

    // Le joueur gagne si il touche la BoxFinish
    for (BoxFinish *boxFinish : m_levels[m_currentLevel]->getBoxFinish())
    {
        if (m_player.collidesWith(boxFinish))
        {
            cout << "temps : "  << timer << "s" << endl;
            m_currentLevel++;
            m_player.moveTo(3, 15);
        }
    }

    // Mise à jour de la position des obstacles
    for (Obstacle *obstacle : m_levels[m_currentLevel]->getObstacles())
    {
        obstacle->move(delta);
    }
    // Mise à jour de la position des S_Plateform
    for (S_Plateform *s_plateform : m_levels[m_currentLevel]->getS_Plateform())
    {
        s_plateform->move(delta);
    }
    // Mise à jour de la position des M_Plateform
    for (M_Plateform *m_plateform : m_levels[m_currentLevel]->getM_Plateform())
    {
        m_plateform->move(delta);
    }
    // Mise à jour de la position des L_Plateform
    for (L_Plateform *l_plateform : m_levels[m_currentLevel]->getL_Plateform())
    {
        l_plateform->move(delta);
    }
    // Mise à jour de la position des pics
    for (Pic *pic : m_levels[m_currentLevel]->getPics())
    {
        pic->move(delta);
    }
    // Mise à jour de la position des doublejumpport
    for (DoubleJumpPort *doublejumpport : m_levels[m_currentLevel]->getDoubleJumpPort())
    {
        doublejumpport->move(delta);
    }
    // Collision du joueur avec les pics stop la partie
    for (Pic *pic : m_levels[m_currentLevel]->getPics())
    {
        if (m_player.collidesWith(pic))
        {
            m_player.moveTo(3, 15);
            timer = 0;
        }
    }
    // Collision du joueur avec les doublejumpport fait un double saut
    for (DoubleJumpPort *doublejumpport : m_levels[m_currentLevel]->getDoubleJumpPort())
    {
        if (m_player.collidesWith(doublejumpport))
        {
            m_player.doubleJump();
        }
    }
    // Mise à jour du niveau
    if (m_levels[m_currentLevel]->getObstacles().size() == 0)
    {
        m_currentLevel++;
    }

    m_player.updateRect();
}

void Game::render()
{
    // Effacement de l'écran
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);



    SDL_RenderCopy(m_renderer, m_texture_background, NULL, NULL); // Dessin du background
    // Dessin des arbres
    for (Case *Case : m_levels[m_currentLevel]->getCase())
    {
        SDL_Rect CaseRect = Case->getRect();
        SDL_RenderCopy(m_renderer, m_texture_Case, NULL, &CaseRect); //A CHANGER EN METTANT LA TEXTURE DES CASES
    }
     for (S_Plateform *S_Plateform : m_levels[m_currentLevel]->getS_Plateform())
    {
        SDL_Rect S_PlateformRect = S_Plateform->getRect();
        SDL_RenderCopy(m_renderer, m_texture_S_Plateform, NULL, &S_PlateformRect);
    }
    for (M_Plateform *M_Plateform : m_levels[m_currentLevel]->getM_Plateform())
    {
        SDL_Rect M_PlateformRect = M_Plateform->getRect();
        SDL_RenderCopy(m_renderer, m_texture_M_Plateform, NULL, &M_PlateformRect);
    }
    for (L_Plateform *L_Plateform : m_levels[m_currentLevel]->getL_Plateform())
    {
        SDL_Rect L_PlateformRect = L_Plateform->getRect();
        SDL_RenderCopy(m_renderer, m_texture_L_Plateform, NULL, &L_PlateformRect);
    }
    //affichage des cases:
    for (Case *Case : m_levels[m_currentLevel]->getCase())
    {
        SDL_Rect CaseRect = Case->getRect();
        SDL_RenderCopy(m_renderer, m_texture_Case, NULL, &CaseRect);
    }
    //affichage des D_case:
    for (D_Case *D_Case : m_levels[m_currentLevel]->getD_Case())
    {
        SDL_Rect D_CaseRect = D_Case->getRect();
        SDL_RenderCopy(m_renderer, m_texture_D_Case, NULL, &D_CaseRect);
    }

     for (Tree *tree : m_levels[m_currentLevel]->getTrees())
    {
        SDL_Rect treeRect = tree->getRect();
        SDL_RenderCopy(m_renderer, m_texture_Trees, NULL, &treeRect);
    }


    SDL_Rect playerRect = m_player.getRect(); // Dessin du joueur
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
    // Dessin des doublejumpport
    for (DoubleJumpPort *doublejumpport : m_levels[m_currentLevel]->getDoubleJumpPort())
    {
        SDL_Rect doublejumpportRect = doublejumpport->getRect();
        SDL_RenderCopy(m_renderer, m_texture_DoubleJumpPort, NULL, &doublejumpportRect);
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
