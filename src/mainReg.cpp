#include <iostream>
#include "player.h"
#include "level.h"
#include "coords.h"
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
    return 0;

}