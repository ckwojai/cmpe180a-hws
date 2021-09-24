#include <iostream>
#include <vector>
#include "asteroid.h"
#include "countHits.h"

using std::vector;
using std::cout;
using std::endl;

int main() {
  Asteroid a1 = {10, right};
  Asteroid a2 = {11, left};
  Asteroid a3 = {11, right};
  Asteroid a4 = {5, left};
  vector<Asteroid> test_a{a1, a2, a3, a4};
  Asteroid b1 = {10, right};
  Asteroid b2 = {11, right};
  Asteroid b3 = {11, right};
  vector<Asteroid> test_b{b1, b2, b3};
  int hits_a = countHits(test_a);
  int hits_b = countHits(test_b);
  cout << hits_a << endl;
  cout << hits_b << endl;
  return 0;
}
