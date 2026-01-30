#include "ItemInCommon.h"
#include <iostream>

using namespace std; 

bool itemInCommon(vector<int> vect1, vector<int> vect2) {
  
  unordered_map<int, bool> common_map;

  for (auto it : vect1) {
    common_map.insert({it, true});
  }

  for (auto it : vect2) {
    if (common_map.find(it) != common_map.end()) {
      return true;
    }
  }
  return false;
}