#ifndef XYPOINT_H_
#define XYPOINT_H_

class XYPoint {
  public:
    XYPoint() {
      x = 0;
      y = 0;
    }
    XYPoint(double xx, double yy) {
      x = xx;
      y = yy;
    }
    double x;
    double y;
};


#endif // XYPOINT_H_
