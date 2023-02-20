#include "level.h"
#include <string.h>
#include <fstream>
#include <iostream>

//on inclut la librairie nlohmann/json.hpp
#include <nlohmann/json.hpp>
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

//we need to add a new method to load the level from a file, the file is a json file, an exemple of the file that we want to load is: /niveaux/level1.json
//we add this method to the level class:
Level* Level::loadFromJSON(string filePATHandname) {
    //we create a new level
    Level* level = new Level();
    //we open the file
    ifstream file(filePATHandname);
    //we create a json object
    json j;
    //we load the json file in the json object
    file >> j;
    //we close the file
    file.close();
    //we get the array of obstacles
    json obstacles = j["obstacles"];
    //we get the array of pics
    json pics = j["pics"];
    //we get the array of boxFinish
    json boxFinish = j["boxFinish"];
    //we iterate over the array of obstacles
    for (json::iterator it = obstacles.begin(); it != obstacles.end(); ++it) {
        //we get the x position of the obstacle
        int x = it.value()["x"];
        //we get the y position of the obstacle
        int y = it.value()["y"];
        //we get the width of the obstacle
        int width = it.value()["width"];
        //we get the height of the obstacle
        int height = it.value()["height"];
        //we add the obstacle to the level
        level->addObstacle(x, y, width, height);
    }
    //we iterate over the array of pics
    for (json::iterator it = pics.begin(); it != pics.end(); ++it) {
        //we get the x position of the pic
        int x = it.value()["x"];
        //we get the y position of the pic
        int y = it.value()["y"];
        //we add the pic to the level
        level->addPic(x, y);
    }
    //we iterate over the array of boxFinish
    for (json::iterator it = boxFinish.begin(); it != boxFinish.end(); ++it) {
        //we get the x position of the boxFinish
        int x = it.value()["x"];
        //we get the y position of the boxFinish
        int y = it.value()["y"];
        //we add the boxFinish to the level
        level->addBoxFinish(x, y);
    }
    //we return the level
    return level;
}


