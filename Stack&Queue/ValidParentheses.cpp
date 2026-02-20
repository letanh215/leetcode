#include <string>
#include <stack>

using namespace std;

class Solution {
  public:
  bool isValid(string s) {
    stack<char> stack;
    
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        stack.push(s[i]);
      } else if (!stack.empty()) {
        switch (s[i]) {
          case ')':
          if (stack.top() == '(') {
            stack.pop();
            break;
          } else {
            return false;
          }
          case ']':
          if (stack.top() == '[') {
            stack.pop();
            break;
          } else {
            return false;
          }
          case '}':
          if (stack.top() == '{') {
            stack.pop();
            break;
          } else {
            return false;
          }
        }
      } else {
        return false;
      }
    }
    
    return stack.empty();
  }
};
