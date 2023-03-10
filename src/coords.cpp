#include "coords.h"


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
}

bool Coords::isColliding(Coords other) {
    return (x + w > other.x && 
            x < other.x + other.w &&
            y + h > other.y &&
            y < other.y + other.h);
}
