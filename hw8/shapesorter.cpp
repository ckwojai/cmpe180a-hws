#include <algorithm>
#include "shapesorter.h"

bool compareShape(Shape* s1, Shape* s2) {
  return s1->area() < s2->area();
}

void ShapeSorter(vector<Shape*>& shapes) {
  std::sort(shapes.begin(), shapes.end(), compareShape);
}
