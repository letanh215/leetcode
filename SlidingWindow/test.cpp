#include <iostream>
#include <vector>
#include <string>

// #include "MaxProfit.cpp"
#include "LongestSubstring.cpp"
using namespace std;

int main() {

  vector<int> vect = {10,1,5,6,7,1};
  Solution sol;

  string s = "zxyzxxxxxyz";
  // cout << sol.maxProfit(vect) << endl;
  cout << sol.lengthOfLongestSubstring(s) << endl;
  return 0;
}
