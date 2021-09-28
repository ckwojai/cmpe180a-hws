CC = g++
CFLAGS = -Wall -g
 

all: hw2.o countHits.o
	$(CC) $(CFLAGS) -o main.out hw2.o countHits.o

test: test.o countHits.o
	$(CC) $(CFLAGS) -o test.out test.o countHits.o

clean:
	-rm *.o $(objects) *.out

test.o: test.cc asteroid.h countHits.h
	$(CC) $(CFLAGS) -c test.cc
 
hw2.o: hw2.cpp asteroid.h countHits.h
	$(CC) $(CFLAGS) -c hw2.cpp
 
countHits.o: countHits.h countHits.cpp asteroid.h
	$(CC) $(CFLAGS) -c countHits.cpp

