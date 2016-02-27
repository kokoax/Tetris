//tetrisRun.cpp
//2016-02-25
#include "tetrisRun.h"
#include <chrono>

mutex cpp_mutex;

/*
 * キー入力があったときにそのキーに合わせて現在表示されているパターンを移動させる
 */
void tetrisRun::KeyAction( tetrisPattern &Pattern, tetrisMap &Map ){
  // 並列処理1 KeyAction( &Pattern, &Map )
  while( 1 ){
    int data = mygetch();

    cpp_mutex.lock();

    if( data == 0x48 || data == 'w'){
      //上キー
      //Map.moveUp( Pattern.nowPattern );
      //Pattern.turnPattern();
      //
    } else if( data == 0x50 || data == 's' ){
      //下キー
      Map.movePatternDown( &Pattern.nowPattern );
    } else if( data == 0x4B || data == 'a' ){
      //左キー
      Map.movePatternLeft( &Pattern.nowPattern );
    } else if( data == 0x4D || data == 'd' ){
      //右キー
      Map.movePatternRight( &Pattern.nowPattern );
    } else if( data == 'e' || data == 'q' ){
      break;
    }

    cpp_mutex.unlock();
  }
}

/*
 * 一定時間ごとに現在表示しているパターンを下に移動させる
 */
void tetrisRun::TimeAction( tetrisPattern &Pattern, tetrisMap &Map ){
  int i = 0;
  // 並列処理2 TimeAction( &Pattern, &Map )
  while( 1 ) {
    //int data = mygetch();

    //usleep( 1000000 );    // usleepはマイクロ秒sleepなので usleep( 1 ) == 0.0000001秒
    this_thread::sleep_for( chrono::seconds( 1 ) );

    cpp_mutex.lock();

    //Map.appearPattern( Pattern.nowPattern );
    Map.movePatternDown( &Pattern.nowPattern );

    //printf( "\e[%d;1H", i+33 );
    //printf( "%d", i++ );

    // alock( KeyAction );
    cpp_mutex.unlock();
  }
}

tetrisRun::tetrisRun( void ){
  tetrisPattern Pattern;
  tetrisMap     Map;

  thread keyAction(  &tetrisRun::KeyAction , this, ref( Pattern ), ref( Map ) );
  thread timeAction( &tetrisRun::TimeAction, this, ref( Pattern ), ref( Map ) );

  //thread timeAction = new thread(  []{ printf( "asd\n" );  );
  //thread timeAction( TimeAction, &Pattern, &Map );

  //keyAction.join();
  //timeAction.join();

  keyAction.join();
  //timeAction.join();
}

