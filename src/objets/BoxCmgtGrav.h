#ifndef BOXCMGTGRAV_H
#define BOXCMGTGRAV_H

#include "SDL2/SDL.h"
#include "../coords.h"

/// @brief classe BoxCmgtGrav
class BoxCmgtGrav {
    public:
        ///@brief constructeur par défaut de la classe BoxCmgtGrav
        BoxCmgtGrav();
        /// @brief constructeur de la classe BoxCmgtGrav, en paramètre les coordonnées de l'objet
        BoxCmgtGrav(int x, int y, int TILE_SIZE);
        /// @brief destructeur de la classe BoxCmgtGrav
        ~BoxCmgtGrav();
        /// @brief fonction qui permet de renvoyer l'objet
        void push_back(BoxCmgtGrav* BoxCmgtGrav);
        /// @brief fonction qui permet de récupérer les coordonnées de l'objet
        SDL_Rect getRect();
        /// @brief fonction qui permet de déplacer l'objet
        void move(double delta);
        /// @brief fonction qui permet de récupérer les coordonnées de l'objet
        Coords getCoords();
        /// @brief fonction qui permet de tester la classe
        void testRegression();
        private:
        /// @brief coordonnées de l'objet
        Coords m_coords;
        /// @brief rectangle de l'objet
        SDL_Rect m_rect;
};

#endif // BOXCMGTGRAV

