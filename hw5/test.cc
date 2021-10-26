#include "BigInt.h"

int main(){
  vector<int> test = {-1, -2, 3, 4};
  BigInt bi(test);
  std::cout << bi;
  return 0;
}
