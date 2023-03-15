#include "pic.h"
#include <iostream>
#include <assert.h>
using namespace std;

Pic::Pic() {
    m_coords = Coords();
    m_triangle = SDL_Rect();
}

Pic::Pic(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 1, 1);
    
    m_triangle.x = x * TILE_SIZE;
    m_triangle.y = y * TILE_SIZE;
    // definit la taille et la forme du pic
    m_triangle.w = TILE_SIZE;
    m_triangle.h = TILE_SIZE;

}

Pic::~Pic() {
}

void Pic::move(double delta) {
}

void Pic::push_back(Pic* pic) {
}

SDL_Rect Pic::getRect() {
    return m_triangle;
}

Coords Pic::getCoords() {
    return m_coords;
}

void Pic::testRegression () {
    cout<<"Test de regression de la classe Pic"<<endl;
    cout<<"test du constructeur de la classe"<<endl;
    Pic pic;
    assert (pic.getCoords().x == 0);
    assert (pic.getCoords().y == 0);
    assert (pic.getCoords().w == 0);
    assert (pic.getCoords().h == 0);
    assert (pic.getRect().x == 0);
    assert (pic.getRect().y == 0);
    assert (pic.getRect().w == 0);
    assert (pic.getRect().h == 0);
    cout<<"test du constructeur de la classe: réussi"<<endl;
    cout<<"test du constructeur de la classe"<<endl;
    Pic pic1(1,2,3);
    assert (pic1.getCoords().x == 1);
    assert (pic1.getCoords().y == 2);
    assert (pic1.getCoords().w == 1);
    assert (pic1.getCoords().h == 1);
    assert (pic1.getRect().x == 3);
    assert (pic1.getRect().y == 6);
    assert (pic1.getRect().w == 3);
    assert (pic1.getRect().h == 3);
    cout<<"test du constructeur de la classe: réussi"<<endl;
    cout<<"test de la methode getRect"<<endl;
    assert (pic1.getRect().x == 3);
    assert (pic1.getRect().y == 6);
    assert (pic1.getRect().w == 3);
    assert (pic1.getRect().h == 3);
    cout<<"test de la methode getRect: réussi"<<endl;
    cout<<"test de la methode getCoords"<<endl;
    assert (pic1.getCoords().x == 1);
    assert (pic1.getCoords().y == 2);
    assert (pic1.getCoords().w == 1);
    assert (pic1.getCoords().h == 1);
    cout<<"test de la methode getCoords: réussi"<<endl;
    cout<<"test de la methode push_back"<<endl;
    pic1.push_back(&pic);
    cout<<"test de la methode push_back: réussi"<<endl;
    cout<<"test de la methode move"<<endl;
    pic1.move(1);
    cout<<"test de la methode move: réussi"<<endl;

}
