#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "obstacle.h"
#include "pic.h"
using namespace std;

class Level {
public:
    Level();
    ~Level();
    void addObstacle(int x, int y, int width, int height);
    vector<Obstacle*> getObstacles();
    void addPic(int x, int y);
    vector<Pic*> getPics();

private:
    vector<Obstacle*> m_obstacles;
    vector<Pic*> m_pics;
};

#endif // LEVEL_HSS