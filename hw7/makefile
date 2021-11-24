CC = g++
CFLAGS = -Wall -g


test: test.o CircularLinkedList.o
	$(CC) $(CFLAGS) -o test.out test.o CircularLinkedList.o

clean:
	-rm *.o $(objects) *.out

test.o: test.cc CircularLinkedList.h
	$(CC) $(CFLAGS) -c test.cc

CircularLinkedList.o: CircularLinkedList.h CircularLinkedList.cpp
	$(CC) $(CFLAGS) -c CircularLinkedList.cpp
