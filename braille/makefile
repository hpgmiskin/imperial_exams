#makefile

FLAGS = -Wall -g

braille: main.o braille.o
	g++ $(FLAGS) main.o braille.o -o braille

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp

braille.o: braille.cpp braille.h
	g++ $(FLAGS) -c braille.cpp

run:
	./braille

clean:
	rm -f *.o
