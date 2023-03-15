#ifndef MUSIC_H
#define MUSIC_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h> //TODO: apparament, il vaut mieux utiliser FMOD que SDL_mixer

class Music {
public:
/**
    @brief Constructeur de la classe Music
    @param std::string& filename : le nom du fichier audio
*/
    Music(const std::string& filename);
/**
    @brief Destructeur de la classe Music
    @param aucun
    */
    ~Music();
/**
    @brief Fonction qui permet de savoir si la musique est en train de jouer
    @param aucun
*/
    bool isPlaying() const;
/**
    @brief Fonction qui permet de jouer la musique
    @param aucun
*/
    void play();
/**
    @brief Fonction qui permet de mettre en pause la musique    
    @param aucun
*/
    void pause();
/**
    @brief Fonction qui permet d'arrêter la musique
    @param aucun
*/
    void stop();

private:
    Mix_Music* m_music; // la musique 
};

#endif
