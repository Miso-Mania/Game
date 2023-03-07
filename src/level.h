#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string.h>
#include "objets/obstacle.h"
#include "objets/BoxFinish.h"
#include "objets/pic.h"
#include "objets/tree.h"
#include "objets/DoubleJumpPort.h"
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class Level {
public:
    /// @brief constructeur de la classe Level
    Level();
    /// @brief destructeur de la classe Level
    ~Level();
    /// @brief fonction qui permet d'ajouter un obstacle
    void addObstacle(int x, int y, int width, int height);
    /// @brief fonction qui permet de récupérer les obstacles
    vector<Obstacle*> getObstacles();
    /// @brief fonction qui permet d'ajouter une pic
    void addPic(int x, int y, int TILE_SIZE);
    /// @brief fonction qui permet de récupérer les pics
    vector<Pic*> getPics();
    /// @brief fonction qui permet d'ajouter une box de fin
    void addBoxFinish(int x, int y, int TILE_SIZE);
    /// @brief fonction qui permet de récupérer les box de fin
    vector<BoxFinish*> getBoxFinish();
    /// @brief fonction qui permet d'ajouter un tree
    void addTree(int x, int y, int TILE_SIZE);
    /// @brief fonction qui permet de récupérer les trees
    vector<Tree*> getTrees();
    /// @brief fonction qui permet d'ajouter un doublejumpport
    void addDoubleJumpPort(int x, int y, int TILE_SIZE);
    /// @brief fonction qui permet de récupérer les doublejumpport
    vector<DoubleJumpPort*> getDoubleJumpPort();
    /// @brief fonction qui permet de charger un niveau, depuis un fichier JSON
    void loadFromJSON(string filePATHandname, int TILE_SIZE);
    /// @brief fonction qui permet de sauvegarder un niveau vers un fichier JSON
    void saveToJSON(string filePATHandname);

    int id;
    string name;
    string creator;

private:
    /// @brief vecteur d'obstacles
    vector<Obstacle*> m_obstacles;
    /// @brief vecteur de pics
    vector<Pic*> m_pics;
    /// @brief vecteur de box de fin
    vector<BoxFinish*> m_BoxFinish;
    /// @brief vecteur de trees
    vector<Tree*> m_trees;
    /// @brief vecteur de doublejumpport
    vector<DoubleJumpPort*> m_DoubleJumpPort;
    int get_Tile_Size();

};

#endif // LEVEL_H