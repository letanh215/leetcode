#include <vector>

using namespace std;

class Solution {
  public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int index = l + (r - l) / 2;
      printf("i: %3d, %3d%3d\n", nums[index], l, r);
      if (target > nums[index]) {
        l = index + 1;
      } else if (target < nums[index]) {
        r = index;
      } else {
        return index;
      }
    }
    
    return (l < nums.size() && nums[l] == target) ? l : -1;
  }
};
