#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "obstacle.h"
using namespace std;

class Level {
public:
    Level();
    ~Level();
    void addObstacle(int x, int y, int width, int height);
    vector<Obstacle*> getObstacles();
    void removeObstacle(Obstacle* obstacle);

private:
    vector<Obstacle*> m_obstacles;
};

#endif // LEVEL_HSS