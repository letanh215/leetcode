#include <iostream>
#include <vector>
#include <string>

// #include "MaxProfit.cpp"
// #include "LongestSubstring.cpp"
// #include "CharacterReplacement.cpp"
// #include "PermutationString.cpp"
#include "MinimumString.cpp"

using namespace std;

int main() {

  vector<int> vect = {10,1,5,6,7,1};
  Solution sol;

  string s = "XYYX";

  string s1 = "abc";
  string s2 = "lecaabee";
  // cout << sol.maxProfit(vect) << endl;
  // cout << sol.lengthOfLongestSubstring(s) << endl;
  // cout << sol.characterReplacement(s, 2) << endl;
  // cout << sol.checkInclusion(s1, s2) << endl;

  string s3 = "ADOBECODEBANCT", t = "ABC";

  cout << s3 << endl;
  cout << sol.minWindow(s3, t) << endl;
  return 0;
}
