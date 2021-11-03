#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "xypoint.h"
#include "shape.h"


class Circle: public Shape {
  public:
    Circle(const XYpoint& icenter, const double& iradius);
    double area();
  private:
    XYpoint center;
    double radius;
};


#endif // CIRCLE_H_
