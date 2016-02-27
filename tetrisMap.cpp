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
  printf( "\e[2J" );    // 画面クリア
  for( int i = 1; i <= MAP_HIGH; i++ ){
    //printf( "\033[%d;1H", i );
    //printf( "%d", i );
    //先頭に行数を表示しているため左に二個ずらしている
    for( int j = 1; j <= MAP_WIDTH; j++ ){
      // 座標( i, j )に次printfで出力する位置を変更する
      printf( "\033[%d;%dH", i, j );
      printf( "%c", map[i-1][j-1] );
      //printf( "c" );
    }
  }
}

tetrisMap::tetrisMap( void ){
  initMap();
  //test();
  printMap();
}

void tetrisMap::movePattern( PATTERN_RETENTION *nowPattern ){
  switch( nowPattern->state ){
    case 0:
      // state == 0 -> 一番最初の状態でマップに表示されていない状態
      appearPattern( *nowPattern );
      break;
    case 1:
      // state == 1 -> 左ボタンが押されている状態
      hidePattern( *nowPattern );
      nowPattern->x--;
      appearPattern( *nowPattern );
      break;
    case 2:
      // state == 2 -> 右ボタンが押されている状態
      hidePattern( *nowPattern );
      nowPattern->x++;
      appearPattern( *nowPattern );
      break;
    case 3:
      // state == 3 -> 下ボタンが押されている状態
      hidePattern( *nowPattern );
      nowPattern->y++;
      appearPattern( *nowPattern );
      break;
    case 4:
      // state == 4 -> パターンが表示されていてかつボタンが何も押されていない状態
      break;
    default:
      // 存在しない状態
      fprintf( stderr, "Missing nowPattern.getState\n" );
      exit( -1 );
      break;
  }
  nowPattern->state = 4;
}

void tetrisMap::hidePattern( const PATTERN_RETENTION ctl ){
  for( int i = ctl.y; i < ctl.y+(int)ctl.pattern.size(); i++ ){
    for( int j = ctl.x; j < ctl.x+(int)ctl.pattern[0].size(); j++ ){
      //map[i][j] = ' ';
      printf( "\e[%d;%dH", i+1, j+1 );
      printf( " " );
    }
  }
}

void tetrisMap::appearPattern( const PATTERN_RETENTION ctl ){
  for( int i = ctl.y; i < ctl.y+(int)ctl.pattern.size(); i++ ){
    for( int j = ctl.x; j < ctl.x+(int)ctl.pattern[0].size(); j++ ){
      //map[i][j] = ctl.pattern[i-ctl.y][j-ctl.x];
      printf( "\e[%d;%dH", i+1, j+1 );
      printf( "%c", ctl.pattern[i-ctl.y][j-ctl.x] );
    }
  }
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

  movePattern( &tmp );
  //appearPattern( tmp );
  //hidePattern( tmp );
  tmp.state = 2;
  movePattern( &tmp );
}

