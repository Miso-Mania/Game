#include "M_Plateform.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <assert.h>
using namespace std;

M_Plateform::M_Plateform() {
    m_coords = Coords();
    m_rect = SDL_Rect();
}

M_Plateform::M_Plateform(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 5, 1);
    m_rect.x = x * TILE_SIZE;
    m_rect.y = y * TILE_SIZE;
    m_rect.w = 5 * TILE_SIZE;
    m_rect.h = TILE_SIZE;
}

M_Plateform::~M_Plateform() {
}

void M_Plateform::move(double delta) {
}

void M_Plateform::push_back(M_Plateform* M_Plateform) {
}

SDL_Rect M_Plateform::getRect() {
    return m_rect;
}

Coords M_Plateform::getCoords() {
    return m_coords;
}

void M_Plateform::testRegression() {
    cout << "Test de regression de la classe M_Plateform" << endl;
    cout << "test du constructeur de la classe" << endl;
    M_Plateform M_Plateform1;
    assert(M_Plateform1.getCoords().x == 0);
    assert(M_Plateform1.getCoords().y == 0);
    assert(M_Plateform1.getCoords().w == 0);
    assert(M_Plateform1.getCoords().h == 0);
    assert(M_Plateform1.getRect().x == 0);
    assert(M_Plateform1.getRect().y == 0);
    assert(M_Plateform1.getRect().w == 0);
    assert(M_Plateform1.getRect().h == 0);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "test du constructeur de la classe" << endl;
    M_Plateform M_Plateform(1, 2, 3);
    assert(M_Plateform.getCoords().x == 1);
    assert(M_Plateform.getCoords().y == 2);
    assert(M_Plateform.getCoords().w == 5);
    assert(M_Plateform.getCoords().h == 1);
    assert(M_Plateform.getRect().x == 3);
    assert(M_Plateform.getRect().y == 6);
    assert(M_Plateform.getRect().w == 15);
    assert(M_Plateform.getRect().h == 3);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "test de la méthode getRect" << endl;
    assert(M_Plateform.getRect().x == 3);
    assert(M_Plateform.getRect().y == 6);
    assert(M_Plateform.getRect().w == 15);
    assert(M_Plateform.getRect().h == 3);
    cout << "test de la méthode getRect: réussi" << endl;
    cout << "test de la méthode getCoords" << endl;
    assert(M_Plateform.getCoords().x == 1);
    assert(M_Plateform.getCoords().y == 2);
    assert(M_Plateform.getCoords().w == 5);
    assert(M_Plateform.getCoords().h == 1);
    cout << "test de la méthode getCoords: réussi" << endl;
    cout << "test de la méthode move" << endl;
    M_Plateform.move(1);
    cout << "test de la méthode move: réussi" << endl;
    cout << "test de la méthode push_back" << endl;
    M_Plateform.push_back(&M_Plateform);
    cout << "test de la méthode push_back: réussi" << endl;
}

