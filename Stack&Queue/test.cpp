#include "ReverseString.h"
#include "BalancedParentheses.h"
#include "SortStack.h"
#include "QueueUsingTwoStacks.cpp"

#include "ValidParentheses.cpp"

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;
int main() {

  // std::string s = "";
  // std::stack<int> ini_stack;

  // ini_stack.push(1);
  // ini_stack.push(3);
  // ini_stack.push(5);
  // ini_stack.push(2);
  // ini_stack.push(4);

  // sortStack(ini_stack);
  // while (!ini_stack.empty()) {
  //   cout << " " << ini_stack.top();
  //   ini_stack.pop();
  // }
  // cout << endl;
  // cout << isBalancedParentheses(s) << endl; 
  // cout << reverseString(s) << endl;;

  // QueueUsingTwoStacks q;

  // q.enqueue(1);
  // q.enqueue(2);

  // q.dequeue();
  // q.enqueue(3);
  // q.enqueue(4);

  // cout << q.front() << endl;
  // q.dequeue();
  // cout << q.front() << endl;

  stack<int> q;
  for (int i = 0; i < 5; i++) {
    q.push(i);
  }

  while (!q.empty()) {
    cout << q.top() << endl;
    q.pop();
  }

  Solution sol;
  // string s = "([{}])";
  vector<string> vect = {"4","13","5","/","+"};
  cout << 4 | 13 << endl;
  // cout << sol.isValid(s) << endl;
  return 0;
}