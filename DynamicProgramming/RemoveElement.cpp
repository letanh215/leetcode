#include "RemoveElement.h"

void removeElement(vector<int>& nums, int val) {
  size_t i = 0;
  for (size_t j = 0; j < nums.size(); j++) {
    if (nums[j] != val) {
      nums[i] = nums[j];
      i++;
    }
  }
  nums.resize(i);
}