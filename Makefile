# Makefile for lab2
# Compiler:
CC=gcc

# compiler options:
CFLAGS=-c -Wextra

all: lab2

lab2: list.o main.o node.o
	$(CC) list.c main.c node.c -o lab2

main: main.o
	$(CC) $(CFLAGS) main.c

list: list.o
	$(CC) $(CFLAGS) list.c

node: node.o
	$(CC) $(CFLAGS) node.c

clean:
	rm -rf *.o *.gch lab2
