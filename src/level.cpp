#include "level.h"
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

void Level::removeObstacle(Obstacle* obstacle) {
    for ( int i = 0; i < m_obstacles.size(); i++ ) {
        if ( m_obstacles[i] == obstacle ) {
            m_obstacles.erase(m_obstacles.begin() + i);
            delete obstacle;
            break;
        }
    }
}

void Level::addPic(int x, int y) {
    Pic* pic = new Pic(x, y);
    m_pics.push_back(pic);
}

vector<Pic*> Level::getPics() {
    return m_pics;
}

void Level::removePic(Pic* pic) {
    for ( int i = 0; i < m_pics.size(); i++ ) {
        if ( m_pics[i] == pic ) {
            m_pics.erase(m_pics.begin() + i);
            delete pic;
            break;
        }
    }
}




