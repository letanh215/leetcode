#include "RemoveDuplicates.h"
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> removeDuplicates(const vector<int>& myList) {

  vector<int> final_set;
  unordered_set<int> set; 

  for (auto it : myList) {
    if (set.find(it) == set.end()) {
      set.insert(it);
    }
  }

  for (auto it = set.begin(); it != set.end(); it++) {
    final_set.push_back(*it);
  }

  return final_set;
}