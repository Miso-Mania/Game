#include 'plateform.h'
#include 'player.h'
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Plateform::Plateform() {
    rect.x = 0;
    rect.y = 0;
    rect.w = 32;
    rect.h = 32;
}

Plateform::Plateform(int x, int y, int w, int h) {
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

Plateform::~Plateform() {
}

void Plateform::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

SDL_Rect Plateform::getRect() {
    return rect;
}

bool Plateform::isColliding(Player player) {
    SDL_Rect playerRect = player.getRect();
    if (playerRect.x + playerRect.w > rect.x && playerRect.x < rect.x + rect.w) {
        if (playerRect.y + playerRect.h > rect.y && playerRect.y < rect.y + rect.h) {
            return true;
        }
    }
    return false;
}

