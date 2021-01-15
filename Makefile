CC=gcc

FLAGS= -Wall -g

all: frequency
frequency: main.o node.o
	$(CC) $(FLAGS) -o frequency main.o node.o
main.o: main.c node.h
	$(CC) $(FLAGS) -c main.c
node.o: node.c node.h
	$(CC) $(FLAGS) -c node.c

clean:
	rm frequency

.PHONY: clean all frequency