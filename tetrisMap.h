#pragma once

#include "tetris.h"
#include "tetrisPattern.h"

class tetrisMap {
  private:
    //char map[MAP_HIGH][MAP_WIDTH];

  public:
    tetrisMap( void );
    void putMap( tetrisPattern nowPattern );
};

