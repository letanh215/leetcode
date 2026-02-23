#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
  public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    stack<double> fleetStack;
    vector<pair<int, int>> pairs;

    for (int i = 0; i < position.size(); i++) {
      pairs.push_back({position[i], speed[i]});
    }

    sort(pairs.rbegin(), pairs.rend());
    
    for (int i = 0; i < pairs.size(); i++) {
      double times = (double)(target - pairs[i].first) / pairs[i].second;
      if (fleetStack.empty() || fleetStack.top() < times) {
        fleetStack.push(times);
      }
    }

    return fleetStack.size();
  }
};
