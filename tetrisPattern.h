#pragma once

#include "tetris.h"
#include "archive.h"

/*
 * このクラスは落下するパターンの形と座標の保持と
 * 出現するすべてのパターンの保持をする.
 */
class tetrisPattern {
  private:
    // 落ちてくるブロックのパターンの数
    // ブロックの最大縦幅
    // ブロックの最大横幅
    vector< vector< vector< char > > >Tpatterns;

    void vstrcpy( int i, int j, const char *from );
    void initPattern( void );
    void initTakePattern( void );

  public:
    int x, y;
    PATTERN_RETENTION nowPattern;
    PATTERN_RETENTION nextPattern;

    tetrisPattern( void );

    void turnRight( void );
    void turnLeft( void );

    void setPattern( void );
    void selectPattern( PATTERN_RETENTION *pattern );

    void test( void );
};

