#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> res;
    int target;
    for (auto it1 = nums.begin(); it1 != nums.end(); it1++) {
      if (*it1 != -target){ 
        target = -*it1;
        
        auto it2 = nums.begin();
        auto it3 = nums.end() - 1;
        while (it2 < it3) {
          int sum = *it2 + *it3;
          
          if (sum > target) {
            it3--;
          }
          
          if (sum < target) {
            it2++;
          }
          
          if (sum == target) {
            if (it1 != it2 && it2 != it3 && it1 != it3) {
              res.push_back({*it1, *it2, *it3});
            }
            it2++;
          }
        }
      }
    }
    return res;
  }
};
