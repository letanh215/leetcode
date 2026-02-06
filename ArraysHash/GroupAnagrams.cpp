#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
    unordered_map<int, vector<string>> map;

    for (auto it = strs.begin(); it != strs.end(); it++) {
      int hash = 0;
      for (int j = 0; j < it->size(); j++) {
        hash += int(it->at(j)) * (int(it->at(j)) - 96);
      }
      if (map.count(hash) == 0) {
        map[hash] = {*it};
      } else {
        map[hash].push_back(*it);
      }
    }

    vector<vector<string>> groups;

    for (auto it = map.begin(); it != map.end(); it++) {
      groups.push_back(it->second);
    }

    return groups;
  }
};
