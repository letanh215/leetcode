#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
  public:
  
  string encode(vector<string>& strs) {
    
    string encoder;
    for (int i = 0; i < strs.size(); i++) {
      encoder += to_string(strs[i].size()) + "\n";
      encoder += strs[i];
    }
    return encoder;
  }
  
  vector<string> decode(string s) {
    string t;
    bool num = true;
    int length, count;
    vector<string> res;
    int i = 0;

    while (i != s.size()) {
      if (s.at(i) == '\n') {
        length = stoi(t);
        t = "";
        if (length != 0) {
          num = !num;
        } else {
          res.push_back("");
        }
        count = 0;
      } else {
        t += s.at(i);
        count++;
        if (count == length && !num) {
          res.push_back(t);
          t = "";
          num = !num;
        }
      }
      i++;
    }
    return res;
  }
};
