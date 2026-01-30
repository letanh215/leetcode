#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
  public:
  int longestConsecutive(vector<int>& nums) {
    
    unordered_set<int> set;
    int longest = 0;
    
    for (auto it : nums) {
      if (set.count(it) == 0) {
        set.insert(it);
      }
    }
    
    for (auto it : nums) {
      if (set.count(it-1) != 0) {
        int count = 1;
        int i = it;
        while (set.count(i-1) != 0) {
          count++;
          i--;
        }
        
        if (count > longest) {
          longest = count;
        }
      }
    }
    
    if (set.size() == 1) {
      return 1;
    }

    return longest;
  }
};
