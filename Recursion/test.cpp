#include <iostream>
#include "BinarySearchTree.cpp"
#include <vector>

using namespace std;

int factorial(int value) {
  if (value == 1) return 1;
  return factorial(value - 1) * value;
}

//  +=====================================================+
//  |                                                     |
//  |          THE TEST CODE BELOW WILL PRINT             |
//  |              OUTPUT TO "USER LOGS"                  |
//  |                                                     |
//  |  Use the output to test and troubleshoot your code  |
//  |                                                     |
//  +=====================================================+


static void test() {
  // Test: Delete Node from an Empty Tree
  {
    cout << "\n----- Test: Delete Node from Empty Tree -----\n";
    BinarySearchTree bst;
    bst.deleteNode(42); // Attempt to delete from an empty tree
    cout << "Attempting to delete value 42 from an empty tree.\n";
    cout << (bst.getRoot() == nullptr ? "PASS\n" : "FAIL\n");
  }
  
  // Test: Delete Leaf Node
  {
    cout << "\n----- Test: Delete Leaf Node -----\n";
    BinarySearchTree bst;
    bst.rInsert(50);
    bst.rInsert(30);
    bst.rInsert(70);
    bst.rInsert(20); // Leaf node
    bst.deleteNode(20); // Deleting the leaf node
    cout << "Deleting leaf node 20.\n";
    cout << (!bst.rContains(20) ? "PASS\n" : "FAIL\n");
  }
  
  // Test: Delete Node with One Child
  {
    cout << "\n----- Test: Delete Node with One Child -----\n";
    BinarySearchTree bst;
    bst.rInsert(50);
    bst.rInsert(30);
    bst.rInsert(70);
    bst.rInsert(20); // Leaf node
    bst.rInsert(25); // Node with one child
    bst.deleteNode(20); // Deleting node with one child
    cout << "Deleting node 20, which has one child 25.\n";
    cout << (!bst.rContains(20) && bst.rContains(25) ? "PASS\n" : "FAIL\n");
  }
  
  // Test: Delete Node with Two Children
  {
    cout << "\n----- Test: Delete Node with Two Children -----\n";
    BinarySearchTree bst;
    bst.rInsert(50);
    bst.rInsert(30);
    bst.rInsert(70);
    bst.rInsert(20);
    bst.rInsert(40);
    bst.rInsert(60);
    bst.rInsert(80);
    bst.deleteNode(30); // Node with two children
    cout << "Deleting node 30, which has two children (20 and 40).\n";
    cout << (!bst.rContains(30) && bst.rContains(20) && bst.rContains(40) ? "PASS\n" : "FAIL\n");
  }
  
  // Test: Delete Root Node
  {
    cout << "\n----- Test: Delete Root Node -----\n";
    BinarySearchTree bst;
    bst.rInsert(50);
    bst.rInsert(30);
    bst.rInsert(70);
    bst.deleteNode(50); // Deleting the root node
    cout << "Deleting root node 50.\n";
    cout << (!bst.rContains(50) ? "PASS\n" : "FAIL\n");
  }
}



int main(int argc, char* argv[]) {
  // cout << factorial(atoi(argv[1])) << endl;
  
  BinarySearchTree bst;
  
  vector<int> toBeAdded = {9, 5, 8 ,5 ,6};
  
  for (auto it : toBeAdded){
    bst.rInsert(it);
    cout << bst.rContains(it) << endl;
  }
  
  // bst.rInsert(6);
  
  // bst.deleteNode(6);
  // cout << bst.root->value << endl;
  // for (auto it : toBeAdded)
  // {
  //   cout << endl;
  //   // bst.deleteNode(it);
  //   for (auto it : toBeAdded){
  //     cout << bst.rContains(it) << endl;
  //   }
  // }
  // bst.BFS();
  bst.DFSPreOrder();
  cout << endl;
  bst.DFSPostOrder();
  cout << endl;
  bst.DFSInOrder();

  // test();
  
  // for (auto it : toBeAdded){
  //   cout << bst.rContains(it) << endl;
  // }
  
  // cout << bst.rContains(9) << endl;
  return 0;
}