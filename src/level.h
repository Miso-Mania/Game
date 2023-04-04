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
#include "objets/BoxCmgtGrav.h"
#include "enemy.h"
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class Level {
public:
/**
    @brief constructeur de la classe Level
    @param aucun
    */
    Level();
/**
    @brief destructeur de la classe Level
    @param aucun
    */
    ~Level();
/**
    @brief fonction qui permet d'ajouter un obstacle
    @param int x, int y, int width, int height
    */
    void addObstacle(int x, int y, int width, int height);
/**
    @brief fonction qui permet de récupérer les obstacles
    @param aucun
    @return vector<Obstacle*>
    */
    vector<Obstacle*> getObstacles();
/**
    @brief fonction qui permet d'ajouter une pic
    @param int x, int y, int TILE_SIZE
    */
    void addPic(int x, int y, int TILE_SIZE);
/**
    @brief fonction qui permet de récupérer les pics
    @param aucun
    @return vector<Pic*>
    */
    vector<Pic*> getPics();
/**
    @brief fonction qui permet d'ajouter une box de fin
    @param int x, int y, int TILE_SIZE
    */
    void addBoxFinish(int x, int y, int TILE_SIZE);
/**
    @brief fonction qui permet de récupérer les box de fin
    @param aucun
    @return vector<BoxFinish*>
    */
    vector<BoxFinish*> getBoxFinish();
/**
    @brief fonction qui permet d'ajouter un arbre
    @param int x, int y, int TILE_SIZE
    */
    void addTree(int x, int y, int TILE_SIZE);
/**
    @brief fonction qui permet de récupérer les arbres
    @param aucun
    @return vector<Tree*>
    */
    vector<Tree*> getTrees();
/**
    @brief fonction qui permet d'ajouter un doublejumpport
    @param int x, int y, int TILE_SIZE
    */
    void addDoubleJumpPort(int x, int y, int TILE_SIZE);
/**
    @brief fonction qui permet de récupérer les doublejumpport
    @param aucun
    @return vector<DoubleJumpPort*>
    */
    vector<DoubleJumpPort*> getDoubleJumpPort();
/**
    @brief fonction qui permet d'ajouter une D_Case
    @param int x, int y, int TILE_SIZE
    */
    void addD_Case(int x, int y, int TILE_SIZE);
/**
    @brief fonction qui permet de récupérer les D_Case
    @param aucun
    @return vector<D_Case*>
    */
    vector<D_Case*> getD_Case();
/**
    @brief fonction qui permet d'ajouter une Case
    @param int x, int y, int TILE_SIZE
    */
    void addCase(int x, int y, int TILE_SIZE);
/**
    @brief fonction qui permet de récupérer les Case
    @param aucun
    @return vector<Case*>
    */
    vector<Case*> getCase();
/**
    @brief fonction qui permet d'ajouter une S_Plateform
    @param int x, int y, int TILE_SIZE
    */
    void addS_Plateform(int x, int y, int TILE_SIZE);
/**
    @brief fonction qui permet de récupérer les S_Plateform
    @param aucun
    @return vector<S_Plateform*>
    */
    vector<S_Plateform*> getS_Plateform();
/**
    @brief fonction qui permet d'ajouter une M_Plateform
    @param int x, int y, int TILE_SIZE
    */
    void addM_Plateform(int x, int y, int TILE_SIZE);
/**
    @brief fonction qui permet de récupérer les M_Plateform
    @param aucun
    @return vector<M_Plateform*>
    */
    vector<M_Plateform*> getM_Plateform();
/**
    @brief fonction qui permet d'ajouter une L_Plateform
    @param int x, int y, int TILE_SIZE
    */
    void addL_Plateform(int x, int y, int TILE_SIZE);
/**
    @brief fonction qui permet de récupérer les L_Plateform
    @param aucun
    @return vector<L_Plateform*>
    */
    vector<L_Plateform*> getL_Plateform();
/**
    @brief fonction qui permet d'ajouter une box changement de gravité
    @param int x, int y, int TILE_SIZE
    */
    void addBoxCmgtGrav(int x, int y, int TILE_SIZE);
/**
    @brief fonction qui permet de récupérer les box changement de gravité
    @param aucun
    @return vector<BoxCmgtGrav*>
    */
    vector<BoxCmgtGrav*> getBoxCmgtGrav();
/**
    @brief fonction qui permet d'ajouter un ennemi
    @param int x, int y, int TILE_SIZE
    */
    void addEnemy(int x, int y, int TILE_SIZE);
/**
    @brief fonction qui permet de récupérer les ennemis
    @return vector<Enemy*>
    */
    vector<Enemy*> getEnemy();
    void click(double x, double y, int TILE_SIZE);

/**
    @brief fonction qui permet de charger un niveau, depuis un fichier JSON
    @param string filePATHandname, int TILE_SIZE
    */
    void loadFromJSON(string filePATHandname, int TILE_SIZE);
/**
    @brief fonction qui permet de sauvegarder un niveau vers un fichier JSON
    @param string filePATHandname
    */
    void saveToJSON(string filePATHandname);

    void testRegression();

    int id;
    string name;
    string creator;

    /// @brief string qui permet de savoir quel type d'objet est sélectionné
    string selectedObj;

private:
    vector<Obstacle*> m_obstacles; // liste des obstacles
    vector<Pic*> m_pics; // liste des pics
    vector<BoxFinish*> m_BoxFinish; // liste des box de fin
    vector<Tree*> m_trees; // liste des arbres
    vector<DoubleJumpPort*> m_DoubleJumpPort; // liste des doublejumpport
    vector<D_Case*> m_D_Case; // liste des D_Case
    vector<Case*> m_Case; // liste des Case
    vector<S_Plateform*> m_S_Plateform; // liste des S_Plateform
    vector<M_Plateform*> m_M_Plateform; // liste des M_Plateform
    vector<L_Plateform*> m_L_Plateform; // liste des L_Plateform
    vector<BoxCmgtGrav*> m_BoxCmgtGrav; // liste des box changement de gravité
    vector<Enemy*> m_Enemy; // liste des ennemis
    int get_Tile_Size(); // fonction qui permet de récupérer la taille d'une tile

};

#endif // LEVEL_H