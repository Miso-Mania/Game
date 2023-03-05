#ifndef S_Plateform_H
#define S_Plateform_H
#include <SDL2/SDL.h>

/// @brief classe S_Plateform
class S_Plateform {
public:
    /// @brief constructeur de la classe S_Plateform, en paramètre les coordonnées de l'S_Plateform
    S_Plateform(int x, int y);
    /// @brief destructeur de la classe S_Plateform
    ~S_Plateform();
    /// @brief fonction qui permet de renvoyer l'S_Plateform
    void push_back(S_Plateform* S_Plateform);
    /// @brief fonction qui permet de récupérer les coordonnées de l'S_Plateform
    SDL_Rect getRect();
    /// @brief fonction qui permet de déplacer l'S_Plateform
    void move(double delta);

private:
    /// @brief coordonnées de l'S_Plateform
    SDL_Rect m_rect;
};

#endif // S_Plateform
