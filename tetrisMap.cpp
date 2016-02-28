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
  fprintf( stderr, "\e[2J" );    // 画面クリア
  for( int i = 1; i <= MAP_HIGH; i++ ){
    //先頭に行数を表示しているため左に二個ずらしている
    for( int j = 1; j <= MAP_WIDTH; j++ ){
      // 座標( i, j )に次printfで出力する位置を変更する
      fprintf( stderr, "\033[%d;%dH", i+1, j+1 );
      fprintf( stderr, "%c", map[i-1][j-1] );
    }
  }
  for( int i = 1; i <= MAP_WIDTH; i++ ){
    fprintf( stderr, "\033[%d;%dH", 1, i );
    fprintf( stderr, "+" );
    fprintf( stderr, "\033[%d;%dH", MAP_HIGH, i );
    fprintf( stderr, "+" );
  }
  for( int i = 1; i <= MAP_HIGH; i++ ){
    fprintf( stderr, "\033[%d;%dH", i, 1 );
    fprintf( stderr, "+" );
    fprintf( stderr, "\033[%d;%dH", i, MAP_WIDTH );
    fprintf( stderr, "+" );
  }
}


tetrisMap::tetrisMap( void ){
  initMap();
  //test();
  printMap();
}

void tetrisMap::movePatternDown( PATTERN_RETENTION *nowPattern ){
  hidePattern( *nowPattern );
  nowPattern->y++;
  appearPattern( *nowPattern );
}

void tetrisMap::movePatternRight( PATTERN_RETENTION *nowPattern ){
  hidePattern( *nowPattern );
  nowPattern->x++;
  appearPattern( *nowPattern );
}

void tetrisMap::movePatternLeft( PATTERN_RETENTION *nowPattern ){
  hidePattern( *nowPattern );
  nowPattern->x--;
  appearPattern( *nowPattern );
}

void tetrisMap::hidePattern( const PATTERN_RETENTION ctl ){
  for( int i = ctl.y; i < ctl.y+(int)ctl.pattern.size()-1; i++ ){
    for( int j = ctl.x; j < ctl.x+(int)ctl.pattern[0].size()-1; j++ ){
      //map[i][j] = ' ';
      fprintf( stderr, "\e[%d;%dH", i+1, j+1 );
      fprintf( stderr, " " );
    }
  }
}

void tetrisMap::appearPattern( const PATTERN_RETENTION ctl ){
  for( int i = ctl.y; i < ctl.y+(int)ctl.pattern.size()-1; i++ ){
    for( int j = ctl.x; j < ctl.x+(int)ctl.pattern[0].size()-1; j++ ){
      //map[i][j] = ctl.pattern[i-ctl.y][j-ctl.x];
      fprintf( stderr, "\e[%d;%dH", i+1, j+1 );
      fprintf( stderr, "%c", ctl.pattern[i-ctl.y][j-ctl.x] );
    }
  }
}

void tetrisMap::turnPatternRight( PATTERN_RETENTION *nowPattern ){
  PATTERN_RETENTION work;

  hidePattern( *nowPattern );

  work.pattern.resize( (int)nowPattern->pattern[0].size() );
  for( int i = 0; i < (int)nowPattern->pattern[0].size(); i++ ){
    work.pattern[i].resize( (int)nowPattern->pattern.size() );
  }


  for( int i = 0; i < (int)nowPattern->pattern.size(); i++ ){
    for( int j = 0; j < (int)nowPattern->pattern[0].size(); j++ ){
      work.pattern[j][(int)nowPattern->pattern.size() - i -1] = nowPattern->pattern[i][j];
      //work.pattern[j][(int)nowPattern->pattern.size() - i -1] = '#';
      fprintf( stderr, "\e[%d;%dH", i+33, j+1 );
      fprintf( stderr, "%c", nowPattern->pattern[i][j] );
    }
  }
  nowPattern->pattern = work.pattern;
  //*nowPattern = work;

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

