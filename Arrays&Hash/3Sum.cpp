#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> res;
    int target;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) {
        break;
      }

      if (nums[i] == nums[i-1] && i != 0) {
        continue;
      }

      target = -nums[i];
      int j = i + 1;
      int k = n - 1;
      while (j < k) {
        if (nums[j] + nums[k] == target) {
          res.push_back({nums[i], nums[j], nums[k]});
          j++;
          while (nums[j] == nums[j-1]) {
            j++;
          }

          k--;
          while (nums[k] == nums[k+1]) {
            k--;
          }
        }

        if (nums[j] + nums[k] < target) {
          j++;
        }

        if (nums[j] + nums[k] > target) {
          k--;
        }
      }
    }
    return res;
  }
};
