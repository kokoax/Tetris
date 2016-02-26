#include "archive.h"

//void vstrcpy( vector< char > to, vector< char > from ){
void vstrcpy( vector< char > to, const char from[] ){
  int i;
  for( i = 0; from[i] != '\0'; i++ ){
    to[i] = from[i];
  }
  to[i] = '\0';
}


int mygetch( void ) {
  struct termios  oldt,
                  newt;
  int ch;

  tcgetattr( STDIN_FILENO, &oldt );

  newt = oldt;

  newt.c_lflag &= ~( ICANON | ECHO );

  tcsetattr( STDIN_FILENO, TCSANOW, &newt );

  ch = getchar( );

  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );

  return ch;
}

