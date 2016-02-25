#pragma once

#include "tetris.h"

/*
 * このクラスは落下するパターンの形と座標の保持と
 * 出現するすべてのパターンの保持をする.
 */
class tetrisPattern {
  private:
    char nextPattern[3][3];
    char nowPattern[3][3];
    int x, y;

    // 落ちてくるブロックのパターンの数
    // ブロックの最大縦幅
    // ブロックの最大横幅
    char **pattern[10];

    void initPattern( void );

  public:
    tetrisPattern( void );

    void moveDown( void );
    void moveRight( void );
    void moveLeft( void );

    void turnRight( void );
    void turnLeft( void );

    void setPattern( void );

};

