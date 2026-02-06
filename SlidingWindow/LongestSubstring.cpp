#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
  public:
  int lengthOfLongestSubstring(string s) {
    string t;
    unordered_set<char> set;

    int r = 0;
    int l = 0;
    int maxLength = 0;
    cout << s.size() << endl;

    while (r < s.size() && l < s.size()) {
      if (set.count(s[r]) == 0) {
        set.insert(s[r]);
      } else {
        while (s[l] != s[r]) {
          set.erase(s[l]);
          l++;
        }
        l++;
      }
      if ((r - l) > maxLength) {
        maxLength = r - l;
      }
      printf("%c %d %d \n", s[r], l, r);
      r++;
    }
    return maxLength;
  }
};
