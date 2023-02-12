#include "level.h"

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

void Level::update(double delta) {
    for ( Obstacle* obstacle : m_obstacles ) {
        obstacle->update(delta);
    }
}

void Level::render(SDL_Renderer *renderer) {
    for ( Obstacle* obstacle : m_obstacles ) {
        obstacle->render(renderer);
    }
}

std::vector<Obstacle*> Level::getObstacles() {
    return m_obstacles;
}
