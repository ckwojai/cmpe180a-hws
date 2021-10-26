CC = g++
CFLAGS = -Wall -g


test: test.o mergeVectors.o
	$(CC) $(CFLAGS) -o test.out test.o mergeVectors.o

clean:
	-rm *.o $(objects) *.out

test.o: test.cc mergeVectors.h
	$(CC) $(CFLAGS) -c test.cc

mergeVectors.o: mergeVectors.h mergeVectors.cpp
	$(CC) $(CFLAGS) -c mergeVectors.cpp
