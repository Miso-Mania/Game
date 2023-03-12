#include <iostream>
#include <ncurses.h>
#include "game.h"
using namespace std;

int main() {
  // Initialize ncurses
  initscr();
  cbreak();
  noecho();
  curs_set(0);

  int player_x = 0;
  int player_y = LINES - 2;
  int player_vy = 0;
  //we store the coordinates of the obstacles in a matrix
  int obstacles[100][2]; // 1 if there is an obstacle, 0 if there is a platform, -1 if there is nothing
  //we initialize the matrix
  for (int i=0; i<100; i++) {
      for (int j=0; j<2; j++) {
          obstacles[i][j]=0;
      }
  }


  // Main game loop
  while (true) {
    // Clear the screen and print the player character
    clear();
    mvhline(LINES - 1, 0, '=', COLS);
    mvprintw(player_y, player_x, "I");
 
    // want to print the obstacles and the platforms, there coordinates are set in the leveltexte.txt file:
    // on ouvre le fichierobstacle en lecture
    FILE* fichierobstacle = NULL;
    fichierobstacle = fopen("niveaux/texte/1/1.txt", "r");
    //on the first line, the coordinates of the obstacles, separated by a space
    int x, y;
    while (fscanf(fichierobstacle, "%d %d", &y, &x) != EOF) {
        mvprintw(LINES - y, x, "X");
        obstacles[y][x]=1;
    } 
    fclose(fichierobstacle);

    //on ouvre le fichierplatform en lecture
    FILE* fichierplatform = NULL;
    fichierplatform = fopen("niveaux/texte/1/0.txt", "r");
    while (fscanf(fichierplatform, "%d %d", &y, &x) != EOF) {
        mvprintw(LINES - y, x, "R");
        obstacles[LINES - y][x]=0;
    }
    fclose(fichierplatform);

    
    

    // Listen for keyboard input to move and jump the player
    int key = getch();
    switch (key) {
      case 'q':
        player_x--;
        break;
      case 'd':
        player_x++;
        break;
      case 'z': //jump
        player_vy = -2; // set upward velocity
        break;
      default:
        break;
    }
    // Apply gravity to the player velocity
    player_vy += 1;

    // Move the player vertically based on the current velocity
    player_y += player_vy;

    // Keep the player above the bottom of the screen
    if (player_y >= LINES - 1) {
      player_y = LINES - 2;
      player_vy = 0;
    }
    //we check if the player touches the obstacle (if yes its game over and we close the game and ncurses)
    if (obstacles[LINES - player_y][player_x]==1) {
        mvprintw(LINES/2, COLS/2, "GAME OVER");
        getch();
        endwin();
        return 0;
    }
    refresh();
  }

  endwin();
  return 0;
}