TARGET = cadex.exe
CXX    = g++
DEBUG  = -g
OPT    = -O2
WARN   = -Wall

CXXFLAGS = $(DEBUG) $(OPT) $(WARN) -std=c++17

LD   = g++
OBJS = main.o  

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(CXXFLAGS) 

main.o:	main.cpp
	$(CXX) -c $(CXXFLAGS) main.cpp -o main.o 


clean:
	rm -rf *.o 