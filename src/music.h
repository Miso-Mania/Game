#ifndef MUSIC_H
#define MUSIC_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h> //TODO: apparament, il vaut mieux utiliser FMOD que SDL_mixer

class Music {
public:
    Music(const std::string& filename);
    ~Music();

    bool isPlaying() const;

    void play();
    void pause();
    void stop();

private:
    Mix_Music* m_music;
};

#endif
