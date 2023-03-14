#include <iostream>
#include "player.h"
#include "level.h"
#include "coords.h"
#include "objets/BoxCmgtGrav.h"
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
    return 0;
}

