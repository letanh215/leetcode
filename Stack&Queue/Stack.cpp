#include <iostream>
#include <climits>

using namespace std;

class Node {
  public:
  int value;
  Node* next;
  Node(int value) {
    this->value = value;
    next = nullptr;
  }
};

class Stack {
  private:
  Node* _top;
  int _height;
  
  public:
  Stack(int value) {
    Node* newNode = new Node(value);
    _top = newNode;
    _height = 1;
  }
  
  ~Stack() {
    Node* temp = _top;
    while (_top) {
      _top = _top->next;
      delete temp;
      temp = _top;
    }
  }
  
  void printStack() {
    Node* temp = _top;
    while (temp) {
      cout << temp->value << endl;
      temp = temp->next;
    }
  }
  
  Node* getTop() {
    return _top;
  }
  
  int topValue() {
    if (_top) return _top->value;
    return INT_MIN;
  }
  
  int getHeight() {
    return _height;
  }
  
  void makeEmpty() {
    Node* temp;
    while (_top) {
      temp = _top;
      _top = _top->next;
      delete temp;
    }
    _height = 0;
  }
  
  void push(int value) {
    Node* newNode = new Node(value);

    newNode->next = _top;
    _top = newNode;
    _height++;
  }

  int pop() {
    if (_top == nullptr) {
      return INT_MIN;
    }

    Node* temp = _top;
    int value = temp->value;
    _top = _top->next;
    _height--;
    delete(temp);
    return value;
  }
  
};


