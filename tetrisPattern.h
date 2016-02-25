#pragma once

#include "tetris.h"

class tetrisPattern {
  private:
    int x, y;

    // 落ちてくるブロックのパターンの数
    // ブロックの最大縦幅
    // ブロックの最大横幅
    char pattern[10][3][3];

    void initPattern( void );

  public:
    tetrisPattern( void );

    void moveDown( void );
    void moveRight( void );
    void moveLeft( void );

    void setPattern( void );

};

