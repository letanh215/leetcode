#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
  public:
  int evalRPN(vector<string>& tokens) {
    stack<int> numbers;
    
    for (int i = 0; i < tokens.size(); i++) {
      if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
        tokens[i] == "/") {
          
          int n2 = numbers.top();
          numbers.pop();
          int n1 = numbers.top();
          numbers.pop();
          
          if (tokens[i] == "+") {
            numbers.push(n1 + n2);
          } else if (tokens[i] == "-") {
            numbers.push(n1 - n2);
          } else if (tokens[i] == "*") {
            numbers.push(n1 * n2);
          } else if (tokens[i] == "/") {
            numbers.push(n1 / n2);
          }
        } else {
          numbers.push(stoi(tokens[i]));
        }
      }
      
      return numbers.top();
    }
  };
  