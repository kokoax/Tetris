//tetrisMap.cpp
//2016-02-25
#include "tetrisMap.h"

void tetrisMap::initMap( void ){
  for( int i = 0; i < MAP_HIGH; i++ ){
    for( int j = 0; j < MAP_WIDTH; j++ ){
      map[i][j] = ' ';
    }
  }
}

void tetrisMap::printMap( void ){
  for( int i = 1; i <= MAP_HIGH; i++ ){
    //先頭に行数を表示しているため左に二個ずらしている
    for( int j = 1; j <= MAP_WIDTH+1; j++ ){
      // 座標( i, j )に次printfで出力する位置を変更する
      fprintf( stderr, "\033[%d;%dH", i+1, j+1 );
      fprintf( stderr, "%c", map[i-1][j-1] );
    }
  }
  for( int i = 1; i <= MAP_WIDTH+2; i++ ){
    fprintf( stderr, "\033[%d;%dH", 1, i );
    fprintf( stderr, "+" );
    fprintf( stderr, "\033[%d;%dH", MAP_HIGH+2, i );
    fprintf( stderr, "+" );
  }
  for( int i = 1; i <= MAP_HIGH+2; i++ ){
    fprintf( stderr, "\033[%d;%dH", i, 1 );
    fprintf( stderr, "+" );
    fprintf( stderr, "\033[%d;%dH", i, MAP_WIDTH+2 );
    fprintf( stderr, "+" );
  }
}


tetrisMap::tetrisMap( void ){
  initMap();
  //test();
  printMap();
}

void tetrisMap::putPatternMap( PATTERN_RETENTION nowPattern ){
  for( int i = nowPattern.y; i < nowPattern.y+(int)nowPattern.pattern.size(); i++ ){
    for( int j = nowPattern.x; j < nowPattern.x+(int)nowPattern.pattern[0].size(); j++ ){
      if( nowPattern.pattern[i-nowPattern.y][j-nowPattern.x] == '#' ){
        map[i-1][j-1] = '#';
      }
    }
  }
}

void tetrisMap::DeleteColumn( int number ){
  for( int i = number; i > 0; i-- ){
    for( int j = 0; j < MAP_WIDTH; j++ ){
      map[i][j] = map[i-1][j];
    }
  }
  for( int i = 0; i < MAP_WIDTH; i++ ){
    map[0][i] = ' ';
  }
}

void tetrisMap::DeleteColumnAligned( void ){
  for( int i = 0; i < MAP_HIGH; i++ ){
    for( int j = 0; j < MAP_WIDTH; j++ ){
      if( map[i][j] != '#' )  break;
      if( j == MAP_WIDTH-1 ){
        DeleteColumn( i-- );
      }
    }
  }
}

void tetrisMap::attachProcess( PATTERN_RETENTION *nowPattern ){
  putPatternMap( *nowPattern );
  DeleteColumnAligned();
  printMap();
}

int tetrisMap::movePatternDown( PATTERN_RETENTION *nowPattern ){
  //if( nowPattern->y < MAP_HIGH - (int)nowPattern->pattern.size() -1 ){
  hidePattern( *nowPattern );
  nowPattern->y++;
  if( checkPenetrate( *nowPattern ) != true ){
    nowPattern->y--;
    attachProcess( &(*nowPattern) );
    return false;
  }
  appearPattern( *nowPattern );
  return true;
}

void tetrisMap::movePatternRight( PATTERN_RETENTION *nowPattern ){
  //if( nowPattern->x < MAP_WIDTH - (int)nowPattern->pattern[0].size() -1 ){
  hidePattern( *nowPattern );
  nowPattern->x++;
  if( checkPenetrate( *nowPattern ) != true ){
    nowPattern->x--;
  }
  appearPattern( *nowPattern );
}

void tetrisMap::movePatternLeft( PATTERN_RETENTION *nowPattern ){
  //if( nowPattern->x > 1 ){
  hidePattern( *nowPattern );
  nowPattern->x--;
  if( checkPenetrate( *nowPattern ) != true ){
    nowPattern->x++;
  }
  appearPattern( *nowPattern );
}

