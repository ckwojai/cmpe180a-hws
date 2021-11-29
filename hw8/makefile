CC = g++
CFLAGS = -Wall -g


test: test.o shape.o shapesorter.o
	$(CC) $(CFLAGS) -o test.out test.o shape.o shapesorter.o

clean:
	-rm *.o $(objects) *.out

test.o: test.cc shape.h xypoint.h shapesorter.h
	$(CC) $(CFLAGS) -c test.cc

shape.o: shape.h xypoint.h
	$(CC) $(CFLAGS) -c shape.cpp

shapesorter.o: shapesorter.cpp shape.h
	$(CC) $(CFLAGS) -c shapesorter.cpp
