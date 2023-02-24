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

void Level::addPic(int x, int y) {
    Pic* pic = new Pic(x, y);
    m_pics.push_back(pic);
}

vector<Pic*> Level::getPics() {
    return m_pics;
}

void Level::addBoxFinish(int x, int y) {
    BoxFinish* box = new BoxFinish(x, y);
    m_BoxFinish.push_back(box);
}

vector<BoxFinish*> Level::getBoxFinish() {
    return m_BoxFinish;
}

void Level::addTree(int x, int y) {
    Tree* tree = new Tree(x, y);
    m_trees.push_back(tree);
}

vector<Tree*> Level::getTrees() {
    return m_trees;
}



void Level::loadFromJSON(string filename) {
    cout << "Loading level from " << filename << endl;
    ifstream file(filename);
    json j;
    file >> j;
    for (auto& element : j["obstacles"]) {
        int x = element["x"];
        int y = element["y"];
        int width = element["width"];
        int height = element["height"];
        addObstacle(x, y, width, height);
        cout << "Obstacle: " << x << ", " << y << ", " << width << ", " << height << endl;
    }
    
    for (auto& element : j["pics"]) {
        int x = element["x"];
        int y = element["y"];
        addPic(x, y);
        cout << "Pic: " << x << ", " << y << endl;
    }
    for (auto& element : j["BoxFinish"]) {
        int x = element["x"];
        int y = element["y"];
        addBoxFinish(x, y);
        cout << "BoxFinish: " << x << ", " << y << endl;
    }
    for (auto& element : j["trees"]) {
        int x = element["x"];
        int y = element["y"];
        addTree(x, y);
        cout << "Un arbre de planté ici: " << x << ", " << y << endl;
    }
}


