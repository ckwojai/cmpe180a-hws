#include <iostream>
#include "mergeStrings.h"

using std::cout;
using std::endl;

int main() {
  // string a = "13579";
  // string b = "2468d";
  string a = "ace";
  string b = "bdf";
  string c = mergeStrings(a, b);

  cout << "mergedString is: " << c;

  return 0;
}
