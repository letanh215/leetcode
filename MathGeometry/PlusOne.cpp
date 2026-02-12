#include <vector>

using namespace std;

class Solution {
  public:
  vector<int> plusOne(vector<int>& digits) {
    
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (digits[i] < 9) {
        digits[i] += 1;
        return digits;
      } else {
        digits[i] = 0;
      }
    }
    vector<int> res = {1};
    for (auto ele : digits) {
      res.push_back(ele);
    }
    return res;
  }
};
