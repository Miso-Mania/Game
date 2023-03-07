#ifndef L_Plateform_H
#define L_Plateform_H
#include <SDL2/SDL.h>

/// @brief classe L_Plateform
class L_Plateform {
public:
    /// @brief constructeur de la classe L_Plateform, en paramètre les coordonnées de l'L_Plateform
    L_Plateform(int x, int y, int TILE_SIZE);
    /// @brief destructeur de la classe L_Plateform
    ~L_Plateform();
    /// @brief fonction qui permet de renvoyer l'L_Plateform
    void push_back(L_Plateform* L_Plateform);
    /// @brief fonction qui permet de récupérer les coordonnées de l'L_Plateform
    SDL_Rect getRect();
    /// @brief fonction qui permet de déplacer l'L_Plateform
    void move(double delta);

private:
    /// @brief coordonnées de l'L_Plateform
    SDL_Rect m_rect;
};

#endif // L_Plateform
