#Makefile

FLAGS = -std=c++11 -g -Wall

shrink: main.o shrink.o
	g++ $(FLAGS) main.o shrink.o -o shrink

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp

shrink.o: shrink.h shrink.cpp
	g++ $(FLAGS) -c shrink.cpp 

run:
	./shrink

clean:
	rm -f *.o
