#include <iostream>

using namespace std;

class Node
{
  public:
  int value;
  Node *next;
  
  Node(int value)
  {
    this->value = value;
    next = nullptr;
  }
};

class LinkedList
{
  private:
  Node *_head;
  Node *_tail;
  int _length;
  
  public:
  LinkedList(int value)
  {
    Node *newNode = new Node(value);
    _head = newNode;
    _tail = newNode;
    _length = 1;
  }
  
  ~LinkedList()
  {
    Node *temp = _head;
    while (_head)
    {
      _head = _head->next;
      delete temp;
      temp = _head;
    }
  }
  
  void printList()
  {
    Node *temp = _head;
    if (temp == nullptr)
    {
      cout << "empty";
    }
    else
    {
      while (temp != nullptr)
      {
        cout << temp->value;
        temp = temp->next;
        if (temp != nullptr)
        {
          cout << " -> ";
        }
      }
    }
    cout << endl;
  }
  
  Node *getHead()
  {
    return _head;
  }
  
  Node *getTail()
  {
    return _tail;
  }
  
  int getLength()
  {
    return _length;
  }
  
  void append(int value)
  {
    Node *newNode = new Node(value);
    if (_length == 0)
    {
      _head = newNode;
      _tail = newNode;
    }
    else
    {
      _tail->next = newNode;
      _tail = newNode;
    }
    _length++;
  }
  
  void deleteFirst()
  {
    if (_length == 0)
    return;
    Node *temp = _head;
    if (_length == 1)
    {
      _head = nullptr;
      _tail = nullptr;
    }
    else
    {
      _head = _head->next;
    }
    delete temp;
    _length--;
  }
  
  void bubbleSort()
  {
    if (_head == nullptr)
    {
      return;
    }
    Node *ptr = _head;
    Node *marker = _tail;
    while (marker != _head)
    {
      while (1) {
        if (ptr->next->value < ptr->value) {
          int temp = ptr->next->value;
          ptr->next->value = ptr->value;
          ptr->value = temp;
        }
        if (ptr->next == marker) break;
        ptr = ptr->next;
      }
      marker = ptr;
      ptr = _head;
    }
  }
};
