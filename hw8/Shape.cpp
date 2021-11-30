#include <cmath>
#include <math.h>

#include "Shape.h"

Circle::Circle(const XYPoint& icenter, const double& iradius) {
  center = icenter;
  radius = iradius;
}

double Circle::area() {
  return radius * radius * M_PI;
}

Triangle::Triangle(const XYPoint& iv1, const XYPoint& iv2, const XYPoint& iv3) {
  v1 = iv1;
  v2 = iv2;
  v3 = iv3;
}

double Triangle::area() {
  return std::abs((v1.x*(v2.y-v3.y)+v2.x*(v3.y-v1.y)+v3.x*(v1.y-v2.y))/2);
}

Rectangle::Rectangle(const XYPoint& iv1, const XYPoint& iv2, const XYPoint& iv3, const XYPoint& iv4){
  v1 = iv1;
  v2 = iv2;
  v3 = iv3;
  v4 = iv4;
}

double Rectangle::area() {
  // assuming rectangle points are given in a counter-clockwise manner
  return std::abs(v1.x*v2.y + v2.x*v3.y + v3.x*v4.y + v4.x*v1.y - v1.x*v1.y - v3.x*v2.y - v4.x*v3.y - v1.x*v4.y) / 2;
}
