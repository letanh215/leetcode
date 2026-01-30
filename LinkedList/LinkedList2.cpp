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
  
  public:
  LinkedList(int value) {
    Node* newNode = new Node(value);
    _head = newNode;
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
  
  void makeEmpty() {
    Node* temp = _head;
    while (_head) {
      _head = _head->next;
      delete temp;
      temp = _head;
    }
  }
  
  void append(int value) {
    Node* newNode = new Node(value);
    if (_head == nullptr) {
      _head = newNode;
    } else {
      Node* currentNode = _head;
      while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
      }
      currentNode->next = newNode;
    }
  }
  
  int binaryToDecimal() {
    int sum = 0;

    Node* currentptr = _head;

    while (currentptr != nullptr) {
      sum = currentptr->value + (sum * 2);
      currentptr = currentptr->next;
    }

    return sum;
  }
  
};


