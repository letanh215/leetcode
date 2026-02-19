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
    int l = 0;
    int i1, i2;
    int length = s.length();
    int need = map_t.size();
    
    for (int r = 0; r < s.length(); r++) {
      map_s[s[r]]++;
      if (map_t.count(s[r]) && map_s[s[r]] == map_t[s[r]]) {
        have++;
      }

      // printf("r: %d, %c\n", r, s[r]);
      while (have == need) {
        if (length > (r - l)) {
          length = r - l; 
          i1 = l;
          i2 = r;
        }
        map_s[s[l]]--;
        if (map_t.count(s[l]) != 0 && map_s[s[l]] < map_t[s[l]]) {
          have--;
        }
        l++;
      }
    }

    if (length == s.length()) {
      return "";
    }
    
    string res;
    for (int i = i1; i <= i2; i++) {
      res += s[i];
    }
    
    return res;
  }
};
