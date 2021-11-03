#include <vector>
#include <iostream>
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include "shapesorter.h"
#include "xypoint.h"

using std::vector;
using std::cout;
using std::endl;

int main(){
  XYpoint cp = {0,0};
  Circle cir(cp, 4);

  XYpoint tp1 = {0,0};
  XYpoint tp2 = {4,0};
  XYpoint tp3 = {2,4};
  Triangle tri(tp1, tp2, tp3);

  XYpoint rp1 = {0,0};
  XYpoint rp2 = {4,0};
  XYpoint rp3 = {4,4};
  XYpoint rp4 = {0,4};
  Rectangle rect(rp1, rp2, rp3, rp4);

  cout << cir.area() << ", " << tri.area() << ", " << rect.area() << endl;

  return 0;
}
