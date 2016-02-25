#pragma once

#include "tetris.h"

class tetrisMap {
  private:
    char map[MAP_HIGH][MAP_WIDTH];

  public:
    tetrisMap( void );
    void putMap( tetrisPattern nowPattern );
};

