#include <algorithm>
#include <iterator>
#include <climits>
#include <iostream>
#include "mergeVectors.h"

void mergeVectors(const vector<vector<int>>& input, vector<int>& result) {
  vector<vector<int>::const_iterator> vec_iters;
  for (auto it=input.cbegin(); it!=input.cend(); it++) {
    vec_iters.push_back((*it).cbegin());
  }
  bool done = false;

  while (!done) {
    vector<int> to_sort_ints;
    int all_done = 0;
    for(auto it=vec_iters.cbegin(); it!=vec_iters.cend(); it++) {
      int index = std::distance(vec_iters.cbegin(), it);
      if (*it != input.at(index).cend()) {
        to_sort_ints.push_back(*(*it));
      } else {
        to_sort_ints.push_back(INT_MAX);
        all_done++;
      }
    }
    for (int i=0; i<to_sort_ints.size(); i++) {
      std::cout << to_sort_ints[i] << " ";
    }
    std::cout << std::endl;
    for (int i=0; i<result.size(); i++) {
      std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    if (all_done == input.size()) { // When all vec_iters reaches the end
      done = true;
    } else {
      auto it = std::min_element(to_sort_ints.cbegin(), to_sort_ints.cend());
      int min_index = std::distance(to_sort_ints.cbegin(), it);
      result.push_back(to_sort_ints.at(min_index));
      vec_iters.at(min_index)++;
    }
  }
}
