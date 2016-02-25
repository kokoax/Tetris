OBJ = tetrisMain.o tetrisMap.o tetrisPattern.o tetrisRun.o archive.o
FLAG = -c -O2 -Wall -W -std=c++11

default : $(OBJ)
	g++ $(OBJ) -o Tetris -lm



tetrisMain.o : tetrisMain.cpp tetris.h
	g++ $(FLAG) tetrisMain.cpp

tetrisMap.o : tetrisMap.cpp tetrisMap.h tetris.h
	g++ $(FLAG) tetrisMap.cpp

tetrisPattern.o : tetrisPattern.cpp tetrisPattern.h tetris.h
	g++ $(FLAG) tetrisPattern.cpp

tetrisRun.o : tetrisRun.cpp tetrisRun.h tetris.h
	g++ $(FLAG) tetrisRun.cpp

archive.o : archive.cpp archive.h tetris.h
	g++ $(FLAG) archive.cpp


run : $(OBJ)
	g++ $(OBJ) -o Tetris -lm
	./Tetris

clean :
	rm *.o
	rm Tetris

