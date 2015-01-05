#makefile

all: substring run

FLAGS = -std=c++11 -Wall -g

substring: main.o substring.o
	g++ $(FLAGS) main.o substring.o -o substring

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp

substring.o: substring.h substring.cpp
	g++ $(FLAGS) -c substring.cpp

run:
	./substring

clean:
	rm -f *.o
