#include "S_Plateform.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <assert.h>
using namespace std;

S_Plateform::S_Plateform() {
    m_coords = Coords();
    m_rect = SDL_Rect();
}

S_Plateform::S_Plateform(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 3, 1);
    m_rect.x = x * TILE_SIZE;
    m_rect.y = y * TILE_SIZE;
    m_rect.w = 3 * TILE_SIZE;
    m_rect.h = TILE_SIZE;
}

S_Plateform::~S_Plateform() {
}

void S_Plateform::move(double delta) {
}

void S_Plateform::push_back(S_Plateform* S_Plateform) {
}

SDL_Rect S_Plateform::getRect() {
    return m_rect;
}

Coords S_Plateform::getCoords() {
    return m_coords;
}

void S_Plateform::testRegression() {
    cout << "Test de regression de la classe S_Plateform" << endl;
    cout << "test du constructeur de la classe" << endl;
    S_Plateform S_Plateform1;
    assert(S_Plateform1.getCoords().x == 0);
    assert(S_Plateform1.getCoords().y == 0);
    assert(S_Plateform1.getCoords().w == 0);
    assert(S_Plateform1.getCoords().h == 0);
    assert(S_Plateform1.getRect().x == 0);
    assert(S_Plateform1.getRect().y == 0);
    assert(S_Plateform1.getRect().w == 0);
    assert(S_Plateform1.getRect().h == 0);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "test du constructeur de la classe" << endl;
    S_Plateform S_Plateform(1, 2, 3);
    assert(S_Plateform.getCoords().x == 1);
    assert(S_Plateform.getCoords().y == 2);
    assert(S_Plateform.getCoords().w == 3);
    assert(S_Plateform.getCoords().h == 1);
    assert(S_Plateform.getRect().x == 3);
    assert(S_Plateform.getRect().y == 6);
    assert(S_Plateform.getRect().w == 9);
    assert(S_Plateform.getRect().h == 3);
    cout << "test du constructeur de la classe: réussi" << endl;
cout << "Test de la methode getRect" << endl;
    assert(S_Plateform.getRect().x == 3);
    assert(S_Plateform.getRect().y == 6);
    assert(S_Plateform.getRect().w == 9);
    assert(S_Plateform.getRect().h == 3);
    cout << "test de la methode getRect: réussi" << endl;
    cout << "Test de la methode getCoords" << endl;
    assert(S_Plateform.getCoords().x == 1);
    assert(S_Plateform.getCoords().y == 2);
    assert(S_Plateform.getCoords().w == 3);
    assert(S_Plateform.getCoords().h == 1);
    cout << "test de la methode getCoords: réussi" << endl;
    cout << "Test de la methode move" << endl;
    S_Plateform.move(1);
    cout << "test de la methode move: réussi" << endl;
    cout << "Test de la methode push_back" << endl;
    S_Plateform.push_back(&S_Plateform);
    cout << "test de la methode push_back: réussi" << endl;
}