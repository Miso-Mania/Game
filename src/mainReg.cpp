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
    return 0;
    cout<<endl;
    cout<<"Changement de Classe"<<endl;
    cout<<endl;
    Coords coords;
    coords.testRegression();

}