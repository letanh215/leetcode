#include "LongestSequence.h"
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int longestConsecutiveSequence(const vector<int>& nums) {
  
  unordered_set<int> int_set;
  int longest = 0;
  int q = 0;
  for (auto it : nums) {

    if (int_set.find(it - 1) == int_set.end()) {
      q = 1;
      int i = it;

      while (int_set.find(it + 1) != int_set.end()) {
        q++;
        i++;
      }

      if (longest < q) longest = q;
    }
  }
  return longest;
}