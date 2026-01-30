#include "TwoSum.h"
#include <cmath>

vector<int> twoSum(const vector<int>& nums, int target) {

  unordered_map<int, int> nums_map;
  
  for (int i = 0; i < nums.size(); i++) {
    int comp = target - nums.at(i);
    auto temp = nums_map.find(comp);
    if (temp != nums_map.end()) {
      vector<int> indices = {temp->second, i};
      return indices;
    } else {
      nums_map[nums.at(i)] = i;
    }
  }
  return vector<int>({});
}