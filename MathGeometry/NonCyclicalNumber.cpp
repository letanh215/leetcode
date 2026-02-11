#include <unordered_set>
#include <string>
#include <cmath>

using namespace std;

class Solution {
  public:

  int squaredSum(int value) {
    string s = to_string(value);
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
      sum += pow(s[i] - '0', 2);
    }
    return sum;
  }

  bool isHappy(int n) {
    unordered_set<int> set;

    while (set.count(n)==0) {
      if (n == 1) return true;
      set.insert(n);
      n = squaredSum(n);
    }

    return false;
  }
};
