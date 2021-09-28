#include <string>

using std::string;

string mergeStrings(const string &a, const string &b) {
  string c = "";
  int len_a = a.length();
  int len_b = b.length();
  if (len_a == len_b) {
    for (int i=0; i < len_a; i++) {
      c += a[i] + b[i];
    }
  } else if (len_a > len_b) {
    for (int i=0; i < len_b; i++) {
      c += a[i] + b[i];
    }
    c += a.substr(len_b, len_a-len_b);
  } else if (len_a < len_b) {
    for (int i=0; i < len_a; i++) {
      c += a[i] + b[i];
    }
    c += b.substr(len_a, len_b-len_a);
  }
  return c;
}
