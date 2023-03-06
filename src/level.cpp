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
