#include "BigInt.h"

int main(){
  vector<int> test = {-1, -2, 3, 4};
  BigInt bi(test);
  std::cout << bi;
  vector<char> test2 = {'-', '9', '8', '7', '6'};
  BigInt bi2(test2);
  std::cout << bi2;
  return 0;
}
