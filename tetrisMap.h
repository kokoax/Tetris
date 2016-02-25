#pragma once

#include "tetris.h"
#include "tetrisPattern.h"
#define MAP_HIGH 20
#define MAP_WIDTH 10

class tetrisMap {
  private:
    char map[MAP_HIGH][MAP_WIDTH];

    void hidePattern( const tetrisPattern ctl );
    void appearPattern( const tetrisPattern ctl );
    void printMap( void );

  public:
    tetrisMap( void );
    void movePattern( tetrisPattern *nowPattern );
};

