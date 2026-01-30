#include "HasUniqueChars.h"
#include <string>
#include <unordered_set>

using namespace std;

bool hasUniqueChars(const string& str) {

  unordered_set<char> c_set;

  for (auto it = str.begin(); it != str.end(); it++) {
    if (c_set.find(*it) == c_set.end()) {
      c_set.insert(*it);
    } else {
      return false;
    }
  }
  
  return true;
}