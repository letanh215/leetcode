#include "FindDuplicates.h"


vector<int> findDuplicates(const vector<int>& nums) {

  vector<int> commons;
  unordered_map<int, bool> nums_map;

  for (auto it = nums.begin(); it != nums.end(); it++) {
    if (nums_map.find(*it) == nums_map.end()) {
      nums_map.insert({*it, 1});
    } else {
      commons.push_back(*it);
    }
  }

  return commons;
}