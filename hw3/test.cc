#include <iostream>
#include "mergeStrings.h"

using std::cout;
using std::endl;


int main() {
  string a = "ace";
  string b = "bdf";
  string c = mergeStrings(a, b);

  cout << "a is: " << a << endl;
  cout << "b is: " << b << endl;
  cout << "mergedString is: " << c << endl << endl;

  a = "13579";
  b = "2468";
  c = mergeStrings(a, b);
  cout << "a is: " << a << endl;
  cout << "b is: " << b << endl;
  cout << "mergedString is: " << c << endl << endl;

  a = "9753";
  b = "86421";
  c = mergeStrings(a, b);

  cout << "a is: " << a << endl;
  cout << "b is: " << b << endl;
  cout << "mergedString is: " << c << endl << endl;

  return 0;
}
