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

  // Main game loop
  while (true) {
    // Clear the screen and print the player character
    clear();
    mvhline(LINES - 1, 0, '=', COLS);
    mvprintw(player_y, player_x, "I");
    //we print the obstacle
    mvprintw(LINES - 2, 2, "X");
    mvprintw(LINES - 2, 5, "N");
    mvprintw(LINES - 2, 6, "X");
    mvprintw(LINES - 2, 7, "N");
    // want to print the obstacles and the platforms, there coordinates are set in the leveltexte.txt file:
    // on ouvre le fichier en lecture
    FILE* fichier = NULL;
    fichier = fopen("niveaux/leveltexte.txt", "r");
    //on the first line, the coordinates of the obstacles, separated by a space
    int x, y;
    while (fscanf(fichier, "%d %d", &x, &y) != EOF) {
        mvprintw(LINES - y, x, "X");
    } 

    
    refresh();

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
    //we check if the player is on the obstacle
    if ((player_y == LINES - 2) && (player_x == 2 || player_x == 6)) {
        //we print the game over
        mvprintw(LINES - 2, 2, "GAME OVER");
        refresh();
        //we wait for the player to press a key
        getch();
        //we exit the game
        break;
      }
      //we check if the player is on the platform
      if ((player_y == LINES - 2) && (player_x == 5 || player_x == 7 )) {
        player_y = LINES - 3;
      }
  }

  // Clean up ncurses
  endwin();
  return 0;
}