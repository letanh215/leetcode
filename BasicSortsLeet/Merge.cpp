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
  
  void merge(LinkedList &otherList) {

    Node* dummy = new Node(0);

    Node* ptr = dummy;
    Node* ptr1 = _head;
    Node* ptr2 = otherList.getHead();

    while (ptr1 != nullptr && ptr2 != nullptr) {
      if (ptr1->value < ptr2->value) {
        ptr->next = ptr1;
        ptr = ptr1;
        ptr1 = ptr1->next;
      } else {
        ptr->next = ptr2;
        ptr = ptr2;
        ptr2 = ptr2->next;
      }
    }

    while (ptr1 != nullptr) {
      ptr->next = ptr1;
      ptr = ptr1;
      ptr1 = ptr1->next;
    }

    while (ptr2 != nullptr) {
      ptr->next = ptr2;
      ptr = ptr2;
      ptr2 = ptr2->next;
    }
    _tail = ptr;
    _head = dummy->next;
    _length += otherList.getLength();
    delete(dummy);

    otherList._head = nullptr;
    otherList._tail = nullptr;
    otherList._length = 0;
  }
  
};


