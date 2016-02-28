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
}

void tetrisPattern::initPattern( void ){
  Tpatterns.resize( 10 );   // ブロックのパターンの数

  // 四角のパターン
  Tpatterns[0].resize( 2 );
  for( int i = 0; i < 2; i++ ){
    Tpatterns[0][i].resize( 2 );
  }

  vstrcpy( 0, 0, "##" );
  vstrcpy( 0, 1, "##" );

 // T字のパターン
  Tpatterns[1].resize( 2 );
  for( int i = 0; i < 2; i++ ){
    Tpatterns[1][i].resize( 3 );
  }

  vstrcpy( 1, 0, "###" );
  vstrcpy( 1, 1, " # " );

  // 縦棒のパターン
  Tpatterns[2].resize( 4 );
  for( int i = 0; i < 4; i++ ){
    Tpatterns[2][i].resize( 1 );
  }

  vstrcpy( 2, 0, "#" );
  vstrcpy( 2, 1, "#" );
  vstrcpy( 2, 2, "#" );
  vstrcpy( 2, 3, "#" );

  // L字のパターン
  Tpatterns[3].resize( 3 );
  for( int i = 0; i < 3; i++ ){
    Tpatterns[3][i].resize( 2 );
  }

  vstrcpy( 3, 0, "##" );
  vstrcpy( 3, 1, "# " );
  vstrcpy( 3, 2, "# " );

  //etc...

  //最後は番兵
  Tpatterns[4].resize( 1 );
  Tpatterns[4][0].resize( 1 );

  Tpatterns[4][0][0] = '\0';

}

void tetrisPattern::initTakePattern( void ){
  selectPattern( &nextPattern );
  selectPattern( &nowPattern );
}

tetrisPattern::tetrisPattern( void ){
  initPattern();
  initTakePattern();

  for( int i = 0; i < 8; i++ ){
    fprintf( stderr, "\033[%d;%dH", 1, i+MAP_WIDTH+5 );
    fprintf( stderr, "+" );
    fprintf( stderr, "\033[%d;%dH", 7, i+MAP_WIDTH+5 );
    fprintf( stderr, "+" );
  }
  for( int i = 0; i < 8; i++ ){
    fprintf( stderr, "\033[%d;%dH", i, MAP_WIDTH+5 );
    fprintf( stderr, "+" );
    fprintf( stderr, "\033[%d;%dH", i, MAP_WIDTH+7+5 );
    fprintf( stderr, "+" );
  }
  fprintf( stderr, "\e[%d;%dH", 8, MAP_WIDTH+5-1 );
  fprintf( stderr, "NEXT BLOCK" );
  printNextPattern();
}

// 次に落下するパターンをセットする
// 現在落下しているパターンに次に落下させるパターンを代入する
// 次に落下するパターンを生成する
void tetrisPattern::setPattern( void ){
  /*
  nowPattern.pattern = nextPattern.pattern;
  nowPattern.x = 1;
  nowPattern.y = 1;
  nowPattern.state = 0;
  */
  nowPattern = nextPattern;

  selectPattern( &nextPattern );
}

void tetrisPattern::selectPattern( PATTERN_RETENTION *pattern ){
  int i, j;
  int select = rand() % 4;

  // パターンが画面に表示されていない状態
  pattern->state = 0;
  pattern->x = 1;
  pattern->y = 1;

  // 選択した落下するパターンのサイズの指定
  pattern->pattern.resize( (int)Tpatterns[select].size() );
  for( i = 0; i < (int)Tpatterns[select].size(); i++ ){
    pattern->pattern[i].resize( (int)Tpatterns[select][i].size() );
  }

  // 選択したパターンを実際に代入
  for( i = 0; i < (int)Tpatterns[select].size(); i++ ){
    for( j = 0; j < (int)Tpatterns[select][i].size(); j++ ){
      pattern->pattern[i][j] = Tpatterns[select][i][j];
    }
  }
}

void tetrisPattern::printNextPattern( void ){
  for( int i = 0 ; i < (int)nowPattern.pattern.size(); i++ ){
    for( int j = 0; j < (int)nowPattern.pattern[0].size(); j++ ){
      if( nowPattern.pattern[i][j] == '#' ){
        fprintf( stderr, "\033[%d;%dH", 6-(int)nowPattern.pattern.size()+i, 6-(int)nowPattern.pattern[0].size()+j+MAP_WIDTH+4 );
        fprintf( stderr, " " );
      }
    }
  }

  for( int i = 0 ; i < (int)nextPattern.pattern.size(); i++ ){
    for( int j = 0; j < (int)nextPattern.pattern[0].size(); j++ ){
      if( nextPattern.pattern[i][j] == '#' ){
        fprintf( stderr, "\033[%d;%dH", 6-(int)nextPattern.pattern.size()+i, 6-(int)nextPattern.pattern[0].size()+j+MAP_WIDTH+4 );
        fprintf( stderr, "#" );
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

