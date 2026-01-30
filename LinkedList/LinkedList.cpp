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
  
  LinkedList():
  _head(nullptr), _tail(nullptr) {
    _length = 0;
  }
  
  LinkedList(int value){
    Node* newNode = new Node(value);
    _tail = newNode;
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
  
  void makeEmpty() {
    Node* temp = _head;
    while (_head) {
      _head = _head->next;
      delete temp;
      temp = _head;
    }
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
  
  void append(int value){
    Node* newNode = new Node(value);
    
    if (_length == 0){
      _head = newNode;
      _tail = newNode;
    } else {
      _tail->next = newNode;
      _tail = newNode;
    }

    _length++;
  }

  void deleteLast(){
    if (_length == 0) {
      return;
    } else if (_length == 1) {
      _head = nullptr;
      _tail = nullptr;
    } else {
      Node* temp = _head;
      while (temp->next != _tail){
        temp = temp->next;
      }
      _tail = temp;
      temp = _tail->next;
      _tail->next = nullptr;
      delete temp;
    }
    _length--;
  }

  void prepend(int value){
    Node* newNode = new Node(value);

    if (_length == 0) {
      _head = newNode;
      _tail = newNode;
    } else {
      newNode->next = _head;
      _head = newNode;
    }

    _length++;
  }

  void deleteFirst() {
    if (_length == 0) {
      return;
    } else if (_length == 1) {
      _head = nullptr;
      _tail = nullptr;
    } else {
      Node* temp = _head;
      _head = temp->next;
      delete temp;
    }

    _length--;
  }

  Node* get(int index) {
    if (index >= _length|| index < 0) {
      return nullptr;
    }
    
    Node* temp = _head;
    for (int i = 0; i < index; i++){
      temp = temp->next;
    }

    return temp;
  }

  bool set(int index, int value) {
    Node* temp = this->get(index);

    if (temp) {
      temp->value = value;
      return true;
    } else {
      return false;
    }
  }

  bool insert(int index, int value) {
    if (index > _length || index < 0) {
      return false;
    }
    
    if (index == 0) {
      this->prepend(value);
    } else if (index == _length) {
      this->append(value);
    } else {
      Node* temp = this->get(index - 1);
      Node* newNode = new Node(value);
      
      newNode->next = temp->next;
      temp->next = newNode;
    }
    _length++;
    return true;
  }

  void deleteNode(int index) {
    if (index >= _length || index < 0) {
      return;
    }

    if (index == 0) {
      this->deleteFirst();
    } else if (index == _length - 1) {
      this->deleteLast();
    } else {
      Node* prev = this->get(index - 1);
      Node* temp = prev->next;

      prev->next = temp->next;
      delete temp;

      _length--; 
    }
  }

  void reverse() {
    Node* temp = _head;

    _head = _tail;
    _tail = temp;

    Node* after = nullptr;
    Node* before = nullptr;

    for (int i = 0; i < _length; i++){
      after = temp->next;
      temp->next = before;
      before = temp;
      temp = after;
    }
  }

  // Find middle node without using length of the linked list
  Node* findMiddleNode() {
    if (_head == nullptr) {
      return nullptr;
    }

    Node* slow = _head;
    Node* fast = _head;

    while (fast != _tail && fast != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    
    return slow;
  }

  // Find if the LL has a loop
  bool hasLoop() {
    if (_head == nullptr) {
      return false;
    }

    Node* slowptr = _head;
    Node* fastptr = _head;

    while (fastptr != _tail && fastptr != nullptr) {
      slowptr = slowptr->next;
      fastptr = fastptr->next->next;
      if (slowptr == fastptr) {
        return true;
      }
    }
    
    return false;
  }

	// Kth node from end finding.
  Node* findKthFromEnd(int k) {
    if (k < 0) {
      return nullptr;
    }
		
    Node* slowptr = _head;
    Node* fastptr = _head;

		if (fastptr == nullptr) {
			return nullptr;
		}
    for (int i = 1; i < k; i++) {
      if (fastptr->next != nullptr) {
				fastptr = fastptr->next;
			} else {
				return nullptr;
			}
    }

    while (fastptr != _tail) {
      slowptr = slowptr->next;
      fastptr = fastptr->next;
    }

    return slowptr;
  }

	void removeDuplicates() {
		if (_head == nullptr) {
			return;
		}
		Node* currentptr = _head;
		Node* runnerptr = _head->next;
		Node* temp;

		while (currentptr != nullptr) {
			temp = currentptr;
			runnerptr = currentptr->next;
			while (runnerptr != nullptr) {
				if (currentptr->value == runnerptr->value){
					cout << "remove " << runnerptr->value << endl;
					temp->next = runnerptr->next;
					runnerptr = temp;
					_length--;
				}
				temp = runnerptr;
				runnerptr = runnerptr->next;
			}
			currentptr = currentptr->next;
		}
	}
};