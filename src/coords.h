#ifndef COORDS_H
#define COORDS_H

class Coords {
public:
/**
    @brief constructeur par défaut de la classe Coords
    @param Aucun
    */
    Coords();
/**
    @brief constructeur de la classe Coords, en paramètre les coordonnées de l'objet
    @param double x, double y, double w, double h
    */
    Coords(double x, double y, double w, double h);
/**
    @brief destructeur de la classe Coords
    @param Aucun
    */
    ~Coords();
/**
    @brief fonction isColliding qui permet de savoir si deux objets sont en collision
    @param Coords other
    @return bool
    */
    bool isColliding(Coords other);
/**
    @brief fonction qui permet de tester la régression de la classe Coords
    @param Aucun
    */
    void testRegression();
    double x, y, w, h;

};

#endif