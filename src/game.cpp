#include "game.h"          
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <random>

const int FPS = 60;
const int window_X_size = 1900;
const int window_Y_size = 1068;
const int NUM_TILES_X = 48;
const int NUM_TILES_Y = 27;
const int TILE_SIZE = 40;
const int NUM_LEVELS = 8;
int inputtype = 0;
int actualLevel = 0;
bool running = true;
bool editionMode = false;
bool speedrun = false;
string usernameGame = "";
bool showBar = false;
int inconNb = 0;

Mix_Music* music = nullptr;


Game::Game(int inputtypeparam, int levelnumber, bool editMode, string userName, bool speedR) : m_window(NULL), m_renderer(NULL), m_currentLevel(0),  showHitbox(false), editMode(false), timeLastFrame(0)
{   
    inputtype = inputtypeparam;
    actualLevel = levelnumber;
    editionMode = editMode;
    usernameGame = userName;
    speedrun = speedR;
    srand(time(NULL));
    // on initialise la SDL
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    m_font = TTF_OpenFont("font/Kemco Pixel Bold.ttf", 50);
    if (m_font == NULL) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }

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
    Mix_Music *on_the_level = Mix_LoadMUS("assets/music/lofi.mp3");
    if (!music)
    {
        std::cerr << "Failed to load music file: " << Mix_GetError() << std::endl;
    }
    if (Mix_PlayMusic(music, -1) != 0)
    {
        std::cerr << "Failed to play music: " << Mix_GetError() << std::endl;
    }
    Mix_PlayMusic(on_the_level, -1);
    int width, height;
    cout << speedrun << endl;
    SDL_GetWindowSize(m_window, &width, &height);
    cout << "width " << width << endl;
    const int TILE_SIZE = width / NUM_TILES_X;
    cout << "TILE_SIZE: " << TILE_SIZE << endl;
    
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

    m_surface_BoxCmgtGrav = IMG_Load("assets/textures/bounce.png");
    m_texture_BoxCmgtGrav = SDL_CreateTextureFromSurface(m_renderer, m_surface_BoxCmgtGrav);

    m_surface_BoxFinish = IMG_Load("assets/textures/porte_fin.png");
    m_texture_BoxFinish = SDL_CreateTextureFromSurface(m_renderer, m_surface_BoxFinish);

    std::cout << "textures loaded" << endl;
    std::cout << "Now loading player icon" << endl;
    FILE *iconFile = NULL;
    iconFile = fopen("user/icon.txt", "r");
    if (iconFile != NULL)
    {
        char icon[2];
        fgets(icon, 2, iconFile);
        fclose(iconFile);
        //if null, we load the default icon
        if (icon[0] == '\0') 
        {
            m_surface_player = IMG_Load("assets/icons/0.png");
        }
        else{ 
            char iconPath[20] = "assets/icons/";
            strcat(iconPath, icon);
            strcat(iconPath, ".png"); 
            m_surface_player = IMG_Load(iconPath);
            iconNb = atoi(icon);
        }
    }
    else 
    {
        cout << "icon.txt not found" << endl;
        m_surface_player = IMG_Load("assets/icons/0.png");
    }

    m_texture_player = SDL_CreateTextureFromSurface(m_renderer, m_surface_player);

    Level *level = new Level();
    //we add the ground
    level->addObstacle(0, 26, 50, 1);
    //we load the level from the json file
    cout << levelnumber << endl;
    level->loadFromJSON("niveaux/level" + std::to_string(levelnumber) + ".json", TILE_SIZE);
    std::cout << "pushing back level" << levelnumber <<endl;
    
    m_levels.push_back(level);

    // loading of the others level is only for speedrun
    for(int i = 2; i <= NUM_LEVELS; i++){
        if(speedR){
            Level *level = new Level();
            level->addObstacle(0, 26, 50, 1);
            level->loadFromJSON("niveaux/level" + std::to_string(i) + ".json", TILE_SIZE);
            m_levels.push_back(level);
        }
    }

    // load the player
    m_player = Player();
    std::cout << "player created" << endl;
    timer = 0;
    std::cout << "timer created" << endl;

    FILE* fichierTimes = NULL;
    if (speedR)
    {
        fichierTimes = fopen("times/speedrun.txt", "r");
    }
    else
    {
        fichierTimes = fopen(("times/level" + std::to_string(levelnumber) + ".txt").c_str(), "r");
    }
    char best[7];
    fgets(best, 7, fichierTimes);
    bestTime = atof(best);

    ParticuleSystem m_particuleSystem = ParticuleSystem();

    timeLastFrame = SDL_GetTicks();
    PlayerCoordsLastFrame = m_player.getCoords();
}

