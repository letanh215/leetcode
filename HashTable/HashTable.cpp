#include <iostream>
#include <vector>

using namespace std;

class Node {
  public:
  string key;
  int value;
  Node* next;
  
  Node(string key, int value) {
    this->key = key;
    this->value = value;
    next = nullptr;
  }
};

class HashTable {
  private:
  static const int SIZE = 7;
  Node* dataMap[SIZE];
  
  int hash(string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
      int asciiValue = int(key[i]);
      hash = (hash + asciiValue *  23) % SIZE;
    }
    return hash;
  }
  
  public:
  HashTable() {
    for(int i = 0; i < SIZE; i++) {
      dataMap[i] = nullptr;
    }
  }
  
  // ---------------------------------------------------
  //  Destructor code is similar to keys() function
  //  Watch that video to help understand how this works
  // ---------------------------------------------------
  ~HashTable() {
    for(int i = 0; i < SIZE; i++) {
      Node* head = dataMap[i];
      Node* temp = head;
      while (head) {
        head = head->next;
        delete temp;
        temp = head;
      }
    }
  }
  
  void printTable() {
    for(int i = 0; i < SIZE; i++) {
      cout << "Index " << i << ": ";
      if(dataMap[i]) {
        cout << "Contains => ";
        Node* temp = dataMap[i];
        while (temp) {
          cout << "{" << temp->key << ", " << temp->value << "}";
          temp = temp->next;
          if (temp) cout << ", ";
        }
        cout << endl;
      } else {
        cout << "Empty" << endl;
      }
    }
  }
  
  void set(string key, int value) {

    int hash = this->hash(key);

    Node* node = new Node(key, value);
    if (dataMap[hash] != nullptr) {
      Node* ptr = dataMap[hash];
      Node* temp;

      while (ptr != nullptr) {
        if (ptr->key == key) {
          ptr->value = value;
          return;
        } else {
          temp = ptr;
          ptr = ptr->next;
        }
      }
      
      temp->next = node;
    } else {
      dataMap[hash] = node;
    }
  }
  
  int get(string key) {
    int hash = this->hash(key);

    if (dataMap[hash] == nullptr) {
      return 0;
    } else {
      Node* ptr = dataMap[hash];

      while (ptr != nullptr) {
        if (ptr->key == key) {
          return ptr->value;
        } else {
          ptr = ptr->next;
        }
      }
    }

    return 0;
  }
  
  vector<string> keys() {
    vector<string> allKeys;

    for (int i = 0; i < SIZE; i++) {
      if (dataMap[i] != nullptr) {
        Node* ptr = dataMap[i];
        while (ptr != nullptr) {
          allKeys.push_back(ptr->key);
          ptr = ptr->next;
        }
      }
    }

    return allKeys;
  }
};


