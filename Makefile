CXXFLAGS = -g3 -gdwarf-2
CCFLAGS = -g3 -gdwarf-2

ifeq ($(OS),Windows_NT)
	CC = wg++
	CCFLAGS += -D WIN32
	RM = del
	EXEC = a.exe
else
	RM = rm
	CXXFLAGS += -std=c++11 -fno-elide-constructors
	CCFLAGS += -std=c++11 -fno-elide-constructors
	EXEC = prog
endif

all: executable

debug: CXXFLAGS += -DDEBUG -g
debug: CCFLAGS += -DDEBUG -g
debug: executable

executable: main.o function.o
	$(CXX) $(CXXFLAGS) -o $(EXEC) main.o function.o
main.o: main.cpp
	$(CC) $(CCFLAGS) -c main.cpp
function.o: function.cpp
	$(CC) $(CCFLAGS) -c function.cpp

remake: clean all

clean:
	$(RM) $(EXEC) main.o function.o