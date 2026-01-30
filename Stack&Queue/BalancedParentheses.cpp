#include "BalancedParentheses.h"

using namespace std;


bool isBalancedParentheses(const string& parentheses) {

  std::stack<char> p_stack;

  if (parentheses.size() == 1) {
    return false;
  }

  if (parentheses.size() == 0) {
    return true;
  }

  for (auto it = parentheses.begin(); it != parentheses.end(); it++) {
    if (*it == '(') {
      p_stack.push('(');
    } else if (*it == ')') {
      if (!p_stack.empty()) p_stack.pop();
      else return false;
    }
  }

  return (p_stack.empty());
}
