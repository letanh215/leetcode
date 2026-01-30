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
  
  void insertionSort() {
    if (_length < 2) {
      return;
    }
    
    Node* sortedListHead = _head;
    Node* unsortedListHead = _head->next;
    sortedListHead->next = nullptr;
    
    while (unsortedListHead != nullptr) {
      Node* current = unsortedListHead;
      unsortedListHead = unsortedListHead->next;
      
      if (current->value < sortedListHead->value) {
        current->next = sortedListHead;
        sortedListHead = current;
      } else {
        Node* searchPointer = sortedListHead;
        while (searchPointer->next != nullptr && current->value > searchPointer->next->value) {
          searchPointer = searchPointer->next;
        }
        current->next = searchPointer->next;
        searchPointer->next = current;
      }
    }
    
    _head = sortedListHead;
    Node* temp = _head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    _tail = temp;
  }
  
};


