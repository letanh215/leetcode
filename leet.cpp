#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
  public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;

    for (int i = 0; i <= nums.size(); i++) {

      int val = target - nums[i];
      auto temp = map.find(val);
      if (temp != map.end()) {
        vector<int> indices = {temp->second, i};
        return indices;
      }
      if (map.count(nums[i]) == 0) {
        map[nums[i]] = i;
      }
    }

    return {};
  }
};
