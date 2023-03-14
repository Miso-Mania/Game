#include "level.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>


using json = nlohmann::json;

using namespace std;

Level::Level() {
}

Level::~Level() {
    for ( Obstacle* obstacle : m_obstacles ) {
        delete obstacle;
    }
}

void Level::addObstacle(int x, int y, int width, int height) {
    Obstacle* obstacle = new Obstacle(x, y, width, height);
    m_obstacles.push_back(obstacle);
}

vector<Obstacle*> Level::getObstacles() {
    return m_obstacles;
}

void Level::addPic(int x, int y, int TILE_SIZE) {
    Pic* pic = new Pic(x, y, TILE_SIZE);
    m_pics.push_back(pic);
}

vector<Pic*> Level::getPics() {
    return m_pics;
}

void Level::addBoxFinish(int x, int y, int TILE_SIZE) {
    BoxFinish* box = new BoxFinish(x, y, TILE_SIZE);
    m_BoxFinish.push_back(box);
}

vector<BoxFinish*> Level::getBoxFinish() {
    return m_BoxFinish;
}

void Level::addTree(int x, int y, int TILE_SIZE) {
    Tree* tree = new Tree(x, y, TILE_SIZE );
    m_trees.push_back(tree);
}

vector<Tree*> Level::getTrees() {
    return m_trees;
}

void Level::addD_Case(int x, int y, int TILE_SIZE) {
    D_Case* d_case = new D_Case(x, y, TILE_SIZE);
    m_D_Case.push_back(d_case);
}

vector<D_Case*> Level::getD_Case() {
    return m_D_Case;
}

void Level::addCase(int x, int y, int TILE_SIZE) {
    Case* case_ = new Case(x, y, TILE_SIZE);
    m_Case.push_back(case_);
}

vector<Case*> Level::getCase() {
    return m_Case;
}

void Level::addS_Plateform(int x, int y, int TILE_SIZE) {
    S_Plateform* s_plateform = new S_Plateform(x, y, TILE_SIZE);
    m_S_Plateform.push_back(s_plateform);
}
vector<S_Plateform*> Level::getS_Plateform() {
    return m_S_Plateform;
}
void Level::addM_Plateform(int x, int y, int TILE_SIZE) {
    M_Plateform* m_plateform = new M_Plateform(x, y, TILE_SIZE);
    m_M_Plateform.push_back(m_plateform);
}
vector<M_Plateform*> Level::getM_Plateform() {
    return m_M_Plateform;
}
void Level::addL_Plateform(int x, int y, int TILE_SIZE) {
    L_Plateform* l_plateform = new L_Plateform(x, y, TILE_SIZE);
    m_L_Plateform.push_back(l_plateform);
}
vector<L_Plateform*> Level::getL_Plateform() {
    return m_L_Plateform;
}

void Level::addDoubleJumpPort(int x, int y, int TILE_SIZE) {
    DoubleJumpPort* doublejumpport = new DoubleJumpPort(x, y, TILE_SIZE);
    m_DoubleJumpPort.push_back(doublejumpport);
}

vector<DoubleJumpPort*> Level::getDoubleJumpPort() {
    return m_DoubleJumpPort;
}

void Level::addBoxCmgtGrav(int x, int y, int TILE_SIZE) {
    BoxCmgtGrav* boxcmgtgrav = new BoxCmgtGrav(x, y, TILE_SIZE);
    m_BoxCmgtGrav.push_back(boxcmgtgrav);
}

vector<BoxCmgtGrav*> Level::getBoxCmgtGrav() {
    return m_BoxCmgtGrav;
}

