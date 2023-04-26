#include "coords.h"
#include <iostream>
#include <assert.h>
using namespace std;


Coords::Coords() {
    x = 0;
    y = 0;
    w = 0;
    h = 0;
}

Coords::Coords(double x, double y, double w, double h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

Coords::~Coords() {
    x = 0;
    y = 0;
    w = 0;
    h = 0;
}

bool Coords::isColliding(Coords other) {
    return (x + w > other.x && 
            x < other.x + other.w &&
            y + h > other.y &&
            y < other.y + other.h);
}

void Coords::testRegression() {
    cout<<"Test de régression de la classe Coords"<<endl;
    cout<<"test du constructeur de la classe"<<endl;
    Coords coords;
    assert (coords.x == 0);
    assert (coords.y == 0);
    assert (coords.w == 0);
    assert (coords.h == 0);
    cout<<"test du constructeur de la classe: réussi"<<endl;
    cout<<"test du constructeur avec paramètres de la classe"<<endl;
    Coords coords2(1,2,3,4);
    assert (coords2.x == 1);
    assert (coords2.y == 2);
    assert (coords2.w == 3);
    assert (coords2.h == 4);
    cout<<"test du constructeur avec paramètres de la classe: réussi"<<endl;
    cout<<"test de la fonction isColliding de la classe"<<endl;
    Coords coords3(1,2,3,4);
    Coords coords4(2,3,4,5);
    assert (coords3.isColliding(coords4) == true);
    Coords coords5(10,10,10,10);
    Coords coords6(20,20,20,20);
    assert (coords5.isColliding(coords6) == false);
    cout<<"test de la fonction isColliding de la classe: réussi"<<endl;
    cout<<"test de la fonction destructeur de la classe"<<endl;
    Coords coords7;
    coords7.~Coords();
    assert (coords7.x == 0);
    assert (coords7.y == 0);
    assert (coords7.w == 0);
    assert (coords7.h == 0);
    cout<<"test de la fonction destructeur de la classe: réussi"<<endl;
}

    