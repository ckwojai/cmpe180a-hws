#include <cmath>
#include "triangle.h"

Triangle::Triangle(const XYpoint& iv1, const XYpoint& iv2, const XYpoint& iv3) {
  v1 = iv1;
  v2 = iv2;
  v3 = iv3;
}

double Triangle::area() {
  return std::abs((v1.x*(v2.y-v3.y)+v2.x*(v3.y-v1.y)+v3.x*(v1.y-v2.y))/2);
}
