#include <iostream>
#include "player.h"
#include "level.h"
#include "coords.h"
#include "objets/BoxCmgtGrav.h"
#include "objets/Case.h"
#include "objets/BoxFinish.h"
#include "objets/D_Case.h"
#include "objets/DoubleJumpPort.h"
#include "objets/L_Plateform.h"
#include "objets/M_Plateform.h"
#include "objets/S_Plateform.h"
#include "objets/obstacle.h"
#include "objets/pic.h"
#include "objets/tree.h"
#include "particule.h"
#include "enemy.h"

using namespace std;

int main () {
    Player player;
    player.testRegression();
    cout<<endl;
    cout<<"Changement de Classe"<<endl;
    cout<<endl;
    Level level;
    level.testRegression();
    cout<<endl;
    cout<<"Changement de Classe"<<endl;
    cout<<endl;
    Coords coords;
    coords.testRegression();
    cout<<endl;
    cout<<"Changement de Classe"<<endl;
    cout<<endl;
    BoxCmgtGrav boxCmgtGrav;
    boxCmgtGrav.testRegression();
    cout<<endl;
    cout<<"Changement de Classe"<<endl;
    cout<<endl;
    Case Case;
    Case.testRegression();
    cout<<endl;
    cout<<"Changement de Classe"<<endl;
    cout<<endl;
    BoxFinish boxFinish;
    boxFinish.testRegression();
    cout<<endl;
    cout<<"Changement de Classe"<<endl;
    cout<<endl;
    D_Case d_Case;
    d_Case.testRegression();
    cout<<endl;
    cout<<"Changement de Classe"<<endl;
    cout<<endl;
    DoubleJumpPort doubleJumpPort;
    doubleJumpPort.testRegression();
    cout<<endl;
    cout<<"Changement de Classe"<<endl;
    cout<<endl;
    L_Plateform l_Plateform;
    l_Plateform.testRegression();
    cout<<endl;
    cout<<"Changement de Classe"<<endl;
    cout<<endl;
    M_Plateform m_Plateform;
    m_Plateform.testRegression();
    cout<<endl;
    cout<<"Changement de Classe"<<endl;
    cout<<endl;
    S_Plateform s_Plateform;
    s_Plateform.testRegression();
    cout<<endl;
    cout<<"Changement de Classe"<<endl;
    cout<<endl;
    Obstacle obstacle;
    obstacle.testRegression();
    cout<<endl;
    cout<<"Changement de Classe"<<endl;
    cout<<endl;
    Pic pic;
    pic.testRegression();
    cout<<endl;
    cout<<"Changement de Classe"<<endl;
    cout<<endl;
    Tree tree;
    tree.testRegression();
    cout<<endl;
    cout<<"Changement de Classe"<<endl;
    cout<<endl;
    Enemy enemy;
    enemy.testRegression();
    cout<<endl;
    return 0;
}