Game::~Game()
{
    // we free the memory
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

    SDL_FreeSurface(m_surface_Timer);
    SDL_DestroyTexture(m_texture_Timer);

    Mix_FreeMusic(music);
    Mix_CloseAudio();
    Mix_Quit();

    TTF_CloseFont(m_font);
    TTF_Quit();

    SDL_Quit();
}

void Game::run()
{
    running = true;
    while (running)
    {
        // Events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            handleEvents(event);
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }
        // update of the game
        update();
        // render of the game
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
        m_levels[m_currentLevel]->saveToJSON("niveaux/level0.json"); //every key pressed save the level
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
    // we get the time since the last frame
    delta = (SDL_GetTicks() - timeLastFrame) / 1000.0;
    timeLastFrame = SDL_GetTicks();
    // update of the player
    m_player.move(delta);
    // update of the camera
    m_player.gravity(delta);

    m_player.incTimeSinceTouchGround(delta);
    m_player.decJumpBuffer(delta);
    timer += delta;

    m_player.hasCollided = false;
    // collision of the player with the obstacles
    for (Obstacle *obstacle : m_levels[m_currentLevel]->getObstacles())
    {
        if (m_player.collidesWith(obstacle))
        {
            m_player.moveOutOf(obstacle);
            // m_player.stopMove();
        }
    }
    // we loose if the player is out of the screen
    if (m_player.getRect().y > window_Y_size)
    {
        m_player.moveTo(1, 23);
        if(!speedrun) timer = 0;
    }

    // Collision between the player and the S_Plateformes
    for (S_Plateform *s_plateform : m_levels[m_currentLevel]->getS_Plateform())
    {
        if (m_player.collidesWith(s_plateform))
        {
            m_player.moveOutOf(s_plateform);
            // m_player.stopMove();
        }
    }   
    // Collision between the player and the M_Plateformes
    for (M_Plateform *m_plateform : m_levels[m_currentLevel]->getM_Plateform())
    {
        if (m_player.collidesWith(m_plateform))
        {
            m_player.moveOutOf(m_plateform);
            // m_player.stopMove();
        }
    }
    // Collision between the player and the SLPlateformes
    for (L_Plateform *l_plateform : m_levels[m_currentLevel]->getL_Plateform())
    {
        if (m_player.collidesWith(l_plateform))
        {
            m_player.moveOutOf(l_plateform);
            // m_player.stopMove();
        }
    }

    // Collision between the player and the case
    for (Case *Case : m_levels[m_currentLevel]->getCase())
    {
        if (m_player.collidesWith(Case))
        {
            m_player.moveOutOf(Case);
        }
    }

    // Collision between the player and the D_Case
    for (D_Case *d_case : m_levels[m_currentLevel]->getD_Case())
    {
        if (m_player.collidesWith(d_case))
        {
            m_player.moveOutOf(d_case);
        }
    }

    // Collision between the player and the BoxCmgtGrav
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
    // if the player touches the finish, we go to the next level
    for (BoxFinish *boxFinish : m_levels[m_currentLevel]->getBoxFinish())  
    {
        if (m_player.collidesWith(boxFinish))
        {

            if(speedrun){
                m_currentLevel++;
                m_player.moveTo(1, 23);
                if (m_currentLevel >= NUM_LEVELS)
                {
                    m_currentLevel = 0;
                    cout << "temps : "  << timer << "s" << endl;
                    // we open the file speedrun.txt and we write the time if it's better than the previous one
                    FILE* fichierTimes = NULL;
                    fichierTimes = fopen("times/speedrun.txt", "r");
                    if (fichierTimes != NULL)
                    {   
                        //On récupère le temps précédent
                        char tempsPrecedent[7];
                        fgets(tempsPrecedent, 7, fichierTimes);
                        if (timer < atof(tempsPrecedent))
                        {   
                            // we remove the previous time and we write the new one
                            fichierTimes = fopen("times/speedrun.txt", "w");
                            // we add the usernamee
                            string toWrite = to_string(timer) + " by " + usernameGame;
                            // we convert the string to a char*
                            char *cstr = new char[toWrite.length() + 1];
                            strcpy(cstr, toWrite.c_str());
                            fputs(cstr, fichierTimes);
                            cout << "Le record a été battu à " << timer - atof(tempsPrecedent) << "s près ! Félicitations !" << endl;
                            bestTime = timer;
                        }
                        else
                        {
                            cout << "Le record n'a pas été battu à " << timer - atof(tempsPrecedent) << "s près ! Le prochain essai sera le bon !" << endl;
                        }
                        fclose(fichierTimes);
                    }
                    timer = 0;
                }
            }
            else{

                cout << "temps : "  << timer << "s" << endl;
                //we open the file levelX.txt and we write the time if it's better than the previous one
                FILE* fichierTimes = NULL;
                fichierTimes = fopen(("times/level" + to_string(actualLevel) + ".txt").c_str(), "r");
                if (fichierTimes != NULL)
                {   
                    // we get the previous time
                    char tempsPrecedent[7];
                    fgets(tempsPrecedent, 7, fichierTimes);
                    if (timer < atof(tempsPrecedent))
                    {   
                        // we remove the previous time and we write the new one
                        fichierTimes = fopen(("times/level" + to_string(actualLevel) + ".txt").c_str(), "w");
                        // we add the username
                        string toWrite = to_string(timer) + " by " + usernameGame;
                        
                        // we convert the string to a char*
                        char *cstr = new char[toWrite.length() + 1];
                        strcpy(cstr, toWrite.c_str());
                        fputs(cstr, fichierTimes);
                        cout << cstr << endl;
                        cout << "Le record a été battu de " << atof(tempsPrecedent) - timer << "s !, félicitations "<< usernameGame << endl;
                        bestTime = timer;
                    }
                    else
                    {
                        cout << "Le record n'a pas été battu à " << timer - atof(tempsPrecedent) << "s près ! Le prochain essai sera le bon !" << endl;
                    }
                    fclose(fichierTimes);
                    FILE* fichierCoins = NULL;
                    fichierCoins = fopen("user/coins.txt", "r");
                    char coins [7]; 
                    fgets(coins, 7,  fichierCoins);
                    int coinsInt = atoi(coins);
                    fclose(fichierCoins);
                    //we add coins to the user, 10 coins - the difference between the previous best time and the current time
                    int coinsToAdd = 10 - round(timer - atof(tempsPrecedent));
                    if (coinsToAdd < 0)
                    {
                        coinsToAdd = 0;
                    }
                    coinsInt += coinsToAdd;
                    FILE* fichierCoins2 = NULL;
                    fichierCoins2 = fopen("user/coins.txt", "w");
                    if (fichierCoins2 != NULL){
                        fputs(to_string(coinsInt).c_str(), fichierCoins2);
                        cout << "Vous avez gagné " << coinsToAdd << " coins !" << endl;
                        cout << "Vous avez maintenant " << coinsInt << " coins !" << endl;
                       
                    }
                    else{ //we add 100 coins if it's the first time the user finishes the level
                        fputs("100", fichierCoins2);
                        cout << "Bravo pour ton premier niveau terminé ! Tu as gagné 100 coins !" << endl;
                        
                    }
                    fclose(fichierCoins2);
                    timer = 0;
                    m_player.moveTo(1, 23);
                    

                    
                }
            }    

        }
    }


    // update for the obstacle
    for (Obstacle *obstacle : m_levels[m_currentLevel]->getObstacles())
    {
        obstacle->move(delta);
    }
    // update for the S_Plateform
    for (S_Plateform *s_plateform : m_levels[m_currentLevel]->getS_Plateform())
    {
        s_plateform->move(delta);
    }
    // update for the M_Plateform
    for (M_Plateform *m_plateform : m_levels[m_currentLevel]->getM_Plateform())
    {
        m_plateform->move(delta);
    }
    // update for the L_Plateform
    for (L_Plateform *l_plateform : m_levels[m_currentLevel]->getL_Plateform())
    {
        l_plateform->move(delta);
    }
    // update for the Pic
    for (Pic *pic : m_levels[m_currentLevel]->getPics())
    {
        pic->move(delta);
    }
    // update for the doublejumpport
    for (DoubleJumpPort *doublejumpport : m_levels[m_currentLevel]->getDoubleJumpPort())
    {
        doublejumpport->move(delta);
    }
    // update for the case
    for (Case *Case : m_levels[m_currentLevel]->getCase())
    {
        Case->move(delta);
    }
    // update for the d_case
    for (D_Case *d_case : m_levels[m_currentLevel]->getD_Case())
    {
        d_case->move(delta);
    }
    // update for the boxCmgtGrav
    for (BoxCmgtGrav *boxCmgtGrav : m_levels[m_currentLevel]->getBoxCmgtGrav())
    {
        boxCmgtGrav->move(delta);
    }
    // we check if the player is on a spike, if it is, we reset the level and the timer
    for (Pic *pic : m_levels[m_currentLevel]->getPics())
    {
        if (m_player.collidesWith(pic))
        {
            m_player.moveTo(1, 23);
            if(!speedrun) timer = 0;
        }
    }
    // we check if the player is on a doublejumpport, if it is, we give him a double jump
    for (DoubleJumpPort *doublejumpport : m_levels[m_currentLevel]->getDoubleJumpPort())
    {
        if (m_player.collidesWith(doublejumpport))
        {
            m_player.doubleJump();
        }
    }
    // update of the level
    if (m_levels[m_currentLevel]->getObstacles().size() == 0)
    {
        m_currentLevel++;
    }

    // we add particules to the trees
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
            Particule *p_particule = new Particule(x, y, 0.1, 0.3, 0, 0, 5, 0.08, r, g, b, 255, SDL_BLENDMODE_BLEND);
            m_particuleSystem.addParticule(p_particule);
        }
    }

    // particles for the doublejumpport
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
            Particule *p_particule = new Particule(x, y, vx, vy, ax, ay, 0.5, 0.08, r, g, b, 255, SDL_BLENDMODE_BLEND);
            m_particuleSystem.addParticule(p_particule);
        }
    }

    // particles on the ground when the player lands
    if(m_player.showParticlesOnLand()){
        for(int i = 0; i < 10; i++){
            Coords p = m_player.getCoords();
            double x = p.x + rand() / (double)RAND_MAX * p.w;
            double y = p.y + p.h - 0.1;
            double vx = rand() / (double)RAND_MAX * 2 - 1;
            double vy = rand() / (double)RAND_MAX * 1 - 0.5;
            double life = rand() / (double)RAND_MAX * 0.5 + 0.5;
            double size = rand() / (double)RAND_MAX * 0.1 + 0.1;
            Particule *p_particule = new Particule(x , y, vx, vy, 0, 0, life, size, 255, 255, 255, 100, SDL_BLENDMODE_BLEND);
            m_particuleSystem.addParticule(p_particule);
        }
    }

    // particles at the end of the level
    for(BoxFinish *boxFinish : m_levels[m_currentLevel]->getBoxFinish()){
        if (rand()%5 == 0)
        {
            Coords boxFinishCoords = boxFinish->getCoords();
            double x = boxFinishCoords.x + rand() / (double)RAND_MAX * 0.5 + 0.25;
            double y = boxFinishCoords.y + rand() / (double)RAND_MAX * 1.5 + 0.5;
            double vx = rand() / (double)RAND_MAX * 8 - 4;
            double vy = rand() / (double)RAND_MAX * 8 - 4;
            double ax = - vx;
            double ay = - vy;

            double h = rand() / (double)RAND_MAX * 360;
            double s = 1;
            double l = 0.5;
            
            // Convert from HSL to RGB

            float chroma = (1 - std::abs(2 * l - 1)) * s;
            float huePrime = h / 60.0;
            float component2 = chroma * (1 - std::abs(std::fmod(huePrime, 2) - 1));
            float red, green, blue;
            
            if (0 <= huePrime && huePrime < 1) {
                red = chroma;
                green = component2;
                blue = 0;
            } else if (1 <= huePrime && huePrime < 2) {
                red = component2;
                green = chroma;
                blue = 0;
            } else if (2 <= huePrime && huePrime < 3) {
                red = 0;
                green = chroma;
                blue = component2;
            } else if (3 <= huePrime && huePrime < 4) {
                red = 0;
                green = component2;
                blue = chroma;
            } else if (4 <= huePrime && huePrime < 5) {
                red = component2;
                green = 0;
                blue = chroma;
            } else {
                red = chroma;
                green = 0;
                blue = component2;
            }
            
            float lightnessAdjustment = l - chroma / 2;
            red += lightnessAdjustment;
            green += lightnessAdjustment;
            blue += lightnessAdjustment;
            
            int r = round(red * 255);
            int g = round(green * 255);
            int b = round(blue * 255);

            Particule *p_particule = new Particule(x, y, vx, vy, ax, ay, 1, 0.12, r, g, b, 255, SDL_BLENDMODE_ADD);
            m_particuleSystem.addParticule(p_particule);
        }
    }

    // special particles for the player if he has the icon 7 or 8
    Coords p = m_player.getCoords();
    Coords dir = Coords(p.x - PlayerCoordsLastFrame.x, p.y - PlayerCoordsLastFrame.y, 0, 0);
    //double dirNorm = sqrt(dir.x * dir.x + dir.y * dir.y);
    //Coords dirNormed = Coords(dir.x / dirNorm, dir.y / dirNorm, 0, 0);
    if((iconNb == 7 || iconNb == 8) &&
        (dir.x != 0 || dir.y != 0) &&
        !(m_player.getDirection() == PlayerDirection::NONE && m_player.getIsOnGround())){
        if (rand()%2 == 0){
            double size = 0.1 + rand() / (double)RAND_MAX * 0.3;
            double x = p.x + rand() / (double)RAND_MAX * (p.w - size);
            double y = p.y + rand() / (double)RAND_MAX * (p.h - size);
            double vx = 0;
            double vy = 0;
            double ax = rand() / (double)RAND_MAX * 3 - 1.5;
            double ay = rand() / (double)RAND_MAX * 3 - 1.5;

            double life = rand() / (double)RAND_MAX * 1 + 0.6;
            
            double r = 50 + rand() / (double)RAND_MAX * 40 - 20;
            double g = 50 + rand() / (double)RAND_MAX * 40 - 20;
            double b = 235 + rand() / (double)RAND_MAX * 40 - 20;

            Particule *p_particule = new Particule(x, y, vx, vy, ax, ay, life, size, r, g, b, 150, SDL_BLENDMODE_ADD);
            m_particuleSystem.addParticule(p_particule);
        }
    }

    m_particuleSystem.update(delta);

    m_player.updateRect();

    PlayerCoordsLastFrame = m_player.getCoords();
}

