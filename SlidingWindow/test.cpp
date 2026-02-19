#include <iostream>
#include <vector>
#include <string>

// #include "MaxProfit.cpp"
// #include "LongestSubstring.cpp"
// #include "CharacterReplacement.cpp"
// #include "PermutationString.cpp"
// #include "MinimumString.cpp"
#include "MaximumSlidingWindow.cpp"

using namespace std;

template <typename T>
void printVector(vector<T> vect) {
  for (auto ele : vect) {
    cout << ele << ", " ;
  }
  cout << endl;
}

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

  // string s3 = "x", t = "xy";

  // cout << s3 << endl;
  // cout << sol.minWindow(s3, t) << endl;

  vector<int> nums = {1,2,1,0,4,2,6};

  printVector(sol.maxSlidingWindow(nums, 3));
  return 0;
}
