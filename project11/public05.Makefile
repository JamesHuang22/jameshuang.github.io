CC= gcc
CFLAGS= -g -ansi -pedantic-errors -Wall -Werror -Wshadow

public05-testprogram.x: public05-testprogram.o
	$(CC) public05-testprogram.o -o public05-testprogram.x

public05-testprogram.o: public05-testprogram.c
	$(CC) $(CFLAGS) -c public05-testprogram.c
