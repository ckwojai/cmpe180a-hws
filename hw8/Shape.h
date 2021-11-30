#ifndef SHAPE_H_
#define SHAPE_H_

#include "XYPoint.h"


class Shape {
  public:
    virtual double area() = 0;
};

class Circle: public Shape {
  public:
    Circle(const XYPoint& icenter, const double& iradius);
    double area();
  private:
    XYPoint center;
    double radius;
};

class Triangle:public Shape {
  public:
    Triangle(const XYPoint& iv1, const XYPoint& iv2, const XYPoint& iv3);
    double area();
  private:
    XYPoint v1, v2, v3;
};

class Rectangle: public Shape {
  public:
    Rectangle(const XYPoint& iv1, const XYPoint& iv2, const XYPoint& iv3, const XYPoint& iv4);
    double area();
  private:
    XYPoint v1, v2, v3, v4;
};

#endif // SHAPE_H_
