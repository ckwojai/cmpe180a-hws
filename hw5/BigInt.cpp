#include <iostream>
#include <algorithm>
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
istream& operator>>(istream& is, BigInt& dt) {
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
BigInt BigInt::operator+(const BigInt& r) {
  char ls = this->digits.at(0);
  char rs = r.digits.at(0);
  auto lit = this->digits.crbegin();
  auto rit = r.digits.crbegin();
  vector<char> result;
  if (ls=='+' and rs=='+') {
    int extra = 0;
    while (lit!=this->digits.crend()-1 && rit!=r.digits.crend()-1) {
      int ld = *lit - '0';
      int rd = *rit - '0';
      int sd = ld + rd + extra;
      if (sd >= 10) {
        extra = 1;
        result.push_back((sd-10) + '0');
      } else {
        result.push_back(sd + '0');
        extra = 0;
      }
      lit++;
      rit++;
    }
    if (lit == this->digits.crend()-1 && rit == r.digits.crend()-1) {
      if (extra==1) {
        result.push_back(extra + '0');
      }
    } else if (lit != this->digits.crend()-1) {
      while(lit != this->digits.crend()) {
        int ld = *lit - '0';
        int sd = ld + extra;
        if (sd >= 10) {
          extra = 1;
          result.push_back((sd-10) + '0');
        } else {
          result.push_back(sd + '0');
          extra = 0;
        }
        lit++;
      }
    } else {
      while(rit != r.digits.crend()-1) {
        int rd = *rit - '0';
        int sd = rd + extra;
        if (sd >= 10) {
          extra = 1;
          result.push_back((sd-10) + '0');
        } else {
          result.push_back(sd + '0');
          extra = 0;
        }
        rit++;
      }
    }
  }
  std::reverse(result.begin(), result.end());
  return BigInt(result);
}
    BigInt BigInt::operator-(const BigInt& r);
    BigInt BigInt::operator*(const BigInt& r);
    bool BigInt::operator!();
    bool BigInt::operator==(const BigInt& r);
    bool BigInt::operator>=(const BigInt& r);
    bool BigInt::operator>(const BigInt& r);
    bool BigInt::operator<=(const BigInt& r);
    bool BigInt::operator<(const BigInt& r);
    BigInt BigInt::operator++();
    BigInt BigInt::operator--();
    BigInt BigInt::operator++(int);
    BigInt BigInt::operator--(int);
