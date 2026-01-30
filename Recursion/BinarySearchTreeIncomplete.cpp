#include <iostream>
#include <queue>

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
    Node* newNode = new Node(value);
    if (root == nullptr) {
      root = newNode;
      return true;
    }
    Node* temp = root;
    while(true) {
      if (newNode->value == temp->value) return false;
      if (newNode->value < temp->value) {
        if (temp->left == nullptr) {
          temp->left = newNode;
          return true;
        }
        temp = temp->left;
      } else {
        if (temp->right == nullptr) {
          temp->right = newNode;
          return true;
        }
        temp = temp->right;
      }
    }
  }

  bool rContains(Node* currentNode, int value) {
    if (currentNode == nullptr) {
      return false;
    }

    if (currentNode->value == value) {
      return true;
    }

    if (currentNode->value >= value) {
      return rContains(currentNode->left, value);
    } else return rContains(currentNode->right, value);
  }
  
  bool rContains(int value) { 
    return rContains(root, value); 
  } 

  Node* rInsert(Node* currentNode, int value) {
    if (currentNode == nullptr) {
      return new Node(value);
    }

    if (currentNode->value < value) {
      currentNode->right = rInsert(currentNode->right, value);
    } else if (currentNode->value > value) {
      currentNode->left = rInsert(currentNode->left, value);
    }
    return currentNode;
  }

  void rInsert(int value) {
    if (root == nullptr) root = new Node(value);
    rInsert(root, value);
  }

  int minValue(Node* currentNode) {
    if (currentNode == nullptr) {
      return -1;
    }
    Node* ptr = currentNode;

    while (ptr->left != nullptr) {
      ptr = ptr->left;
    }

    return ptr->value;
  }

  Node* deleteNode(Node* currentNode, int value) {
    if (currentNode == nullptr) {
      return nullptr;
    }

    if (currentNode->value == value) {
      if (currentNode->right == nullptr) {
        return currentNode->left;
      } else {
        currentNode->value = minValue(currentNode->right);
        currentNode->right = deleteNode(currentNode->right, currentNode->value);
      }
    }

    if (currentNode->value < value) {
      currentNode->right = deleteNode(currentNode->right, value);
    } else if (currentNode->value > value) {
      currentNode->left = deleteNode(currentNode->left, value);
    }

    return currentNode;
  }

  void deleteNode(int value) {
    if (root == nullptr) {
      return;
    }
    if (root->left == nullptr && root->right == nullptr) {
      root = nullptr;
      return;
    }
    root = deleteNode(root, value); 
  }

  void BFS() {

    if (root == nullptr) {
      return;
    }

    queue<Node*> q;
    Node* ptr;
    if (root )
    q.push(root);
    while (!q.empty()) {
      ptr = q.front();
      q.pop();

      cout << ptr->value << " ";

      if (ptr->left != nullptr) q.push(ptr->left);
      if (ptr->right != nullptr) q.push(ptr->right);
    }
  }

  void DFSPreOrder(Node* currentNode) {
    if (currentNode == nullptr) {
      return;
    }
    cout << currentNode->value << " ";
    DFSPreOrder(currentNode->left);
    DFSPreOrder(currentNode->right);
  }

  void DFSPreOrder() {
    DFSPreOrder(root);
  }

  void DFSPostOrder(Node *currentNode) {
    if (currentNode == nullptr) {
      return;
    }
    DFSPostOrder(currentNode->left);
    DFSPostOrder(currentNode->right);
    cout << currentNode->value << " ";
  }

  void DFSPostOrder() {
    DFSPostOrder(root);
  }

  void DFSInOrder(Node* currentNode) {
    if (currentNode == nullptr) {
      return;
    }
    DFSInOrder(currentNode->left);
    cout << currentNode->value << " ";
    DFSInOrder(currentNode->right);
  }

  void DFSInOrder() {
    DFSInOrder(root);
  }
  
};

