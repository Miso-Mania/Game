
#include <ncurses.h>
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

    FILE* fichierplatform = NULL;
    fichierplatform = fopen("niveaux/texte/1/0.txt", "r");
    //on the first line, the coordinates of the obstacles, separated by a space;
    while (fscanf(fichierobstacle, "%d %d", &y, &x) != EOF) {
      mvprintw(LINES - y, x, "P");
    } 
    fclose(fichierplatform);

    FILE* fichierboxfinish = NULL;
    fichierboxfinish = fopen("niveaux/texte/1/2.txt", "r");
    //on the first line, the coordinates of the obstacles, separated by a space;
    while (fscanf(fichierboxfinish, "%d %d", &y, &x) != EOF) {
      mvprintw(LINES - y, x, "F");
    } 
    fclose(fichierboxfinish);

    char lastInput = 'o';
    // Listen for keyboard input to move and jump the player
    int key = getch();
    switch (key) {
      case 'q':
        player_x--;
        lastInput = 'q';

        break;
      case 'd':
        player_x++;
        lastInput = 'd';
        break;
      case 'z': //jump
        lastInput = 'z';
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
    //we check if the player touches the obstacle (if yes its game over, we print a message on the screen and  and we close the game and ncurses)
    if (mvwinch(stdscr, player_y, player_x) == 'X') {
      mvprintw(LINES / 2, COLS / 2 - 5, "GAME OVER");
      getch();
      endwin();
      return 0;
    }
     //we check if he his inside the platform (if yes we push him out)
      if (mvwinch(stdscr, player_y , player_x) == 'P') {
        if (lastInput == 'q')
          player_x++;
        else if (lastInput == 'd'){
          player_x--;
        }
      }//we check if the player is on top of a platform, if yes he will not fall
      if (mvwinch(stdscr, player_y - 1, player_x) == 'P') {
        player_y++;
      }
      //we check if the player touches the finish (if yes we print a message on the screen and  and we close the game and ncurses)
      if (mvwinch(stdscr, player_y, player_x) == 'F') {
        mvprintw(LINES / 2, COLS / 2 - 5, "YOU WIN");
        getch();
        endwin();
        return 0;
      }



    

    
    refresh();
  }

  endwin();
  return 0;
}