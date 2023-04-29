#include "enemy.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <assert.h>
using namespace std;

Enemy::Enemy() {
    m_coords = Coords();
    m_rect = SDL_Rect();
}

Enemy::Enemy(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 2, 1);
    m_rect.x = x * TILE_SIZE;
    m_rect.y = y * TILE_SIZE;
    m_rect.w = 2 * TILE_SIZE;
    m_rect.h = 3 * TILE_SIZE;
}

Enemy::~Enemy() {
}

void Enemy::push_back(Enemy* Enemy) {
}



SDL_Rect Enemy::getRect() {
    return m_rect;
}

Coords Enemy::getCoords() {
    return m_coords;
}

void Enemy::testRegression() {
    cout << "Test de regression de la classe Enemy" << endl;
    cout << "test du constructeur de la classe" << endl;
    Enemy Enemy1;
    assert(Enemy1.getCoords().x == 0);
    assert(Enemy1.getCoords().y == 0);
    assert(Enemy1.getCoords().w == 0);
    assert(Enemy1.getCoords().h == 0);
    assert(Enemy1.getRect().x == 0);
    assert(Enemy1.getRect().y == 0);
    assert(Enemy1.getRect().w == 0);
    assert(Enemy1.getRect().h == 0);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "test du constructeur de la classe" << endl;
    Enemy Enemy(1, 2, 3);
    assert(Enemy.getCoords().x == 1);
    assert(Enemy.getCoords().y == 2);
    assert(Enemy.getCoords().w == 2);
    assert(Enemy.getCoords().h == 1);
    assert(Enemy.getRect().x == 3);
    assert(Enemy.getRect().y == 6);
    assert(Enemy.getRect().w == 6);
    assert(Enemy.getRect().h == 9);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "test de la méthode push_back" << endl;
    Enemy.push_back(&Enemy);
    assert(Enemy.getCoords().x == 1);
    assert(Enemy.getCoords().y == 2);
    assert(Enemy.getCoords().w == 2);
    assert(Enemy.getCoords().h == 1);
    assert(Enemy.getRect().x == 3);
    assert(Enemy.getRect().y == 6);
    assert(Enemy.getRect().w == 6);
    assert(Enemy.getRect().h == 9);
    cout << "test de la méthode push_back: réussi" << endl;
    cout << "test de la méthode getRect" << endl;
    assert(Enemy.getRect().x == 3);
    assert(Enemy.getRect().y == 6);
    assert(Enemy.getRect().w == 6);
    assert(Enemy.getRect().h == 9);
    cout << "test de la méthode getRect: réussi" << endl;
    cout << "test de la méthode getCoords" << endl;
    assert(Enemy.getCoords().x == 1);
    assert(Enemy.getCoords().y == 2);
    assert(Enemy.getCoords().w == 2);
    assert(Enemy.getCoords().h == 1);
    cout << "test de la méthode getCoords: réussi" << endl;
}








