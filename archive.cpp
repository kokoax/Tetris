#include "archive.h"

//void vstrcpy( vector< char > to, vector< char > from ){
void vstrcpy( vector< char > to, const char from[] ){
  int i;
  for( i = 0; from[i] != '\0'; i++ ){
    to[i] = from[i];
  }
  to[i] = '\0';
}

