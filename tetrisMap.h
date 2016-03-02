#pragma once

#include "tetris.h"
#include "tetrisPattern.h"

class tetrisMap {
  private:
    char map[MAP_HIGH][MAP_WIDTH];
    int score;

    void initMap( void );
    void printMap( void );
    void hidePattern( const PATTERN_RETENTION ctl );
    int  checkPenetrate( PATTERN_RETENTION nowPattern );
    void putPatternMap( PATTERN_RETENTION nowPattern );
    void attachProcess( PATTERN_RETENTION *nowPattern );
    void DeleteColumnAligned( void );
    void DeleteColumn( int number );
    void checkGameover( void );
    void printScore( void );
    void printOther( void );

  public:
    tetrisMap( void );

    int  movePatternDown( PATTERN_RETENTION *nowPattern );
    void movePatternRight( PATTERN_RETENTION *nowPattern );
    void movePatternLeft( PATTERN_RETENTION *nowPattern );

    void turnPatternRight( PATTERN_RETENTION *nowPattern );
    void turnPatternLeft( PATTERN_RETENTION *nowPattern );

    void appearPattern( const PATTERN_RETENTION ctl );

    void test( void );
};

