#include <iostream>

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


class LinkedList {
  private:
  Node* _head;
  Node* _tail;
  int _length;
  
  public:
  LinkedList(int value) {
    Node* newNode = new Node(value);
    _head = newNode;
    _tail = newNode;
    _length = 1;
  }
  
  ~LinkedList() {
    Node* temp = _head;
    while (_head) {
      _head = _head->next;
      delete temp;
      temp = _head;
    }
  }
  
  void printList() {
    Node* temp = _head;
    if (temp == nullptr) {
      cout << "empty";
    } else {
      while (temp != nullptr) {
        cout << temp->value;
        temp = temp->next;
        if (temp != nullptr) {
          cout << " -> ";
        }
      }
    }
    cout << endl;
  }
  
  Node* getHead() {
    return _head;
  }
  
  Node* getTail() {
    return _tail; 
  }
  
  int getLength() {
    return _length;
  }
  
  void append(int value) {
    Node* newNode = new Node(value);
    if (_length == 0) {
      _head = newNode;
      _tail = newNode;
    } else {
      _tail->next = newNode;
      _tail = newNode;
    }
    _length++;
  }
  
  void deleteFirst() {
    if (_length == 0) return;
    Node* temp = _head;
    if (_length == 1) {
      _head = nullptr;
      _tail = nullptr;
    } else {
      _head = _head->next;
    }
    delete temp;
    _length--;
  }
  
  void selectionSort() {
    if (_length < 2) {
      return;
    }

    Node* ptr1 = _head;
    Node* ptr2;

    while (ptr1 != nullptr) {
      ptr2 = ptr1->next;
      Node* min_ptr = ptr1;
      while (ptr2 != nullptr) {
        if (ptr2->value < min_ptr->value) {
          min_ptr = ptr2;
        }
        ptr2 = ptr2->next;
      }

      if (min_ptr != ptr1) {
        int temp = ptr1->value;
        ptr1->value = min_ptr->value;
        min_ptr->value = temp;
      }
      ptr1 = ptr1->next;
    }
  }
  
};