void Game::renderTimer(int y, double time){
    SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
    int size_timer;
        if(time < 10) size_timer = 4;
        else if(time < 100) size_timer = 5;
        else if(time < 1000) size_timer = 6;
        else size_timer = 7;
        string temp = to_string(time);
        char *char_timer = new char[temp.length()];
        strcpy(char_timer, temp.c_str());
        char_timer[size_timer] = '\0';
        char_timer[size_timer-3] = '.';

        SDL_Color white = {255, 255, 255};
        m_surface_Timer = TTF_RenderText_Solid(m_font, char_timer, white);
        m_texture_Timer = SDL_CreateTextureFromSurface(m_renderer, m_surface_Timer);
        SDL_Rect TimerRect = {1920 - size_timer*30 - 10, y+5, size_timer*30, 40};
        SDL_Rect TimerBackRect = {1920 - size_timer*30 - 15, y, size_timer*30 + 5, 45};
        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 100);
        SDL_RenderFillRect(m_renderer, &TimerBackRect);
        SDL_RenderCopy(m_renderer, m_texture_Timer, NULL, &TimerRect);
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


    // we clear the screen
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);



    SDL_RenderCopy(m_renderer, m_texture_background, NULL, NULL); // we add the background
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
    for (Case *Case : m_levels[m_currentLevel]->getCase())
    {
        SDL_Rect CaseRect = Case->getRect();
        SDL_RenderCopy(m_renderer, m_texture_Case, NULL, &CaseRect);
    }
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


    SDL_Rect playerRect = m_player.getRect(); // draw the player
    SDL_RenderCopy(m_renderer, m_texture_player, NULL, &playerRect);

    if (showHitbox){
        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
        Coords coords_j = m_player.getCoords();
        SDL_Rect rectHitbox = {(int)(coords_j.x * 40), (int)(coords_j.y * 40), (int)(coords_j.h * 40), (int)(coords_j.w * 40)};
        SDL_RenderDrawRect(m_renderer, &rectHitbox);
    }
        
    // draw the obstacles
    for (Obstacle *obstacle : m_levels[m_currentLevel]->getObstacles())
    {
        SDL_Rect obstacleRect = obstacle->getRect();
        SDL_RenderCopy(m_renderer, m_texture_obstacle, NULL, &obstacleRect);
    }

    // draw the pics
    for (Pic *pic : m_levels[m_currentLevel]->getPics())
    {
        SDL_Rect picRect = pic->getRect();
        SDL_RenderCopy(m_renderer, m_texture_pic, NULL, &picRect);
    }
    for (DoubleJumpPort *doublejumpport : m_levels[m_currentLevel]->getDoubleJumpPort())
    {
        SDL_Rect doublejumpportRect = doublejumpport->getRect();
        SDL_RenderCopy(m_renderer, m_texture_DoubleJumpPort, NULL, &doublejumpportRect);
    }
    for (BoxFinish *box : m_levels[m_currentLevel]->getBoxFinish())
    {
        SDL_Rect boxFinishRect = box->getRect();
        SDL_RenderCopy(m_renderer, m_texture_BoxFinish, NULL, &boxFinishRect);
    }
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
        //hover on the current tile of the mouse    
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

    //render the particle system
    m_particuleSystem.render(m_renderer, window_X_size, window_Y_size);

    //render the timer
    if(!editionMode){
        renderTimer(10, timer);
        renderTimer(60, bestTime);
    }

    // render the level
    SDL_RenderPresent(m_renderer);
}
