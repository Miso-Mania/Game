#include "game.h"           //TODO: CREATE A DIFFERENT CLASS FOR OBSTACLES AND PLATTFORMS
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include <random>

const int FPS = 60;
const int window_X_size = 1900;
const int window_Y_size = 1068;
const int NUM_TILES_X = 48;
const int NUM_TILES_Y = 27;
const int TILE_SIZE = 40;
int inputtype = 0;
int actualLevel = 0;
bool running = true;
bool editionMode = false;
string usernameGame = "";
bool showBar = false;

Mix_Music* music = nullptr;


Game::Game(int inputtypeparam, int levelnumber, bool editMode, string userName) : m_window(NULL), m_renderer(NULL), m_currentLevel(0),  showHitbox(false), editMode(false), timeLastFrame(0)
{   
    inputtype = inputtypeparam;
    actualLevel = levelnumber;
    editionMode = editMode;
    usernameGame = userName;
    srand(time(NULL));
    // on initialise la SDL
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    std::cout << "SDL initialized" << std::endl;
    // on créé une fenetre  de 1920*1080, fullscreen et on la rend visible
    m_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_X_size, window_Y_size, SDL_WINDOW_FULLSCREEN);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    std::cout << "Window created" << std::endl;
    //sound
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Failed to initialize SDL2: " << SDL_GetError() << std::endl;
    }
    if (SDL_Init(SDL_INIT_AUDIO) != 0) {
        std::cerr << "Failed to initialize SDL2: " << SDL_GetError() << std::endl;
    }
    if (Mix_Init(MIX_INIT_MP3) != MIX_INIT_MP3)
    {
        std::cerr << "Failed to initialize SDL2 Mixer: " << Mix_GetError() << std::endl;
    }
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) != 0)
    {
        std::cerr << "Failed to open audio device: " << Mix_GetError() << std::endl;
    }
    Mix_Music *music = Mix_LoadMUS("assets/music/lofi.mp3");
    if (!music)
    {
        std::cerr << "Failed to load music file: " << Mix_GetError() << std::endl;
    }
    if (Mix_PlayMusic(music, -1) != 0)
    {
        std::cerr << "Failed to play music: " << Mix_GetError() << std::endl;
    }
    Mix_PlayMusic(music, -1);

    int width, height;
    SDL_GetWindowSize(m_window, &width, &height);
    cout << "width " << width << endl;
    const int TILE_SIZE = width / NUM_TILES_X;
    cout << "TILE_SIZE: " << TILE_SIZE << endl;
    m_surface_player = IMG_Load("assets/textures/icon.png");
    m_texture_player = SDL_CreateTextureFromSurface(m_renderer, m_surface_player);

    m_surface_pic = IMG_Load("assets/textures/spikes.png");
    m_texture_pic = SDL_CreateTextureFromSurface(m_renderer, m_surface_pic);

    m_surface_obstacle = IMG_Load("assets/textures/ground.png");
    m_texture_obstacle = SDL_CreateTextureFromSurface(m_renderer, m_surface_obstacle);

    m_surface_background = IMG_Load("assets/textures/back2.png");
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

    m_surface_DoubleJumpPort = IMG_Load("assets/textures/orb.png");
    m_texture_DoubleJumpPort = SDL_CreateTextureFromSurface(m_renderer, m_surface_DoubleJumpPort);

    m_surface_BoxCmgtGrav = IMG_Load("assets/textures/Manu.png");
    m_texture_BoxCmgtGrav = SDL_CreateTextureFromSurface(m_renderer, m_surface_BoxCmgtGrav);

    m_surface_BoxFinish = IMG_Load("assets/textures/porte_fin.png");
    m_texture_BoxFinish = SDL_CreateTextureFromSurface(m_renderer, m_surface_BoxFinish);

    std::cout << "textures loaded" << endl;

    Level *level = new Level();
    //we add the ground
    level->addObstacle(0, 26, 50, 1);
    //we load the level from the json file
    cout << levelnumber << endl;
    level->loadFromJSON("niveaux/level" + std::to_string(levelnumber) + ".json", TILE_SIZE);
    std::cout << "pushing back level" << levelnumber <<endl;
    
    m_levels.push_back(level);
    // Chargement du joueur
    m_player = Player();
    std::cout << "player created" << endl;
    timer = 0;
    std::cout << "timer created" << endl;

    ParticuleSystem m_particuleSystem = ParticuleSystem();

    timeLastFrame = SDL_GetTicks();
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

    SDL_FreeSurface(m_surface_BoxCmgtGrav);
    SDL_DestroyTexture(m_texture_BoxCmgtGrav);

    Mix_FreeMusic(music);
    Mix_CloseAudio();
    Mix_Quit();

    SDL_Quit();
}

