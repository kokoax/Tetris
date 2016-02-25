//tetrisPattarn.cpp
//2016-02-25
#include "tetrisPattern.h"

/* ブロックのパターンを決め打ちですべて入れる
 * Pattern:  四角 2 x 2
 *           T字  2 x 3
 *           縦棒 3 x 1
 */
void tetrisPattern::initPattern( void ){
  // 四角のパターン
  char *rectPattern[2] = {
    "##",
    "##"
  };

  // T字のパターン
  char TPattern[2][4] = {
    "###",
    " # "
  };

  // 縦棒のパターン
  char StickPattern[4][2] = {
    "#",
    "#",
    "#",
    "#"
  };

  //etc...
}

tetrisPattern::tetrisPattern( void ){

}

void tetrisPattern::moveDown( void ){

}

void tetrisPattern::moveRight( void ){

}

void tetrisPattern::moveLeft( void ){

}

// 次に落下するパターンをセットする
void tetrisPattern::setPattern( void ){

}
