#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string.h>
#include "objets/obstacle.h"
#include "objets/BoxFinish.h"
#include "objets/pic.h"
#include "objets/tree.h"
#include "objets/D_Case.h"
#include "objets/Case.h"
#include "objets/S_Plateform.h"
#include "objets/M_Plateform.h"
#include "objets/L_Plateform.h"
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
    /// @brief fonction qui permet d'ajouter une D_Case
    void addD_Case(int x, int y, int TILE_SIZE);
    /// @brief fonction qui permet de récupérer les D_Case
    vector<D_Case*> getD_Case();
    /// @brief fonction qui permet d'ajouter une Case
    void addCase(int x, int y, int TILE_SIZE);
    /// @brief fonction qui permet de récupérer les Case
    vector<Case*> getCase();
    /// @brief fonction qui permet d'ajouter une S_Plateform
    void addS_Plateform(int x, int y, int TILE_SIZE);
    /// @brief fonction qui permet de récupérer les S_Plateform
    vector<S_Plateform*> getS_Plateform();
    /// @brief fonction qui permet d'ajouter une M_Plateform
    void addM_Plateform(int x, int y, int TILE_SIZE);
    /// @brief fonction qui permet de récupérer les M_Plateform
    vector<M_Plateform*> getM_Plateform();
    /// @brief fonction qui permet d'ajouter une L_Plateform
    void addL_Plateform(int x, int y, int TILE_SIZE);
    /// @brief fonction qui permet de récupérer les L_Plateform
    vector<L_Plateform*> getL_Plateform();

    void click(double x, double y, int TILE_SIZE);



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
    /// @brief vecteur de D_Case
    vector<D_Case*> m_D_Case;
    /// @brief vecteur de Case
    vector<Case*> m_Case;
    /// @brief vecteur de S_Plateform
    vector<S_Plateform*> m_S_Plateform;
    /// @brief vecteur de M_Plateform
    vector<M_Plateform*> m_M_Plateform;
    /// @brief vecteur de L_Plateform
    vector<L_Plateform*> m_L_Plateform;
    int get_Tile_Size();

};

#endif // LEVEL_H