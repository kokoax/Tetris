OBJ = tetrisMain.o tetrisMap.o tetrisPattern.o tetrisRun.o archive.o
FLAG = -c -O2 -W -std=c++11

default : $(OBJ)
	g++ $(OBJ) -o Tetris -lm -lpthread

tetrisMain.o : tetrisMain.cpp tetris.h
	g++ $(FLAG) tetrisMain.cpp -lpthread

tetrisMap.o : tetrisMap.cpp tetrisMap.h tetris.h
	g++ $(FLAG) tetrisMap.cpp -lpthread

tetrisPattern.o : tetrisPattern.cpp tetrisPattern.h tetris.h
	g++ $(FLAG) tetrisPattern.cpp -lpthread

tetrisRun.o : tetrisRun.cpp tetrisRun.h tetris.h
	g++ $(FLAG) tetrisRun.cpp -lpthread

archive.o : archive.cpp archive.h tetris.h
	g++ $(FLAG) archive.cpp -lpthread


run : $(OBJ)
	g++ $(OBJ) -o Tetris -lm -lpthread
	./Tetris

clean :
	rm *.o
	rm Tetris

