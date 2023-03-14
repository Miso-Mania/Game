#include "BoxFinish.h"
#include <iostream>
#include <assert.h>
using namespace std;

BoxFinish::BoxFinish() {
    m_coords = Coords();
    m_triangle = SDL_Rect();
}

BoxFinish::BoxFinish(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 1, 2);
    m_triangle.x = x * TILE_SIZE;
    m_triangle.y = y * TILE_SIZE;
    m_triangle.w = TILE_SIZE;
    m_triangle.h = 2 * TILE_SIZE;
}

BoxFinish::~BoxFinish() {
}

void BoxFinish::move(double delta) {
}

void BoxFinish::push_back(BoxFinish* BoxFinish) {
}

SDL_Rect BoxFinish::getRect() {
    return m_triangle;
}

Coords BoxFinish::getCoords() {
    return m_coords;
}

void BoxFinish::testRegression() {
    cout << "Test de regression de la classe BoxFinish" << endl;
    cout << "test du constructeur de la classe" << endl;
    BoxFinish boxFinish;
    assert(boxFinish.getCoords().x == 0);
    assert(boxFinish.getCoords().y == 0);
    assert(boxFinish.getCoords().w == 0);
    assert(boxFinish.getCoords().h == 0);
    assert(boxFinish.getRect().x == 0);
    assert(boxFinish.getRect().y == 0);
    assert(boxFinish.getRect().w == 0);
    assert(boxFinish.getRect().h == 0);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "test du constructeur de la classe" << endl;
    BoxFinish boxFinish1(1, 2, 3);
    assert(boxFinish1.getCoords().x == 1);
    assert(boxFinish1.getCoords().y == 2);
    assert(boxFinish1.getCoords().w == 1);
    assert(boxFinish1.getCoords().h == 2);
    assert(boxFinish1.getRect().x == 3);
    assert(boxFinish1.getRect().y == 6);
    assert(boxFinish1.getRect().w == 3);
    assert(boxFinish1.getRect().h == 6);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "test de la méthode getRect()" << endl;
    assert(boxFinish1.getRect().x == 3);
    assert(boxFinish1.getRect().y == 6);
    assert(boxFinish1.getRect().w == 3);
    assert(boxFinish1.getRect().h == 6);
    cout << "test de la méthode getRect(): réussi" << endl;
    cout << "test de la méthode getCoords()" << endl;
    assert(boxFinish1.getCoords().x == 1);
    assert(boxFinish1.getCoords().y == 2);
    assert(boxFinish1.getCoords().w == 1);
    assert(boxFinish1.getCoords().h == 2);
    cout << "test de la méthode getCoords(): réussi" << endl;
    cout << "test de la méthode move()" << endl;
    boxFinish1.move(1);
    cout << "test de la méthode move(): réussi" << endl;
    cout << "test de la méthode push_back()" << endl;
    boxFinish1.push_back(&boxFinish);
    cout << "test de la méthode push_back(): réussi" << endl;
}