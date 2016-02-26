//tetrisPattarn.cpp
//2016-02-25
#include "tetrisPattern.h"

/* ブロックのパターンを決め打ちですべて入れる
 * Pattern:  四角 2 x 2
 *           T字  2 x 3
 *           縦棒 3 x 1
 */
void tetrisPattern::vstrcpy( int i, int j, const char *from ){
  int k;
  for( k = 0; from[k] != '\0'; k++ ){
    Tpatterns[i][j][k] = from[k];
  }
  Tpatterns[i][j][k] = '\0';
}

void tetrisPattern::clearStr( int i, int j, int length ){
  for( int k = 0; k < length; k++ ){
    Tpatterns[i][j][k] = '\0';
  }
}

void tetrisPattern::initPattern( void ){
  Tpatterns.resize( 10 );   // ブロックのパターンの数

  // 四角のパターン
  Tpatterns[0].resize( 3 );
  for( int i = 0; i < 3; i++ ){
    Tpatterns[0][i].resize( 3 );
  }

  vstrcpy( 0, 0, "##" );
  vstrcpy( 0, 1, "##" );
  clearStr( 0, 2, (int)Tpatterns[0][0].size() );

 // T字のパターン
  Tpatterns[1].resize( 3 );
  for( int i = 0; i < 3; i++ ){
    Tpatterns[1][i].resize( 4 );
  }

  vstrcpy( 1, 0, "###" );
  vstrcpy( 1, 1, " # " );
  clearStr( 1, 2, (int)Tpatterns[1][0].size() );

  // 縦棒のパターン
  Tpatterns[2].resize( 5 );
  for( int i = 0; i < 5; i++ ){
    Tpatterns[2][i].resize( 2 );
  }

  vstrcpy( 2, 0, "#" );
  vstrcpy( 2, 1, "#" );
  vstrcpy( 2, 2, "#" );
  vstrcpy( 2, 3, "#" );
  clearStr( 2, 4, (int)Tpatterns[2][0].size() );

  //etc...

  //最後は番兵
  Tpatterns[3].resize( 1 );
  Tpatterns[3][0].resize( 1 );

  Tpatterns[3][0][0] = '\0';

}

void tetrisPattern::initTakePattern( void ){
  nextPattern.pattern.resize( 5 );
  nowPattern.pattern.resize( 5 );
  for( int i = 0; i < 5; i++ ){
    nextPattern.pattern[i].resize( 5 );
    nowPattern.pattern[i].resize( 5 );
  }
  setPattern( &nextPattern );
  setPattern( &nowPattern );
}

tetrisPattern::tetrisPattern( void ){
  initPattern();
  initTakePattern();
}

void tetrisPattern::moveDown( void ){

}

void tetrisPattern::moveRight( void ){

}

void tetrisPattern::moveLeft( void ){

}

// 次に落下するパターンをセットする
void tetrisPattern::setPattern( PATTERN_RETENTION *pattern ){
  int select = rand() % 3;
  state = 0;  // パターンをセットしなおす時はパターンが下まで落ちきったときなので状態は表示されていないところまで戻る
  for( int i = 0; Tpatterns[select][i][0] != '\0'; i++ ){
    for( int j = 0; Tpatterns[select][i][j] != '\0'; j++ ){
      pattern->pattern[i][j] = Tpatterns[select][i][j];
    }
    if( Tpatterns[select][i+1][0] == '\0' ){
      for( int j = 0; Tpatterns[select][i][j] != '\0'; j++ ){
        pattern->pattern[i+1][j] = Tpatterns[select][i+1][j];
      }
    }
  }
}

void tetrisPattern::test( void ){
  printf( "Created patterns print\n" );
  for( int i = 0; Tpatterns[i][0][0] != '\0'; i++ ){
    printf( "\nPattern Number %d\n", i );
    for( int j = 0; Tpatterns[i][j][0] != '\0'; j++ ){
      for( int k = 0; Tpatterns[i][j][k] != '\0'; k++ ){
        printf( "%c", Tpatterns[i][j][k] );
      }
      printf( "\n" );
    }
    printf( "\n" );
  }

  printf( "nowPattern print\n" );
  for( int i = 0; nowPattern.pattern[i][0] != '\0'; i++ ){
    for( int j = 0; nowPattern.pattern[i][j] != '\0'; j++ ){
      printf( "%c", nowPattern.pattern[i][j] );
    }
    printf( "\n" );
  }
  printf( "\n" );

  printf( "nextPattern print\n" );
  for( int i = 0; nextPattern.pattern[i][0] != '\0'; i++ ){
    for( int j = 0; nextPattern.pattern[i][j] != '\0'; j++ ){
      printf( "%c", nextPattern.pattern[i][j] );
    }
    printf( "\n" );
  }
}

