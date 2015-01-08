#makefile

FLAGS = -std=c++11 -g -Wall 

maze: main.o maze.o
	g++ $(FLAGS) main.o maze.o -o maze

main.o: main.cpp maze.h
maze.o: maze.cpp maze.h

%.o: %.cpp
	g++ $(FLAGS) -c $<

run:
	./maze

clean:
	rm *.o maze
