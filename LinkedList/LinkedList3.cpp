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
  int _length;
  
  public:
  LinkedList(int value) {
    Node* newNode = new Node(value);
    _head = newNode;
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
  
  int getLength() {
    return _length;
  }
  
  void makeEmpty() {
    Node* temp = _head;
    while (_head) {
      _head = _head->next;
      delete temp;
      temp = _head;
    }
    _length = 0;
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
    _length++;
  }
  
  void deleteFirst() {
    if (_length == 0) return;
    Node* temp = _head;
    if (_length == 1) {
      _head = nullptr;
    } else {
      _head = _head->next;
    }
    delete temp;
    _length--;
  }
  
  void partitionList(int x) {
    if (_head == nullptr) {
      return;
    }
    
    Node* less_dummy = new Node(0);
    Node* greater_dummy = new Node(0);
    Node* ptr = _head;
    Node* prev1, *prev2;
    prev1 = less_dummy;
    prev2 = greater_dummy;
    
    while (ptr != nullptr) {
      if (ptr->value < x) {
        prev1->next = ptr;
        prev1 = prev1->next;
      } else {
        prev2->next = ptr;
        prev2 = prev2->next;
      }
      ptr = ptr->next;
    }
    
    prev1->next = greater_dummy->next;
    _head = less_dummy->next;
    prev2->next = nullptr;
    
    delete less_dummy;
    delete greater_dummy;
  }

  void reverseBetween(int m, int n) {
    if (m == n || _head == nullptr) {
      return;
    }

    Node* dummy = new Node(0);
    dummy->next = _head;
    Node* prev = dummy;
    Node* current = _head;
    Node* to_move;

    int i = 0;
    while (i < m) {
      i++;
      prev = prev->next;
      current = prev->next;
    }

    while (i < n) {
      i++;
      to_move = current->next;

      // process to swap the first 3
      current->next = to_move->next;
      to_move->next = prev->next;
      prev->next = to_move;
    } 

    if (m == 0) {
      _head = dummy->next;
    }
    delete dummy;
  }

  void swapPairs() {
    if (_head == nullptr) {
      return;
    }

    Node* dummy = new Node(0);
    dummy->next = _head;

    Node* first = _head;
    Node* second = _head->next;
    Node* prev = dummy;

    while (first != nullptr && second != nullptr) {
      prev->next = second;
      first->next = second->next;
      second->next = first;

      prev = first;
      first = first->next;
      if (first != nullptr) second = first->next;
    }

    _head = dummy->next;
    delete dummy;
  }
  
};

