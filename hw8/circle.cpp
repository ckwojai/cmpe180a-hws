#include "circle.h"
#include <math.h>

Circle::Circle(const XYpoint& icenter, const double& iradius) {
  center = icenter;
  radius = iradius;
}

double Circle::area() {
  return radius * radius * M_PI;
}
