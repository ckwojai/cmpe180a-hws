#ifndef __BIGINT_H_
#define __BIGINT_H_
#include<iostream>
#include<vector>

using std::vector;
using std::ostream;
using std::istream;

class BigInt {
  public:
    BigInt();
    BigInt(const vector<int>& vec_int);
    BigInt(const vector<char>& vec_char);
    BigInt(int[], int arr_s);
    BigInt(char[], int arr_s);
    BigInt operator+(const BigInt& r) const;
    BigInt operator-(const BigInt& r) const;
    BigInt operator*(const BigInt& r) const;
    bool operator!();
    bool operator==(const BigInt& r) const;
    bool operator>=(const BigInt& r) const;
    bool operator>(const BigInt& r) const;
    bool operator<=(const BigInt& r) const;
    bool operator<(const BigInt& r) const;
    BigInt operator++();
    BigInt operator--();
    BigInt operator++(int);
    BigInt operator--(int);
    friend ostream& operator<<(ostream& os, const BigInt& bi);
    friend istream& operator>>(istream& is, BigInt& dt);
  private:
    void init(const vector<int>& vec_int);
    BigInt abs() const;
    BigInt neg() const;
    vector<char> digits;
};

#endif // __MERGESTRINGS_H_