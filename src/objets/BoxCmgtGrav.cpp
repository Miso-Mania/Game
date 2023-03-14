# include "BoxCmgtGrav.h"
# include <iostream>
# include <assert.h>
using namespace std;

BoxCmgtGrav::BoxCmgtGrav() {
    m_coords = Coords();
    m_rect = SDL_Rect();
}

BoxCmgtGrav::BoxCmgtGrav(int x, int y, int TILE_SIZE) {
    m_coords = Coords(x, y, 1, 3);
    
    m_rect.x = x * TILE_SIZE;
    m_rect.y = y * TILE_SIZE;
    // definit la taille et la forme de la box
    m_rect.w = TILE_SIZE;
    m_rect.h = 3*TILE_SIZE;

}

BoxCmgtGrav::~BoxCmgtGrav() {
}

void BoxCmgtGrav::move(double delta) {
}

void BoxCmgtGrav::push_back(BoxCmgtGrav* BoxCmgtGrav) {
}

SDL_Rect BoxCmgtGrav::getRect() {
    return m_rect;
}

Coords BoxCmgtGrav::getCoords() {
    return m_coords;
}

void BoxCmgtGrav::testRegression () {
    cout<<"Test de regression de la classe BoxCmgtGrav"<<endl;
    cout<<"test du constructeur de la classe"<<endl;
    BoxCmgtGrav boxCmgtGrav;
    assert (boxCmgtGrav.getCoords().x == 0);
    assert (boxCmgtGrav.getCoords().y == 0);
    assert (boxCmgtGrav.getCoords().w == 0);
    assert (boxCmgtGrav.getCoords().h == 0);
    assert (boxCmgtGrav.getRect().x == 0);
    assert (boxCmgtGrav.getRect().y == 0);
    assert (boxCmgtGrav.getRect().w == 0);
    assert (boxCmgtGrav.getRect().h == 0);
    cout<<"test du constructeur de la classe: réussi"<<endl;
    cout<<"test du constructeur de la classe"<<endl;
    BoxCmgtGrav boxCmgtGrav1(1,2,3);
    assert (boxCmgtGrav1.getCoords().x == 1);
    assert (boxCmgtGrav1.getCoords().y == 2);
    assert (boxCmgtGrav1.getCoords().w == 1);
    assert (boxCmgtGrav1.getCoords().h == 3);
    assert (boxCmgtGrav1.getRect().x == 3);
    assert (boxCmgtGrav1.getRect().y == 6);
    assert (boxCmgtGrav1.getRect().w == 3);
    assert (boxCmgtGrav1.getRect().h == 9);
    cout<<"test du constructeur de la classe: réussi"<<endl;
    cout<<"test de la fonction destructeur de la classe"<<endl;
    BoxCmgtGrav boxCmgtGrav2(1,2,3);
    boxCmgtGrav2.~BoxCmgtGrav();
    cout<<"test de la fonction destructeur de la classe: réussi"<<endl;
    cout<<"test de la fonction getRect de la classe"<<endl;
    BoxCmgtGrav boxCmgtGrav3(1,2,3);
    assert (boxCmgtGrav3.getRect().x == 3);
    assert (boxCmgtGrav3.getRect().y == 6);
    assert (boxCmgtGrav3.getRect().w == 3);
    assert (boxCmgtGrav3.getRect().h == 9);
    cout<<"test de la fonction getRect de la classe: réussi"<<endl;
    cout<<"test de la fonction getCoords de la classe"<<endl;
    BoxCmgtGrav boxCmgtGrav4(1,2,3);
    assert (boxCmgtGrav4.getCoords().x == 1);
    assert (boxCmgtGrav4.getCoords().y == 2);
    assert (boxCmgtGrav4.getCoords().w == 1);
    assert (boxCmgtGrav4.getCoords().h == 3);
    cout<<"test de la fonction getCoords de la classe: réussi"<<endl;
    cout<<"test de la fonction push_back de la classe"<<endl;
    BoxCmgtGrav boxCmgtGrav5(1,2,3);
    BoxCmgtGrav boxCmgtGrav6(1,2,3);
    boxCmgtGrav5.push_back(&boxCmgtGrav6);
    cout<<"test de la fonction push_back de la classe: réussi"<<endl;
    cout<<"test de la fonction move de la classe"<<endl;
    BoxCmgtGrav boxCmgtGrav7(1,2,3);
    boxCmgtGrav7.move(1);
    cout<<"test de la fonction move de la classe: réussi"<<endl;
}