void Level::loadFromJSON(string filename, int TILE_SIZE) {
    cout << "Loading level from " << filename << endl;
    ifstream file(filename);
    json j;
    file >> j;

    id = j["id"];
    name = j["nom du niveau"];
    creator = j["createur"];
    for (auto& element : j["obstacles"]) {
        int x = element["x"];
        int y = element["y"];
        int width = element["width"];
        int height = element["height"];
        addObstacle(x , y, width , height);
        cout << "Obstacle: " << x << ", " << y << ", " << width << ", " << height << endl;
    }
    for (auto& element : j["pics"]) {
        int x = element["x"];
        int y = element["y"];
        addPic(x, y, TILE_SIZE);
        cout << "Pic: " << x << ", " << y << endl;
        
    }
    for (auto& element : j["BoxFinish"]) {
        int x = element["x"];
        int y = element["y"];
        addBoxFinish(x, y, TILE_SIZE);
        cout << "BoxFinish: " << x << ", " << y << endl;
    }
    for (auto& element : j["trees"]) {
        int x = element["x"];
        int y = element["y"];
        addTree(x, y, TILE_SIZE);
        cout << "Un arbre de planté ici: " << x << ", " << y << endl;
    }
    for (auto& element : j["DoubleJumpPort"]) {
        int x = element["x"];
        int y = element["y"];
        addDoubleJumpPort   (x, y, TILE_SIZE);
        cout << "DoubleJumpPort posé ici :" << x << ", " << y << endl;
        }
    for (auto& element : j["Case"]) {
        int x = element["x"];
        int y = element["y"];
        addCase(x, y, TILE_SIZE);
        cout << "Une Case de posée ici: " << x << ", " << y << endl;
    }
    for (auto& element : j["D_Case"]) {
        int x = element["x"];
        int y = element["y"];
        addD_Case(x, y, TILE_SIZE);
        cout << "Une D_Case de posée ici: " << x << ", " << y << endl;
    }
    for (auto& element : j["S_Plateform"]) {
        int x = element["x"];
        int y = element["y"];
        addS_Plateform(x, y, TILE_SIZE);
        cout << "Une S_Plateform de posée ici: " << x << ", " << y << endl;
    }
    for (auto& element : j["M_Plateform"]) {
        int x = element["x"];
        int y = element["y"];
        addM_Plateform(x, y, TILE_SIZE);
        cout << "Une M_Plateform de posée ici: " << x << ", " << y << endl;
    }
    for (auto& element : j["L_Plateform"]) {
        int x = element["x"];
        int y = element["y"];
        addL_Plateform(x, y, TILE_SIZE);
        cout << "Une M_Plateform de posée ici: " << x << ", " << y << endl;
    }
    for (auto& element : j["BoxCmgtGrav"]) {
        int x = element["x"];
        int y = element["y"];
        addBoxCmgtGrav(x, y, TILE_SIZE);
        cout << "Une BoxCmgtGrav de posée ici: " << x << ", " << y << endl;
    }
}

void Level::saveToJSON(string filename) {
    json j;

    j["id"] = id;
    j["nom du niveau"] = name;
    j["createur"] = creator;
    for (Obstacle* obstacle : m_obstacles) {
        json obstacleJSON;
        SDL_Rect obstacleRect = obstacle->getRect();
        obstacleJSON["x"] = obstacleRect.x;
        obstacleJSON["y"] = obstacleRect.y;
        obstacleJSON["width"] = obstacleRect.w;
        obstacleJSON["height"] = obstacleRect.h;
        j["obstacles"].push_back(obstacleJSON);
    }
    for (Pic* pic : m_pics) {
        json picJSON;
        SDL_Rect picRect = pic->getRect();
        picJSON["x"] = picRect.x;
        picJSON["y"] = picRect.y;
        j["pics"].push_back(picJSON);
    }
    for (BoxFinish* box : m_BoxFinish) {
        json boxJSON;
        SDL_Rect boxRect = box->getRect();
        boxJSON["x"] = boxRect.x;
        boxJSON["y"] = boxRect.y;
        j["BoxFinish"].push_back(boxJSON);
    }
    for (Tree* tree : m_trees) {
        json treeJSON;
        SDL_Rect treeRect = tree->getRect();
        treeJSON["x"] = treeRect.x;
        treeJSON["y"] = treeRect.y;
        treeJSON["width"] = treeRect.w;
        treeJSON["height"] = treeRect.h;
        j["trees"].push_back(treeJSON);
    }
    ofstream file(filename);
    file << j;
}

int Level::get_Tile_Size() {
    return id;
}

