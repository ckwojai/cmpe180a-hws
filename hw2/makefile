CC = g++
CFLAGS = -Wall -g
 

all: hw2.o countHits.o
	$(CC) $(CFLAGS) -o main hw2.o countHits.o

clean:
	-rm *.o $(objects) main 
 
 
hw2.o: hw2.cpp asteroid.h countHits.h
	$(CC) $(CFLAGS) -c hw2.cpp
 
countHits.o: countHits.h asteroid.h
	$(CC) $(CFLAGS) -c countHits.cpp

