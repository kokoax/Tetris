//tetrisMap.cpp
//2016-02-25
#include "tetrisMap.h"

void tetrisMap::printMap( void ){
  for( int i = 0; i < MAP_HIGH; i++ ){
    for( int j = 0; j < MAP_WIDTH; j++ ){
    }
  }
}

tetrisMap::tetrisMap( void ){
  printMap();
}

void tetrisMap::movePattern( tetrisPattern *nowPattern ){
  switch( nowPattern->getState() ){
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
    default:
      // 存在しない状態
      fprintf( stderr, "Missing nowPattern.getState\n" );
      exit( -1 );
      break;
  }
}

void tetrisMap::hidePattern( const tetrisPattern ctl ){
  for( int i = 0; i < ctl.y; i++ ){
    for( int j = 0; j < ctl.x; j++ ){
    }
  }
}

void tetrisMap::appearPattern( const tetrisPattern ctl ){
  for( int i = 0; i < ctl.y; i++ ){
    for( int j = 0; j < ctl.x; j++ ){
    }
  }
}

