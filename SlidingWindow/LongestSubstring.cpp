#include <string>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
  public:

  int lengthOfLongestSubstring(string s) {
    string t;
    unordered_set<char> set;

    int l = 0;
    int maxLength = 0;

    for (int r = 0; r < s.size(); r++) {
      if (set.count(s[r]) != 0) {
        while (set.count(s[r]) != 0) {
          set.erase(s[l]);
          l++;
        }
      }
      set.insert(s[r]);
      maxLength = max(maxLength, r - l + 1);
    }
    return maxLength;
  }
};
