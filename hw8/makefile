CC = g++
CFLAGS = -Wall -g


test: test.o circle.o triangle.o rectangle.o shapesorter.o
	$(CC) $(CFLAGS) -o test.out test.o circle.o rectangle.o triangle.o shapesorter.o

clean:
	-rm *.o $(objects) *.out

test.o: test.cc shape.h xypoint.h circle.h triangle.h rectangle.h shapesorter.h
	$(CC) $(CFLAGS) -c test.cc

circle.o: circle.cpp shape.h xypoint.h
	$(CC) $(CFLAGS) -c circle.cpp

triangle.o: triangle.cpp shape.h xypoint.h
	$(CC) $(CFLAGS) -c triangle.cpp

rectangle.o: rectangle.cpp shape.h xypoint.h
	$(CC) $(CFLAGS) -c rectangle.cpp

shapesorter.o: shapesorter.cpp shape.h
	$(CC) $(CFLAGS) -c shapesorter.cpp
