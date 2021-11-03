#include "rectangle.h"

Rectangle::Rectangle(const XYpoint& iv1, const XYpoint& iv2, const XYpoint& iv3, const XYpoint& iv4){
  v1 = iv1;
  v2 = iv2;
  v3 = iv3;
  v4 = iv4;
}

double Rectangle::area() {
  // assuming rectangle points are given in a counter-clockwise manner
  return (v1.x*v2.y + v2.x*v3.y + v3.x*v4.y + v4.x*v1.y - v1.x*v1.y - v3.x*v2.y - v4.x*v3.y - v1.x*v4.y) / 2;
}
