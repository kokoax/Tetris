//tetrisRun.cpp
//2016-02-25
#include "tetrisRun.h"
#include "tetrisPattern.h"
#include "tetrisMap.h"

tetrisRun::tetrisRun( void ){
  tetrisPattern Pattern;
  tetrisMap     Map;
  while( 1 ){
    Map.movePattern( &Pattern.nowPattern );
    int data = mygetch();
    if( data == 0x48 || data == 'w'){
      //上キー
      //Map.moveUp( Pattern.nowPattern );
      //
    } else if( data == 0x50 || data == 's' ){
      //下キー
      Pattern.nowPattern.state = 1;
    } else if( data == 0x4B || data == 'a' ){
      //左キー
      Pattern.nowPattern.state = 2;
    } else if( data == 0x4D || data == 'd' ){
      //右キー
      Pattern.nowPattern.state = 3;
    } else if( data == 'e' || data == 'q' ){
      break;
    }
  }
}

