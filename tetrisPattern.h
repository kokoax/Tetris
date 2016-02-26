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
    void clearStr( int i, int j, const int length );
    void initPattern( void );
    void initTakePattern( void );

  public:
    int x, y;
    vector< vector< char > >nextPattern;
    vector< vector< char > >nowPattern;
    int state;

    tetrisPattern( void );

    void moveDown( void );
    void moveRight( void );
    void moveLeft( void );

    void turnRight( void );
    void turnLeft( void );

    void setPattern( vector< vector< char > > *pattern );

    void test( void );
};

