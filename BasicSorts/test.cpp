#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include <iostream>

using namespace std;
int main() {
  int array[7] = {3, 8, 4, 2, 1, 11, 5};
  // insertionSort(array, 5);

  // mergeSort(array, 0, 6);
  // pivot(array, 0, 6);
  quickSort(array, 0, 6);
  for (auto it : array) {
    cout << it << endl;
  }

  return 0;
}