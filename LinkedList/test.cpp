#include "LinkedList3.cpp"
#include <array>

int main() {
  LinkedList ll = LinkedList(3);

  // for (int i = 2; i < 6; i++) {
  //   ll.append(i);
  //   ll.append(i);
  // }

  std::array<int, 5> values = {8, 5, 10, 2, 1};

  for (int i = 0; i < values.size(); i++) {
    ll.append(values.at(i));
  }

  // ll.partitionList(5);
  ll.swapPairs();
  ll.printList();
  return 0;
}