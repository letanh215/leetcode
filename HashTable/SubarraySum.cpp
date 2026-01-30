#include "SubarraySum.h"

vector<int> subarraySum(const vector<int>& nums, int target) {

  unordered_map<int, int> sum_index;

  int sum = 0;
  sum_index[0] = -1;
  for (int i = 0; i < nums.size(); i++) {
    if (nums.at(i) == target) {
      return vector<int>({i, i});
    }
    sum += nums.at(i);
    int hash = sum - target;

    if (sum_index.find(hash) != sum_index.end()) {
      return vector<int>({sum_index[hash]+1, i});
    } else {
      sum_index[sum] = i;
    }
  }
  return vector<int>({});
}
