#include <iostream>
#include "BigInt.h"

void BigInt::init(const vector<int>& vec_int) {
  for(auto it=vec_int.cbegin(); it!=vec_int.cend(); it++) {
    int digit = *it;
    if (!(digit >=-9 && digit<=9)) {
      std::cerr << "Provided digit out of bound. Please provide a single digit.\n";
        exit(0);
      }
    if (it == vec_int.cbegin()) { // First element, okay to be negative
      if (digit <= 0) {
        digits.push_back('-');
        digits.push_back('0' + abs(digit));
      } else {
        digits.push_back('+');
        digits.push_back('0' + digit);
      }
    } else {
      if (digit < 0) {
        std::cerr<<"negative digits, using abs() to convert\n";
        digits.push_back('0' + abs(digit));
      } else {
        digits.push_back('0' + digit);
        }
    }
  }
}

BigInt::BigInt(const vector<int>& vec_int) {
  init(vec_int);
}
ostream& operator<<(ostream& os, const BigInt& bi) {
  for(auto it=bi.digits.cbegin(); it!=bi.digits.cend(); it++) {
    os << *it;
  }
  os << std::endl;
  return os;
}

BigInt::BigInt(const vector<char>& vec_char) {
  vector<int> vec_int;
  bool isNegative = false;
  for(auto it=vec_char.cbegin(); it!=vec_char.cend(); it++) {
    if (it==vec_char.cbegin()) {
      if (*it == '-') {
	isNegative = true;
      } else {
        vec_int.push_back(*it-'0');
      }
    } else if (it==vec_char.cbegin()+1) {
      if (isNegative) {
	int num = -(*it-'0');
	vec_int.push_back(num);
      } else {
        vec_int.push_back(*it-'0');
      }
    } else {
      vec_int.push_back(*it-'0');
    }
  }
  init(vec_int);
}
BigInt::BigInt(int[], int arr_s) {
}
BigInt::BigInt(char[], int arr_s) {
}
