OBJ = tetrisMain.o
FLAG = -c -O2 -Wall

default : $(OBJ)
	g++ $(OBJ) -o Tetris -lm



tetrisMain.o : tetrisMain.cpp
	g++ $(FLAG) tetrisMain.cpp



run : $(OBJ)
	g++ $(OBJ) -o Tetris -lm
	./Tetris.exe

clean :
	rm *.o
	rm *.exe

