CC = g++
CFLAGS = -Wall -g


test: test.o mergeStrings.o
	$(CC) $(CFLAGS) -o test.out test.o mergeStrings.o

clean:
	-rm *.o $(objects) *.out

test.o: test.cc mergeStrings.h
	$(CC) $(CFLAGS) -c test.cc

mergeStrings.o: mergeStrings.h mergeStrings.cpp
	$(CC) $(CFLAGS) -c mergeStrings.cpp
