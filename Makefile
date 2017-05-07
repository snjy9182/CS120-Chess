CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -g

main: Main.o Chess.o Board.o
	$(CXX) $(CXXFLAGS) Chess.o Board.o Main.o -o main

Board.o: Game.h
Chess.o: Game.h Chess.h Prompts.h Terminal.h
Main.o: Game.h Chess.h Prompts.h Main.cpp


clean:
	rm *.o chess

