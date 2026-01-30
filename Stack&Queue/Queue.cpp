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

class Queue {
  private:
  Node* _first;
  Node* _last;
  int _length;
  
  public:
  Queue(int value) {
    Node* newNode = new Node(value);
    _first = newNode;
    _last = newNode;
    _length = 1;
  }
  
  ~Queue() {
    Node* temp = _first;
    while (_first) {
      _first = _first->next;
      delete temp;
      temp = _first;
    }
  }
  
  void printQueue() {
    if (_length == 0) {
      cout << "Queue: empty" << endl;
      return;
    }
    Node* temp = _first;
    cout << "Queue: ";
    while (temp) {
      cout << temp->value;
      temp = temp->next;
      if (temp) {
        cout << " -> ";
      }
    }
    cout << endl;
  }
  
  
  Node* getFirst() {
    return _first;
  }
  
  Node* getLast() {
    return _last;
  }
  
  int getLength() {
    return _length;
  }
  
  void makeEmpty() {
    Node* temp;
    while (_first) {
      temp = _first;
      _first = _first->next;
      delete temp;
    }
    _first = nullptr;
    _last = nullptr;
    _length = 0;
  }
  
  bool isEmpty() {
    if (_length == 0) return true;
    return false;
  }
  
  void enqueue(int value) {
    Node* newNode = new Node(value);

    if (_length == 0) {
      _first = newNode;
      _last = newNode;
    } else {
      _last->next = newNode;
      _last = newNode;
    }

    _length++;
  }
  
  int dequeue() {
    if (_length == 0) {
      return INT_MIN;
    } 

    Node* temp = _first;
    _first = _first->next;
    int value = temp->value;
    delete(temp);
    _length--;
    return value;
  }
};


