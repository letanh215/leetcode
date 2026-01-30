#include "ReverseString.h"

string reverseString(const std::string& str) {
  std::stack<char> s;

  for (int i = 0; i < str.size(); i++) {
    s.push(str.at(i));
  }
  std::string r_str = "";
  while (!s.empty()) {
    r_str += s.top();
    s.pop();
  }
  return r_str;
}