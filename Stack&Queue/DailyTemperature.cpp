#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
  public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<pair<int, int>> ts;
    vector<int> res(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); i++) {
      while (!ts.empty() && temperatures[i] > ts.top().first) {
        res[ts.top().second] = i - ts.top().second;
        ts.pop();
      }
      ts.push({temperatures[i], i});
    }
    
    return res;
  }
};
