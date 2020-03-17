tictactoe: main.o minimax.o player.o board.o
	g++ -o tictactoe main.o minimax.o player.o board.o

main.o : main.cpp
	g++ -o main.o -c main.cpp

minimax.o : minimax.cpp minimax.h
	g++ -o minimax.o -c minimax.cpp

player.o : playerFunctions.cpp playerFunctions.h
	g++ -o player.o -c playerFunctions.cpp

board.o : board.cpp board.h
	g++ -o board.o -c board.cpp

clean :
	rm *.o
	rm tictactoe
