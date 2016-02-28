//tetrisRun.cpp
//2016-02-25
#include "tetrisRun.h"

mutex cpp_mutex;

/*
 * キー入力があったときにそのキーに合わせて現在表示されているパターンを移動させる
 */
void tetrisRun::KeyAction( tetrisPattern &Pattern, tetrisMap &Map ){
  // 並列処理1 KeyAction( &Pattern, &Map )
  while( 1 ){
    int data = mygetch();   //キー入力を待機

    cpp_mutex.lock();

    // 入力されたキーごとに処理をする
    if( data == 0x48 || data == 'w'){
      //上キー
      //パターンの回転を行う
      // ex.
      // Pattern.turn();
      // Map.appearPattern( Pattern.nowPattern );
      Map.turnPatternRight( &Pattern.nowPattern );
    } else if( data == 0x50 || data == 's' ){
      //下キー
      if( Map.movePatternDown( &Pattern.nowPattern ) == false ){
        Pattern.setPattern();
      }
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
    //1000000 us = 1 s
    this_thread::sleep_for( chrono::microseconds( 1000000 ) );

    cpp_mutex.lock();

    if( Map.movePatternDown( &Pattern.nowPattern ) == false ){
      Pattern.setPattern();
    }

    // alock( KeyAction );
    cpp_mutex.unlock();
  }
}

tetrisRun::tetrisRun( void ){
  tetrisPattern Pattern;
  tetrisMap     Map;

  thread keyAction(  &tetrisRun::KeyAction , this, ref( Pattern ), ref( Map ) );
  thread timeAction( &tetrisRun::TimeAction, this, ref( Pattern ), ref( Map ) );

  /* keyActionでプログラムの終了を制御しているためkeyActionが終わったら
   * timeActionの状態に関わらず終了する */
  keyAction.join();
  //timeAction.join();
}

