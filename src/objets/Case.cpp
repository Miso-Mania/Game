#include "Case.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <assert.h>
using namespace std;

Case::Case() {
    m_coords = Coords();
    m_rect = SDL_Rect();
}

Case::Case(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 1, 1);
    m_rect.x = x * TILE_SIZE;
    m_rect.y = y * TILE_SIZE;
    m_rect.w = TILE_SIZE;
    m_rect.h = TILE_SIZE;
}

Case::~Case() {
}

void Case::move(double delta) {
}

void Case::push_back(Case* Case) {
}

SDL_Rect Case::getRect() {
    return m_rect;
}

Coords Case::getCoords() {
    return m_coords;
}

void Case::testRegression() {
    cout << "Test de regression de la classe Case" << endl;
    cout << "test du constructeur de la classe" << endl;
    Case Case1;
    assert(Case1.getCoords().x == 0);
    assert(Case1.getCoords().y == 0);
    assert(Case1.getCoords().w == 0);
    assert(Case1.getCoords().h == 0);
    assert(Case1.getRect().x == 0);
    assert(Case1.getRect().y == 0);
    assert(Case1.getRect().w == 0);
    assert(Case1.getRect().h == 0);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "test du constructeur de la classe" << endl;
    Case Case(1, 2, 3);
    assert(Case.getCoords().x == 1);
    assert(Case.getCoords().y == 2);
    assert(Case.getCoords().w == 1);
    assert(Case.getCoords().h == 1);
    assert(Case.getRect().x == 3);
    assert(Case.getRect().y == 6);
    assert(Case.getRect().w == 3);
    assert(Case.getRect().h == 3);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "test de la méthode getRect()" << endl;
    assert(Case.getRect().x == 3);
    assert(Case.getRect().y == 6);
    assert(Case.getRect().w == 3);
    assert(Case.getRect().h == 3);
    cout << "test de la méthode getRect(): réussi" << endl;
    cout << "test de la méthode getCoords()" << endl;
    assert(Case.getCoords().x == 1);
    assert(Case.getCoords().y == 2);
    assert(Case.getCoords().w == 1);
    assert(Case.getCoords().h == 1);
    cout << "test de la méthode getCoords(): réussi" << endl;
    cout << "test de la méthode move()" << endl;
    Case.move(1);
    cout << "test de la méthode move(): réussi" << endl;
    cout << "test de la méthode push_back()" << endl;
    Case.push_back(&Case1);
    cout << "test de la méthode push_back(): réussi" << endl;
}