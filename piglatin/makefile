#makefile

FLAGS = -std=c++11 -Wall -g

piglatin: piglatin.o main.o
	g++ $(FLAGS) piglatin.o main.o -o piglatin

piglatin.o: piglatin.cpp piglatin.h
main.o: main.cpp

%.o: %.cpp
	g++ $(FLAGS) -c $<

run:
	./piglatin

clean:
	rm -f *.o piglatin

