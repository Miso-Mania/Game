#include "particule.h"

Particule::Particule(double x, double y, double vx, double vy, double ax, double ay, double life, double size, int r, int g, int b, int a, SDL_BlendMode blendMode) {
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
    this->a = a;
    this->blendMode = blendMode;
}

Particule::~Particule() {
}

void Particule::update(double delta) {
    vx += ax * delta;
    vy += ay * delta;
    x += vx * delta;
    y += vy * delta;
    life -= delta;
}

bool Particule::isAlive() {
    return life > 0;
}

void Particule::push_back(Particule* Particule) {
}

ParticuleSystem::ParticuleSystem() {
}

ParticuleSystem::~ParticuleSystem() {
}

void ParticuleSystem::update(double delta) {
    for (int i=m_particules.size()-1; i >= 0; i--) {
        m_particules[i]->update(delta);
        if (!m_particules[i]->isAlive()) {
            delete m_particules[i];
            m_particules.erase(m_particules.begin() + i);
        }
    }
}

void ParticuleSystem::render(SDL_Renderer *m_renderer, int windowWidth, int windowHeight) {
    for (Particule *p : m_particules) {
        SDL_Rect rect;
        rect.x = p->x * 40;
        rect.y = p->y * 40;
        rect.w = p->size * 40;
        rect.h = p->size * 40;
        SDL_SetRenderDrawBlendMode(m_renderer, p->blendMode);
        SDL_SetRenderDrawColor(m_renderer, p->r, p->g, p->b, p->a);
        SDL_RenderFillRect(m_renderer, &rect);
    }
}

void ParticuleSystem::addParticule(Particule *p) {
    m_particules.push_back(p);
}

