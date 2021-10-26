#include<iostream>
#include<vector>
#include "mergeVectors.h"

using namespace std;

const int points_per_test = 10;

void testMergedVectors(const string &test_name, vector<vector<int>> &input,
                const vector<int> &expected_merged_vec, int points_for_this_test,
                   int &total_grade) {

    vector<int> merged_vector;
    mergeVectors(input, merged_vector);
    bool equalFlag = true;

    if(merged_vector.size() == expected_merged_vec.size()){
        for(int i=0; i<expected_merged_vec.size(); i++){
            if(expected_merged_vec[i] != merged_vector[i]){
               //Expected and Merged Vector (From Function) have different Values
               cout << test_name << " Failed! False Output" << endl;
               equalFlag = false;
               break;
            }
        }
        if(equalFlag){
            cout << test_name << " Passed!" << "\n";
            total_grade += points_for_this_test;
        }
    }else{
        //Expected and Merged Vector (From Function) are of different Lengths
        cout << test_name << " Failed!" << endl;
    }
}

int main(){
    int total_grade = 0;
    //Input Vector for Test Cases
    vector<vector<int>> inVec;

    //Test1.0
    //Temp Vectors
    vector<int> temp1{1,2};
    vector<int> temp2{1,3};

    //Preparing Input Vector
    inVec.push_back(temp1);
    inVec.push_back(temp2);

    //Expected Merged Vector
    vector<int> res1{1,1,2,3};
    testMergedVectors("Test1.0",inVec, res1, points_per_test, total_grade);

    //Final Grade
    cout << total_grade << endl;
    return 0;
}
