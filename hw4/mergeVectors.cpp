#include <algorithm>
#include <iterator>
#include <climits>
#include <iostream>
#include "mergeVectors.h"

bool asc_order(vector<int> vec) {
  if (vec.size() <= 1) {
    return true;
  }
  for (auto it=vec.cbegin(); it!=vec.cend()-1; it++) {
    if (*it > *(it+1)) {
      return false;
    } else if (*it < *(it+1)) {
      return true;
    } else if (*it == *(it+1)) {
      continue;
    }
  }
  return true;
}

void mergeVectors(const vector<vector<int>>& input, vector<int>& result) {
  int desc_count = 0;
  // Make sure all vectors are sorted in ascending order
  vector<vector<int>> asc_input;
  for (auto it=input.cbegin(); it!=input.cend(); it++) {
    if (asc_order(*it)) {
      asc_input.push_back(*it);
    } else {
      desc_count++;
      vector<int> rev_vec(*it);
      std::reverse((rev_vec).begin(), (rev_vec).end());
      asc_input.push_back(rev_vec);
    }
  }
  // Create iterators for all vectors
  vector<vector<int>::const_iterator> vec_iters;
  for (auto it=asc_input.cbegin(); it!=asc_input.cend(); it++) {
    vec_iters.push_back((*it).cbegin());
  }
  bool done = false;

  // Merge logic
  while (!done) {
    vector<int> to_sort_ints;
    int all_done = 0;
    for(auto it=vec_iters.cbegin(); it!=vec_iters.cend(); it++) {
      int index = std::distance(vec_iters.cbegin(), it);
      if (*it != asc_input.at(index).cend()) {
        to_sort_ints.push_back(*(*it));
      } else {
        to_sort_ints.push_back(INT_MAX);
        all_done++;
      }
    }
    if (all_done == asc_input.size()) { // When all vec_iters reaches the end
      done = true;
    } else {
      auto it = std::min_element(to_sort_ints.cbegin(), to_sort_ints.cend());
      int min_index = std::distance(to_sort_ints.cbegin(), it);
      result.push_back(to_sort_ints.at(min_index));
      vec_iters.at(min_index)++;
    }
  }
  // Majority sorting
  if (desc_count > (input.size() - desc_count)) {
    std::reverse(result.begin(), result.end());
  }
}
