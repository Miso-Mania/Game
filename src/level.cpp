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

void Level::loadFromJSON(string filename) {
    cout << "enterring loadFromJSON "<< endl;
    cout << "Loading level from " << filename << endl;
}


