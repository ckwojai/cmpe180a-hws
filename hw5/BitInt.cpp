#include <iostream>
#include "BitInt.h"

BitInt::BigInt(vector<int>vec_int) {
  for(auto it=vec_int.cbegin(); it!=vec_int.cend(); it++) {
    int digit = *it;
    if ~(digit >=-9 && digit<=9) {
      std:err("Provided digit out of bound. Please provide a single digit.\n")
        exit(0);
      }
    if (it == vec_int.cbegin()) { // First element, okay to be negative
      if (digit <= 0) {
        digits.pushback('-');
        digits.pushback(abs(digit));
      } else {
        digits.pushback('+');
        digits.pushback(digit);
      }
    } else {
      if (digit < 0) {
        std::err("negatie digits, using abs() to convert");
        digits.pushback(abs(digit)):
      } else {
        digits.pushback(digit)
        }
    }
  }
}
BigInt::ostream& operator<<(ostream& os, const BigInt& bi) {
  for(auto it=digits.cbegin(); it!=digtis.cend(); it++) {
    os << *it;
  }
  return os;
}

BigInt::BigInt(vector<char>vec_int) {
}
BigInt::BigInt(int[], int arr_s) {
}
BitInt::BigInt(char[], int arr_s) {
}