void Level::testRegression() {
    cout << "Test de regression de la Classe Player:" << endl;
    cout<< "Test du constructeur de la classe Player:" << endl;
    cout<< "Test du constructeur de la classe Player réussi" << endl;
    cout<< "Test du destructeur de la classe Player:" << endl;
    assert(m_obstacles.size() == 0);
    cout<< "Test du destructeur de la classe Player réussi" << endl;
    cout<< "Test de la méthode addObstacle:" << endl;
    addObstacle(0, 0, 0, 0);
    assert(m_obstacles.size() == 1);
    cout<< "Test de la méthode addObstacle réussi" << endl;
    cout<< "Test de la méthode addPic:" << endl;
    addPic(0, 0, 0);
    assert(m_pics.size() == 1);
    cout<< "Test de la méthode addPic réussi" << endl;
    cout<< "Test de la méthode addBoxFinish:" << endl;
    addBoxFinish(0, 0, 0);
    assert(m_BoxFinish.size() == 1);
    cout<< "Test de la méthode addBoxFinish réussi" << endl;
    cout<< "Test de la méthode addTree:" << endl;
    addTree(0, 0, 0);
    assert(m_trees.size() == 1);
    cout<< "Test de la méthode addTree réussi" << endl;
    cout<< "Test de la méthode addDoubleJumpPort:" << endl;
    addDoubleJumpPort(0, 0, 0);
    assert(m_DoubleJumpPort.size() == 1);
    cout<< "Test de la méthode addDoubleJumpPort réussi" << endl;
    cout<< "Test de la méthode addCase:" << endl;
    addCase(0, 0, 0);
    assert(m_Case.size() == 1);
    cout<< "Test de la méthode addCase réussi" << endl;
    cout<< "Test de la méthode addD_Case:" << endl;
    addD_Case(0, 0, 0);
    assert(m_D_Case.size() == 1);
    cout<< "Test de la méthode addD_Case réussi" << endl;
    cout<< "Test de la méthode addS_Plateform:" << endl;
    addS_Plateform(0, 0, 0);
    assert(m_S_Plateform.size() == 1);
    cout<< "Test de la méthode addS_Plateform réussi" << endl;
    cout<< "Test de la méthode addM_Plateform:" << endl;
    addM_Plateform(0, 0, 0);
    assert(m_M_Plateform.size() == 1);
    cout<< "Test de la méthode addM_Plateform réussi" << endl;
    cout<< "Test de la méthode addL_Plateform:" << endl;
    addL_Plateform(0, 0, 0);
    assert(m_L_Plateform.size() == 1);
    cout<< "Test de la méthode addL_Plateform réussi" << endl;
    cout<< "Test de la méthode addBoxCmgtGrav:" << endl;
    addBoxCmgtGrav(0, 0, 0);
    assert(m_BoxCmgtGrav.size() == 1);
    cout<< "Test de la méthode addBoxCmgtGrav réussi" << endl;
    cout<< "Test de la méthode get_Tile_Size:" << endl;
    assert(get_Tile_Size() == 0);
    cout<< "Test de la méthode get_Tile_Size réussi" << endl;
    cout<< "Test de la méthode getObstacles:" << endl;
    assert(getObstacles().size() == 1);
    cout<< "Test de la méthode getObstacles réussi" << endl;
    cout<< "Test de la méthode getPics:" << endl;
    assert(getPics().size() == 1);
    cout<< "Test de la méthode getPics réussi" << endl;
    cout<< "Test de la méthode getBoxFinish:" << endl;
    assert(getBoxFinish().size() == 1);
    cout<< "Test de la méthode getBoxFinish réussi" << endl;
    cout<< "Test de la méthode getTrees:" << endl;
    assert(getTrees().size() == 1);
    cout<< "Test de la méthode getTrees réussi" << endl;
    cout<< "Test de la méthode getDoubleJumpPort:" << endl;
    assert(getDoubleJumpPort().size() == 1);
    cout<< "Test de la méthode getDoubleJumpPort réussi" << endl;
    cout<< "Test de la méthode getCase:" << endl;
    assert(getCase().size() == 1);
    cout<< "Test de la méthode getCase réussi" << endl;
    cout<< "Test de la méthode getD_Case:" << endl;
    assert(getD_Case().size() == 1);
    cout<< "Test de la méthode getD_Case réussi" << endl;
    cout<< "Test de la méthode getS_Plateform:" << endl;
    assert(getS_Plateform().size() == 1);
    cout<< "Test de la méthode getS_Plateform réussi" << endl;
    cout<< "Test de la méthode getM_Plateform:" << endl;
    assert(getM_Plateform().size() == 1);
    cout<< "Test de la méthode getM_Plateform réussi" << endl;
    cout<< "Test de la méthode getL_Plateform:" << endl;
    assert(getL_Plateform().size() == 1);
    cout<< "Test de la méthode getL_Plateform réussi" << endl;
    cout<< "Test de la méthode getBoxCmgtGrav:" << endl;
    assert(getBoxCmgtGrav().size() == 1);
    cout<< "Test de la méthode getBoxCmgtGrav réussi" << endl;
}