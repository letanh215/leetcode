#include "FindPairs.h"
#include <vector>
#include <unordered_set>

using namespace std;


vector<vector<int>> findPairs(const vector<int>& arr1, const vector<int>& arr2, int target) {

  unordered_set<int> mySet;
  vector<vector<int>> final_vect;

  for (auto it : arr1) {
    mySet.insert(it);
  }

  for (auto it : arr2) {
    int hash = target - it;

    if (mySet.find(hash) != mySet.end()) {
      final_vect.push_back({hash, it});
    }
  }

  return final_vect;
}