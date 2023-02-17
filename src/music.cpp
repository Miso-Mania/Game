#include "music.h"

Music::Music(const std::string& filename) : m_music(nullptr) {
    m_music = Mix_LoadMUS(filename.c_str());
}

Music::~Music() {
    if (m_music) {
        Mix_FreeMusic(m_music);
        m_music = nullptr;
    }
}

bool Music::isPlaying() const {
    return Mix_PlayingMusic() != 0;
}

void Music::play() {
    if (m_music) {
        if (!isPlaying()) {
            Mix_PlayMusic(m_music, -1);
        }
    }
}

void Music::pause() {
    if (isPlaying()) {
        Mix_PauseMusic();
    }
}

void Music::stop() {
    if (isPlaying()) {
        Mix_HaltMusic();
    }
}