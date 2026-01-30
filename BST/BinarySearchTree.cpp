#include <iostream>

using namespace std;


class Node { 
  public: 
  int value;
  Node* left;
  Node* right;
  
  Node(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};


class BinarySearchTree {
  public:
  Node* root;
  
  public:
  BinarySearchTree() { root = nullptr; }
  
  
  // ---------------------------------------------------
  //  Below is a helper function used by the destructor
  //  Deletes all nodes in BST
  //  Similar to DFS PostOrder in Tree Traversal section
  // ---------------------------------------------------
  void destroy(Node* currentNode) {
    if (currentNode == nullptr) return;
    if (currentNode->left) destroy(currentNode->left);
    if (currentNode->right) destroy(currentNode->right);
    delete currentNode;
  }
  
  ~BinarySearchTree() { destroy(root); }
  
  Node* getRoot() {
    return root;
  } 
  
  bool insert(int value) {
    Node* node = new Node(value);
    if (root == nullptr) {
      root = node;
      return true;
    } else {
      Node* ptr = root;
      while (1) 
      {
        if (ptr->value == value ) {
          return false;
        } else if (ptr->value > value) {
          if (ptr->left == nullptr) 
          {
            ptr->left = node;
            return true;
          } else {
            ptr = ptr->left;
          }
        } else if (ptr->value < value) {
          if (ptr->right == nullptr) 
          {
            ptr->right = node;
            return true;
          } else {
            ptr = ptr->right;
          }
        }
      }
    }
  }

  bool contains(int value) {
    if (root == nullptr) {
      return false;
    } else {

      Node* ptr = root;
      while (ptr != nullptr) {
        if (ptr->value == value) {
          return true;
        } else if (ptr->value > value) {
          ptr = ptr->left;
        } else {
          ptr = ptr->right;
        }
      }
    }

    return false;
  }
  
};


