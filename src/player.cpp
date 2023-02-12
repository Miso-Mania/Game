#include "player.h"

Player::Player(): m_rect({0, 0, 32, 32}), m_yVelocity(0) {
}

Player::~Player() {
}

void Player::update(double delta) {
    m_rect.y += (int)(m_yVelocity * delta);
    //gravité
    m_yVelocity += 500 * delta;
    // Clamp velocity
    if (m_yVelocity > 500) {
        m_yVelocity = 500;
    }
}

void Player::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &m_rect);
}

void Player::handleEvents(SDL_Event &event) {
    switch (event.type) {
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_SPACE) {
                jump();
            }
            break;
        default:
            break;
    }
}

void Player::jump() {
    m_yVelocity = -500;
}




