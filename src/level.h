#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "obstacle.h"

class Level {
public:
    Level();
    ~Level();
    void addObstacle(int x, int y, int width, int height);
    void update(double delta);
    void render(SDL_Renderer *renderer);
    std::vector<Obstacle> getObstacles();
    

private:
    std::vector<Obstacle> m_obstacles;
};

#endif // LEVEL_H