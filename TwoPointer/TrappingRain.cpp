#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
  public:
  int trap(vector<int>& height) {

    vector<int> prefix(height.size());
    vector<int> surfix(height.size());

    int maxIndex = 0;
    for (int i = 0; i < height.size(); i++) {
      prefix[i] = height[maxIndex];
      if (height[i] > height[maxIndex]) {
        maxIndex = i;
      }
    }

    maxIndex = height.size() - 1;
    for (int i = height.size() - 1; i >= 0; i--) {
      surfix[i] = height[maxIndex];
      if (height[i] > height[maxIndex]) {
        maxIndex = i;
      }
    }

    int sum = 0;
    for (int i = 1; i < height.size() - 1; i++) {
      int a = min(prefix[i], surfix[i]) - height[i];
      if (height[i] > prefix[i] || height[i] > surfix[i]) {
        a = 0;
      } 
      sum += a;
    }
    cout << endl;
    return sum;
  }
};
