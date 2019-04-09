CC=gcc
CFLAGS=-I.
DEPS =  MovieTree.h MovieStack.h Database.h Control.h Interface201.h 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

CS201: MovieTree.o MovieStack.o Database.o Control.o Interface201.o main.o
	$(CC) -o hellomake MovieTree.o MovieStack.o Database.o Control.o Interface201.o main.o
