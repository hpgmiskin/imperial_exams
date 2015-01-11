#make file

FLAGS = -std=c++11 -Wall -g

all: sonnet run

sonnet: sonnet.o main.o
	g++ $(FLAGS) sonnet.o main.o -o sonnet

main.o: main.cpp sonnet.h
sonnet.o: sonnet.cpp sonnet.h

%.o: %.cpp
	g++ $(FLAGS) -c $<

run:
	./sonnet

clean:
	rm -f *.o sonnet
