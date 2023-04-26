#include <iostream>
#include <ncurses.h>

const  int size = 100;
bool running = true;


int main() {
  // Initialize ncurses
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  //On demande au joueur quel niveau il veut 
  int level = 0; //level 1 par défaut
  std::cout << "Veuillez entrer le niveau que vous voulez jouer (1-3)" << std::endl;
  std::cin >> level;
  //on vérifie que le niveau est valide
  while (level != 1 && level != 2 && level != 3) {
    std::cout << "Veuillez entrer un niveau valide" << std::endl;

    std::cin >> level;
  }
  int player_x = 0;
  int player_y = LINES - 2;
  int player_vy = 0;


  // Main game loop
  while (running) {
    // Clear the screen and print the player character
    clear();

    mvhline(LINES - 1, 0, '=', COLS);
    mvprintw(player_y, player_x, "I");
 
    FILE* fichierobstacle = NULL;
    // we open the file corresponding to the level
    if (level == 1) {
      fichierobstacle = fopen("niveaux/texte/1/1.txt", "r");
    }
    else if (level == 2) {
      fichierobstacle = fopen("niveaux/texte/2/1.txt", "r");
    }
    else if (level == 3) {
      fichierobstacle = fopen("niveaux/texte/3/1.txt", "r");
    }
    int x, y;
    while (fscanf(fichierobstacle, "%d %d", &y, &x) != EOF) {
      mvprintw(LINES - y, x, "!");
    } 
    fclose(fichierobstacle); 

    FILE* fichierplatform = NULL;

    if (level == 1) {
      fichierplatform = fopen("niveaux/texte/1/0.txt", "r");
    }
    else if (level == 2) {
      fichierplatform = fopen("niveaux/texte/2/0.txt", "r");
    }
    else if (level == 3) {
      fichierplatform = fopen("niveaux/texte/3/0.txt", "r");
    }
    //on the first line, the coordinates of the obstacles, separated by a space;
    while (fscanf(fichierobstacle, "%d %d", &y, &x) != EOF) {
      mvprintw(LINES - y, x, "#");
    } 
    fclose(fichierplatform);

    FILE* fichierboxfinish = NULL;

    if (level == 1) {
      fichierboxfinish = fopen("niveaux/texte/1/2.txt", "r");
    }
    else if (level == 2) {
      fichierboxfinish = fopen("niveaux/texte/2/2.txt", "r");
    }
    else if (level == 3) {
      fichierboxfinish = fopen("niveaux/texte/3/2.txt", "r");
    }
    //on the first line, the coordinates of the obstacles, separated by a space;
    while (fscanf(fichierboxfinish, "%d %d", &y, &x) != EOF) {
      mvprintw(LINES - y, x, "F");
    } 
    fclose(fichierboxfinish);

    char lastInput = 'o';
    char lastlastInput = 'o'; // the imput before the last one, it get the value of lastInput at the end of the loop
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
    if (mvwinch(stdscr, player_y, player_x) == '!') {
      mvprintw(LINES / 2, COLS / 2 - 5, "GAME OVER");
      getch();
      endwin();
      return 0;
    }
    //Collisions with the platform
    if (mvwinch(stdscr, player_y, player_x) == '#') {
      if(lastlastInput == 'z'){
        player_y --;
        player_vy = 0;
      }
      else if(lastlastInput == 'q'){
        player_x ++;
      }
      else if(lastlastInput == 'd'){
        player_x --;
      }
      if (lastInput == 'd') {
        player_x --;
      }
      else if (lastInput == 'q') {
        player_x ++;
      }
      else if (lastInput == 'z') {
        player_y ++;
        player_vy = 0;
      }
    }
      //we check if the player touches the finish (if yes we go to the next level)
    if (mvwinch(stdscr, player_y, player_x) == 'F') {
      if(level == 3){
        mvprintw(LINES / 2, COLS / 2 - 5, "YOU WIN");
        getch();
        endwin();
        return 0;
      }
      else{
      running = false;
      //on clear tout le terminal
      clear();
      level = 0;

      }
      
    }
    // Refresh the screen



    

    lastlastInput = lastInput;
    refresh();
  }
  main();

  return 0;
}
