#include <iostream>

using namespace std;

class Node { 
  public: 
  int value;
  Node* next;
  Node* prev;
  
  Node(int value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
  }
};

class DoublyLinkedList {
  private:
  Node* _head;
  Node* _tail;
  int _length;
  
  public:
  
  DoublyLinkedList(int value) {
    Node* newNode = new Node(value);
    _head = newNode;
    _tail = newNode;
    _length = 1;
  }
  
  ~DoublyLinkedList() {
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
      cout << "empty" << endl;
      return;
    }
    while (temp->next != nullptr) {
      cout << temp->value << " <-> ";
      temp = temp->next;
    }
    cout << temp->value << endl;
  }
  
  void makeEmpty() {
    Node* current = _head;
    while (current != nullptr) {
      Node* nodeToDelete = current;
      current = current->next;
      delete nodeToDelete;
    }
    _head = nullptr;
    _tail = nullptr;
    _length = 0;
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
    if (_head == nullptr) {
      _head = newNode;
      _tail = newNode;
    } else {
      _tail->next = newNode;
      newNode->prev = _tail;
      _tail = newNode;
    }
    
    _length++;
  }

  void deleteLast() {
    if (_length == 0) {
      return;
    }

    if (_length == 1) {
      _head = nullptr;
      _tail = nullptr;
    } else {
      Node* temp = _tail->prev;
      temp->next = nullptr;
      delete _tail;
      _tail = temp;
    }

    _length--;
  }

  void prepend(int value) {
    Node* newNode = new Node(value);
    if (_length == 0) {
      _head = newNode;
      _tail = _head;
    } else {
      _head->prev = newNode;
      newNode->next = _head;
      _head = newNode;
    }

    _length++;
  }

  void deleteFirst() {
    if (_length == 0) {
      return;
    }

    if (_length == 1) {
      _head = nullptr;
      _tail = nullptr;
    } else {
      Node* temp = _head->next;
      temp->prev = nullptr;
      delete _head;
      _head = temp;
    }

    _length--;
  }

  Node* get(int index) {
    if (index < 0 || index >= _length) {
      return nullptr;
    }
    Node* ptr;
    int i;

    if (index > (_length / 2)) {
      ptr = _tail;
      i = _length - 1;
      while (i != index) {
        ptr = ptr->prev;
        i--;
      }  
    } else {
      ptr = _head;
      i = 0;
      while (i != index) {
        ptr = ptr->next;
        i++;
      }
    }

    return ptr;
  }

  bool set(int index, int value) {
    if (_length == 0) {
      return false;
    }

    if (index < 0 || index >= _length) {
      return false;
    }
    
    Node* temp = this->get(index);
    temp->value = value;
    return true;
  }

  bool insert(int index, int value) {
    if (index < 0 || index > _length) {
      return false;
    }

    if (index == _length) {
      this->append(value);
      return true;
    } else if (index == 0) {
      this->prepend(value);
      return true;
    }
    Node* newNode = new Node(value);
    Node* prev = this->get(index - 1);
    Node* next = prev->next;

    prev->next = newNode;
    newNode->prev = prev;

    next->prev = newNode;
    newNode->next = next;
    _length++;
    return true;
  }

  void deleteNode(int index) {
    if (_length == 0) {
      return;
    }

    if (index < 0 || index >= _length) {
      return;
    }

    if (index == 0) {
      this->deleteFirst();
      return;
    } else if (index == _length-1) {
      this->deleteLast();
      return;
    }

    Node* prev = this->get(index - 1);
    Node* temp = prev->next;
    Node* next = temp->next;

    prev->next = next;
    next->prev = prev;
    delete temp;
    _length--;
    return;
  }

  bool isPalindrome() {
    if (_length > -1 && _length <2) {
      return true;
    }

    Node* f_ptr = _head;
    Node* l_ptr = _tail;

    while (true) {
      if (f_ptr->value != l_ptr->value) {
        return false;
      }

      f_ptr = f_ptr->next;
      l_ptr = l_ptr->prev;

      if (f_ptr == l_ptr) {
        return true;
      }

      if (l_ptr->next == f_ptr) {
        return true;
      }
    }
  }

  void reverse() {
    if (_length > -1 && _length < 2) {
      return;
    }

    Node* dummy = new Node(0);
    Node* temp = dummy;
    Node* current = _head;

    dummy->next = _head;
    _head->prev = dummy;
    _tail = _head;

    while (current != nullptr) {
      cout << current->value << endl;
      current->prev = current->next;
      current->next = temp;

      temp = current;
      current = current->prev;
    }
    _tail->next = nullptr;
    delete(dummy);
    _head = temp;
  }

  void partitionList(int x) {
    if (_length == 0) {
      return;
    }

    Node* d1 = new Node(0);
    Node* d2 = new Node(0);
    Node* less_ptr = d1;
    Node* great_ptr = d2;

    Node* ptr = _head;
    while (ptr != nullptr) {
      if (ptr->value < x) {
        less_ptr->next = ptr;
        ptr->prev = less_ptr;
        less_ptr = less_ptr->next;
      } else {
        great_ptr->next = ptr;
        ptr->prev = great_ptr;
        great_ptr = great_ptr->next;
      }

      ptr = ptr->next;
    }
    if (d1->next != nullptr) {
      _head = d1->next;
    } else {
      _head = d2->next;
    }

    if (d2->next != nullptr) {
      less_ptr->next = d2->next;
      Node* temp = d2->next;
      temp->prev = less_ptr;
    } else {
      less_ptr->next = nullptr;
    }
    great_ptr->next = nullptr;
    
    delete(d1);
    delete(d2);
  }

  void reverseBetween(int startIndex, int endIndex) {
    if (_length >-1 && _length < 2) {
      return;
    }

    if (startIndex < 0 || endIndex >= _length) {
      return;
    }

    Node* dummy = new Node(0);
    dummy->next = _head;
    _head->prev = dummy;
    Node* prev = dummy;
    Node* ptr = _head;
    Node* to_move;

    int i = 0;
    while (i != startIndex) {
      prev = prev->next;
      ptr = ptr->next;
      i++;
    }
    while (i != endIndex) {
      to_move = ptr->next;

      ptr->next = to_move->next;
      to_move->next = prev->next;

      to_move->prev = prev;
      prev->next = to_move;

      // ptr = ptr->next;
      i++;
    }

    _head = dummy->next;
    _head->prev = nullptr;
    delete(dummy);
  }

  void swapPairs() {
    if (_length < 2) {
      return;
    }

    Node* d1 = new Node(0);
    Node* d2 = new Node(0);

    d1->next = _head;
    _head->prev = d1;

    Node* first = _head;
    Node* second = _head->next;
    Node* prev = d1;

    while (first != nullptr && second != nullptr) {

      // if (first != nullptr && second != nullptr) {
      //   cout << first->value << " " << second->value << endl;
      // }
      Node* temp;
      if (second->next != nullptr) {
        temp = second->next;
      } else {
        temp = d2;
      }

      first->next = temp;
      temp->prev = first;
      second->next = first;

      second->prev = prev;
      prev->next = second;

      prev = first;
      first = first->next;
      second = first->next;
    }

    _head = d1->next;
    if (d2->prev != nullptr) {
      d2->prev->next = nullptr;
    }
    delete(d1);
    delete(d2);
  }

};
