#include "L_Plateform.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <assert.h>
using namespace std;

L_Plateform::L_Plateform() {
    m_coords = Coords();
    m_rect = SDL_Rect();
}

L_Plateform::L_Plateform(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 7, 1);
    m_rect.x = x * TILE_SIZE;
    m_rect.y = y * TILE_SIZE;
    m_rect.w = 7 * TILE_SIZE;
    m_rect.h = TILE_SIZE;
}

L_Plateform::~L_Plateform() {
}

void L_Plateform::move(double delta) {
}

void L_Plateform::push_back(L_Plateform* L_Plateform) {
}

SDL_Rect L_Plateform::getRect() {
    return m_rect;
}

Coords L_Plateform::getCoords() {
    return m_coords;
}

void L_Plateform::testRegression() {
    cout << "Test de regression de la classe L_Plateform" << endl;
    cout << "test du constructeur de la classe" << endl;
    L_Plateform L_Plateform1;
    assert(L_Plateform1.getCoords().x == 0);
    assert(L_Plateform1.getCoords().y == 0);
    assert(L_Plateform1.getCoords().w == 0);
    assert(L_Plateform1.getCoords().h == 0);
    assert(L_Plateform1.getRect().x == 0);
    assert(L_Plateform1.getRect().y == 0);
    assert(L_Plateform1.getRect().w == 0);
    assert(L_Plateform1.getRect().h == 0);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "test du constructeur de la classe" << endl;
    L_Plateform L_Plateform(1, 2, 3);
    assert(L_Plateform.getCoords().x == 1);
    assert(L_Plateform.getCoords().y == 2);
    assert(L_Plateform.getCoords().w == 7);
    assert(L_Plateform.getCoords().h == 1);
    assert(L_Plateform.getRect().x == 3);
    assert(L_Plateform.getRect().y == 6);
    assert(L_Plateform.getRect().w == 21);
    assert(L_Plateform.getRect().h == 3);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout<< "Test de la méthode getRect" << endl;
    assert(L_Plateform.getRect().x == 3);
    assert(L_Plateform.getRect().y == 6);
    assert(L_Plateform.getRect().w == 21);
    assert(L_Plateform.getRect().h == 3);
    cout << "test de la méthode getRect: réussi" << endl;
    cout << "test de la méthode getCoords" << endl;
    assert(L_Plateform.getCoords().x == 1);
    assert(L_Plateform.getCoords().y == 2);
    assert(L_Plateform.getCoords().w == 7);
    assert(L_Plateform.getCoords().h == 1);
    cout << "test de la méthode getCoords: réussi" << endl;
    cout << "test de la méthode move" << endl;
    L_Plateform.move(1);
    cout << "test de la méthode move: réussi" << endl;
    cout << "test de la méthode push_back" << endl;
    L_Plateform.push_back(&L_Plateform);
    cout << "test de la méthode push_back: réussi" << endl;

}
