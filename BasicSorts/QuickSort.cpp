#include "QuickSort.h"


void swap(int array[], int firstIndex, int secondIndex) {
  int temp = array[firstIndex];
  array[firstIndex] = array[secondIndex];
  array[secondIndex] = temp;
}


int pivot(int array[], int pivotIndex, int endIndex) {

  int swapIndex = pivotIndex + 1;
  int pivotValue = array[pivotIndex];

  for (int i = pivotIndex + 1; i <= endIndex; i++) {
    if (array[i] < pivotValue) {
      swap(array, swapIndex, i);
      swapIndex++;
    }
  }

  swap(array, swapIndex-1, pivotIndex);
  return swapIndex-1;
}

void quickSort(int array[], int leftIndex, int rightIndex) {
  if (leftIndex >= rightIndex) {
    return;
  }

  int midIndex = pivot(array, leftIndex, rightIndex);
  quickSort(array, leftIndex, midIndex);
  quickSort(array, midIndex + 1, rightIndex);
}