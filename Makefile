OBJ = tetrisMain.o tetrisMap.o tetrisPattern.o tetrisRun.o archive.o
FLAG = -c -O2 -W -std=c++11

default : $(OBJ)
	g++ $(OBJ) -o Tetris -lm -lpthread

tetrisMain.o : src/tetrisMain.cpp header/tetris.h
	g++ $(FLAG) src/tetrisMain.cpp -lpthread

tetrisMap.o : src/tetrisMap.cpp header/tetrisMap.h header/tetris.h
	g++ $(FLAG) src/tetrisMap.cpp -lpthread

tetrisPattern.o : src/tetrisPattern.cpp header/tetrisPattern.h header/tetris.h
	g++ $(FLAG) src/tetrisPattern.cpp -lpthread

tetrisRun.o : src/tetrisRun.cpp header/tetrisRun.h header/tetris.h
	g++ $(FLAG) src/tetrisRun.cpp -lpthread

archive.o : src/archive.cpp header/archive.h header/tetris.h
	g++ $(FLAG) src/archive.cpp -lpthread


run : $(OBJ)
	g++ $(OBJ) -o Tetris -lm -lpthread
	./Tetris

clean :
	rm *.o
	rm Tetris

