#ifndef M_Plateform_H
#define M_Plateform_H
#include <SDL2/SDL.h>

/// @brief classe M_Plateform
class M_Plateform {
public:
    /// @brief constructeur de la classe M_Plateform, en paramètre les coordonnées de l'M_Plateform
    M_Plateform(int x, int y);
    /// @brief destructeur de la classe M_Plateform
    ~M_Plateform();
    /// @brief fonction qui permet de renvoyer l'M_Plateform
    void push_back(M_Plateform* M_Plateform);
    /// @brief fonction qui permet de récupérer les coordonnées de l'M_Plateform
    SDL_Rect getRect();
    /// @brief fonction qui permet de déplacer l'M_Plateform
    void move(double delta);

private:
    /// @brief coordonnées de l'M_Plateform
    SDL_Rect m_rect;
};

#endif // M_Plateform