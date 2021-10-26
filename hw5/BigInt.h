#ifndef __BIGINT_H_
#define __BIGINT_H_
#include<vector>

using std::vector;
using std::ostream;

class BigInt {
  public:
    BigInt();
    BigInt(vector<int>vec_int);
    BigInt(vector<char>vec_int);
    BigInt(int[], int arr_s);
    BigInt(char[], int arr_s);
    friend ostream& operator<<(ostream& os, const BigInt& bi);
  private:
    vector<char> digits;
};

#endif // __MERGESTRINGS_H_
