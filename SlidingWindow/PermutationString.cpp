#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
  bool checkInclusion(string s1, string s2) {
    
    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);
    
    int matches = 0;
    
    for (int i = 0; i < s1.size(); i++) {
      freq1[s1[i] - 'a']++;
      freq2[s2[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; i++) {
      if (freq1[i] == freq2[i]){
        matches++;
      }
    }
    
    int l = 0;
    int i = 0;
    for (int r = s1.size(); r < s2.size(); r++) {
      if (matches == 26) {
        return true;
      }

      i = s2[r] - 'a';
      freq2[i]++;
      if (freq2[i] == freq1[i]) {
        matches++;
      } else if (freq2[i] - 1 == freq1[i]) {
        matches--;
      }

      i = s2[l] - 'a';
      freq2[i]--;

      if (freq2[i] == freq1[i]) {
        matches++;
      } else if (freq2[i] + 1 == freq1[i]) {
        matches--;
      }
      l++;
    }
    return matches == 26;
  }
};
