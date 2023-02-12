#include "player.h"

Player::Player(int x, int y, int w, int h) :
    mPosX(x), mPosY(y), WIDTH(w), HEIGHT(h), mVelX(0), mVelY(0) {
    rect = {x, y, w, h};
}

Player::~Player() {
}

void Player::handleEvent(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_UP: mVelY -= 10; break;
            case SDLK_DOWN: mVelY += 10; break;
            case SDLK_LEFT: mVelX -= 10; break;
            case SDLK_RIGHT: mVelX += 10; break;
        }
    } else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_UP: mVelY += 10; break;
            case SDLK_DOWN: mVelY -= 10; break;
            case SDLK_LEFT: mVelX += 10; break;
            case SDLK_RIGHT: mVelX -= 10; break;
        }
    }
}

void Player::move() {
    mPosX += mVelX;
    mPosY += mVelY;
    rect = {mPosX, mPosY, WIDTH, HEIGHT};
}

void Player::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

SDL_Rect Player::getRect() {
    return rect;
}

void Player::onCollision(SDL_Rect platformRect) {
    if (mPosY + HEIGHT >= platformRect.y && mPosY <= platformRect.y + platformRect.h) {
        if (mPosX + WIDTH >= platformRect.x && mPosX <= platformRect.x + platformRect.w) {
            if (mPosY + HEIGHT - mVelY <= platformRect.y) {
                mPosY = platformRect.y - HEIGHT;
                mVelY = 0;
            }
        }
    }
}

void Player::update() {
    if (mPosY + HEIGHT < 600) {
        mVelY += 1;
    }
}





