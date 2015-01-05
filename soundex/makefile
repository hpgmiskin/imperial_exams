#makefile

FLAGS = -Wall -g -std=c++11

soundex: main.o soundex.o
	g++ $(FLAGS) main.o soundex.o -o soundex

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp

soundex.o: soundex.h soundex.cpp
	g++ $(FLAGS) -c soundex.cpp

run:
	./soundex

clean:
	rm -f *.o
