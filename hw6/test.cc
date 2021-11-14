#include "BigInt.h"
void test(const vector<char>& lv, const vector<char>& rv) {
  BigInt l(lv);
  BigInt r(rv);
  std::cout << "l: " << l << "; r: " << r << std::endl;
  // std::cout << "++l = " << ++l << std::endl;
  // std::cout << "--r = " << --r << std::endl;
  std::cout << "l + r = " << l + r << std::endl;
  std::cout << "l - r = " << l - r << std::endl;
  std::cout << "r - l = " << r - l << std::endl;
  std::cout << "l * r = " << r * l << std::endl;
}

int main(){
  vector<char> lv = {'-', '1', '0'};
  vector<char> rv = {'-', '2', '2'};
  test(lv, rv);
  lv = {'+', '1', '0', '0', '0', '0', '0', '0'};
  rv = {'-', '9'};
  test(lv, rv);
  lv = {'+', '0', '0', '0', '9', '9', '9', '9'};
  rv = {'-', '9'};
  test(lv, rv);
  lv = {'+', '9', '9', '9', '9'};
  rv = {'+', '1', '2', '3', '4'};
  test(lv, rv);

  char ca[4] = {'-', '1'};
  int ia[3] = {1};
  BigInt la(ca, 2);
  BigInt ra(ia, 1);
  std::cout << ++la << std::endl;
  std::cout << --ra << std::endl;
  // std::cout << BigInt(lv) + BigInt(rv) << std::endl;
  BigInt bi;
  std::cin >> bi;
  std::cout << bi;
  return 0;
}
