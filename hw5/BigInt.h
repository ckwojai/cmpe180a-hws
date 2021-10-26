#ifndef __BIGINT_H_
#define __BIGINT_H_
#include<iostream>
#include<vector>

using std::vector;
using std::ostream;

class BigInt {
  public:
    BigInt();
    BigInt(const vector<int>& vec_int);
    BigInt(const vector<char>& vec_char);
    BigInt(int[], int arr_s);
    BigInt(char[], int arr_s);
    friend ostream& operator<<(ostream& os, const BigInt& bi);
  private:
    vector<char> digits;
};

#endif // __MERGESTRINGS_H_
