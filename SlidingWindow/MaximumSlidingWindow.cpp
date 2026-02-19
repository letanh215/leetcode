#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
  public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> queue;

    for (int i = 0; i < k; i++) {
      queue.push({nums[i], i});
    }

    vector<int> res;
    res.push_back(queue.top().first);
    int l = 0;
    for (int i = k; i < nums.size(); i++) {
      queue.push({nums[i], i});
      l++;
      while (queue.top().second < l) {
        queue.pop();
      }
      res.push_back(queue.top().first);
    }

    return res;
  }
};
