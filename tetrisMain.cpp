//tetrisMain.cpp
//2015-10-14

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <unistd.h>

#define WIDTH 20
#define HEIGHT 40
#define TYPE_NUM 2

typedef struct Pattern {
	int h, w;
} PATTERN;

PATTERN T = {
	3,
	2,
};

PATTERN I = {
	4,
	1,
};

class TETRIS {
	private:
		int Tetris[HEIGHT][WIDTH];
		PATTERN pattern[TYPE_NUM];
		int block_height;
		int block_width;

	public:
		TETRIS( void );
		void run( void );
		void print( void );
		void startMoving( void );
};

TETRIS::TETRIS( ){
	for( int i = 0; i < HEIGHT; i++ ){
		for( int j = 0; j < WIDTH; j++ ){
			Tetris[i][j] = 0;
		}
	}
	pattern[0] = T;
	pattern[1] = I;
}

void TETRIS::startMoving( void ){

	for( int i = 0; i < HEIGHT; i++ ){

	}
}

void TETRIS::run( void ){
	int now = rand() % TYPE_NUM;
	int next = rand() % TYPE_NUM;

	startMoving( );

}

void TETRIS::print( ){
	for( int i = 0; i < HEIGHT; i++ ){
		for( int j = 0; j < WIDTH; j++ ){
			printf( "%2d", Tetris[i][j] );
		}
		printf( "\n" );
	}
}

int main( void ){
	TETRIS Tetris;

	Tetris.run( );

	return 0;
}

