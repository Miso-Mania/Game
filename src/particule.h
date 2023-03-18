#include <vector>
#include <SDL2/SDL.h>

class Particule {
    public:
        Particule(double x, double y, double vx, double vy, double ax, double ay, double life, double size, int r, int g, int b);
        ~Particule();
        void update(double delta);
        bool isAlive();
        void push_back(Particule* Particule);

        double x, y, vx, vy, ax, ay; // position, vitesse, accélération
        double life, size;           // durée de vie, taille
        int r, g, b;                 // couleur
};

class ParticuleSystem {
    public:
        ParticuleSystem();
        ~ParticuleSystem();
        void update(double delta);
        void render(SDL_Renderer *m_renderer, int windowWidth, int windowHeight);
        void addParticule(Particule *p);

    private:
        std::vector<Particule*> m_particules;
};