void Game::run()
{
    running = true;
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
        update();
        // Affichage
        render();
    }
}

void Game::handleEvents(SDL_Event &event)
{   
    if(event.type == SDL_MOUSEBUTTONDOWN && editionMode) {
        cout << "click" << endl;
        double x = event.button.x * 1.0 / TILE_SIZE;
        double y = event.button.y * 1.0 / TILE_SIZE;
        m_levels[m_currentLevel]->click(x, y, 40);
    } else if(event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_1:
                m_levels[m_currentLevel]->selectedObj = "Case";
                break;
            case SDLK_2:
                m_levels[m_currentLevel]->selectedObj = "D_Case";
                break;
            case SDLK_3:
                m_levels[m_currentLevel]->selectedObj = "S_Plateform";
                break;
            case SDLK_4:
                m_levels[m_currentLevel]->selectedObj = "M_Plateform";
                break;
            case SDLK_5:
                m_levels[m_currentLevel]->selectedObj = "L_Plateform";
                break;
            case SDLK_6:
                m_levels[m_currentLevel]->selectedObj = "DoubleJumpPort";
                break;
            case SDLK_7:
                m_levels[m_currentLevel]->selectedObj = "BoxFinish";
                break;
            case SDLK_8:
                m_levels[m_currentLevel]->selectedObj = "Tree";
                break;
            case SDLK_9:
                m_levels[m_currentLevel]->selectedObj = "Pic";
                break;
            case SDLK_0:
                m_levels[m_currentLevel]->selectedObj = "BoxCmgtGrav";
                break;
            case SDLK_h:
                showHitbox = !showHitbox;
                break;
            }
        m_levels[m_currentLevel]->saveToJSON("niveaux/level0.json"); //on sauvegarde à chaque touche
        } 

    if( inputtype == 1) {
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
    }else if( inputtype == 2) {
        if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_q:
            m_player.setDirection(PlayerDirection::LEFT);
            break;
        case SDLK_d:
            m_player.setDirection(PlayerDirection::RIGHT);
            break;
        case SDLK_z:
            m_player.jump();
            break;
        }
    }
    else if (event.type == SDL_KEYUP)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_q:
            if (m_player.getDirection() == PlayerDirection::LEFT)
            {
                m_player.setDirection(PlayerDirection::NONE);
            }
            break;
        case SDLK_d:
            if (m_player.getDirection() == PlayerDirection::RIGHT)
            {
                m_player.setDirection(PlayerDirection::NONE);
            }
            break;
        }
    }
    
    }
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_h:
            showHitbox = !showHitbox;
            break;
        case SDLK_ESCAPE:
            running = false;
            break;
        case SDLK_t:
            showBar = !showBar;
            break;
        }
    }
}

