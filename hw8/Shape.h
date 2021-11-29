#ifndef SHAPE_H_
#define SHAPE_H_

#include "XYPoint.h"


class Shape {
  public:
    virtual double area() = 0;
};

class Circle: public Shape {
  public:
    Circle(const XYpoint& icenter, const double& iradius);
    double area();
  private:
    XYpoint center;
    double radius;
};

class Triangle:public Shape {
  public:
    Triangle(const XYpoint& iv1, const XYpoint& iv2, const XYpoint& iv3);
    double area();
  private:
    XYpoint v1, v2, v3;
};

class Rectangle: public Shape {
  public:
    Rectangle(const XYpoint& iv1, const XYpoint& iv2, const XYpoint& iv3, const XYpoint& iv4);
    double area();
  private:
    XYpoint v1, v2, v3, v4;
};

#endif // SHAPE_H_
