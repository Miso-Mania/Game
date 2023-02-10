#include 'player.h'
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Player::Player() {
    rect.x = 0;
    rect.y = 0;
    rect.w = 32;
    rect.h = 32;
    speed_x = 0;
    speed_y = 0;
}

Player::~Player() {
}

void Player::moveLeft() {
    speed_x = -1;
}

void Player::moveRight() {
    speed_x = 1;
}

void Player::jump() {
    speed_y = -1;
}

void Player::updatePosition() {
    rect.x += speed_x;
    rect.y += speed_y;
    speed_x = 0;
    speed_y = 0;
}

void Player::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

SDL_Rect Player::getRect() {
    return rect;
}

