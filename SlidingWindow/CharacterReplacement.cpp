#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
  int characterReplacement(string s, int k) {
    
    unordered_map<char, int> map;
    
    int maxFreq = 0;
    int l = 0;
    int maxLength = 0;
    for (int r = 0; r < s.size(); r++) {
      map[s[r]]++;
      maxFreq = max(maxFreq, map[s[r]]);

      int window = r - l + 1;
      if ((window - maxFreq) > k) {
        map[s[l]]--;
        l++;
      } else {
        maxLength = max(maxLength, r - l + 1);
      }
    }
    return maxLength;
  }
};
