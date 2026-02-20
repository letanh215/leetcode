#include <stack>
#include <algorithm>

class MinStack {
  private:
    std::stack<int> min_stack_, main_stack_;
  public:
  MinStack() {
    while (!min_stack_.empty()) min_stack_.pop();
    while (!main_stack_.empty()) main_stack_.pop();
  }
  
  void push(int val) {
    if (main_stack_.empty()) {
      min_stack_.push(val);
    } else {
      min_stack_.push(std::min(val, min_stack_.top()));      
    }
    main_stack_.push(val);
  }
  
  void pop() {
    main_stack_.pop();
    min_stack_.pop();
  }
  
  int top() {
    return main_stack_.top();
  }
  
  int getMin() {
    return min_stack_.top();
  }
};
