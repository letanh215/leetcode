#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value);
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree();
    ~BinarySearchTree();
    void insert(int value);
    bool contains(int value);
    void BFS();
    void DFSPreOrder();
    void DFSPostOrder();
    void DFSInOrder();

private:
    void destroy(Node* currentNode);
    void DFSPreOrder(Node* currentNode);
    void DFSPostOrder(Node* currentNode);
    void DFSInOrder(Node* currentNode);
};

#endif
