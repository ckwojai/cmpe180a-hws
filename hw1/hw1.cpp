/**
 * @file hw1.cpp
 * @author Kin Chang
 * Contact: kinwo.chang@sjsu.edu
 */
#include <fstream>    // file I/O
#include <iostream>   // cout or cin
#include <cstdlib>    // for exit()
#include <sstream>    // for istringsteam
#include <string>     // for string
#include <cstring>    // for strcmp

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::getline;
using std::istringstream;
using std::string;

void print_matrix(int* matrix, int m, int n) {
  for (int i=0; i < m; i++) {
    for (int j=0; j < n; j++) {
      cout << matrix[i*n+j] << " ";
    }
    cout << endl;
  }
}

void get_matrix_dimension(ifstream& file_stream, int& m, int& n) {
  string line;
  while (getline(file_stream, line)) {
    istringstream iss(line);
    if (!(iss >> m >> n)) {
      cout << "Can't extract no. of row and column in the first line." << endl;
      exit(1);
    }
    break;
  }
}

void extract_matrix(ifstream& file_stream, int* mat, const int& m, const int& n) {
  // Expecting the current line of file_stream to be the matrix content
  int line_counter = 0;
  string line;
  while (getline(file_stream, line) && line_counter < m) {
    istringstream iss(line);
    for (int i=0; i < n; i++) {
      if (!(iss >> mat[line_counter*n+i])) {
        cout << "Can't extract matrix content. Please check your structure." << endl;
        exit(1);
      }
    }
    int more_column_test;
    if (iss >> more_column_test) {
        cout << "More columns then specified. Please check your structure." << endl;
        exit(1);
    }
    line_counter++;
  }
  if (line_counter < m) { // Not enough rows to extract
        cout << "Number of rows doesn't match what's specified. Please check your structure." << endl;
        exit(1);
  }
}

void multiply_matrix(int* lmat, int* rmat, int* mat_result, const int& m1, const int& n1, const int& n2) {
  for (int i=0; i < m1; i++) {
    for (int j=0; j < n2; j++) {
      int sum = 0;
      for (int k=0; k < n1; k++) {
        sum += lmat[i*n1+k] * rmat[k*n2+j];
      }
      mat_result[i*n2+j] = sum;
    }
  }
}


int main(int argc, char* argv[]) {
  // cout << "command received: ";
  // for (int i=0; i < argc; i++) {
  //   cout << argv[i] << " ";
  // }
  // cout << endl;
  if (argc != 5) {
    cout << "Invalid number of arguments! Please use both the flags -m and -M only" << endl;
    exit(1);
  }
  char* file1_path;
  char* file2_path;
  for (int i=1; i < argc; i++) { // start at 1 because 0 is matrixproduct
    if (strcmp(argv[i], "-m") == 0) {
      file1_path = argv[i+1];
      i++;
    } else if (strcmp(argv[i], "-M") == 0) {
      file2_path = argv[i+1];
      i++;
    } else {
      cout << "Invalid flags. Please use '-m' for the first matrix file and '-M' for the second." << endl;
      exit(1);
    }
  }

  ifstream file1_stream(file1_path);
  ifstream file2_stream(file2_path);
  if (file1_stream.fail() || file2_stream.fail()) {
    cout << "Input files opening failed." << endl;
    exit(1);
  }

  // m_1 := no. of row in the first matrix;  n_2 := no. of column in the second matrix.
  int m_1 = 0, n_1 = 0;
  int m_2 = 0, n_2 = 0;

  get_matrix_dimension(file1_stream, m_1, n_1);
  get_matrix_dimension(file2_stream, m_2, n_2);

  if (n_1 != m_2) {
    cout << "Matrix dimension error: " << n_1 << "!=" << m_2 << ". Please check the dimension of the matrices." << endl;
    exit(1);
  }
  int *mat_1 = new int[m_1*n_1];
  int *mat_2 = new int[m_2*n_2];
  int *mat_result = new int[m_1*n_2];

  extract_matrix(file1_stream, mat_1, m_1, n_1);
  extract_matrix(file2_stream, mat_2, m_2, n_2);

  multiply_matrix(mat_1, mat_2, mat_result, m_1, n_1, n_2);

  // cout << "Matrix 1:" << endl;
  // print_matrix(mat_1, m_1, n_1);
  // cout << "Matrix 2:" << endl;
  // print_matrix(mat_2, m_2, n_2);
  // cout << "Result Matrix:" << endl;
  print_matrix(mat_result, m_1, n_2);
  // cout << "================================================================================" << endl;

  // Clean up dynamically allocated memory from arrays
  delete [] mat_1;
  delete [] mat_2;
  delete [] mat_result;
}
