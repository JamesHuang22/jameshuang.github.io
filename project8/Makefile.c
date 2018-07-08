CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -Werror -Wshadow -g -D ENABLE_VALGRIND

all: public01.x public02.x public03.x public04.x public05.x \
	 public06.x public07.x public08.x public09.x public10.x

public01.x: public01.o graph.o compare-name-lists.o
	$(CC) public01.o graph.o compare-name-lists.o -o public01.x
public02.x: public02.o graph.o memory-checking.o
	$(CC) public02.o graph.o memory-checking.o -o public02.x
public03.x: public03.o graph.o compare-name-lists.o memory-checking.o
	$(CC) public03.o graph.o compare-name-lists.o memory-checking.o -o public03.x
public04.x: public04.o graph.o memory-checking.o
	$(CC) public04.o graph.o memory-checking.o -o public04.x
public05.x: public05.o graph.o memory-checking.o
	$(CC) public05.o graph.o memory-checking.o -o public05.x
public06.x: public06.o graph.o compare-name-lists.o
	$(CC) public06.o graph.o compare-name-lists.o -o public06.x
public07.x: public07.o graph.o compare-name-lists.o
	$(CC) public07.o graph.o compare-name-lists.o -o public07.x
public08.x: public08.o graph.o 
	$(CC) public08.o graph.o -o public08.x
public09.x: public09.o graph.o compare-name-lists.o 
	$(CC) public09.o graph.o compare-name-lists.o -o public09.x
public10.x: public10.o graph.o compare-name-lists.o memory-checking.o
	$(CC) public10.o graph.o compare-name-lists.o memory-checking.o -o public10.x

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c
compare-name-lists.o: compare-name-lists.c compare-name-lists.h
	$(CC) $(CFLAGS) -c compare-name-lists.c

public01.o: public01.c graph.h compare-name-lists.h
	$(CC) $(CFLAGS) -c public01.c
public02.o: public02.c graph.h memory-checking.h
	$(CC) $(CFLAGS) -c public02.c
public03.o: public03.c graph.h compare-name-lists.h memory-checking.h
	$(CC) $(CFLAGS) -c public03.c
public04.o: public04.c graph.h memory-checking.h
	$(CC) $(CFLAGS) -c public04.c
public05.o: public05.c graph.h memory-checking.h
	$(CC) $(CFLAGS) -c public05.c
public06.o: public06.c graph.h compare-name-lists.h
	$(CC) $(CFLAGS) -c public06.c
public07.o: public07.c graph.h compare-name-lists.h
	$(CC) $(CFLAGS) -c public07.c
public08.o: public08.c graph.h
	$(CC) $(CFLAGS) -c public08.c
public09.o: public09.c graph.h compare-name-lists.h
	$(CC) $(CFLAGS) -c public09.c
public10.o: public10.c graph.h compare-name-lists.h memory-checking.h
	$(CC) $(CFLAGS) -c public10.c

clean:
	rm -f *.x public01.o public02.o public03.o public04.o public05.o \
	public06.o public07.o public08.o public09.o public10.o graph.o
