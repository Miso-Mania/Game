#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string.h>
#include "objets/obstacle.h"
#include "objets/BoxFinish.h"
#include "objets/pic.h"
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class Level {
public:
    Level();
    ~Level();
    void addObstacle(int x, int y, int width, int height);
    vector<Obstacle*> getObstacles();
    void addPic(int x, int y);
    vector<Pic*> getPics();
    void addBoxFinish(int x, int y);
    vector<BoxFinish*> getBoxFinish();
    void loadFromJSON(string filePATHandname);
    

private:
    vector<Obstacle*> m_obstacles;
    vector<Pic*> m_pics;
    vector<BoxFinish*> m_BoxFinish;
};

#endif // LEVEL_H