#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
  string minWindow(string s, string t) {
    if (t.length() == 0) {
      return "";
    }
    unordered_map<char, int> map_t, map_s;

    for (int i = 0; i < t.length(); i++) {
      map_t[t[i]]++;
    }

    int have = 0;
    int l = 0, r = 0;
    int i1, i2;
    int length = s.length();

    while (l < s.length()) {
      while (have != map_t.size() && r < s.length()) {
        // printf("%c %d %d\n", s[r], r, have);
        if (map_t.count(s[r]) != 0) {
          map_s[s[r]]++;
          // printf("%d\n", map_s[s[r]] == map_t[s[r]]);
          if (map_s[s[r]] == map_t[s[r]]){
            have++;
          }
        }
        r++;
      }

      if (length > (r - l) && have == map_t.size()) {
        printf("CPoint: l: %d r: %d\n", l, r);
        length = r - l;
        i1 = l;
        i2 = r;
      }

      if (map_s.count(s[l]) != 0) {
        map_s[s[l]]--;
        have--;
      }

      l++;
    }

    if (length == s.length()) {
      return "";
    }
    string res;
    for (int i = i1; i < i2; i++) {
      res += s[i];
    }
    return res;
  }
};
