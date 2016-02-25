//tetrisPattarn.cpp
//2016-02-25
#include "tetrisPattern.h"

/* ブロックのパターンを決め打ちですべて入れる
 * Pattern:  四角 2 x 2
 *           T字  2 x 3
 *           縦棒 3 x 1
 */
void tetrisPattern::initPattern( void ){
  pattern[0] = { "000",
                 "0##",
                 "0##",
  };
  strcpy( 
  pattern[1] = { "000",
                 "0##",
                 "0##",
  };

  pattern[2] = { "000",
                 "0##",
                 "0##",
  };

}

tetrisPattern::tetrisPattern( void ){

}

void tetrisPattern::moveDown( void ){

}

void tetrisPattern::moveRight( void ){

}

void tetrisPattern::moveLeft( void ){

}

void tetrisPattern::setPattern( void ){

}
