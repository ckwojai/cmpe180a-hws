#include "BigInt.h"
void test(const vector<char>& lv, const vector<char>& rv) {
  BigInt l(lv);
  BigInt r(rv);
  std::cout << "l: " << l << "; r: " << r << std::endl;
  std::cout << "l + r = " << l + r << std::endl;
  std::cout << "l - r = " << l - r << std::endl;
  std::cout << "r - l = " << r - l << std::endl;
}

int main(){
  vector<char> lv = {'-', '1', '2', '3'};
  vector<char> rv = {'-', '9'};
  test(lv, rv);
  lv = {'+', '1', '0', '0', '0', '0', '0', '0'};
  rv = {'-', '9'};
  test(lv, rv);
  lv = {'+', '0', '0', '0', '9', '9', '9', '9'};
  rv = {'-', '9'};
  test(lv, rv);

  char ca[4] = {'-', '1', '2', '3'};
  int ia[3] = {1, 2, 3};
  BigInt la(ca, 4);
  BigInt ra(ia, 3);
  // std::cout << la + ra << std::endl;
  // std::cout << BigInt(lv) + BigInt(rv) << std::endl;
  return 0;
}
