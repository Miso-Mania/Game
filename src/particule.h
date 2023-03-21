#include <vector>
#include <SDL2/SDL.h>

class Particule {
    public:
    /**
        @brief constructeur de la classe Particule
        @param double x, double y, double vx, double vy, double ax, double ay, double life, double size, int r, int g, int b, int a
    */
        Particule(double x, double y, double vx, double vy, double ax, double ay, double life, double size, int r, int g, int b, int a);
    /**
        @brief destructeur de la classe Particule
        @param aucun
    */
        ~Particule();
    /**
        @brief Met à jour la particule
        @param delta
    */
        void update(double delta);
    /**
        @brief booléen qui permet de savoir si la particule est en vie
        @param aucun
        @return bool
    */
        bool isAlive();
    /**
        @brief push_back permet d'ajouter une particule dans le vecteur
        @param Particule* Particule
    */
        void push_back(Particule* Particule);

        double x, y, vx, vy, ax, ay; // position, vitesse, accélération
        double life, size;           // durée de vie, taille
        int r, g, b, a;              // couleur
};

class ParticuleSystem {
    public:
    /**
        @brief Constructeur de la classe ParticuleSystem
        @param aucun
    */
        ParticuleSystem();
    /**
        @brief Destructeur de la classe ParticuleSystem
        @param aucun
    */
        ~ParticuleSystem();
    /**
        @brief Met à jour la particule
        @param delta
    */
        void update(double delta);
    /**
        @brief render permet de dessiner les particules
        @param SDL_Renderer *m_renderer, int windowWidth, int windowHeight
     */
        void render(SDL_Renderer *m_renderer, int windowWidth, int windowHeight);
    /**
        @brief addParticule permet d'ajouter une particule dans le vecteur
        @param Particule *p
    */
        void addParticule(Particule *p);

    private:
        std::vector<Particule*> m_particules;
};