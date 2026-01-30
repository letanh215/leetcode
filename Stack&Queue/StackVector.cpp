#include <iostream>
#include <vector>

using namespace std;

class Stack {
  private:
  vector<int> _stackVector;
  
  public:
  vector<int>& getStackVector() {
    return _stackVector;
  }
  
  void printStack() {
    for (int i = _stackVector.size() - 1; i >= 0; i--) {
      cout << _stackVector[i] << endl;
    }
  }
  
  bool isEmpty() {
    return _stackVector.size() == 0;
  }
  
  int peek() {
    if (isEmpty()) {
      return int();
    } else {
      return _stackVector[_stackVector.size() - 1];
    }
  }
  
  int size() {
    return _stackVector.size();
  }
  
  void push(int value) {
    _stackVector.push_back(value);
  }
  
  void pop() {
    if (_stackVector.size() != 0) {
      _stackVector.pop_back();
    }
  }
};


