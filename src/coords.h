#ifndef COORDS_H
#define COORDS_H

class Coords {
public:
    Coords();
    Coords(double x, double y, double w, double h);
    ~Coords();
    double x, y, w, h;
    bool isColliding(Coords other);
    void testRegression();

};

#endif