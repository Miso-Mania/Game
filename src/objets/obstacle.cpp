#include "obstacle.h"
#include "../coords.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <assert.h>
using namespace std;

Obstacle::Obstacle() {
    m_coords = Coords();
    m_rect = SDL_Rect();
}

Obstacle::Obstacle(int x, int y, int width, int height) {
    m_coords = Coords(x, y, width, height);
    m_rect.x = x * 40;
    m_rect.y = y * 40;
    m_rect.w = width * 40;
    m_rect.h = height * 40;
}



Obstacle::~Obstacle() {
}

void Obstacle::move(double delta) {
}

void Obstacle::push_back(Obstacle* obstacle) {
}

SDL_Rect Obstacle::getRect() {
    return m_rect;
}

Coords Obstacle::getCoords() {
    return m_coords;
}

void Obstacle::testRegression() {
    cout << "Test de regression de la classe Obstacle" << endl;
    cout << "test du constructeur de la classe" << endl;
    Obstacle obstacle1;
    assert(obstacle1.getCoords().x == 0);
    assert(obstacle1.getCoords().y == 0);
    assert(obstacle1.getCoords().w == 0);
    assert(obstacle1.getCoords().h == 0);
    assert(obstacle1.getRect().x == 0);
    assert(obstacle1.getRect().y == 0);
    assert(obstacle1.getRect().w == 0);
    assert(obstacle1.getRect().h == 0);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "test du constructeur de la classe" << endl;
    Obstacle obstacle(1, 2, 3, 4);
    assert(obstacle.getCoords().x == 1);
    assert(obstacle.getCoords().y == 2);
    assert(obstacle.getCoords().w == 3);
    assert(obstacle.getCoords().h == 4);
    assert(obstacle.getRect().x == 40);
    assert(obstacle.getRect().y == 80);
    assert(obstacle.getRect().w == 120);
    assert(obstacle.getRect().h == 160);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "Test de la méthode getRect" << endl;
    assert(obstacle.getRect().x == 40);
    assert(obstacle.getRect().y == 80);
    assert(obstacle.getRect().w == 120);
    assert(obstacle.getRect().h == 160);
    cout << "Test de la méthode getRect: réussi" << endl;
    cout << "Test de la méthode getCoords" << endl;
    assert(obstacle.getCoords().x == 1);
    assert(obstacle.getCoords().y == 2);
    assert(obstacle.getCoords().w == 3);
    assert(obstacle.getCoords().h == 4);
    cout << "Test de la méthode getCoords: réussi" << endl;
    cout << "Test de la méthode move" << endl;
    obstacle.move(1);
    cout << "Test de la méthode move: réussi" << endl;
    cout << "Test de la méthode push_back" << endl;
    obstacle.push_back(&obstacle);
    cout << "Test de la méthode push_back: réussi" << endl;
}