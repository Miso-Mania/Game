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
 
    FILE* fichierobstacle = NULL;
    fichierobstacle = fopen("niveaux/texte/1/1.txt", "r");
    //on the first line, the coordinates of the obstacles, separated by a space
    int x, y;
    while (fscanf(fichierobstacle, "%d %d", &y, &x) != EOF) {
      mvprintw(LINES - y, x, "X");
    } 
    fclose(fichierobstacle);
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
    if (mvwinch(stdscr, player_y, player_x) == 'X') {
      endwin();
      return 0;
    }
    refresh();
  }

  endwin();
  return 0;
}