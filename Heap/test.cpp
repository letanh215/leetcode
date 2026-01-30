#include "MaxHeap.cpp"

int main() {
  MaxHeap heap;

  vector<int> valuesToInsert = {10, 20, 30, 5, 15, 25, 35};
  cout << "Inserting values: ";
  for (int value : valuesToInsert) {
      cout << value << " ";
      heap.insert(value);
  }
  heap.printHeap();
  heap.remove();
  heap.remove();
  // vector<int> heap_vector = heap.getHeap();
  // cout << heap_vector[heap_vector.size() + 4] << endl;

  heap.printHeap();

  return 0;
}