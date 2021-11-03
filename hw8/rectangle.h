#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "shape.h"
#include "xypoint.h"


class Rectangle: public Shape {
  public:
    Rectangle(const XYpoint& iv1, const XYpoint& iv2, const XYpoint& iv3, const XYpoint& iv4);
    double area();
  private:
    XYpoint v1, v2, v3, v4;
};


#endif // RECTANGLE_H_
