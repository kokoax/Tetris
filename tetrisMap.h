#pragma once

#include "tetris.h"
#include "tetrisPattern.h"
#define MAP_HIGH 30
#define MAP_WIDTH 15

class tetrisMap {
  private:
    char map[MAP_HIGH][MAP_WIDTH];

    void initMap( void );
    void printMap( void );
    void hidePattern( const PATTERN_RETENTION ctl );
    void appearPattern( const PATTERN_RETENTION ctl );

  public:
    tetrisMap( void );
    void movePattern( PATTERN_RETENTION *nowPattern );

    void test( void );
};

