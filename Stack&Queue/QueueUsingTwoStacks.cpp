#include <stack>
#include <climits>
#include <iostream>

using namespace std;

class QueueUsingTwoStacks {
  private:
  stack<int> _stack1, _stack2;
  
  public:
  int front() {
    if (_stack2.empty()) {
      while (!_stack1.empty()) {
        _stack2.push(_stack1.top());
        _stack1.pop();
      }
    }
    
    if (_stack2.empty()) {
      return INT_MIN;
    }
    
    return _stack2.top();
  }
  
  bool isEmpty() {
    return _stack1.empty() && _stack2.empty();
  }
  
  void enqueue(int value) {
    _stack1.push(value);
  }

  void dequeue() {
    if (this->isEmpty()) return;
    if (_stack2.empty()) {
      this->front();
    }

    if (!_stack2.empty()) _stack2.pop();
  }
};


