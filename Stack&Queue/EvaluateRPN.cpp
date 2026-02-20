#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
  public:
  int evalRPN(vector<string>& tokens) {
    stack<string> numbers;
    stack<string> operators;

    for (int i = tokens.size() - 1; i >= 0; i--) {
      if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*"
          || tokens[i] == "/") {
        operators.push(tokens[i]);   
      } else {
        numbers.push(tokens[i]);
      }
    }

    if (numbers.size() != operators.size() + 1) {
      return -1;
    }

    int res = stoi(numbers.top());
    numbers.pop();

    while (!numbers.empty()) {
      string op = operators.top();
      int n = stoi(numbers.top());
      if (op == "+") {
        res += n;
      } else if (op == "-") {
        res -= n;
      } else if (op == "*") {
        res *= n;
      } else {
        int d = res % n;
        res /= n;
        if (d > 0) {
          res += 1;
        }
      }

      operators.pop();
      numbers.pop();
    }

    return res;
  }
};