void Game::update()
{
    // Calcul du temps écoulé depuis la dernière mise à jour
    double delta = (SDL_GetTicks() - timeLastFrame) / 1000.0;
    timeLastFrame = SDL_GetTicks();
    // Mise à jour de la position du joueur
    m_player.move(delta);
    // Mise à jour de la gravité du joueur
    m_player.gravity(delta);

    m_player.incTimeSinceTouchGround(delta);
    m_player.decJumpBuffer(delta);
    timer += delta;

    m_player.hasCollided = false;
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
        m_player.moveTo(1, 23);
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

    // Le joeur se retourne et il chute jusqu'à y=0 quand il traverse BoxCmgtGrav
    for (BoxCmgtGrav *boxCmgtGrav : m_levels[m_currentLevel]->getBoxCmgtGrav())
    {
        if (m_player.collidesWith(boxCmgtGrav))
        {
            m_player.setGravity(-m_player.getGravity());
            m_player.setDirection(PlayerDirection::NONE);
            m_player.setJumpBuffer(0.1);
            m_player.setTimeSinceTouchGround(0);
        }
    }
    // Le joueur gagne si il touche la BoxFinish
    for (BoxFinish *boxFinish : m_levels[m_currentLevel]->getBoxFinish())
    {
        if (m_player.collidesWith(boxFinish))
        {
            cout << "temps : "  << timer << "s" << endl;
            //on ouvre le fichier /times/levelX.txt, on va récupérer le temps précédent et le comparer avec le nouveau
            FILE* fichierTimes = NULL;
            fichierTimes = fopen(("times/level" + to_string(actualLevel) + ".txt").c_str(), "r");
            if (fichierTimes != NULL)
            {   
                //On récupère le temps précédent
                char tempsPrecedent[7];
                fgets(tempsPrecedent, 7, fichierTimes);
                if (timer < atof(tempsPrecedent))
                {   
                    //On remplace le temps précédent par le nouveau en écrivant dans le fichier que l'on a ouvert
                    fichierTimes = fopen(("times/level" + to_string(actualLevel) + ".txt").c_str(), "w");
                    // on concatène le temps avec l'username
                    string toWrite = to_string(timer) + " by " + usernameGame;
                    
                    //on converti la string toWrite en char*
                    char *cstr = new char[toWrite.length() + 1];
                    strcpy(cstr, toWrite.c_str());
                    fputs(cstr, fichierTimes);
                    cout << cstr << endl;
                    cout << "Le record a été battu de " << atof(tempsPrecedent) - timer << "s !, félicitations "<< usernameGame << endl;
                }
                else
                {
                    cout << "Le record n'a pas été battu à " << timer - atof(tempsPrecedent) << "s près ! Le prochain essai sera le bon !" << endl;
                }
                fclose(fichierTimes);
            }
            timer = 0;
            m_player.moveTo(1, 23);


        
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
    // Mise à jour de la position des Case
    for (Case *Case : m_levels[m_currentLevel]->getCase())
    {
        Case->move(delta);
    }
    // Mise à jour de la position des D_Case
    for (D_Case *d_case : m_levels[m_currentLevel]->getD_Case())
    {
        d_case->move(delta);
    }
    // Mise à jour de la position des BoxCmgtGrav
    for (BoxCmgtGrav *boxCmgtGrav : m_levels[m_currentLevel]->getBoxCmgtGrav())
    {
        boxCmgtGrav->move(delta);
    }
    // Collision du joueur avec les pics stop la partie
    for (Pic *pic : m_levels[m_currentLevel]->getPics())
    {
        if (m_player.collidesWith(pic))
        {
            m_player.moveTo(1, 23);
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

    // ajout de particules sur les arbres
    for (Tree *tree : m_levels[m_currentLevel]->getTrees())
    {   
        if (rand()%20 == 0)
        {
            Coords treeCoords = tree->getCoords();
            double x = treeCoords.x + rand() / (double)RAND_MAX * 2.5 + 0.5;
            double y = treeCoords.y + rand() / (double)RAND_MAX + 1.2;
            double r = 255; //+ rand() / (double)RAND_MAX * 20 - 10;
            double g = 120; //+ rand() / (double)RAND_MAX * 20 - 10;
            double b = 180; //+ rand() / (double)RAND_MAX * 20 - 10;
            Particule *p_particule = new Particule(x, y, 0.1, 0.3, 0, 0, 5, 0.08, r, g, b, 255);
            m_particuleSystem.addParticule(p_particule);
        }
    }

    // ajout de particules sur les portails
    for (DoubleJumpPort *doublejumpport : m_levels[m_currentLevel]->getDoubleJumpPort())
    {   
        if (rand()%5 == 0)
        {
            Coords doublejumpportCoords = doublejumpport->getCoords();
            double x = doublejumpportCoords.x + rand() / (double)RAND_MAX * 0.5 + 0.25;
            double y = doublejumpportCoords.y + rand() / (double)RAND_MAX * 0.5 + 0.25;
            double vx = rand() / (double)RAND_MAX * 16 - 8;
            double vy = rand() / (double)RAND_MAX * 16 - 8;
            double ax = - vx * 4;
            double ay = - vy * 4;
            double r = 0; //+ rand() / (double)RAND_MAX * 20 - 10;
            double g = 255; //+ rand() / (double)RAND_MAX * 20 - 10;
            double b = 255; //+ rand() / (double)RAND_MAX * 20 - 10;
            Particule *p_particule = new Particule(x, y, vx, vy, ax, ay, 0.5, 0.08, r, g, b, 255);
            m_particuleSystem.addParticule(p_particule);
        }
    }

    // ajout de particules sur le sol quand le joueur atterit
    if(m_player.showParticlesOnLand()){
        for(int i = 0; i < 10; i++){
            Coords p = m_player.getCoords();
            double x = p.x + rand() / (double)RAND_MAX * p.w;
            double y = p.y + p.h - 0.1;
            double vx = rand() / (double)RAND_MAX * 2 - 1;
            double vy = rand() / (double)RAND_MAX * 1 - 0.5;
            double life = rand() / (double)RAND_MAX * 0.5 + 0.5;
            double size = rand() / (double)RAND_MAX * 0.1 + 0.1;
            Particule *p_particule = new Particule(x , y, vx, vy, 0, 0, life, size, 255, 255, 255, 100);
            m_particuleSystem.addParticule(p_particule);
        }
    }

    m_particuleSystem.update(delta);

    m_player.updateRect();
}

void Game::render()
{

    Uint8 alpha = 0xFF;
    SDL_SetTextureAlphaMod(m_texture_Case, alpha);
    SDL_SetTextureAlphaMod(m_texture_D_Case, alpha);
    SDL_SetTextureAlphaMod(m_texture_S_Plateform, alpha);
    SDL_SetTextureAlphaMod(m_texture_M_Plateform, alpha);
    SDL_SetTextureAlphaMod(m_texture_L_Plateform, alpha);
    SDL_SetTextureAlphaMod(m_texture_pic, alpha);
    SDL_SetTextureAlphaMod(m_texture_DoubleJumpPort, alpha);
    SDL_SetTextureAlphaMod(m_texture_BoxFinish, alpha);
    SDL_SetTextureAlphaMod(m_texture_BoxCmgtGrav, alpha);
    SDL_SetTextureAlphaMod(m_texture_Trees, alpha);


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

    if (showHitbox){
        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
        Coords coords_j = m_player.getCoords();
        SDL_Rect rectHitbox = {(int)(coords_j.x * 40), (int)(coords_j.y * 40), (int)(coords_j.h * 40), (int)(coords_j.w * 40)};
        SDL_RenderDrawRect(m_renderer, &rectHitbox);
    }
        
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
    // Dessin des BoxFinish
    for (BoxFinish *box : m_levels[m_currentLevel]->getBoxFinish())
    {
        SDL_Rect boxFinishRect = box->getRect();
        SDL_RenderCopy(m_renderer, m_texture_BoxFinish, NULL, &boxFinishRect);
    }
    // Dessin des BoxCmgtGrav
    for (BoxCmgtGrav *boxCmgtGrav : m_levels[m_currentLevel]->getBoxCmgtGrav())
    {
        SDL_Rect boxCmgtGravRect = boxCmgtGrav->getRect();
        SDL_RenderCopy(m_renderer, m_texture_BoxCmgtGrav, NULL, &boxCmgtGravRect);
    }

    
    if (editionMode){
        int x, y;
        bool mouseOnObj = false;
        SDL_GetMouseState(&x, &y);
        SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 150);
        //dessin du surlignage de l'objet survolé par la souris
        for (Case *Case : m_levels[m_currentLevel]->getCase()) {
            SDL_Rect CaseRect = Case->getRect();
            if (x > CaseRect.x && x < CaseRect.x + CaseRect.w && y > CaseRect.y && y < CaseRect.y + CaseRect.h && !mouseOnObj)
            {
                SDL_RenderFillRect(m_renderer, &CaseRect);
                mouseOnObj = true;
            }
        }
        for (D_Case *D_Case : m_levels[m_currentLevel]->getD_Case()) {
            SDL_Rect D_CaseRect = D_Case->getRect();
            if (x > D_CaseRect.x && x < D_CaseRect.x + D_CaseRect.w && y > D_CaseRect.y && y < D_CaseRect.y + D_CaseRect.h && !mouseOnObj)
            {
                SDL_RenderFillRect(m_renderer, &D_CaseRect);
                mouseOnObj = true;
            }
        }
        for (S_Plateform *S_Plateform : m_levels[m_currentLevel]->getS_Plateform()) {
            SDL_Rect S_PlateformRect = S_Plateform->getRect();
            if (x > S_PlateformRect.x && x < S_PlateformRect.x + S_PlateformRect.w && y > S_PlateformRect.y && y < S_PlateformRect.y + S_PlateformRect.h && !mouseOnObj)
            {
                SDL_RenderFillRect(m_renderer, &S_PlateformRect);
                mouseOnObj = true;
            }
        }
        for (M_Plateform *M_Plateform : m_levels[m_currentLevel]->getM_Plateform()) {
            SDL_Rect M_PlateformRect = M_Plateform->getRect();
            if (x > M_PlateformRect.x && x < M_PlateformRect.x + M_PlateformRect.w && y > M_PlateformRect.y && y < M_PlateformRect.y + M_PlateformRect.h && !mouseOnObj)
            {
                SDL_RenderFillRect(m_renderer, &M_PlateformRect);
                mouseOnObj = true;
            }
        }
        for (L_Plateform *L_Plateform : m_levels[m_currentLevel]->getL_Plateform()) {
            SDL_Rect L_PlateformRect = L_Plateform->getRect();
            if (x > L_PlateformRect.x && x < L_PlateformRect.x + L_PlateformRect.w && y > L_PlateformRect.y && y < L_PlateformRect.y + L_PlateformRect.h && !mouseOnObj)
            {
                SDL_RenderFillRect(m_renderer, &L_PlateformRect);
                mouseOnObj = true;
            }
        }
        for (Pic *Pic : m_levels[m_currentLevel]->getPics()) {
            SDL_Rect PicRect = Pic->getRect();
            if (x > PicRect.x && x < PicRect.x + PicRect.w && y > PicRect.y && y < PicRect.y + PicRect.h && !mouseOnObj)
            {
                SDL_RenderFillRect(m_renderer, &PicRect);
                mouseOnObj = true;
            }
        }
        for (DoubleJumpPort *DoubleJumpPort : m_levels[m_currentLevel]->getDoubleJumpPort()) {
            SDL_Rect DoubleJumpPortRect = DoubleJumpPort->getRect();
            if (x > DoubleJumpPortRect.x && x < DoubleJumpPortRect.x + DoubleJumpPortRect.w && y > DoubleJumpPortRect.y && y < DoubleJumpPortRect.y + DoubleJumpPortRect.h && !mouseOnObj)
            {
                SDL_RenderFillRect(m_renderer, &DoubleJumpPortRect);
                mouseOnObj = true;
            }
        }
        for (BoxFinish *BoxFinish : m_levels[m_currentLevel]->getBoxFinish()) {
            SDL_Rect BoxFinishRect = BoxFinish->getRect();
            if (x > BoxFinishRect.x && x < BoxFinishRect.x + BoxFinishRect.w && y > BoxFinishRect.y && y < BoxFinishRect.y + BoxFinishRect.h && !mouseOnObj)
            {
                SDL_RenderFillRect(m_renderer, &BoxFinishRect);
                mouseOnObj = true;
            }
        }
        for (BoxCmgtGrav *BoxCmgtGrav : m_levels[m_currentLevel]->getBoxCmgtGrav()) {
            SDL_Rect BoxCmgtGravRect = BoxCmgtGrav->getRect();
            if (x > BoxCmgtGravRect.x && x < BoxCmgtGravRect.x + BoxCmgtGravRect.w && y > BoxCmgtGravRect.y && y < BoxCmgtGravRect.y + BoxCmgtGravRect.h && !mouseOnObj)
            {
                SDL_RenderFillRect(m_renderer, &BoxCmgtGravRect);
                mouseOnObj = true;
            }
        }
        for (Tree *Tree : m_levels[m_currentLevel]->getTrees()) {
            SDL_Rect TreeRect = Tree->getRect();
            if (x > TreeRect.x && x < TreeRect.x + TreeRect.w && y > TreeRect.y && y < TreeRect.y + TreeRect.h && !mouseOnObj)
            {
                SDL_RenderFillRect(m_renderer, &TreeRect);
                mouseOnObj = true;
            }
        }
        SDL_SetTextureBlendMode(m_texture_Case, SDL_BLENDMODE_BLEND);
        Uint8 alpha = 0x7F; 
        if (!mouseOnObj){
            if (m_levels[m_currentLevel]->selectedObj == "Case") {
                SDL_SetTextureAlphaMod(m_texture_Case, alpha);
                SDL_Rect CaseRect = {x - x % 40, y - y % 40, 40, 40};
                SDL_RenderCopy(m_renderer, m_texture_Case, NULL, &CaseRect);
            } else if (m_levels[m_currentLevel]->selectedObj == "D_Case") {
                SDL_SetTextureAlphaMod(m_texture_D_Case, alpha);
                SDL_Rect D_CaseRect = {x - x % 40, y - y % 40, 80, 80};
                SDL_RenderCopy(m_renderer, m_texture_D_Case, NULL, &D_CaseRect);
            } else if (m_levels[m_currentLevel]->selectedObj == "S_Plateform") {
                SDL_SetTextureAlphaMod(m_texture_S_Plateform, alpha);
                SDL_Rect S_PlateformRect = {x - x % 40, y - y % 40, 40 * 3, 40};
                SDL_RenderCopy(m_renderer, m_texture_S_Plateform, NULL, &S_PlateformRect);
            } else if (m_levels[m_currentLevel]->selectedObj == "M_Plateform") {
                SDL_SetTextureAlphaMod(m_texture_M_Plateform, alpha);
                SDL_Rect M_PlateformRect = {x - x % 40, y - y % 40, 40 * 5, 40};
                SDL_RenderCopy(m_renderer, m_texture_M_Plateform, NULL, &M_PlateformRect);
            } else if (m_levels[m_currentLevel]->selectedObj == "L_Plateform") {
                SDL_SetTextureAlphaMod(m_texture_L_Plateform, alpha);
                SDL_Rect L_PlateformRect = {x - x % 40, y - y % 40, 40 * 7, 40};
                SDL_RenderCopy(m_renderer, m_texture_L_Plateform, NULL, &L_PlateformRect);
            } else if (m_levels[m_currentLevel]->selectedObj == "Pic") {
                SDL_SetTextureAlphaMod(m_texture_pic, alpha);
                SDL_Rect PicRect = {x - x % 40, y - y % 40, 40, 40};
                SDL_RenderCopy(m_renderer, m_texture_pic, NULL, &PicRect);                
            } else if (m_levels[m_currentLevel]->selectedObj == "DoubleJumpPort") {
                SDL_SetTextureAlphaMod(m_texture_DoubleJumpPort, alpha);
                SDL_Rect DoubleJumpPortRect = {x - x % 40, y - y % 40, 40, 40};
                SDL_RenderCopy(m_renderer, m_texture_DoubleJumpPort, NULL, &DoubleJumpPortRect);
            } else if (m_levels[m_currentLevel]->selectedObj == "Tree") {
                SDL_SetTextureAlphaMod(m_texture_Trees, alpha);
                SDL_Rect TreeRect = {x - x % 40, y - y % 40, 40 * 3, 40 * 3};
                SDL_RenderCopy(m_renderer, m_texture_Trees, NULL, &TreeRect);
            } else if (m_levels[m_currentLevel]->selectedObj == "BoxFinish") {
                SDL_SetTextureAlphaMod(m_texture_BoxFinish, alpha);
                SDL_Rect BoxFinishRect = {x - x % 40, y - y % 40, 40, 40*2};
                SDL_RenderCopy(m_renderer, m_texture_BoxFinish, NULL, &BoxFinishRect);
            } else if (m_levels[m_currentLevel]->selectedObj == "BoxCmgtGrav") {
                SDL_SetTextureAlphaMod(m_texture_BoxCmgtGrav, alpha);
                SDL_Rect BoxCmgtGravRect = {x - x % 40, y - y % 40, 40, 40*2};
                SDL_RenderCopy(m_renderer, m_texture_BoxCmgtGrav, NULL, &BoxCmgtGravRect);
            }
        }

        if (showBar){
            int offset = 7;
            //this draws a horizontal bar at the top of the screen with each of the ojects
            SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 100);
            SDL_Rect BarRect = {40*(offset-1), 0, 40 * 36, 40*3};
            SDL_RenderFillRect(m_renderer, &BarRect);

            SDL_Rect CaseRect = {40*(offset), 0, 40, 40};
            SDL_RenderCopy(m_renderer, m_texture_Case, NULL, &CaseRect);
            SDL_Rect D_CaseRect = {40*(2+offset), 0, 40*2, 40*2};
            SDL_RenderCopy(m_renderer, m_texture_D_Case, NULL, &D_CaseRect);
            SDL_Rect S_PlateformRect = {40*(5+offset), 0, 40 * 3, 40};
            SDL_RenderCopy(m_renderer, m_texture_S_Plateform, NULL, &S_PlateformRect);
            SDL_Rect M_PlateformRect = {40*(9+offset), 0, 40 * 5, 40};
            SDL_RenderCopy(m_renderer, m_texture_M_Plateform, NULL, &M_PlateformRect);
            SDL_Rect L_PlateformRect = {40*(15+offset), 0, 40 * 7, 40};
            SDL_RenderCopy(m_renderer, m_texture_L_Plateform, NULL, &L_PlateformRect);
            SDL_Rect DoubleJumpPortRect = {40*(23+offset), 0, 40, 40};
            SDL_RenderCopy(m_renderer, m_texture_DoubleJumpPort, NULL, &DoubleJumpPortRect);
            SDL_Rect BoxFinishRect = {40*(25+offset), 0, 40, 40*2};
            SDL_RenderCopy(m_renderer, m_texture_BoxFinish, NULL, &BoxFinishRect);
            SDL_Rect TreeRect = {40*(27+offset), 0, 40 * 3, 40 * 3};
            SDL_RenderCopy(m_renderer, m_texture_Trees, NULL, &TreeRect);
            SDL_Rect PicRect = {40*(31+offset), 0, 40, 40};
            SDL_RenderCopy(m_renderer, m_texture_pic, NULL, &PicRect);
            SDL_Rect BoxCmgtGravRect = {40*(33+offset), 0, 40, 40*2};
            SDL_RenderCopy(m_renderer, m_texture_BoxCmgtGrav, NULL, &BoxCmgtGravRect);


        }
    }

    // Affichage des particules
    m_particuleSystem.render(m_renderer, window_X_size, window_Y_size);

    // Affichage
    SDL_RenderPresent(m_renderer);
}
