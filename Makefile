
CC = gcc
CFLAGS = -Wall

system: mainFunction.o system.o
mainFunction.o: mainFunction.c mainFunction.h
system.o: system.c mainFunction.h

clean:
	rm *.o system
