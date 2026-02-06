#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
  public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
      if (map.count(nums[i]) == 0) {
        map[nums[i]] = 1;
      } else {
        map[nums[i]]++;
      }
    }

    vector<vector<int>> freq(nums.size() + 1);
    for (auto it : map) {
      freq[it.second].push_back(it.first);
    }
    
    vector<int> res;
    int count = 0;
    int i = nums.size();
    while (count != k) {
      if (freq[i].size() != 0) {
        for (auto it = freq[i].begin(); it != freq[i].end(); it++) {
          res.push_back(*it);
          count++;
          if (count == k) {
            break;
          }
        }
      }
      i--;
    }
    return res;
  }
};
