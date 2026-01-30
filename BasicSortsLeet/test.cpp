// #include "BubbleSort.cpp"
// #include "SelectionSort.cpp"
#include "Merge.cpp"
#include <vector>

int main() {
  LinkedList ll1 = LinkedList(1);
  LinkedList ll2 = LinkedList(2);

  ll2.deleteFirst();

  vector<int> toAdd1 = {5, 9 ,12};
  vector<int> toAdd2 = {4, 11, 18};
  for (int it : toAdd1) {
    ll1.append(it);
  }

  // for (int it : toAdd2) {
  //   ll2.append(it);
  // }
  
  ll1.merge(ll2);
  ll1.printList();

  return 0;
}