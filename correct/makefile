#makefile

FLAGS = -std=c++11 -Wall -g

correct: main.o correct.o
	g++ $(FLAGS) main.o correct.o -o correct

main.o: main.cpp correct.h
correct.o: correct.cpp correct.h

$.o: $.cpp
	g++ $(FLAGS) -c $<

run:
	./correct

clean:
	rm -f *.o correct
