#include "particule.h"

Particule::Particule(double x, double y, double vx, double vy, double ax, double ay, double life, double size, int r, int g, int b) {
    this->x = x;
    this->y = y;
    this->vx = vx;
    this->vy = vy;
    this->ax = ax;
    this->ay = ay;
    this->life = life;
    this->size = size;
    this->r = r;
    this->g = g;
    this->b = b;
}

Particule::~Particule() {
}

void Particule::update(double delta) {
    vx += ax;
    vy += ay;
    x += vx;
    y += vy;
    life -= delta;
}

bool Particule::isAlive() {
    return life > 0;
}

ParticuleSystem::ParticuleSystem() {
}

ParticuleSystem::~ParticuleSystem() {
}

void ParticuleSystem::update(double delta) {
    int i = 0;
    for (Particule &p : m_particules) {
        p.update(delta);
        if (!p.isAlive()) {
            m_particules.erase(m_particules.begin() + i);
        }
        i++;
    }
}

void ParticuleSystem::render(int windowWidth, int windowHeight) {
    for (Particule &p : m_particules) {
        SDL_Rect rect;
        rect.x = p.x / 48 * windowWidth;
        rect.y = p.y / 27 * windowHeight;
        rect.w = p.size / 48 * windowWidth;
        rect.h = p.size / 27 * windowHeight;
        SDL_SetRenderDrawColor(m_renderer, p.r, p.g, p.b, 255);
        SDL_RenderFillRect(m_renderer, &rect);
    }
}

void ParticuleSystem::addParticule(Particule p) {
    m_particules.push_back(p);
}

