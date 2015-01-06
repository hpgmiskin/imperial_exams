#makefile

FLAGS = -std=c++11 -Wall -g

words: main.o words.o
	g++ $(FLAGS) main.o words.o -o words

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp

words.o: words.cpp words.h
	g++ $(FLAGS) -c words.cpp

run:
	./words

clean:
	rm -f *.o
