OBJ = tetrisMain.o tetrisMap.o tetrisPattern.o tetrisRun.o
FLAG = -c -O2 -Wall -W

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



run : $(OBJ)
	g++ $(OBJ) -o Tetris -lm
	./Tetris

clean :
	rm *.o
	rm Tetris

