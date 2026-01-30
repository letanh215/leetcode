#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
  bool isPalindrome(string s) {
    
    auto i = s.begin();
    while (i != s.end()) {
      if (*i < 'A' && (*i > '9' || *i < '0')) {
        // printf("%d \n", '?')
        s.erase(i);
      } else {
        if (*i > 64 && *i < 91) {
          *i = *i + 32;
        }
        i++;
      }
    }

    auto it1 = s.begin();
    auto it2 = s.end() - 1;

    while (it1 != s.end()) {
      if (*it1 == *it2) {
        it1++;
        it2--;
      } else {
        return false;
      }
    }
    return true;
  }
};