void tetrisMap::hidePattern( const PATTERN_RETENTION ctl ){
  for( int i = ctl.y; i < ctl.y+(int)ctl.pattern.size(); i++ ){
    for( int j = ctl.x; j < ctl.x+(int)ctl.pattern[0].size(); j++ ){
      //map[i][j] = ' ';
      if( ctl.pattern[i-ctl.y][j-ctl.x] == '#' ){
        fprintf( stderr, "\e[%d;%dH", i+1, j+1 );
        fprintf( stderr, " " );
      }
    }
  }
}

void tetrisMap::appearPattern( const PATTERN_RETENTION ctl ){
  for( int i = ctl.y; i < ctl.y+(int)ctl.pattern.size(); i++ ){
    for( int j = ctl.x; j < ctl.x+(int)ctl.pattern[0].size(); j++ ){
      //map[i][j] = ctl.pattern[i-ctl.y][j-ctl.x];
      if( ctl.pattern[i-ctl.y][j-ctl.x] == '#' ){
        fprintf( stderr, "\e[%d;%dH", i+1, j+1 );
        fprintf( stderr, "%c", ctl.pattern[i-ctl.y][j-ctl.x] );
      }
    }
  }
}

int tetrisMap::checkPenetrate( PATTERN_RETENTION nowPattern ){
  if ( nowPattern.y < 1 ){
    return UP;
  } else if( nowPattern.y > ( MAP_HIGH+2  - (int)nowPattern.pattern.size()    -1 ) ){
    return DOWN;
  } else if( nowPattern.x < 1 ){
    return LEFT;
  } else if( nowPattern.x > ( MAP_WIDTH+2 - (int)nowPattern.pattern[0].size() -1 ) ){
    return RIGHT;
  } else {
    for( int i = 0; i < (int)nowPattern.pattern.size(); i++ ){
      for( int j = 0; j < (int)nowPattern.pattern[0].size(); j++ ){
        if( ( nowPattern.pattern[i][j] == '#' ) &&
            ( map[i + nowPattern.y -1][j + nowPattern.x -1] == '#' ) ){
          return DOWN;
        }
      }
    }
  }
  return true;
}

void tetrisMap::turnPatternRight( PATTERN_RETENTION *nowPattern ){
  PATTERN_RETENTION work;
  work.x = nowPattern->x;
  work.y = nowPattern->y;

  hidePattern( *nowPattern );

  work.pattern.resize( (int)nowPattern->pattern[0].size() );
  for( int i = 0; i < (int)nowPattern->pattern[0].size(); i++ ){
    work.pattern[i].resize( (int)nowPattern->pattern.size() );
  }

  for( int i = 0; i < (int)nowPattern->pattern.size(); i++ ){
    for( int j = 0; j < (int)nowPattern->pattern[0].size(); j++ ){
      work.pattern[j][(int)nowPattern->pattern.size() - i -1] = nowPattern->pattern[i][j];
    }
  }

  if( checkPenetrate( work ) == true ){
    nowPattern->pattern = work.pattern;
  }

  appearPattern( *nowPattern );
}

void tetrisMap::test( void ){
  PATTERN_RETENTION tmp;
  tmp.pattern.resize( 3 );
  for( int i = 0; i < 3; i++ ){
    tmp.pattern[i].resize( 3 );
  }
  tmp.pattern[0][0] = '#';
  tmp.pattern[0][1] = '#';
  tmp.pattern[0][2] = '\0';
  tmp.pattern[1][0] = '#';
  tmp.pattern[1][1] = '#';
  tmp.pattern[1][2] = '\0';
  tmp.pattern[2][0] = '\0';
  tmp.pattern[2][1] = '\0';
  tmp.pattern[2][2] = '\0';

  tmp.x = 0;
  tmp.y = 0;
  tmp.state = 0;

  movePatternDown( &tmp );
  //appearPattern( tmp );
  //hidePattern( tmp );
  tmp.state = 2;
  movePatternLeft( &tmp );
}

