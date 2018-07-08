CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -Werror -Wshadow


all: main.x program1.x tester.x

program1.x: program1.o compare-arrays.o
	$(CC) program1.o compare-arrays.o -o program1.x

tester.x: tester.o fill-array.o incr-array.o sum-array.o
	$(CC) tester.o fill-array.o incr-array.o \
	 	  sum-array.o -o tester.x

main.x：main.o fill-array.o compare-arrays.o
	$(CC) main.o fill-array.o compare-arrays.o \
		  -o main.x

main.o: main.c fill-array.h compare-arrays.h
	$(CC) $(CFLAGS) -c main.c

program1.o: program1.c compare-arrays.h
	$(CC) $(CFLAGS) -c program1.c

tester.o: tester.c fill-array.h incr-array.h sum-array.h
	$(CC) $(CFLAGS) -c tester.c

fill-array.o: fill-array.c fill-array.h
	$(CC) $(CFLAGS) -c fill-array.c

incr-array.o: incr-array.c incr-array.h
	$(CC) $(CFLAGS) -c incr-array.c

compare-arrays.o: compare-arrays.c compare-arrays.h
	$(CC) $(CFLAGS) -c compare-arrays.c

sum-array.o: sum-array.c sum-array.h
	$(CC) $(CFLAGS) -c sum-array.c

clean:
         rm -f *.x *.o