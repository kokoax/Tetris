CXX		 	 = g++
OBJECTS	 = tetrisMain.o tetrisMap.o tetrisPattern.o tetrisRun.o archive.o
CXXFLAGS = -c -O2 -W -std=c++11
LDFLAGS	 = -lm -lpthread
TARGET   = Tetris

default : $(OBJECTS)
	$(CXX) -o $(TARGET) $^ $(LDFLAGS)

%.o : src/%.cpp
	$(CXX) $(CXXFLAGS) $< $(LDFLAGS)

run : $(OBJECTS)
	$(CXX) -o $(TARGET) $^  $(LDFLAGS)
	./$(TARGET)

clean :
	$(RM) *.o
	$(RM) $(TARGET)

