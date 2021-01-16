GCC = gcc -Wall -g
all: frequency
frequency: main.o node.o
	$(GCC) -o frequency main.o node.o
main.o: main.c node.h
	$(GCC) -c main.c
node.o: node.c node.h
	$(GCC) -c node.c

clean:
	rm frequency *.o

.PHONY: clean all frequency