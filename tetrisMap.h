#pragma once

#include "tetris.h"
#include "tetrisPattern.h"

class tetrisMap {
  private:
    char map[MAP_HIGH][MAP_WIDTH];

    void initMap( void );
    void printMap( void );
    void hidePattern( const PATTERN_RETENTION ctl );

  public:
    tetrisMap( void );
    void movePatternDown( PATTERN_RETENTION *nowPattern );
    void movePatternRight( PATTERN_RETENTION *nowPattern );
    void movePatternLeft( PATTERN_RETENTION *nowPattern );
    void appearPattern( const PATTERN_RETENTION ctl );

    void test( void );
};

