#include "BigInt.h" /* Your own header file */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    vector<int> integerVector;
    integerVector.push_back(0);

    vector<char> charVector;
    charVector.push_back('5');

    char charArray[] = {'5'};

    BigInt A = BigInt(integerVector);
     cout << "A = " << A << endl;

     BigInt B = BigInt(charVector);
     cout << "B = " << B << endl;

    BigInt C = BigInt(charArray, 1);
    cout << "C = " << C << endl;

    BigInt D = B * C;

    cout << "D = " << D << endl;
    cout << "A+B = " << A + B << endl;
    cout << "B-C = " << B - C << endl;

    if (A == D)
    {
        cout << "A is equal to D " << endl;
    }
    else
    {
        cout << "A is not equal to D" << endl;
    }

    cout << "Is A>B? : " << (A > B) << endl;
    cout << "Is B<C? : " << (B < C) << endl;
    cout << "Is A>=D? : " << (A >= D) << endl;
    cout << "Is C<=D? : " << (C <= D) << endl;
    cout << "Output of Post Increment A: " << A++ << endl;
    cout << "Output of Post Decrement A: " << A-- << endl;
    cout << "Output of Pre Increment A: " << ++A << endl;
    cout << "Output of Pre Decrement A: " << --A << endl;
    cout << "What is ! of (A-D)? " << !(A - D) << endl;

    return 0;
}
