//tetrisRun.cpp
//2016-02-25
#include "../header/tetrisRun.h"

mutex cpp_mutex;

/*
 * キー入力があったときにそのキーに合わせて現在表示されているパターンを移動させる
 */
void tetrisRun::KeyAction( tetrisPattern &Pattern, tetrisMap &Map ){
  // 並列処理1 KeyAction( &Pattern, &Map )
  while( 1 ){
    int data = mygetch();   //キー入力を待機

    //並列処理内で共有変数を変更するのでロックする
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
        Map.appearPattern( Pattern.nowPattern );
        Pattern.printNextPattern();
      }
    } else if( data == 0x4B || data == 'a' ){
      //左キー
      Map.movePatternLeft( &Pattern.nowPattern );
    } else if( data == 0x4D || data == 'd' ){
      //右キー
      Map.movePatternRight( &Pattern.nowPattern );
    } else if( data == 'e' || data == 'q' ){
      //fprintf( stderr, "\e[2J" );
      system( "clear" );
      exit( true );
    }

    //ロックの解除
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
    this_thread::sleep_for( chrono::microseconds( (int)( 1000000 / ( ( Map.score+100 ) / 100 ) ) ) );

    //並列処理内で共有変数を変更するのでロックする
    cpp_mutex.lock();

    //マップに現在落下しているパターンを一段下に移動して表示する
    //現時点より下に移動できないときfalseが帰ってくるので接地したと評価して以下を実行する
    if( Map.movePatternDown( &Pattern.nowPattern ) == false ){
      //次に落ちてくるパターンを現在落ちているパターンに代入し
      //次に落ちてくるパターンをランダムに選択する
      Pattern.setPattern();
      //それをマップに表示する
      Map.appearPattern( Pattern.nowPattern );
      //次に落ちてくるパターンを表示する
      Pattern.printNextPattern();
    }

    //ロックの解除
    cpp_mutex.unlock();
  }
}

tetrisRun::tetrisRun( void ){
  tetrisMap     Map;
  tetrisPattern Pattern;

  //最初に落下を始めるパターンを表示する
  Map.appearPattern( Pattern.nowPattern );

  //キー入力があったときにブロックを表示する処理をするスレッド
  thread keyAction(  &tetrisRun::KeyAction , this, ref( Pattern ), ref( Map ) );
  //一定時間ごとにブロックを下に移動して表示するスレッド
  thread timeAction( &tetrisRun::TimeAction, this, ref( Pattern ), ref( Map ) );

  /* keyActionでプログラムの終了を制御しているためkeyActionが終わったら
   * timeActionの状態に関わらず終了する */
  keyAction.join();
  //timeAction.join();
}

