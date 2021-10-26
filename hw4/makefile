CC = g++
CFLAGS = -Wall -g


test: test.o mergeVectors.o
	$(CC) $(CFLAGS) -o test.out test.o mergeStrings.o

clean:
	-rm *.o $(objects) *.out

test.o: test.cc mergeVectors.h
	$(CC) $(CFLAGS) -c test.cc

mergeStrings.o: mergeVectors.h mergeVectors.cpp
	$(CC) $(CFLAGS) -c mergeVectors.cpp
