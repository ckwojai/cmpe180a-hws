CC = g++
CFLAGS = -Wall -g


test: test.o BigInt.o
	$(CC) $(CFLAGS) -o test.out test.o BigInt.o

clean:
	-rm *.o $(objects) *.out

test.o: test.cc BigInt.h
	$(CC) $(CFLAGS) -c test.cc

BigInt.o: BigInt.h BigInt.cpp
	$(CC) $(CFLAGS) -c BigInt.cpp
