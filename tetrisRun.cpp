//tetrisRun.cpp
//2016-02-25
#include "tetrisRun.h"
#include "tetrisPattern.h"
#include "tetrisMap.h"

tetrisRun::tetrisRun( void ){
  tetrisPattern Pattern;
  tetrisMap     Map;
  //auto result = async( launch::async, [] { return long_calc(); } );
  while( 1 ){
    int data = getch();
    if( data == 0x48 ){
      //上キー
      //Map.moveUp( Pattern.nowPattern );
      //
    } else if( data == 0x50 ){

      //下キー
    } else if( data == 0x4B ){
      //左キー
    } else if( data == 0x4D ){
      //右キー
    }
  }
}

