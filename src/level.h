#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "obstacle.h"

class Level {
public:
    Level();
    ~Level();
    void addObstacle(int x, int y, int width, int height);
    std::vector<Obstacle*> getObstacles();
    void removeObstacle(Obstacle* obstacle);

private:
    std::vector<Obstacle*> m_obstacles;
};

#endif // LEVEL_HSS