#include <iostream>
#include <math.h>

#include "XYPoint.h"
#include "Shape.h"
#include "ShapeSorter.h"

using namespace std;


const int points_per_test = 10;

void testArea(const string &test_name, Shape *s,
                   double expected_area, double points_for_this_test,
                   int &total_grade) {
    if (round(s->area()) == round(expected_area)) {
        total_grade += points_for_this_test;
        cout << test_name + " succeeded! +" << points_for_this_test << endl;
    } else {
        cout << test_name + " failed!" << endl;
    }
}

void testShapeSorter(const string &test_name, vector<Shape*> test_shapes_vector,
                   vector<Shape*> expected_shapes_vector, int points_for_this_test,
                   int &total_grade) {
    if (test_shapes_vector.size() != expected_shapes_vector.size()){
        cout << test_name + " failed!" << endl;
        return;
    }

    bool result = equal(test_shapes_vector.begin(), test_shapes_vector.end(), expected_shapes_vector.begin());
    if (result){
        total_grade += points_for_this_test;
        cout << test_name + " succeeded! +" << points_for_this_test << endl;
    }
    else{
       cout << test_name + " failed!" << endl;
    }
}

int main() {

    int total_grade = 0;

    string test1("Test1");
    XYPoint p1(-2,4);
    XYPoint p2(-2, 12);
    XYPoint p3(4, 12);
    XYPoint p4(4,4);

    Shape *shape1;
    Shape *shape2;
    Shape *shape3;

    vector<Shape*> shapes1;

    Rectangle rec1(p1, p2, p3, p4);
    Triangle tri1(p2, p3, p4);
    Circle cir1(p1, 3);

    shape1 = &rec1;
    shape2 = &tri1;
    shape3 = &cir1;

    testArea("Test Rectangle Area", shape1, 48, points_per_test, total_grade);
    testArea("Test Triangle Area", shape2, 24, points_per_test, total_grade);
    testArea("Test Circle Area", shape3, 28, points_per_test, total_grade);

    shapes1.push_back(shape1);
    shapes1.push_back(shape2);
    shapes1.push_back(shape3);
    ShapeSorter(shapes1);

    vector<Shape*> result1;
    result1.push_back(shape2);
    result1.push_back(shape3);
    result1.push_back(shape1);

    testShapeSorter("Test Shape Sorter", shapes1, result1, points_per_test, total_grade);
    cout << "TOTAL GRADE=" << total_grade << endl;
}
