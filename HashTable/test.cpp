// #include "ItemInCommon.h"
// #include "FirstNonRepeatingChar.h"
// #include "TwoSum.h"
// #include "SubarraySum.h"
#include "RemoveDuplicates.h"
#include "FindPairs.h"
#include "LongestSequence.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
  vector<int> v1 = {1, 3, 3, 5};
  vector<int> v2 = {1, 4, 6};

  vector<int> nums = {1};

  // cout << itemInCommon(v1, v2) << endl;

  // string s = "Hello";
  // cout << firstNonRepeatingChar(s) << endl;
  // vector<int> indices = subarraySum(nums, 13);
  // vector<int> indices = removeDuplicates(nums);
  // vector<vector<int>> vect = findPairs(v1, v2, 9);

  // for (auto it : indices) {
  //   cout << it << " ";
  // }

  // for (auto it1 : vect) {
  //   cout << it1.at(0) << " " << it1.at(1) << endl;
  // }

  cout << longestConsecutiveSequence(nums);
  // cout << endl;
  return 0;
}