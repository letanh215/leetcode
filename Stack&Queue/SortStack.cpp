#include "SortStack.h"

void sortStack(stack<int>& inputStack) {

  std::stack<int> tempstack;
  int temp;

  while (!inputStack.empty()) {
    temp = inputStack.top();
    inputStack.pop();

    if (tempstack.empty()) {
      tempstack.push(temp);
    } else {

      while (tempstack.top() > temp) {
        inputStack.push(tempstack.top());
        tempstack.pop();
        if (tempstack.empty()) {
          break;
        }
      }
      tempstack.push(temp);
    }
  }

  while (!tempstack.empty()) {
    inputStack.push(tempstack.top());
    tempstack.pop();
  }
}
