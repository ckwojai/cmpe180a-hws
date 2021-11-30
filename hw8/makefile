CC = g++
CFLAGS = -Wall -g


test: test.o shape.o shapesorter.o
	$(CC) $(CFLAGS) -o test.out test.o shape.o shapesorter.o

clean:
	-rm *.o $(objects) *.out

test.o: test.cc Shape.h XYPoint.h ShapeSorter.h
	$(CC) $(CFLAGS) -c test.cc

shape.o: Shape.h Shape.cpp XYPoint.h
	$(CC) $(CFLAGS) -c Shape.cpp -o shape.o

shapesorter.o: ShapeSorter.cpp Shape.h
	$(CC) $(CFLAGS) -c ShapeSorter.cpp -o shapesorter.o

xypoint.o: XYPoint.h XYPoint.cpp
	$(CC) $(CFLAGS) -c XYPoint.cpp -o xypoint.o
