#include "D_Case.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <assert.h>
using namespace std;

D_Case::D_Case() {
    m_coords = Coords();
    m_rect = SDL_Rect();
}

D_Case::D_Case(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 2, 2);
    m_rect.x = x * TILE_SIZE;
    m_rect.y = y * TILE_SIZE;
    m_rect.w = 2 * TILE_SIZE;
    m_rect.h = 2 * TILE_SIZE;
}

D_Case::~D_Case() {
}

void D_Case::move(double delta) {
}

void D_Case::push_back(D_Case* D_Case) {
}

SDL_Rect D_Case::getRect() {
    return m_rect;
}

Coords D_Case::getCoords() {
    return m_coords;
}

void D_Case::testRegression() {
    cout << "Test de regression de la classe D_Case" << endl;
    cout << "test du constructeur de la classe" << endl;
    D_Case D_Case1;
    assert(D_Case1.getCoords().x == 0);
    assert(D_Case1.getCoords().y == 0);
    assert(D_Case1.getCoords().w == 0);
    assert(D_Case1.getCoords().h == 0);
    assert(D_Case1.getRect().x == 0);
    assert(D_Case1.getRect().y == 0);
    assert(D_Case1.getRect().w == 0);
    assert(D_Case1.getRect().h == 0);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "test du constructeur de la classe" << endl;
    D_Case D_Case(1, 2, 3);
    assert(D_Case.getCoords().x == 1);
    assert(D_Case.getCoords().y == 2);
    assert(D_Case.getCoords().w == 2);
    assert(D_Case.getCoords().h == 2);
    assert(D_Case.getRect().x == 3);
    assert(D_Case.getRect().y == 6);
    assert(D_Case.getRect().w == 6);
    assert(D_Case.getRect().h == 6);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "Test de la methode getRect" << endl;
    assert(D_Case.getRect().x == 3);
    assert(D_Case.getRect().y == 6);
    assert(D_Case.getRect().w == 6);
    assert(D_Case.getRect().h == 6);
    cout << "Test de la methode getRect: réussi" << endl;
    cout << "Test de la methode getCoords" << endl;
    assert(D_Case.getCoords().x == 1);
    assert(D_Case.getCoords().y == 2);
    assert(D_Case.getCoords().w == 2);
    assert(D_Case.getCoords().h == 2);
    cout << "Test de la methode getCoords: réussi" << endl;
    cout << "Test de la methode push_back" << endl;
    D_Case.push_back(&D_Case);
    cout << "Test de la methode push_back: réussi" << endl;
    cout << "Test de la methode move" << endl;
    D_Case.move(1);
    cout << "Test de la methode move: réussi" << endl;

}