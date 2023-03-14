#include "tree.h"
#include <assert.h>
#include <iostream>
using namespace std;

Tree::Tree() {
    m_coords = Coords();
    m_rect = SDL_Rect();
}

Tree::Tree(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 5, 3);
    m_rect.x = x * TILE_SIZE;
    m_rect.y = y * TILE_SIZE;
    m_rect.w = 3 * TILE_SIZE;
    m_rect.h = 3 * TILE_SIZE;
}

Tree::~Tree() {
}

void Tree::move(double delta) {
}

void Tree::push_back(Tree* Tree) {
}

SDL_Rect Tree::getRect() {
    return m_rect;
}

Coords Tree::getCoords() {
    return m_coords;
}

void Tree::testRegression() {
    cout << "Test de regression de la classe Tree" << endl;
    cout << "test du constructeur de la classe" << endl;
    Tree Tree1;
    assert(Tree1.getCoords().x == 0);
    assert(Tree1.getCoords().y == 0);
    assert(Tree1.getCoords().w == 0);
    assert(Tree1.getCoords().h == 0);
    assert(Tree1.getRect().x == 0);
    assert(Tree1.getRect().y == 0);
    assert(Tree1.getRect().w == 0);
    assert(Tree1.getRect().h == 0);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "test du constructeur de la classe" << endl;
    Tree Tree(1, 2, 3);
    assert(Tree.getCoords().x == 1);
    assert(Tree.getCoords().y == 2);
    assert(Tree.getCoords().w == 5);
    assert(Tree.getCoords().h == 3);
    assert(Tree.getRect().x == 3);
    assert(Tree.getRect().y == 6);
    assert(Tree.getRect().w == 9);
    assert(Tree.getRect().h == 9);
    cout << "test du constructeur de la classe: réussi" << endl;
    cout << "test de la méthode getRect()" << endl;
    assert(Tree.getRect().x == 3);
    assert(Tree.getRect().y == 6);
    assert(Tree.getRect().w == 9);
    assert(Tree.getRect().h == 9);
    cout << "test de la méthode getRect(): réussi" << endl;
    cout << "test de la méthode getCoords()" << endl;
    assert(Tree.getCoords().x == 1);
    assert(Tree.getCoords().y == 2);
    assert(Tree.getCoords().w == 5);
    assert(Tree.getCoords().h == 3);
    cout << "test de la méthode getCoords(): réussi" << endl;
    cout << "test de la méthode move()" << endl;
    Tree.move(1);
    cout << "test de la méthode move(): réussi" << endl;
    cout << "test de la méthode push_back()" << endl;
    Tree.push_back(&Tree);
    cout <<  "test de la méthode push_back(): réussi" << endl;

}