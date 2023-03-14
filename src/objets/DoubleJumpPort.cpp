#include "DoubleJumpPort.h"
#include <assert.h>
#include <iostream>
using namespace std;

DoubleJumpPort::DoubleJumpPort() {
    m_coords = Coords();
    m_rect = SDL_Rect();
}

DoubleJumpPort::DoubleJumpPort(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 1, 1);
    m_rect.x = x * TILE_SIZE;
    m_rect.y = y * TILE_SIZE;
    m_rect.w = TILE_SIZE;
    m_rect.h = TILE_SIZE;
}

DoubleJumpPort::~DoubleJumpPort() {
}

void DoubleJumpPort::move(double delta) {
}

void DoubleJumpPort::push_back(DoubleJumpPort* DoubleJumpPort) {
}

SDL_Rect DoubleJumpPort::getRect() {
    return m_rect;
}

Coords DoubleJumpPort::getCoords() {
    return m_coords;
}

void DoubleJumpPort::testRegression() {
    cout << "Test de regression de la classe DoubleJumpPort" << endl;
    cout << "test du constructeur de la classe" << endl;
    DoubleJumpPort DoubleJumpPort1;
    assert(DoubleJumpPort1.getCoords().x == 0);
    assert(DoubleJumpPort1.getCoords().y == 0);
    assert(DoubleJumpPort1.getCoords().w == 0);
    assert(DoubleJumpPort1.getCoords().h == 0);
    assert(DoubleJumpPort1.getRect().x == 0);
    assert(DoubleJumpPort1.getRect().y == 0);
    assert(DoubleJumpPort1.getRect().w == 0);
    assert(DoubleJumpPort1.getRect().h == 0);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "test du constructeur de la classe" << endl;
    DoubleJumpPort DoubleJumpPort(1, 2, 3);
    assert(DoubleJumpPort.getCoords().x == 1);
    assert(DoubleJumpPort.getCoords().y == 2);
    assert(DoubleJumpPort.getCoords().w == 1);
    assert(DoubleJumpPort.getCoords().h == 1);
    assert(DoubleJumpPort.getRect().x == 3);
    assert(DoubleJumpPort.getRect().y == 6);
    assert(DoubleJumpPort.getRect().w == 3);
    assert(DoubleJumpPort.getRect().h == 3);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "test de la méthode getRect()" << endl;
    assert(DoubleJumpPort.getRect().x == 3);
    assert(DoubleJumpPort.getRect().y == 6);
    assert(DoubleJumpPort.getRect().w == 3);
    assert(DoubleJumpPort.getRect().h == 3);
    cout << "test de la méthode getRect(): réussi" << endl;
    cout << "test de la méthode getCoords()" << endl;
    assert(DoubleJumpPort.getCoords().x == 1);
    assert(DoubleJumpPort.getCoords().y == 2);
    assert(DoubleJumpPort.getCoords().w == 1);
    assert(DoubleJumpPort.getCoords().h == 1);
    cout << "test de la méthode getCoords(): réussi" << endl;
    cout << "test de la méthode move()" << endl;
    DoubleJumpPort.move(1);
    cout << "test de la méthode move(): réussi" << endl;
    cout << "test de la méthode push_back()" << endl;
    DoubleJumpPort.push_back(&DoubleJumpPort);
    cout << "test de la méthode push_back(): réussi" << endl;

}