#include "BigInt.h"

int main(){
  vector<int> test = {1, 2, 3};
  BigInt bi(test);
  std::cout << bi;
  vector<char> test2 = {'9'};
  BigInt bi2(test2);
  std::cout << bi2;
  BigInt sum = bi + bi2;
  std::cout << sum;
  return 0;
}
