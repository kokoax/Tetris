#pragma once

#include "tetris.h"
#include "tetrisPattern.h"
#include "tetrisMap.h"

void *KeyAction( void *arg );
void *TimeAction( void *arg );

class tetrisRun {
  private:
    int state;

    void KeyAction( tetrisPattern &Pattern, tetrisMap &Map );
    void TimeAction( tetrisPattern &Pattern, tetrisMap &Map );

  public:
    tetrisRun( void );

};

