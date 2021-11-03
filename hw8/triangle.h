#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "shape.h"
#include "xypoint.h"


class Triangle:public Shape {
  public:
    Triangle(const XYpoint& iv1, const XYpoint& iv2, const XYpoint& iv3);
    double area();
  private:
    XYpoint v1, v2, v3;
};


#endif // TRIANGLE_H_
