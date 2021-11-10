/**
 * @file mcp.cc
 * @author Kin Chang
 * Contact: kinwo.chang@sjsu.edu
 */
#include <fstream>    // file I/O
#include <iostream>   // cout or cin
#include <string>
#include <cstring>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::ios;
using std::cerr;
using std::strcmp;

bool file_exist(const string& name) {
  if (FILE *file = fopen(name.c_str(), "r")) {
    fclose(file);
    return true;
  } else {
    return false;
  }
}

void copy_file(const string& src_name, const string& dest_name){
  if (!file_exist(src_name)) {
    cerr << "Source file " << src_name << " doesn't exist." << endl;
    exit(1);
  }
  if (file_exist(dest_name)) {
    cerr << "Target file: " << dest_name << " already exists." << endl;
    exit(1);
  }
  ifstream source(src_name, ios::binary);
  ofstream dest(dest_name, ios::binary);
  dest << source.rdbuf();
  source.close();
  dest.close();
}

int main(int argc, char* argv[]) {
  if (argc < 5) {
    cout << "Invalid number of arguments! Please use both -s and -t flags." << endl;
    exit(1);
  }
  string src_path;
  vector<string> des_path_vec;
  bool src_file_check = false;
  bool target_file_check = false;

  for (int i=1; i < argc; i++) { // start at 1 because 0 is matrixproduct
    if (strcmp(argv[i], "-s") == 0) {
      src_path = string(argv[i+1]);
      src_file_check = true;
      i++;
    } else if (strcmp(argv[i], "-t") == 0) {
      des_path_vec.push_back(string(argv[i+1]));
      target_file_check = true;
      i++;
    } else {
      cerr << "Invalid flags. Please use '-s' for the source file and '-t' for the target file." << endl;
      exit(1);
    }
  }
  if (src_file_check && target_file_check) {
    for (auto it=des_path_vec.cbegin(); it!=des_path_vec.cend(); it++) {
      copy_file(src_path, *it);
    }
  } else {
      cerr << "Not enough flags are provided. Please use '-s' for the source file and '-t' for the target file." << endl;
      exit(1):
  }
}
