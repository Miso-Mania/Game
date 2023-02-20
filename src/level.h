#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "objets/obstacle.h"
#include "objets/BoxFinish.h"
#include "objets/pic.h"
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
    Level* loadFromLevel(int level);
    

private:
    vector<Obstacle*> m_obstacles;
    vector<Pic*> m_pics;
    vector<BoxFinish*> m_BoxFinish;
};

#endif // LEVEL_H