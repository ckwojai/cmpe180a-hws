#include <iostream>
#include <algorithm>
#include <cmath>
#include "BigInt.h"


void BigInt::init(const vector<int>& vec_int) {
  for(auto it=vec_int.cbegin(); it!=vec_int.cend(); it++) {
    int digit = *it;
    if (!(digit >=-9 && digit<=9)) {
      std::cerr << "Provided digit out of bound. Please provide a single digit.\n";
        exit(0);
      }
    if (it == vec_int.cbegin()) { // First element, okay to be negative
      if (digit < 0) {
        digits.push_back('-');
        digits.push_back('0' + std::abs(digit));
      } else {
        digits.push_back('+');
        digits.push_back('0' + digit);
      }
    } else {
      if (digit < 0) {
        std::cerr<<"negative digits, using abs() to convert\n";
        digits.push_back('0' + std::abs(digit));
      } else {
        digits.push_back('0' + digit);
        }
    }
  }
}

BigInt::BigInt(const vector<int>& vec_int) {
  init(vec_int);
}

BigInt::BigInt(const vector<char>& vec_char) {
  vector<int> vec_int;
  bool isNegative = false;
  for(auto it=vec_char.cbegin(); it!=vec_char.cend(); it++) {
    if (it==vec_char.cbegin()) {
      if (*it == '-') {
	isNegative = true;
      } else if (*it == '+') {
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
ostream& operator<<(ostream& os, const BigInt& bi) {
  for(auto it=bi.digits.cbegin(); it!=bi.digits.cend(); it++) {
    os << *it;
  }
  return os;
}
istream& operator>>(istream& is, BigInt& dt) {
  return is;
}

BigInt::BigInt(int[], int arr_s) {
}
BigInt::BigInt(char[], int arr_s) {
}
BigInt BigInt::abs() const {
  vector<char> tmp = this->digits;
  tmp.at(0) = '+'; // make it positive
  BigInt abs_bi(tmp);
  return abs_bi;
}

BigInt BigInt::neg() const {
  vector<char> tmp = this->digits;
  tmp.at(0) = '-'; // make it positive
  BigInt neg_bi(tmp);
  return neg_bi;
}

BigInt BigInt::operator+(const BigInt& r) const {
  char ls = this->digits.at(0);
  char rs = r.digits.at(0);
  auto lit = this->digits.crbegin();
  auto rit = r.digits.crbegin();
  vector<char> result;
  if ((ls=='+' && rs=='+') || (ls=='-' && rs=='-')) {
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
    }
    while(lit != this->digits.crend()-1) {
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
    result.push_back(ls); // (-a+-b)=-(a+b)
    std::reverse(result.begin(), result.end());
    return BigInt(result);
  } else if (ls=='+' && rs=='-') { // pos1 + neg2, which is the same as pos1 - abs(neg2)
    return (*this - r.abs());
  } else if (ls=='-' && rs=='+') { // neg1 + pos2, which is the same as pos2 - abs(neg1)
    return (this->abs() - r);
  }
}

BigInt BigInt::operator-(const BigInt& r) const {
  char ls = this->digits.at(0);
  char rs = r.digits.at(0);
  auto lit = this->digits.crbegin();
  auto rit = r.digits.crbegin();
  vector<char> result;
  if (ls=='+' && rs=='+') {
    if (*this > r) { // l - r > 0
      int borrow = 0;
      while (lit!=this->digits.crend()-1 && rit!=r.digits.crend()-1) {
        int ld = *lit - '0';
        int rd = *rit - '0';
        int ld_borrow = ld - borrow;
        if (ld_borrow >= rd) {
          result.push_back((ld_borrow-rd) + '0');
          borrow = 0;
        } else if (ld_borrow < rd) {
          result.push_back((ld_borrow+10-rd) + '0');
          borrow = 1;
        }
        lit++;
        rit++;
      }
      while (lit!=this->digits.crend()-1) {
        int ld = *lit - '0';
        if (borrow == 1) {
          if (ld-borrow >= 0) {
            result.push_back((ld-borrow) + '0');
            borrow = 0;
          } else {
            borrow = 1;
            result.push_back('9');
          }
        } else {
          result.push_back(ld + '0');
        }
        lit++;
      }
      result.push_back('+');
      std::reverse(result.begin(), result.end());
      return BigInt(result);
    } else if (*this < r) { // l - r = -(r - l) < 0
      BigInt res = r - *this;
      return res.neg();
    }
  } else if (ls=='-' && rs=='-') { // l - r = l + abs(r) = abs(r) - abs(l)
    return r.abs() - (*this).abs();
  } else if (ls=='+' && rs=='-') { // pos1 - neg2, which is the same as pos1 + abs(neg2)
    return *this + r.abs();
  } else if (ls=='-' && rs=='+') { // neg1 - pos2, which is the same as neg1 + neg(pos2)
    return (*this + r.neg());
  }
}
bool BigInt::operator==(const BigInt& r) const {
  return this->digits == r.digits;
}
bool BigInt::operator>=(const BigInt& r) const {
  if (*this == r) {
    return true;
  }
  return *this > r;
}
bool BigInt::operator>(const BigInt& r) const {
  if (*this == r) {
    return false;
  }
  char ls = this->digits.at(0);
  char rs = r.digits.at(0);
  if (ls == '+' and rs == '-') {
    return true;
  } else if (ls == '-' and rs == '+') {
    return false;
  } else if (ls == '+' and rs == '+') {
    if (this->digits.size() > r.digits.size()) {
      return true;
    } else if (this->digits.size() < r.digits.size()) {
      return false;
    } else {// same number of digits
      auto lit = this->digits.cbegin()+1;
      auto rit = r.digits.cbegin()+1;
      while (lit!=this->digits.cend() && rit!=r.digits.cend()) {
        int ld = *lit - '0';
        int rd = *rit - '0';
        if (ld > rd) {
          return true;
        } else if (ld < rd) {
          return false;
        } else { // they are equal
          lit++;
          rit++;
        }
      }
    }
  } else if (ls == '-' and rs == '-') {
    if (this->digits.size() > r.digits.size()) {
      return false;
    } else if (this->digits.size() < r.digits.size()) {
      return true;
    } else {// same number of digits
      auto lit = this->digits.cbegin()+1;
      auto rit = r.digits.cbegin()+1;
      while (lit!=this->digits.cend() && rit!=r.digits.cend()) {
        int ld = *lit - '0';
        int rd = *rit - '0';
        if (ld > rd) {
          return false;
        } else if (ld < rd) {
          return true;
        } else { // they are equal
          lit++;
          rit++;
        }
      }
    }
  }
}
bool BigInt::operator<(const BigInt& r) const {
  return r > *this;
}
bool BigInt::operator<=(const BigInt& r) const {
  return r >= *this;
}
