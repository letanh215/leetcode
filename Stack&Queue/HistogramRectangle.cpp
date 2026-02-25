#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
  public:
  int largestRectangleArea(vector<int>& heights) {
    stack<int> hStack;
    int n = heights.size();
    int highest = 0;
    vector<int> l_bounds(n, -1), r_bounds(n, n);

    for (int i = 0; i < heights.size(); i++) {
      while (!hStack.empty() && heights[hStack.top()] >= heights[i]) {
        hStack.pop();
      }

      if (!hStack.empty()) {
        l_bounds[i] = hStack.top();
      }

      hStack.push(i);
    }

    while (!hStack.empty()) hStack.pop();

    for (int i = n - 1; i >= 0; i--) {
      while (!hStack.empty() && heights[i] <= heights[hStack.top()]) {
        hStack.pop();
      }

      if (!hStack.empty()) {
        r_bounds[i] = hStack.top();
      }

      hStack.push(i);
    }

    for (int i = 0; i < n; i++) {
      l_bounds[i]++;
      r_bounds[i]--;
      int value = heights[i] * (r_bounds[i] - l_bounds[i] + 1);
      if (highest < value) {
        highest = value;
      }
    }
    return highest;
  }

};
