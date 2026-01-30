#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  vector<int> productExceptSelf(vector<int>& nums) {

    int n = nums.size();
    vector<int> prod;
    vector<int> predfix(n);
    predfix[0] = 1;

    vector<int> postfix(n);
    postfix[n-1] = 1;

    for (int i = 1; i < n; i++) {
      predfix[i] = predfix[i-1] * nums[i-1];
    }

    for (int i = n - 2; i >= 0; i--) {
      postfix[i] = postfix[i+1] * nums[i+1];
    }

    for (int i = 0; i < n; i++) {
      prod.push_back(postfix[i] * predfix[i]);
    }

    return prod;
  }
};