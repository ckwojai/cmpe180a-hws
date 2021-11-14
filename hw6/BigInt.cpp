#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include "BigInt.h"

using std::cout;
using std::endl;

void BigInt::init(const vector<int>& vec_int) {
  bool leading_zero = true;
  for(auto it=vec_int.cbegin(); it!=vec_int.cend(); it++) {
    int digit = *it;
    if (leading_zero && digit==0) {
      if (vec_int.size() == 1) { // {0}
        digits.push_back('+');
	digits.push_back('0');
	return;
      }
      if (it == vec_int.cbegin()) {
        std::cerr << "sign can't be determined if first element is 0, assuming positive.\n";
        digits.push_back('+');
      }
      continue;
    } else {
      leading_zero = false;
    }
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

void BigInt::init(const vector<char>& vec_char) {
  bool leading_zero = true;
  for(auto it=vec_char.cbegin(); it!=vec_char.cend(); it++) {
    int digit = *it - '0';
    if (it==vec_char.cbegin()) {
      if (*it == '+' || *it == '-') {
        digits.push_back(*it);
      } else {
        digits.push_back('+');
        if (!(digit >=0 && digit<=9)) {
          std::cerr << "Provided digit out of bound. Please provide a single digit.\n";
          exit(0);
        } else if (digit == 0) { // sign is a leading 0...
	  if (vec_char.size() == 1) { // {'0'}
	    digits.push_back('0');
	    return;
	  }
          std::cerr << "Sign digit is 0. Ignoring it...\n";
        } else {
          digits.push_back(*it);
          leading_zero = false;
        }
      }
    } else {
      if (leading_zero && digit==0) {
      } else {
	int digit = *it - '0';
        if (!(digit >=0 && digit<=9)) {
          std::cerr << "Provided digit out of bound. Please provide a single digit.\n";
          exit(0);
	}
        digits.push_back(*it);
        leading_zero = false;
      }
    }
  }
}

BigInt::BigInt(int arr[], int arr_s) {
  vector<int> vi;
  for (int i=0; i < arr_s; i++) {
    vi.push_back(arr[i]);
  }
  init(vi);
}
BigInt::BigInt(char arr[], int arr_s) {
  vector<char> vc;
  for (int i=0; i < arr_s; i++) {
    vc.push_back(arr[i]);
  }
  init(vc);
}
BigInt::BigInt(const vector<int>& vec_int) {
  init(vec_int);
}

BigInt::BigInt(const vector<char>& vec_char) {
  init(vec_char);
}

BigInt::BigInt() {
}

ostream& operator<<(ostream& os, const BigInt& bi) {
  for(auto it=bi.digits.cbegin(); it!=bi.digits.cend(); it++) {
    os << *it;
  }
  return os;
}

istream& operator>>(istream& is, BigInt& dt) {
  std::string str;
  is >> str;
  vector<char> vc(str.begin(), str.end());
  dt.init(vc);
  return is;
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

BigInt BigInt::operator*(const BigInt& r) const {
  char ls = this->digits.at(0);
  char rs = r.digits.at(0);
  if (!r || !*this) { // either operand is 0
    vector<char> vc = {'+', '0'};
    return BigInt(vc);
  }
  if (r.digits.size() == 2) { // single digits
    BigInt result(*this);
    for (int i=0; i < r.digits.back() - 1; i++) {
      result = result + result;
    }
    return result;
  }
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
    if (extra == 1) { // for cases like 9999+9, or 1+9;
      result.push_back('1');
    }
    // remove leading 0s before adding sign
    for (auto it=result.crbegin(); it!=result.crend(); it++) {
      if (*it == '0') {
        result.pop_back();
      } else {
        break;
      }
    }
    result.push_back(ls); // (-a+-b)=-(a+b)
    std::reverse(result.begin(), result.end());
    return BigInt(result);
  } else if (ls=='+' && rs=='-') { // pos1 + neg2, which is the same as pos1 - abs(neg2)
    return (*this - r.abs());
  } else if (ls=='-' && rs=='+') { // neg1 + pos2, which is the same as pos2 - abs(neg1)
    return (r - this->abs());
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
      // remove leading 0s before adding sign
      for (auto it=result.crbegin(); it!=result.crend(); it++) {
        if (*it == '0') {
          result.pop_back();
        } else {
          break;
        }
      }
      result.push_back('+');
      std::reverse(result.begin(), result.end());
      return BigInt(result);
    } else if (*this < r) { // l - r = -(r - l) < 0
      BigInt res = r - *this;
      return res.neg();
    } else { // l-r = 0
      int arr[1] = {0};
      BigInt z(arr,1);
      return z;
    }
  } else if (ls=='-' && rs=='-') { // l - r = l + abs(r) = abs(r) - abs(l)
    return r.abs() - (*this).abs();
  } else if (ls=='+' && rs=='-') { // pos1 - neg2, which is the same as pos1 + abs(neg2)
    return *this + r.abs();
  } else if (ls=='-' && rs=='+') { // neg1 - pos2, which is the same as neg1 + neg(pos2)
    return (*this + r.neg());
  }
}

bool BigInt::operator!() const {
  int arr[1] = {0};
  BigInt z(arr, 1);
  return *this == z;
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
    if (this->digits.size() > r.digits.size()) { // assuming no leading zeros
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
BigInt BigInt::operator++() {
  int arr[1] = {1};
  BigInt one(arr, 1);
  *this = *this + one;
  return *this;
}

BigInt BigInt::operator--() {
  int arr[1] = {1};
  BigInt one(arr, 1);
  *this = *this - one;
  return *this;
}

BigInt BigInt::operator++(int) {
  BigInt tmp(*this);
  operator++();
  return tmp;
}

BigInt BigInt::operator--(int) {
  BigInt tmp(*this);
  operator--();
  return tmp;
}
